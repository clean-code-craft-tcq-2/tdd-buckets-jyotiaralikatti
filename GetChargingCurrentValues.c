#include <stdio.h>
#include<assert.h>
#include "GetChargingCurrentValues.h"
Range_Cfg range;
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
Range_Cfg GetPeriodicSetRanges(int *CurrentValues, int TotalCurrentValues)
{
  int CurrentElement,NextElement,RangeDifference;
  int i,TotalPeriodicSetRanges = 0;
    for (i=1;i<TotalCurrentValues;i++){
        CurrentElement = CurrentValues[i-1];
        NextElement = CurrentValues[i];
        RangeDifference = NextElement - CurrentElement;        
        if( (RangeDifference == 1)){
          TotalPeriodicSetRanges++;
          range.lowerRange = CurrentElement;
        }
        if((RangeDifference == 0)&&(TotalCurrentValues == 2))
        TotalPeriodicSetRanges=1;
    }
	range. NumberOfPeriodicRanges = TotalPeriodicSetRanges;
  return range;
}
