//
// Created by mfbut on 4/4/2021.
//

#include "gtest/gtest.h"
#include "formatting.h"

TEST(ParseArgsTests, CheckArgumentsParsedSuccessfully) {
    /*
     * Check that you parse the command line arguments correctly.
     * (ar_out and len_out are set to the right values).
     * Don't forget to free any memory that was dynamically allocated as part of your test.'
     * give argc and argv values length
     */

    int *ar_out;
    int *len_out;
    ar_out = (int*) calloc(6, sizeof(int));
    len_out = (int*) calloc(1, sizeof(int));
    parse_args(6, (char **) "1 2 3 4 5 6", ar_out, len_out);
    ASSERT_EQ(*len_out, 6);
    EXPECT_EQ(ar_out[0], 1);
    EXPECT_EQ(ar_out[1], 2);
    EXPECT_EQ(ar_out[2], 3);
    EXPECT_EQ(ar_out[3], 4);
    EXPECT_EQ(ar_out[4], 5);
    EXPECT_EQ(ar_out[5], 6);
}


//parse is that you go through each element
//ar_out = would return the list of numbers
//len_out = should return how many numbers there are
    //pointer of pointer is char **
    //len_out = length of array
    //ar_out  = the numbers in array




TEST(ParseArgsTests, CheckParseNoArgs){
  /*
   * Check that you parse you can successfully parse "no" command line arguments.
   */
    int *ar_out;
    int *len_out;
    ar_out = (int*) calloc(0, sizeof(int));
    len_out = (int*) calloc(1, sizeof(int));
    parse_args(0, (char **) "", ar_out, len_out);
    ASSERT_EQ(*len_out, 0);
    EXPECT_EQ(ar_out, nullptr);

}
