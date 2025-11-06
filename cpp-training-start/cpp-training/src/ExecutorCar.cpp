#include "CommandCar.hpp"
#include "ExecutorCar.hpp"
#include <unordered_map>
#include "CmderFactoryCar.hpp"
#include "Singleton.hpp"

namespace adas
{
    Executor* Executor::NewExecutorCar(const Pose& pose)noexcept
    {
        return new(std::nothrow) ExecutorCar(pose);
    }

    ExecutorCar::ExecutorCar(const Pose& pose) noexcept: poseHandler(pose)
    {
    }

    void ExecutorCar::Execute(const std::string& commands)noexcept
    {
        const auto carcmders = Singleton<CmderFactoryCar>::Instance().GetCarCmders(commands);

        std::for_each(
        carcmders.begin(),
        carcmders.end(),
        [this](const CmderCar & carcmder) noexcept 
        {
            carcmder(poseHandler);
        });

    }

    Pose ExecutorCar::Query()const noexcept
    {
        return poseHandler.Query();
    }
}