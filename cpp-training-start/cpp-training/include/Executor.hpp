#pragma once
#include<string>
namespace adas
{
    struct Pose{
        int x;
        int y;
        char heading;
    };

    class Executor
    {
    public:
        static Executor* NewExecutor(const Pose& pose = {0,0,'N'})noexcept;
        static Executor* NewExecutorBus(const Pose& pose = {0,0,'N'})noexcept;
        static Executor* NewExecutorCar(const Pose& pose = {0,0,'N'})noexcept;

    public:
        Executor(void) = default;
        virtual ~Executor(void) = default;
        Executor(const Executor&) = delete;//ban this way to originate
        Executor& operator=(const Executor&) = delete;

    public:
        virtual void Execute(const std::string& command)noexcept = 0;
        virtual Pose Query(void)const noexcept = 0;
    };
}