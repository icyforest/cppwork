#pragma once
#include "PoseHandler.hpp"
#include <functional>
namespace adas
{
    class FastCommandBus final
        {
            public:
                void operator()(PoseHandler& poseHandler) const noexcept
                {
                    poseHandler.Fast();
                }
        };
    class ReverseCommandBus final
        {
            public:
                void operator()(PoseHandler& poseHandler) const noexcept
                {
                    poseHandler.Reverse();
                }
        };
    class MoveCommandBus final
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
                        poseHandler.Backward();
                    }
                    else
                    {
                        poseHandler.Forward();
                    }
                }
        };
    class TurnLeftCommandBus final
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
                        poseHandler.Backward();
                        poseHandler.TurnRight();
                    }
                    else
                    {
                        poseHandler.Forward();
                        poseHandler.TurnLeft();
                    }
                }
        };
    class TurnRightCommandBus final
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
                        poseHandler.Backward();
                        poseHandler.TurnLeft();
                    }
                    else
                    {
                        poseHandler.Forward();
                        poseHandler.TurnRight();
                    }
                }
        };
}