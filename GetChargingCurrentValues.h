
#define MAX_12BIT_CURRENTVALUE 4094
#define MAX_CURRENT_IN_AMPS    10
#define MAX_STRING_LEN         32

extern int Index;
extern char output_string[20];

char* GetPeriodicSetRanges (int *, int , int , char *);
int cmpfunc (const void * a, const void * b);
void ConvertAnalogCurrentInputs2Digital(int *, int , int *);
