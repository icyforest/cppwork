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
    }

    void Executorlmpl::Execute(const std::string& commands)noexcept
    {
        if(commands == "M")
        {
            if(this -> pose.heading == 'E')
            {
                this -> pose.x ++;
            }
            if(this -> pose.heading == 'W')
            {
                this -> pose.x --;
            }
            if(this -> pose.heading == 'N')
            {
                this -> pose.y ++;
            }
            if(this -> pose.heading == 'S')
            {
                this -> pose.y --;
            }
        }
        if(commands == "L")
        {
            if(this -> pose.heading == 'E')
            {
                this -> pose.heading = 'N';
            }
            if(this -> pose.heading == 'W')
            {
                this -> pose.heading = 'S';
            }
            if(this -> pose.heading == 'N')
            {
                this -> pose.heading = 'W';
            }
            if(this -> pose.heading == 'S')
            {
                this -> pose.heading = 'E';
            }
        }
        if(commands == "R")
        {
            if(this -> pose.heading == 'E')
            {
                this -> pose.heading = 'S';
            }
            if(this -> pose.heading == 'W')
            {
                this -> pose.heading = 'N';
            }
            if(this -> pose.heading == 'N')
            {
                this -> pose.heading = 'E';
            }
            if(this -> pose.heading == 'S')
            {
                this -> pose.heading = 'W';
            }
        }
    }

    Pose Executorlmpl::Query()const noexcept
    {
        return pose;
    }
}