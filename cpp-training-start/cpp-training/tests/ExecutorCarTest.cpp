#include<gtest/gtest.h>
#include<memory>
#include"PoseEq.hpp"
#include"Executor.hpp"
namespace adas
{
    
    TEST(ExecutorCarTest,should_return_x_plus_2_given_command_is_M_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("M");

       const Pose target({2,0,'E'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_facing_N_and_y_plus_1_given_command_is_L_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("L");

       const Pose target({0,1,'N'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_facing_S_and_y_minus_1_given_command_is_R_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("R");

       const Pose target({0,-1,'S'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }

    TEST(ExecutorCarTest,should_return_x_minus_2_given_status_is_back_and_command_is_M_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("BM");

       const Pose target({-2,0,'E'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_y_plus_1_and_facing_S_given_status_is_back_and_command_is_L_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("BL");

       const Pose target({0,1,'S'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_y_minus_1_and_facing_N_given_status_is_back_and_command_is_R_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("BR");

       const Pose target({0,-1,'N'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_x_plus_4_given_status_is_fast_and_command_is_M_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("FM");

       const Pose target({4,0,'E'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_x_plus_1_and_y_plus_1_and_facing_N_given_status_is_fast_and_command_is_L_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("FL");

       const Pose target({1,1,'N'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_x_plus_1_and_y_minus_1_and_facing_S_given_status_is_fast_and_command_is_R_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("FR");

       const Pose target({1,-1,'S'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_x_minus_4_given_status_is_fast_and_back_and_command_is_M_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("FBM");

       const Pose target({-4,0,'E'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_x_minus_1_and_y_plus_1_and_facing_S_given_status_is_fast_and_back_and_command_is_L_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("FBL");

       const Pose target({-1,1,'S'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }
    
    TEST(ExecutorCarTest,should_return_x_minus_1_and_y_minus_1_and_facing_N_given_status_is_fast_and_back_and_command_is_R_and_facing_is_E)
    {
       std::unique_ptr<Executor>executor(Executor::NewExecutorCar({0,0,'E'}));
      
       executor->Execute("FBR");

       const Pose target({-1,-1,'N'});
       ASSERT_EQ(target,executor->Query());
       //Arrange-Act-Assert
    }

}