#include "Command.hpp"
#include "Executorlmpl.hpp"
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
        for(const auto cmd : commands)
        {
            std::unique_ptr<ICommand> cmder;
            if(cmd == 'F')
            {
                cmder = std::make_unique<FastCommand>();
            }
            else if(cmd == 'M')
            {
                cmder = std::make_unique<MoveCommand>();
            }
            else if(cmd == 'L')
            {
                cmder = std::make_unique<TurnLeftCommand>();
            }
            else if(cmd == 'R')
            {
                cmder = std::make_unique<TurnRightCommand>();
            }

            if(cmder)
            {
                cmder -> DoOperate(posehandler);
            }
        }
    }

    Pose Executorlmpl::Query()const noexcept
    {
        return posehandler.Query();
    }
}