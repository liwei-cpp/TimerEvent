#include "include/shared_timer.h"
#include "inc/shared_timer_impl.h"

namespace TimerEvent
{
SharedTimer::SharedTimer(std::function<void()> task, bool isOneOff)
    : m_timerImpl(std::make_shared<SharedTimerImpl>(task, isOneOff))
{}

void SharedTimer::Register(const std::chrono::nanoseconds& val)
{
    m_timerImpl->Register(val);
}

void SharedTimer::Unschedule()
{
    m_timerImpl->Unschedule();
}
}