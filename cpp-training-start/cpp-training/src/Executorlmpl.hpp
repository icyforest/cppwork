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
        Pose pose;
        bool fast;
    };
}