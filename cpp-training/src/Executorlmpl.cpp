#include "Command.hpp"
#include "Executorlmpl.hpp"
#include <unordered_map>
namespace adas
{
    Executor* Executor::NewExecutor(const Pose& pose)noexcept
    {
        return new(std::nothrow) Executorlmpl(pose);
    }

    Executorlmpl::Executorlmpl(const Pose& pose) noexcept: posehandler(pose)
    {
    }

    void Executorlmpl::Execute(const std::string& commands)noexcept
    {
        std::unordered_map<char, std::function<void(PoseHandler & posehandler)>>  cmderMap;
        cmderMap.emplace('M', MoveCommand());
        cmderMap.emplace('L', TurnLeftCommand());
        cmderMap.emplace('R', TurnRightCommand());
        cmderMap.emplace('F', FastCommand());

        for (const auto cmd : commands) {
            const auto it = cmderMap.find(cmd);
            if (it != cmderMap.end()) {
                it->second(this -> posehandler);
            }
        }
    }

    Pose Executorlmpl::Query()const noexcept
    {
        return posehandler.Query();
    }
}