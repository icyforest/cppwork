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
        for(const auto cmd : commands)
        {
            if(cmd == 'M')
            {
                if(this -> pose.heading == 'E')
                {
                    this -> pose.x ++;
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
            else if(cmd == 'L')
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
            else if(cmd == 'R')
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
    }

    Pose Executorlmpl::Query()const noexcept
    {
        return pose;
    }
}