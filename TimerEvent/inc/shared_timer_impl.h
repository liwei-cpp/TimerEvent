#pragma once
#include <chrono>
#include <functional>
#include <mutex>
#include <memory>
#include <stdexcept>

#include "inc/running_context.h"

namespace TimerEvent
{
class SharedTimerImpl : public std::enable_shared_from_this<SharedTimerImpl>
{
public:
    SharedTimerImpl(std::function<void()> task, bool isOneOff = false);
    ~SharedTimerImpl();
    
    void Register(const std::chrono::nanoseconds& dru);
    
    void Unschedule();
    
private:
    const std::function<void()> m_task;
    const bool m_isOneOff;
    
    std::shared_ptr<RunningContext> m_runningContext;
    std::mutex m_scheduleMutex;
};
}