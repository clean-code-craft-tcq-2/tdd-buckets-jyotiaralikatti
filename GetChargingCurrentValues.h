typedef struct 
{
    int lowerRange;
    int upperRange;
	int NumberOfPeriodicRanges;
}Range_Cfg;

Range_Cfg GetPeriodicSetRanges(int *CurrentValues, int TotalCurrentValues);
void SortCurrentValues(int *CurrentValues, int TotalCurrentValues);
int GetChargingCurrentValues (int *CurrentValues, int TotalCurrentValues);
int GetNumberOfPeriodicRanges( int RangeDifference);

