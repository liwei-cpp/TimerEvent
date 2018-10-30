#pragma once
#include <chrono>
#include <functional>
#include <memory>

namespace TimerEvent
{
class SharedTimerImpl;

class SharedTimer
{
public:
    SharedTimer(std::function<void()> task, bool isOneOff = false);
    
    template<typename TDuration>
    void Schedule(const TDuration& duration)
    {
        auto nanoSchedule = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
        Register(nanoSchedule);
    }
    
    void Unschedule();

private:
    void Register(const std::chrono::nanoseconds& seconds);
    
private:
    std::shared_ptr<SharedTimerImpl> m_timerImpl;
};
}