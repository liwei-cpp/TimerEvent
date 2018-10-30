#include "inc/shared_timer_impl.h"
#include "inc/event.h"

namespace TimerEvent
{
SharedTimerImpl::SharedTimerImpl(std::function<void()> task, bool isOneOff)
    : m_task(std::move(task))
    , m_isOneOff(isOneOff)
{}

SharedTimerImpl::~SharedTimerImpl()
{
    Unschedule();
}

void SharedTimerImpl::Register(const std::chrono::nanoseconds& dru)
{
    std::lock_guard<std::mutex> lg(m_scheduleMutex);
    if (m_runningContext)
    {
        throw std::runtime_error("Cannot re-schedule an available timer.");
    }
    
    std::weak_ptr<SharedTimerImpl> wp = shared_from_this();
    std::function<std::shared_ptr<RunningContext>()> windUp =
        [timer{std::move(wp)}]
        {
            auto stInst = timer.lock();
            if (!stInst)
                return std::shared_ptr<RunningContext>();

            std::lock_guard<std::mutex> lg(stInst->m_scheduleMutex);
            
            if (stInst->m_isOneOff)
                stInst->m_runningContext.reset();
            return stInst->m_runningContext;
        };
        
    m_runningContext = std::make_shared<RunningContext>(dru, m_task, std::move(windUp));
    Event::Instance().Add(m_runningContext);
}

void SharedTimerImpl::Unschedule()
{
    std::lock_guard<std::mutex> lg(m_scheduleMutex);
    if (m_runningContext)
    {
        Event::Instance().Remove(m_runningContext);
        m_runningContext.reset();
    }
}
}