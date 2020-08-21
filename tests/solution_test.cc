#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

TEST(TEST0, TEST0) {
  BST b;
  b.push(3); 
  b.push(2); 
  b.push(15); 
  b.push(5); 
  b.push(45); 
  b.push(4); 

  //            3
  //        2         15
  //               5     45
  //            4     
  // vector<int> result1 = {3,2,15,5,45,4};

  int result0 = 4;
  vector<int> result1 = {2,3,4,5,15,45};

  EXPECT_EQ(b.MaxDep(), result0);
  EXPECT_EQ(b.NonRecursiveInorderTraveral(), result1);
  EXPECT_EQ(b.RecursiveInorderTraveral(), result1);

  // test kthSmallest
  int k1 = 2;
  int k2 = 3;
  int k3 = 4;
  int k4 = 5;
  int k5 = 15;
  int k6 = 45;

  EXPECT_EQ(b.kthSmallest(1), k1);
  EXPECT_EQ(b.kthSmallest(2), k2);
  EXPECT_EQ(b.kthSmallest(3), k3);
  EXPECT_EQ(b.kthSmallest(4), k4);
  EXPECT_EQ(b.kthSmallest(5), k5);
  EXPECT_EQ(b.kthSmallest(6), k6);

}

TEST(TEST1, TEST1) {
  BST b;
  b.push(3); 
  b.push(2); 
  b.push(20); 
  b.push(15); 
  b.push(27); 

  //            3
  //        2       20
  //            15      27

  // vector<int> result1 = {3,2,20,15,27};

  int result2 = 3;
  vector<int> result3 = {2,3,15,20,27};
  EXPECT_EQ(b.MaxDep(), result2);
  EXPECT_EQ(b.NonRecursiveInorderTraveral(), result3);
  EXPECT_EQ(b.RecursiveInorderTraveral(), result3);

  // test kthSmallest
  int kk1 = 2;
  int kk2 = 3;
  int kk3 = 15;
  int kk4 = 20;
  int kk5 = 27;

  EXPECT_EQ(b.kthSmallest(1), kk1);
  EXPECT_EQ(b.kthSmallest(2), kk2);
  EXPECT_EQ(b.kthSmallest(3), kk3);
  EXPECT_EQ(b.kthSmallest(4), kk4);
  EXPECT_EQ(b.kthSmallest(5), kk5);

}

TEST(TEST2, TEST2) {
  BST b;
  b.push(8); 
  b.push(3); 
  b.push(10); 
  b.push(1); 
  b.push(6); 
  b.push(14);
  b.push(4);
  b.push(7);
  b.push(13);

  //            8
  //        3       10
  //    1       6       14
  //          4   7    13 

  // vector<int> result1 = {3,2,20,15,27};

  int result2 = 4;
  vector<int> result3 = {1,3,4,6,7,8,10,13,14};
  EXPECT_EQ(b.MaxDep(), result2);
  EXPECT_EQ(b.NonRecursiveInorderTraveral(), result3);
  EXPECT_EQ(b.RecursiveInorderTraveral(), result3);

  // test kthSmallest
  int kkk1 = 1;
  int kkk2 = 3;
  int kkk3 = 4;
  int kkk4 = 6;
  int kkk5 = 7;
  int kkk6 = 8;
  int kkk7 = 10;
  int kkk8 = 13;
  int kkk9 = 14;

  EXPECT_EQ(b.kthSmallest(1), kkk1);
  EXPECT_EQ(b.kthSmallest(2), kkk2);
  EXPECT_EQ(b.kthSmallest(3), kkk3);
  EXPECT_EQ(b.kthSmallest(4), kkk4);
  EXPECT_EQ(b.kthSmallest(5), kkk5);
  EXPECT_EQ(b.kthSmallest(6), kkk6);
  EXPECT_EQ(b.kthSmallest(7), kkk7);
  EXPECT_EQ(b.kthSmallest(8), kkk8);
  EXPECT_EQ(b.kthSmallest(9), kkk9);

}




