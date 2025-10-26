#include"Executorlmpl.hpp"
namespace adas
{
    Executor* Executor::NewExecutor(const Pose& pose)noexcept
    {
        return new(std::nothrow) Executorlmpl(pose);
    }

    Executorlmpl::Executorlmpl(const Pose& pose) noexcept
    {
        this -> pose.x = pose.x;
        this -> pose.y = pose.y;
        this -> pose.heading = pose.heading;
        this -> isfast = false;
    }

    void Executorlmpl::Execute(const std::string& commands)noexcept
    {
        for(const auto cmd : commands)
        {
            if(cmd == 'F')
            {
                this -> isfast = true;
            }
            if(cmd == 'M')
            {
                std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
                if(isfast)
                {    
                    cmder -> DoOperate(*this);
                }
                cmder -> DoOperate(*this);
            }
            else if(cmd == 'L')
            {
                std::unique_ptr<MoveCommand> cmder1 = std::make_unique<MoveCommand>();
                std::unique_ptr<TurnLeftCommand> cmder2 = std::make_unique<TurnLeftCommand>();
                if(isfast)
                {    
                    cmder1 -> DoOperate(*this);
                }
                cmder2 -> DoOperate(*this);
            }
            else if(cmd == 'R')
            {
                std::unique_ptr<MoveCommand> cmder1 = std::make_unique<MoveCommand>();
                std::unique_ptr<TurnRightCommand> cmder2 = std::make_unique<TurnRightCommand>();
                if(isfast)
                {    
                    cmder1 -> DoOperate(*this);
                }
                cmder2 -> DoOperate(*this);
            }
        }
    }

    Pose Executorlmpl::Query()const noexcept
    {
        return pose;
    }

    void Executorlmpl::MoveCommand::executorMove(Executorlmpl & executor)noexcept
    {
        if(executor.pose.heading == 'E')
        {
             executor.pose.x += 1;
        }
        else if(executor.pose.heading == 'W')
        {
            executor.pose.x --;
        }
        else if(executor.pose.heading == 'N')
        {
            executor.pose.y ++;
        }
        else if(executor.pose.heading == 'S')
        {
            executor.pose.y --;
        }
    }

    void Executorlmpl::TurnLeftCommand::executorTurnLeft(Executorlmpl & executor)noexcept
    {
        if(executor.pose.heading == 'E')
        {
            executor.pose.heading = 'N';
        }
        else if(executor.pose.heading == 'W')
        {
            executor.pose.heading = 'S';
        }
        else if(executor.pose.heading == 'N')
        {
            executor.pose.heading = 'W';
        }
        else if(executor.pose.heading == 'S')
        {
            executor.pose.heading = 'E';
        }
    }

    void Executorlmpl::TurnRightCommand::executorTurnRight(Executorlmpl & executor)noexcept
    {
        if(executor.pose.heading == 'E')
        {
            executor.pose.heading = 'S';
        }
        else if(executor.pose.heading == 'W')
        {
            executor.pose.heading = 'N';
        }
        else if(executor.pose.heading == 'N')
        {
            executor.pose.heading = 'E';
        }
        else if(executor.pose.heading == 'S')
        {
            executor.pose.heading = 'W';
        }
    }
}