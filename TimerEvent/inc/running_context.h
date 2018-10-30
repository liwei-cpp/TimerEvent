#pragma once
#include <functional>
#include <memory>

namespace TimerEvent
{
class RunningContext
{
public:
    RunningContext(std::chrono::nanoseconds duration,
                   const std::function<void()>& task,
                   std::function<std::shared_ptr<RunningContext>()> windUp)
        : m_duration(std::move(duration))
        , m_task(task)
        , m_windUp(std::move(windUp))
    {}
    
    const auto& Task() const
    {
        return m_task;
    }
    
    const auto& Duration() const noexcept
    {
        return m_duration;
    }
    
    auto Next()
    {
        return m_windUp();
    }
    
private:
    const std::chrono::nanoseconds m_duration;
    const std::function<void()>& m_task;
    std::function<std::shared_ptr<RunningContext>()> m_windUp;
};
}