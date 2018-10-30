#include "inc/event.h"
#include <algorithm>
#include <chrono>
#include <iterator>
#include <memory>

namespace
{
using namespace TimerEvent;

inline
std::pair<std::chrono::steady_clock::time_point, std::shared_ptr<RunningContext>>
CookTimeInfo(const std::chrono::steady_clock::time_point& now, std::shared_ptr<RunningContext> cont)
{
    std::chrono::steady_clock::time_point timeTrigger = now + cont->Duration();
    return 
        std::pair<std::chrono::steady_clock::time_point, std::shared_ptr<RunningContext>>(std::move(timeTrigger),
                                                                                          std::move(cont));
}
}

namespace TimerEvent
{
Event& Event::Instance()
{
    static Event inst;
    return inst;
}

Event::Event()
    : m_loopThread(&Event::Loop, this)
{
}

Event::~Event()
{
    m_running = false;
    RemoveAll();
    m_loopThread.join();
}

void Event::Add(std::shared_ptr<RunningContext> cont)
{
    if (!cont) return;
    std::lock_guard<std::mutex> lock(m_timerMutex);
    
    auto item = CookTimeInfo(std::chrono::steady_clock::now(), std::move(cont));
    
    if (m_timers.empty())
    {
        m_timers.emplace_back(std::move(item));
    }
    else
    {
        auto it = std::lower_bound(m_timers.begin(), m_timers.end(), item);
        m_timers.insert(it, item);
    }
    m_timerCondition.notify_one();
}

void Event::Remove(const std::shared_ptr<RunningContext>& cont)
{
    std::lock_guard<std::mutex> lock(m_timerMutex);
    for (auto it = m_timers.begin(); it != m_timers.end(); ++it)
    {
        if (it->second == cont)
        {
            m_timers.erase(it);
            break;
        }
    }
    m_timerCondition.notify_one();
}

void Event::RemoveAll()
{
    std::lock_guard<std::mutex> lock(m_timerMutex);
    m_timers.clear();
    m_timerCondition.notify_one();
}

void Event::TriggerTimers(const std::chrono::steady_clock::time_point& now)
{
    std::deque<std::pair<std::chrono::steady_clock::time_point, std::shared_ptr<RunningContext>>> processed;
    
    while (!m_timers.empty())
    {
        const auto& t = m_timers.front();
        if (t.first > now)
        {
            break;
        }
        
        const auto& taskContext = t.second;
        auto next = t.second->Next();
        
        if (next)
        {
           processed.push_back(CookTimeInfo(now, taskContext));
        }
        const auto& curTask = taskContext->Task();
        curTask();
        m_timers.pop_front();
    }
    
    if (processed.empty())
    {
        return;
    }
    
    std::sort(processed.begin(), processed.end());
    std::deque<std::pair<std::chrono::steady_clock::time_point, std::shared_ptr<RunningContext>>> nextTimers;
    std::merge(m_timers.begin(), m_timers.end(),
               processed.begin(), processed.end(),
               std::back_inserter(nextTimers));
    m_timers = std::move(nextTimers);
}

void Event::Loop()
{
    std::unique_lock<std::mutex> lock(m_timerMutex);
    while (m_running)
    {
        auto now = std::chrono::steady_clock::now();
        
        TriggerTimers(now);

        std::chrono::steady_clock::time_point tillTime;
        
        if (m_timers.empty())
        {
            tillTime = now + std::chrono::seconds(1);
        }
        else
        {
            tillTime = m_timers.front().first;
        }

        m_timerCondition.wait_until(lock, tillTime);
    }
    lock.unlock();
}
}