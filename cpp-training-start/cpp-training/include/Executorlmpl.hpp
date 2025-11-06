#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"
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
        PoseHandler poseHandler;
    };
}