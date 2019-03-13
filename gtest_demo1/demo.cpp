#include <stdio.h>
#include <gtest/gtest.h>
#include "comp_manager.h"
#include "component.h"

class A_test : public ::testing::Test
{
 public:
  virtual void SetUp() {
 }
  virtual void TearDown() {
 }
  CompManager comp_manager;
};

TEST_F(A_test, FirstAdd) {
  EXPECT_EQ(0, comp_manager.Add("71.TXT"));
  EXPECT_EQ(0, comp_manager.Add("71.TXT"));
  EXPECT_EQ(0, comp_manager.Add("1.TXT"));
  EXPECT_EQ(0, comp_manager.Add("1.TXT"));
  EXPECT_TRUE(comp_manager.Delete("71.TXT",1));
  EXPECT_TRUE(comp_manager.Delete("1.TXT",2));
  EXPECT_TRUE(comp_manager.Rotate("71.TXT",2,30));
}

GTEST_API_ int main(int argc, char **argv) {
  //std::cout << "Running main() from gtest_main.cc\n";
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  system("pause");
  //return RUN_ALL_TESTS();
}