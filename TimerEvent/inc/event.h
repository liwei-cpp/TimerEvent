#pragma once
#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>

#include "inc/running_context.h"

namespace TimerEvent
{
class Event
{
public:
    static Event& Instance();
    Event(const Event&) = delete;
    Event& operator= (const Event&) = delete;    
    ~Event();
    
public:
    void Add(std::shared_ptr<RunningContext> cont);
    void Remove(const std::shared_ptr<RunningContext>& cont);
    void RemoveAll();

private:
    Event();
    void Loop();
    void TriggerTimers(const std::chrono::steady_clock::time_point& now);
    
private:
    std::thread m_loopThread;
    std::mutex m_timerMutex;
    std::condition_variable m_timerCondition;
    bool m_running = true;
    std::deque<std::pair<std::chrono::steady_clock::time_point, std::shared_ptr<RunningContext>>> m_timers;
};
}