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
    
    private:
        class MoveCommand final
        {
            public:
                void DoOperate(Executorlmpl & executor)noexcept
                {
                    executorMove(executor);
                }
                void executorMove(Executorlmpl & executor)noexcept;
        };
        class TurnLeftCommand final
        {
            public:
                void DoOperate(Executorlmpl & executor)noexcept
                {
                    executorTurnLeft(executor);
                }
                void executorTurnLeft(Executorlmpl & executor)noexcept;
        };
        class TurnRightCommand final
        {
            public:
                void DoOperate(Executorlmpl & executor)noexcept
                {
                    executorTurnRight(executor);
                }
                void executorTurnRight(Executorlmpl & executor)noexcept;
        };

    public:
        Pose pose;
        bool isfast;
    };
}