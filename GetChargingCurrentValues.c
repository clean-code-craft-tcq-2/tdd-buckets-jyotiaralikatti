#include <stdio.h>
#include "GetChargingCurrentValues.h"
Range_Cfg range;
int GetChargingCurrentValues (int *CurrentValues, int TotalCurrentValues){
  int TotalPeriodicSetRanges = 0;
  int i;
  SortCurrentValues(CurrentValues,TotalCurrentValues);
  for(i = 0; i < TotalCurrentValues ; i++)
  {
   range = GetPeriodicSetRanges(CurrentValues,TotalCurrentValues);
  }
    printf("%d-%d, %d",range.lowerRange,range.upperRange,range.NumberOfPeriodicRanges);
  return TotalPeriodicSetRanges;
}
void SortCurrentValues(int *CurrentValues, int TotalCurrentValues)
{
  int i,swap;
  for(i = 0; i <(TotalCurrentValues - 1); i++)
  {
    if(CurrentValues[i] > CurrentValues[i+1])
    {
      swap = CurrentValues[i];
      CurrentValues[i] = CurrentValues[i+1];
      CurrentValues[i+1] = swap;
      i = -1;
    }
  }  
  printf("Sorted elements\n");
  for(i = 0; i <(TotalCurrentValues ); i++)
  printf("%d\t",CurrentValues[i]);
}
Range_Cfg GetPeriodicSetRanges(int *CurrentValues, int TotalCurrentValues)
{
  int CurrentElement,NextElement,RangeDifference;
  int i,TotalPeriodicSetRanges = 0;
    for (i=1;i<=TotalCurrentValues;i++){
        CurrentElement = CurrentValues[i-1];
        NextElement = CurrentValues[i];
        RangeDifference = NextElement - CurrentElement;        
        if( (RangeDifference == 1)){
          TotalPeriodicSetRanges++;
          range.lowerRange = CurrentElement;
        }
        else {
          range.upperRange = NextElement;
        }
    }
	range. NumberOfPeriodicRanges = TotalPeriodicSetRanges;
  return range;
}
