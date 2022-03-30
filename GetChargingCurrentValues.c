#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "GetChargingCurrentValues.h"

char* GetPeriodicSetRanges (int *CurrentValues, int TotalCurrentValues, int Index, char *result);
char output_string[20] = "\0";
int Index = 0;

char* GetPeriodicSetRanges (int *CurrentValues, int TotalCurrentValues, int Index, char *result)
{
	int i;
	
	for (i = 0; i < (TotalCurrentValues - 1); i++)
	{
		if ((CurrentValues[i+1] - CurrentValues[i]) > 1)
		{
			sprintf (output_string, "%d-%d,%d\n", CurrentValues[Index],CurrentValues[i], i+1-Index);
			Index = i+1;
			strcat(result, output_string);
			memset(output_string, '\0', sizeof(output_string));
		}
	}
	sprintf (output_string, "%d-%d,%d", CurrentValues[Index],CurrentValues[i], i+1-Index);
	strcat(result, output_string);
	return result;
}
