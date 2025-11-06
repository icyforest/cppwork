#include "Command.hpp"
#include "Executorlmpl.hpp"
#include <unordered_map>
#include "CmderFactory.hpp"
#include "Singleton.hpp"

namespace adas
{
    Executor* Executor::NewExecutor(const Pose& pose)noexcept
    {
        return new(std::nothrow) Executorlmpl(pose);
    }

    Executorlmpl::Executorlmpl(const Pose& pose) noexcept: poseHandler(pose)
    {
    }

    void Executorlmpl::Execute(const std::string& commands)noexcept
    {
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);

        std::for_each(
        cmders.begin(),
        cmders.end(),
        [this](const Cmder & cmder) noexcept 
        {
            cmder(poseHandler);
        });

    }

    Pose Executorlmpl::Query()const noexcept
    {
        return poseHandler.Query();
    }
}