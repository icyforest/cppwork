#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"
namespace adas
{
    // go straight when is fast
    TEST(ExecutorFastTest,should_return_x_plus_2_given_command_is_FM_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

       executor->Execute("FM");

       const Pose target({2,0,'E'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_x_minus_2_given_command_is_FM_and_facing_is_W)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'W'}));

       executor->Execute("FM");

       const Pose target({-2,0,'W'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_y_plus_2_given_command_is_FM_and_facing_is_N)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

       executor->Execute("FM");

       const Pose target({0,2,'N'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_y_minus_2_given_command_is_FM_and_facing_is_S)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'S'}));

       executor->Execute("FM");

       const Pose target({0,-2,'S'});
       ASSERT_EQ(target,executor->Query());
    }
    //turn left when is fast
    TEST(ExecutorFastTest,should_return_facing_N_and_x_plus_1_given_command_is_FL_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

       executor->Execute("FL");

       const Pose target({1,0,'N'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_S_and_x_minus_1_given_command_is_FL_and_facing_is_W)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'W'}));

       executor->Execute("FL");

       const Pose target({-1,0,'S'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_W_and_y_plus_1_given_command_is_FL_and_facing_is_N)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

       executor->Execute("FL");

       const Pose target({0,1,'W'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_E_and_y_minus_1_given_command_is_FL_and_facing_is_S)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'S'}));

       executor->Execute("FL");

       const Pose target({0,-1,'E'});
       ASSERT_EQ(target,executor->Query());
    }
    //turn right when is fast
    TEST(ExecutorFastTest,should_return_facing_S_and_x_plus_1_given_command_is_FR_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

       executor->Execute("FR");

       const Pose target({1,0,'S'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_N_and_x_minus_1_given_command_is_FR_and_facing_is_W)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'W'}));

       executor->Execute("FR");

       const Pose target({-1,0,'N'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_E_and_y_plus_1_given_command_is_FR_and_facing_is_N)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

       executor->Execute("FR");

       const Pose target({0,1,'E'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_W_and_y_minus_1_given_command_is_FR_and_facing_is_S)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'S'}));

       executor->Execute("FR");

       const Pose target({0,-1,'W'});
       ASSERT_EQ(target,executor->Query());
    }
    //cancel when have double F and turing commands
    TEST(ExecutorFastTest,should_return_S_given_command_is_FFR_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

       executor->Execute("FFR");

       const Pose target({0,0,'S'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_N_given_command_is_FFR_and_facing_is_W)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'W'}));

       executor->Execute("FFR");

       const Pose target({0,0,'N'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_E_given_command_is_FFR_and_facing_is_N)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

       executor->Execute("FFR");

       const Pose target({0,0,'E'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_W_given_command_is_FFR_and_facing_is_S)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'S'}));

       executor->Execute("FFR");

       const Pose target({0,0,'W'});
       ASSERT_EQ(target,executor->Query());
    }
    
    TEST(ExecutorFastTest,should_return_N_given_command_is_FFL_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'E'}));

       executor->Execute("FFL");

       const Pose target({0,0,'N'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_S_given_command_is_FFL_and_facing_is_W)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'W'}));

       executor->Execute("FFL");

       const Pose target({0,0,'S'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_W_given_command_is_FFL_and_facing_is_N)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'N'}));

       executor->Execute("FFL");

       const Pose target({0,0,'W'});
       ASSERT_EQ(target,executor->Query());
    }

    TEST(ExecutorFastTest,should_return_facing_E_given_command_is_FFL_and_facing_is_S)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutor({0,0,'S'}));

       executor->Execute("FFL");

       const Pose target({0,0,'E'});
       ASSERT_EQ(target,executor->Query());
    }
    
}