#pragma once
#include "PoseHandler.hpp"
#include <functional>
namespace adas
{
    class FastCommandCar final
        {
            public:
                void operator()(PoseHandler& poseHandler) const noexcept
                {
                    poseHandler.Fast();
                }
        };
    class ReverseCommandCar final
        {
            public:
                void operator()(PoseHandler& poseHandler) const noexcept
                {
                    poseHandler.Reverse();
                }
        };
    class MoveCommandCar final
        {
            public:
                void operator()(PoseHandler& poseHandler) const noexcept
                {
                    if(poseHandler.IsFast())
                    {
                        if(poseHandler.IsReverse())
                        {
                            poseHandler.Backward();
                            poseHandler.Backward();
                        }
                        else
                        {
                            poseHandler.Forward();
                            poseHandler.Forward();
                        }
                    }
                    if(poseHandler.IsReverse())
                    {
                        poseHandler.Backward();
                        poseHandler.Backward();
                    }
                    else
                    {
                        poseHandler.Forward();
                        poseHandler.Forward();
                    }
                }
        };
    class TurnLeftCommandCar final
        {
            public:
                void operator()(PoseHandler& poseHandler) const noexcept
                {
                    if(poseHandler.IsFast())
                    {
                        if(poseHandler.IsReverse())
                        {
                            poseHandler.Backward();
                        }
                        else
                        {
                            poseHandler.Forward();
                        }
                    }
                    if(poseHandler.IsReverse())
                    {
                        poseHandler.TurnRight();
                        poseHandler.Backward();
                    }
                    else
                    {
                        poseHandler.TurnLeft();
                        poseHandler.Forward();
                    }
                }
        };
    class TurnRightCommandCar final
        {
            public:
                void operator()(PoseHandler& poseHandler) const noexcept
                {
                    if(poseHandler.IsFast())
                    {
                        if(poseHandler.IsReverse())
                        {
                            poseHandler.Backward();
                        }
                        else
                        {
                            poseHandler.Forward();
                        }
                    }
                    if(poseHandler.IsReverse())
                    {
                        poseHandler.TurnLeft();
                        poseHandler.Backward();
                    }
                    else
                    {
                        poseHandler.TurnRight();
                        poseHandler.Forward();
                    }
                }
        };
}