#include <stdio.h>
#include "GetChargingCurrentValues.h"

int GetChargingCurrentValues (int *CurrentValues, int TotalCurrentValues){
  int TotalPeriodicSetRanges = 0;
  int i,temp;
  
  /* to sort values in an order */
  for(i = 0; i < TotalCurrentValues ; i++)
  {  
	if(CurrentValues[i] > CurrentValues[i+1])
    {
      temp = CurrentValues[i];
      CurrentValues[i] = CurrentValues[i+1];
      CurrentValues[i+1] = temp;
      i= -1;	  
	}
   }
  /* arrage and the ranges */
	if (  (TotalCurrentValues == 1) || (TotalCurrentValues == 2))
	{ 
		TotalPeriodicSetRanges = TotalCurrentValues;
	}
  return TotalPeriodicSetRanges;
}
