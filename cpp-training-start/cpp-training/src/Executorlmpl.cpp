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
                if(isfast)
                {    
                    this -> Move();
                }
                this -> Move();
            }
            else if(cmd == 'L')
            {
                if(isfast)
                {    
                    this -> Move();
                }
                this -> TurnLeft();
            }
            else if(cmd == 'R')
            {
                if(isfast)
                {    
                    this -> Move();
                }
                this -> TurnRight();
            }
        }
    }

    Pose Executorlmpl::Query()const noexcept
    {
        return pose;
    }

    void Executorlmpl::Move()noexcept
    {
        if(this -> pose.heading == 'E')
        {
             this -> pose.x += 1;
        }
        else if(this -> pose.heading == 'W')
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

    void Executorlmpl::TurnLeft()noexcept
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

    void Executorlmpl::TurnRight()noexcept
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
}