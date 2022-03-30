#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "GetChargingCurrentValues.h"

/* detect multiple ranges and check if the number of readings of each range matches the expected value.*/
TEST_CASE("Case1 : For inputs in sorted order") {
     int input_range[]={3,4,5,8,9};// {3, 5, 4, 8, 10, 9, 7};
  const char *expected_range = "3-5,3\n8-9,2";//3-5,3\n7-10,4";
  char readingRange[MAX_STRING_LEN]={0};
  
  int no_of_elements = sizeof(input_range)/sizeof(input_range[0]);
  char *actual_result;

  actual_result = GetPeriodicSetRanges(input_range, no_of_elements, Index, readingRange);
  REQUIRE(strcmp(actual_result, expected_range) == 0);
}

TEST_CASE("Case2 : For inputs in Unsorted order") {
     int input_range2[]= {3, 5, 4, 8, 10, 9, 7};
  const char *expected_range2 = "3-5,3\n7-10,4";
  char readingRange2[MAX_STRING_LEN]={0};
  
  int no_of_elements = sizeof(input_range2)/sizeof(input_range2[0]);
  char *actual_result2;

  actual_result2 = GetPeriodicSetRanges(input_range2, no_of_elements, Index, readingRange2);
  REQUIRE(strcmp(actual_result2, expected_range2) == 0);
}
