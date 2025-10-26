#pragma once
#include "Executor.hpp"
#include<memory>

namespace adas
{
    class Executorlmpl final:public Executor
    {
    public:
        explicit Executorlmpl(const Pose& pose)noexcept;
        ~Executorlmpl()noexcept = default;

        Executorlmpl(const Executorlmpl&) = delete;
        Executorlmpl& operator=(const Executorlmpl&) = delete;
    
    public:
        void Execute(const std::string&command)noexcept override;
        Pose Query(void)const noexcept override;
    
    public:
        bool IsFast(void)noexcept
        {
            return this -> fast;
        }
        void Fast(void)noexcept;
        void Move(void)noexcept;
        void TurnLeft(void)noexcept;
        void TurnRight(void)noexcept;

    private:
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

    private:
        Pose pose;
        bool fast;
    };
}