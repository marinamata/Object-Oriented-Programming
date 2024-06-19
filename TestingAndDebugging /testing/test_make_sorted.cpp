//
// Created by mfbut on 4/4/2021.
//

#include "gtest/gtest.h"
#include "sorting.h"

TEST(MakeSortedTests, SortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int ar[7] = {1, 2, 3, 4, 5, 6, 7};
    make_sorted(ar, 7);
    //option 1
    for (int i = 1; i < 7; i++) {
        EXPECT_EQ(ar[i - 1], i);
    }}


    TEST(MakeSortedTests, SortReverseSortedArray) {
        /*
         * Check that we can sort an array that is reverse sorted order.
         * Don't forget to free any memory that was dynamically allocated as part of your test.
         */
        int ar[7] = {7, 6, 5, 4, 3, 2, 1};
        make_sorted(ar, 7);
//option1
    //for (int i = 1; i < 7; i++) {
        //EXPECT_EQ(ar[i - 1], i);
    //}
    //option2
        EXPECT_EQ(ar[0], 1);
        EXPECT_EQ(ar[1], 2);
        EXPECT_EQ(ar[2], 3);
        EXPECT_EQ(ar[3], 4);
        EXPECT_EQ(ar[4], 5);
        EXPECT_EQ(ar[5], 6);
        EXPECT_EQ(ar[6], 7);


    }




    TEST(MakeSortedTests, SortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int ar[7] = {3, 5, 1, 2, 6, 7, 4};
    make_sorted(ar, 7);
    //option1
    //for (int i = 1; i < int(sizeof(ar)); i++) {
        //EXPECT_EQ(ar[i - 1], i);
        //option2

        EXPECT_EQ(ar[0], 1);
        EXPECT_EQ(ar[1], 2);
        EXPECT_EQ(ar[2], 3);
        EXPECT_EQ(ar[3], 4);
        EXPECT_EQ(ar[4], 5);
        EXPECT_EQ(ar[5], 6);
        EXPECT_EQ(ar[6], 7);

    }


    TEST(MakeSortedTests, SortArrayWithDuplicates) {
        /*
         * Check that we can sort an array where there are duplicate elements in it.
         * Don't forget to free any memory that was dynamically allocated as part of your test.
         */
        int ar[7] = {1, 1, 3, 6, 5, 6, 7};
        make_sorted(ar, 7);
        EXPECT_EQ(ar[0], 1);
        EXPECT_EQ(ar[1], 1);
        EXPECT_EQ(ar[2], 3);
        EXPECT_EQ(ar[3], 5);
        EXPECT_EQ(ar[4], 6);
        EXPECT_EQ(ar[5], 6);
        EXPECT_EQ(ar[6], 7);
    }


