//
// Created by mfbut on 4/4/2021.
//

#include "gtest/gtest.h"
#include "sorting.h"

TEST(SwapTests, SwapTwoValues){
  /*
   * Swap two values and see if the swap was successful.
   */
    int ar[7] = {1,2,3,4,5,6,7};
    swap(&ar[3], &ar[6]);
    EXPECT_EQ(ar[3], 7);
    EXPECT_EQ(ar[6], 4);


}

TEST(SwapTests, SwapValuesInArray){
  /*
   * Swap a few values in an array.
   * Check that the ones that swapped did swap and the ones that didn't swap
   * are still at the same locations
   *
   */
    int ar[7] = {1,2,3,4,5,6,7};
    swap(&ar[3], &ar[6]);
   EXPECT_EQ(ar[3], 7);
   EXPECT_EQ(ar[6], 4);

   swap(&ar[5], &ar[2]);
    EXPECT_EQ(ar[5], 3);
    EXPECT_EQ(ar[2], 6);

   EXPECT_EQ(ar[0], 1);
   EXPECT_EQ(ar[1], 2);
   EXPECT_EQ(ar[4],5);



}


