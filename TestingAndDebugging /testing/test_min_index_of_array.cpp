//
// Created by mfbut on 4/4/2021.
//
#include "gtest/gtest.h"
#include "sorting.h"

TEST(MinIndexOfArrayTests, MinIndexAtFrontOfArray){
/*
 * See if we can find the index of the minimum value when it is at the front of the array
 */
int ar[7] = {1,2,3,4,5,6,7};
int start = min_index_of_array(ar, 7, 0);
EXPECT_EQ(start,0);
}

TEST(MinIndexOfArrayTests, MinIndexAtEndOfArray){
/*
 * See if we can find the index of the minimum value when it is at the end of the array
 */
    int ar[7] = {7,2,3,4,5,6,1};
    int start = min_index_of_array(ar, 7,0);
    EXPECT_EQ(start,6);
}

TEST(MinIndexOfArrayTests, MinIndexAtMiddleOfArray){
/*
 * See if we can find the index of the minimum value when it is somewhere
 * in the "middle" of the array.
 */
    int ar[7] = {4,2,3,1,5,6,7};
    int start = min_index_of_array(ar, 7, 0);
    EXPECT_EQ(start,3);
}

TEST(MinIndexOfArrayTests, DuplicateMinimums){
/*
 * See if we return the index of the first minimum in the array
 * When there are multiple values that are the minimum.
 */
    int ar[7] = {1,2,3,4,1,6,7};
    int start = min_index_of_array(ar, 7, 0);
    EXPECT_EQ(start,0);

}

TEST(MinIndexOfArrayTests, ArrayDoesNotChange){
/*
 * Check that finding the minimum of the array did not change the contents of the array.
 */
    int ar[7] = {1,2,3,4,5,6,7};
    int start = min_index_of_array(ar, 7, 0);

    EXPECT_EQ(ar[0],1);
    EXPECT_EQ(ar[1],2);
    EXPECT_EQ(ar[2],3);
    EXPECT_EQ(start,0);
    EXPECT_EQ(ar[3],4);
    EXPECT_EQ(ar[4],5);
    EXPECT_EQ(ar[5],6);
    EXPECT_EQ(ar[6],7);






}
