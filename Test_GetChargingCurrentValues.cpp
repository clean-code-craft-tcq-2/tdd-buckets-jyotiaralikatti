#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "GetChargingCurrentValues.h"

TEST_CASE("Checks the charging current ranges and get the no of occurences") {
  int CurrentValues[] = {4,5};
  REQUIRE(GetChargingCurrentValues(CurrentValues,2) == 1);
}
TEST_CASE("Checks the charging current if there are same ranges and get the number of occurences") {
  int CurrentValues[] = {4,4};
  REQUIRE(GetChargingCurrentValues(CurrentValues,2) == 1);
}

TEST_CASE("Checks the periodicity of charging current ranges and get the no of occurences for sequectial inputs") {
  int CurrentValues[] = {4,5,6};
  REQUIRE(GetChargingCurrentValues(CurrentValues,3) == 1);
}

TEST_CASE("Checks the periodicity of charging current ranges and get the no of occurences for non sequential inputs") {
  int CurrentValues[] = {9,5,4,9,5};
  REQUIRE(GetChargingCurrentValues(CurrentValues,5) == 2);
}
