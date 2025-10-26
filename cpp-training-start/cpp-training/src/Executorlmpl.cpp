#include "Command.hpp"
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
        this -> fast = false;
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
                cmder -> DoOperate(*this);
            }
        }
    }

    Pose Executorlmpl::Query()const noexcept
    {
        return pose;
    }

    void Executorlmpl::Move(void)noexcept
    {
        if(this -> pose.heading == 'E')
        {
             this -> pose.x += 1;
        }
        else if(pose.heading == 'W')
        {
            this -> pose.x --;
        }
        else if(this -> pose.heading == 'N')
        {
            this -> pose.y ++;
        }
        else if(this -> pose.heading == 'S')
        {
            this -> pose.y --;
        }
    }

    void Executorlmpl::TurnLeft(void)noexcept
    {
        if(this -> pose.heading == 'E')
        {
            this -> pose.heading = 'N';
        }
        else if(this -> pose.heading == 'W')
        {
            this -> pose.heading = 'S';
        }
        else if(this -> pose.heading == 'N')
        {
            this -> pose.heading = 'W';
        }
        else if(this -> pose.heading == 'S')
        {
            this -> pose.heading = 'E';
        }
    }

    void Executorlmpl::TurnRight(void)noexcept
    {
        if(this -> pose.heading == 'E')
        {
            this -> pose.heading = 'S';
        }
        else if(this -> pose.heading == 'W')
        {
            this -> pose.heading = 'N';
        }
        else if(this -> pose.heading == 'N')
        {
            this -> pose.heading = 'E';
        }
        else if(this -> pose.heading == 'S')
        {
            this -> pose.heading = 'W';
        }
    }

    void Executorlmpl::Fast(void)noexcept
    {
        this -> fast = !this -> fast;
    }
}