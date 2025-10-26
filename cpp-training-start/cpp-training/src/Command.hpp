#pragma once
#include "Executorlmpl.hpp"
namespace adas
{
    class ICommand
        {
            public:
                virtual ~ICommand() = default;
                virtual void DoOperate(Executorlmpl& executor)const noexcept = 0;
        };
    class FastCommand final: public ICommand
        {
            public:
                void DoOperate(Executorlmpl & executor)const noexcept override
                {
                    executor.Fast();
                }
        };
    class MoveCommand final: public ICommand
        {
            public:
                void DoOperate(Executorlmpl & executor)const noexcept override
                {
                    if(executor.IsFast()){
                        executor.Move();
                    }
                    executor.Move();
                }
        };
    class TurnLeftCommand final: public ICommand
        {
            public:
                void DoOperate(Executorlmpl & executor)const noexcept override
                {
                    if(executor.IsFast()){
                        executor.Move();
                    }
                    executor.TurnLeft();
                }
        };
    class TurnRightCommand final: public ICommand
        {
            public:
                void DoOperate(Executorlmpl & executor)const noexcept override
                {
                    if(executor.IsFast()){
                        executor.Move();
                    }
                    executor.TurnRight();
                }
        };
}