#include "PoseHandler.hpp"
namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose)
{
}
    Pose PoseHandler::Query()const noexcept
    {
        return pose;
    }

    void PoseHandler::Forward(void)noexcept
    {
        if(this -> pose.heading == 'E')
        {
            this -> pose.x ++;
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

    void PoseHandler::Backward(void)noexcept
    {
        if(this -> pose.heading == 'E')
        {
            this -> pose.x --;
        }
        else if(pose.heading == 'W')
        {
            this -> pose.x ++;
        }
        else if(this -> pose.heading == 'N')
        {
            this -> pose.y --;
        }
        else if(this -> pose.heading == 'S')
        {
            this -> pose.y ++;
        }
    }

    void PoseHandler::TurnLeft(void)noexcept
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

    void PoseHandler::TurnRight(void)noexcept
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

    void PoseHandler::Fast(void)noexcept{
        this -> fast = !this -> fast;
    }
    
    bool PoseHandler::IsFast(void)const noexcept{
        return this -> fast;
    }

    void PoseHandler::Reverse(void)noexcept{
        this -> reverse = !this -> reverse;
    }
    
    bool PoseHandler::IsReverse(void)const noexcept{
        return this -> reverse;
    }
}