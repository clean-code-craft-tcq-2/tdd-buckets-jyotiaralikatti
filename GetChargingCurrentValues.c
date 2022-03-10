#include <stdio.h>
#include "GetChargingCurrentValues.h"
int GetPeriodicSetRanges(int *CurrentValues, int TotalCurrentValues);
void SortCurrentValues(int *CurrentValues, int TotalCurrentValues);

int GetChargingCurrentValues (int *CurrentValues, int TotalCurrentValues){
  int TotalPeriodicSetRanges = 0;
  int i;
  
 // SortCurrentValues(CurrentValues,TotalCurrentValues);
  
  for(i = 0; i < TotalCurrentValues ; i++)
  {
   TotalPeriodicSetRanges = GetPeriodicSetRanges(CurrentValues,TotalCurrentValues);
  }
  
  return TotalPeriodicSetRanges;
}

/*void SortCurrentValues(int *CurrentValues, int TotalCurrentValues)
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
}*/

int GetPeriodicSetRanges(int *CurrentValues, int TotalCurrentValues)
{
  int lowerRange,NextElement,RangeDifference;
  int TotalPeriodicSetRanges = 0;
 
    lowerRange = CurrentValues[0];
    NextElement = CurrentValues[1];
    RangeDifference = NextElement - lowerRange;
    if(RangeDifference == 0 || RangeDifference == 1)
    {
      TotalPeriodicSetRanges++;
      printf("Range, Readings\n");
      printf("%d-%d, %d",lowerRange,NextElement,TotalCurrentValues);
    }
  
  return TotalPeriodicSetRanges;
}



