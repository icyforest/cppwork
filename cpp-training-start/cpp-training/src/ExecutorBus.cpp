#include "CommandBus.hpp"
#include "ExecutorBus.hpp"
#include <unordered_map>
#include "CmderFactoryBus.hpp"
#include "Singleton.hpp"

namespace adas
{
    Executor* Executor::NewExecutorBus(const Pose& pose)noexcept
    {
        return new(std::nothrow) ExecutorBus(pose);
    }

    ExecutorBus::ExecutorBus(const Pose& pose) noexcept: poseHandler(pose)
    {
    }

    void ExecutorBus::Execute(const std::string& commands)noexcept
    {
        const auto buscmders = Singleton<CmderFactoryBus>::Instance().GetBusCmders(commands);

        std::for_each(
        buscmders.begin(),
        buscmders.end(),
        [this](const CmderBus & buscmder) noexcept 
        {
            buscmder(poseHandler);
        });

    }

    Pose ExecutorBus::Query()const noexcept
    {
        return poseHandler.Query();
    }
}