#include<gtest/gtest.h>
#include<memory>
#include"PoseEq.hpp"
#include"Executor.hpp"
namespace adas
{
    TEST(ExecutorBusTest,should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("M");

       const Pose target({1,0,'E'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_plus_1_facing_N_given_command_is_L_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("L");

       const Pose target({1,0,'N'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_plus_1_facing_S_given_command_is_R_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("R");

       const Pose target({1,0,'S'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }

    TEST(ExecutorBusTest,should_return_x_minus_1_given_status_is_back_and_command_is_M_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("BM");

       const Pose target({-1,0,'E'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_minus_1_and_facing_S_given_status_is_back_and_command_is_L_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("BL");

       const Pose target({-1,0,'S'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_minus_1_and_facing_N_given_status_is_back_and_command_is_R_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("BR");

       const Pose target({-1,0,'N'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_plus_2_given_status_is_fast_and_command_is_M_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("FM");

       const Pose target({2,0,'E'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_plus_2_and_facing_N_given_status_is_fast_and_command_is_L_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("FL");

       const Pose target({2,0,'N'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_plus_2_and_facing_S_given_status_is_fast_and_command_is_R_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("FR");

       const Pose target({2,0,'S'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_minus_2_given_status_is_fast_and_back_and_command_is_M_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("FBM");

       const Pose target({-2,0,'E'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_minus_2_and_facing_S_given_status_is_fast_and_back_and_command_is_L_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("FBL");

       const Pose target({-2,0,'S'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorBusTest,should_return_x_minus_2_and_facing_N_given_status_is_fast_and_back_and_command_is_R_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorBus({0,0,'E'}));
      
       executor->Execute("FBR");

       const Pose target({-2,0,'N'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }

}