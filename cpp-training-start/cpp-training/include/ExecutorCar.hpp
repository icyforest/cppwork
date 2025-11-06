#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"
#include<memory>
namespace adas
{
    class ExecutorCar final:public Executor
    {
    public:
        explicit ExecutorCar(const Pose& pose)noexcept;
        ~ExecutorCar()noexcept = default;

        ExecutorCar(const ExecutorCar&) = delete;
        ExecutorCar& operator=(const ExecutorCar&) = delete;
    
    public:
        void Execute(const std::string&command)noexcept override;
        Pose Query(void)const noexcept override;
    
    private:
        PoseHandler poseHandler;
    };
}