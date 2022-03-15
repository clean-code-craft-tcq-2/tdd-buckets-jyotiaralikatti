#include <stdio.h>
#include<assert.h>
#include "GetChargingCurrentValues.h"
Range_Cfg range;
int TotalPeriodicSetRanges;
int GetChargingCurrentValues (int *CurrentValues, int TotalCurrentValues){
  int i;
  SortCurrentValues(CurrentValues,TotalCurrentValues);

   range = GetPeriodicSetRanges(CurrentValues,TotalCurrentValues);
  return range.NumberOfPeriodicRanges;
}
void SortCurrentValues(int *CurrentValues, int TotalCurrentValues)
{
  int i,swap;
  for(i = 0; i <(TotalCurrentValues - 1); i++){
    if(CurrentValues[i] > CurrentValues[i+1]){
      swap = CurrentValues[i];
      CurrentValues[i] = CurrentValues[i+1];
      CurrentValues[i+1] = swap;
      i = -1;
    }
  }  
}
int GetNumberOfPeriodicRanges( int RangeDifference)
{

    if( (RangeDifference == 1)){
        TotalPeriodicSetRanges++;
    }
  
    return TotalPeriodicSetRanges;
}
Range_Cfg GetPeriodicSetRanges(int *CurrentValues, int TotalCurrentValues)
{
  int i;
    for (i=1;i<TotalCurrentValues;i++){
    int CurrentElement,NextElement,RangeDifference;

    CurrentElement = CurrentValues[i-1];
    NextElement = CurrentValues[i];
    RangeDifference = NextElement - CurrentElement; 
    range. NumberOfPeriodicRanges = GetNumberOfPeriodicRanges(RangeDifference);
    
    if((RangeDifference == 0)&&(TotalCurrentValues == 2))
        range. NumberOfPeriodicRanges = 1; 
    }
  return range;
}
