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

TEST_CASE("Case3 : For inputs in Unsorted order and duplicates") {
     int input_range3[]= {3, 5, 4, 8, 3, 7, 10, 9, 7};
  const char *expected_range3 = "3-5,4\n7-10,5";
  char readingRange3[MAX_STRING_LEN]={0};
  
  int no_of_elements = sizeof(input_range3)/sizeof(input_range3[0]);
  char *actual_result3;

  actual_result3 = GetPeriodicSetRanges(input_range3, no_of_elements, Index, readingRange3);
  REQUIRE(strcmp(actual_result3, expected_range3) == 0);
}

TEST_CASE("Case4 : For inputs in Unsorted order, duplicates, negative value and single value in a range") {
     int input_range4[]= {-5,3, 5, 4, 8, 3, 7, 10, 9, 7};
  const char *expected_range4 = "-5--5,1\n3-5,4\n7-10,5";
  char readingRange4[MAX_STRING_LEN]={0};
  
  int no_of_elements = sizeof(input_range4)/sizeof(input_range4[0]);
  char *actual_result4;

  actual_result4 = GetPeriodicSetRanges(input_range4, no_of_elements, Index, readingRange4);
  REQUIRE(strcmp(actual_result4, expected_range4) == 0);
}

/* For Analog inputs consider "0" for invalid values and covert upto 12bit resolution, Max_current = 10amps*/
TEST_CASE("Case5 : For Analog 12bit current values: convert to digital, Sort and print ranges" ) {
  int input_range[]= {4095,4094};
  const char *expected_range = "0-0,1\n10-10,1";
  char readingRange4[MAX_STRING_LEN]={0};
  
  int no_of_elements = sizeof(input_range4)/sizeof(input_range4[0]);
  char *actual_result4;
  
  ConvertAnalogCurrentInputs2Digital(input_range, no_of_elements, DigitalCurrentValues );
  actual_result4 = GetPeriodicSetRanges(input_range4, no_of_elements, Index, readingRange4);
          
  REQUIRE(strcmp(actual_result4, expected_range4) == 0);
}
