//
// Created by mfbut on 4/4/2021.
//

#include "gtest/gtest.h"
#include "sorting.h"
#include "formatting.h"

TEST(CopyArrayTests, CopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     * check that location of the first one are the same
     *
     */
    int ar[7] = {1, 2, 3, 4, 5, 6, 7};
    int* copy = copy_array(ar, 7);
    EXPECT_NE(ar, copy);

    free(copy);

}
TEST(CopyArrayTests, ValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     * if size of original array is the same as size of copy
     * 1) compare the lengths of arrays, ig they are not equal then the copy is different
     * 2) sort the array is some order
     * 3) for index i of the arrays, compare array1[i] and array2[i] to be equal
     * 4) if at any point the condition fails, then return false
     * checks for size and value
     */

    //this checks for size and value
    int ar[7] = {1, 2, 3, 4, 5, 6, 7};
    int* copy = copy_array(ar, 7);
    //EXPECT_EQ(sizeof(ar), sizeof(copy));
    for (int i = 0; i < 7; i++) {
        EXPECT_EQ(copy[i], ar[i]);
    }
    free(copy);
}

TEST(CopyArrayTests, OriginalDoesNotChange) {
    /*
     * Check that the values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     * 1) make original array = (array1) (line1)
     * 2) make the copy of the array(copy[])
     * if the size of array and array "copy" are not equal then print out statement
     * if they are the same size, the check each index value
     * this only checks if sizes of arrays are the same
     */

    int ar[7] = {1, 2, 3, 4, 5, 6, 7};
    int* copy = copy_array(ar, 7);
    for (int i = 0; i < 7; i++){
        EXPECT_EQ(i+1, ar[i]);
    }

  free(copy);

}