// main_test.cpp
#include "Vector.cpp"
#include <gtest/gtest.h>

TEST(VectorTest, VectorSize){
    VectorM<int, 100> test;
    EXPECT_EQ(100, test.size());
}

TEST(VectorTest, VectorAccessOperator){
    VectorM<int, 10> test;
    EXPECT_EQ(0, test[1]);
}

TEST(VectorTest, VectorEqualOperator){
    VectorM<int, 10> test;
    test[1] = 100;
    EXPECT_EQ(100, test[1]);
}

TEST(VectorTest, VectorNonDefaultTemplateValue){
    VectorM<int, 10,100> test;
    EXPECT_EQ(100, test[1]);
}

TEST(VectorTest, VectorTestMultiplyOperator){
    VectorM<int, 3, 10> test;
    VectorM<int, 3, 1> test2;
    EXPECT_EQ(30, test*test2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}