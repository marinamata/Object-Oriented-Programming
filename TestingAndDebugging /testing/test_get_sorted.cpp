//
// Created by mfbut on 4/4/2021.
//

#include "gtest/gtest.h"
#include "sorting.h"

TEST(GetSortedTests, SortArray) {
/*
 * See that the array was successfully sorted.
 * Don't forget to free any memory that was dynamically allocated as part of your test.
 */
    int ar[8] = {2, 3, 7, 4, 6, 1, 5, 8,};
    int *sortedAr = get_sorted(ar, 8);
    //for (int i = 1; i < 8; i++) {
       // EXPECT_EQ(sortedAr[i - 1], i);

        EXPECT_EQ(sortedAr[0], 1);
        EXPECT_EQ(sortedAr[1], 2);
        EXPECT_EQ(sortedAr[2], 3);
        EXPECT_EQ(sortedAr[3], 4);
        EXPECT_EQ(sortedAr[4], 5);
        EXPECT_EQ(sortedAr[5], 6);
        EXPECT_EQ(sortedAr[6], 7);
        EXPECT_EQ(sortedAr[7], 8);



    free(sortedAr);
}


TEST(GetSortedTests, CopyWasMade){
  /*
   * Check that a sorted array is copy of the original array in sorted order.
   * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
   * Don't forget to free any memory that was dynamically allocated.
   * Don't forget to free any memory that was dynamically allocated as part of your test.
   */
    int ar[8] = {2, 3, 7, 4, 6, 1, 5, 8,};
    int* sortedAr = get_sorted( ar, 8);

    EXPECT_NE(ar, sortedAr);

    free(sortedAr);
}

TEST(GetSortedTests, OriginalDoesNotChange){
  /*
   * Check that the original array was not modified.
   * Don't forget to free any memory that was dynamically allocated as part of your test.
   */
    int ar[8] = {2, 3, 7, 4, 6, 1, 5, 8,};
    int* sortedAr = get_sorted( ar, 8);

    EXPECT_EQ(ar[0], 2);
    EXPECT_EQ(ar[1], 3);
    EXPECT_EQ(ar[2], 7);
    EXPECT_EQ(ar[3], 4);
    EXPECT_EQ(ar[4], 6);
    EXPECT_EQ(ar[5], 1);
    EXPECT_EQ(ar[6], 5);
    EXPECT_EQ(ar[7], 8);

    free(sortedAr);
}

TEST(GetSortedTests, SortSortedArray){
  /*
   * Check that we can sort an array that is already sorted.
   * Don't forget to free any memory that was dynamically allocated as part of your test.
   */
    int ar[8] = {1, 2, 3, 4, 5, 6, 7, 8,};
    int* sortedAr = get_sorted( ar, 8);
    for(int i=1; i <8; i++){
        EXPECT_EQ(sortedAr[i-1],i);
    }
    free(sortedAr);
}

TEST(GetSortedTests, SortReverseSortedArray){
  /*
   * Check that we can sort an array that is reverse sorted order.
   * Don't forget to free any memory that was dynamically allocated as part of your test.
   */
    int ar[8] = {8, 7, 6, 5, 4, 3, 2, 1,};
    int* sortedAr = get_sorted( ar, 8);
    for(int i=1; i <8; i++){
        EXPECT_EQ(sortedAr[i-1],i);
    }
    free(sortedAr);
}

TEST(GetSortedTests, SortAverageArray){
  /*
   * Check that we can sort an array where the elements in it are in random order.
   * Don't forget to free any memory that was dynamically allocated as part of your test.
   */

    int ar[8] = {5,6,7,8,4,3,2,1};
    int* sortedAr = get_sorted( ar, 8);
    for(int i=1; i <8; i++){
        EXPECT_EQ(sortedAr[i-1],i);
    }
    free(sortedAr);
}


TEST(GetSortedTests, SortArrayWithDuplicates){
  /*
   * Check that we can sort an array where there are duplicate elements in it.
   * Don't forget to free any memory that was dynamically allocated as part of your test.
   */
    int ar[8] = {2, 3, 3, 4, 6, 1, 5, 1,};
    int* sortedAr = get_sorted( ar, 8);

    EXPECT_EQ(sortedAr[0], 1);
    EXPECT_EQ(sortedAr[1], 1);
    EXPECT_EQ(sortedAr[2], 2);
    EXPECT_EQ(sortedAr[3], 3);
    EXPECT_EQ(sortedAr[4], 3);
    EXPECT_EQ(sortedAr[5], 4);
    EXPECT_EQ(sortedAr[6], 5);
    EXPECT_EQ(sortedAr[7], 6);




    free(sortedAr);
}



