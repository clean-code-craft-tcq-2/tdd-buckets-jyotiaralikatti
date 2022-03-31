#include "GetPeriodicSetOfRanges.h"
#include <stdio.h>
#include <math.h>

void ConvertAnalogCurrentInputs2Digital(int *AnalogCurrentInputs, int TotalCurrentValues, int *DigitalCurrentValues)
{
    int invalid=0;
    for(int i=0; i<TotalCurrentValues;i++)
    {
         if (AnalogCurrentInputs[i] > MAX_12BIT_CURRENTVALUE)
         {
             AnalogCurrentInputs[i] = 0 ; //assume the invalid sample as 0
             invalid++;
         }    
        DigitalCurrentValues[i] = (MAX_CURRENT_IN_AMPS * AnalogCurrentInputs[i] )/ MAX_12BIT_CURRENTVALUE;
        DigitalCurrentValues[i] = round(DigitalCurrentValues[i]);
    }
} 
