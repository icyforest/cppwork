#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"
#include<memory>
namespace adas
{
    class ExecutorBus final:public Executor
    {
    public:
        explicit ExecutorBus(const Pose& pose)noexcept;
        ~ExecutorBus()noexcept = default;

        ExecutorBus(const ExecutorBus&) = delete;
        ExecutorBus& operator=(const ExecutorBus&) = delete;
    
    public:
        void Execute(const std::string&command)noexcept override;
        Pose Query(void)const noexcept override;
    
    private:
        PoseHandler poseHandler;
        int length = {2};
    };
}