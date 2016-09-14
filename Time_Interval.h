/*
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
*/
char Time_Interval(char *Past, char *Present,
                   int *Year, int *Month, int *Day,
                   int *Hour, int *Minute, int *Second){
//#########################################################################################################################
// Preset
//#########################################################################################################################
    char *Memory = (char *)calloc(5, sizeof(char));
    if (Memory == NULL){
        return 'X';
    }



    // Present date
    // Year
    strncat(Memory, Present,        4);
    (*Year)     = atoi(Memory);
    
    // Month
    memset(Memory, 0, 5);
    strncat(Memory, Present + 4,    2);
    (*Month)    = atoi(Memory);
    
    // Day
    memset(Memory, 0, 5);
    strncat(Memory, Present + 6,    2);
    (*Day)      = atoi(Memory);
    
    // Hour
    memset(Memory, 0, 5);
    strncat(Memory, Present + 8,    2);
    (*Hour)     = atoi(Memory);
    
    // Minute
    memset(Memory, 0, 5);
    strncat(Memory, Present + 10,   2);
    (*Minute)   = atoi(Memory);
    
    // Second
    memset(Memory, 0, 5);
    strncat(Memory, Present + 12,   2);
    (*Second)   = atoi(Memory);
    


    // Past date
    // Year
    memset(Memory, 0, 5);
    strncat(Memory, Past,       4);
    int Past_Year     = atoi(Memory);
    
    // Month
    memset(Memory, 0, 5);
    strncat(Memory, Past + 4,   2);
    int Past_Month    = atoi(Memory);
    
    // Day
    memset(Memory, 0, 5);
    strncat(Memory, Past + 6,   2);
    int Past_Day      = atoi(Memory);
    
    // Hour
    memset(Memory, 0, 5);
    strncat(Memory, Past + 8,   2);
    int Past_Hour     = atoi(Memory);
    
    // Minute
    memset(Memory, 0, 5);
    strncat(Memory, Past + 10,  2);
    int Past_Minute   = atoi(Memory);
    
    // Second
    memset(Memory, 0, 5);
    strncat(Memory, Past + 12,  2);
    int Past_Second     = atoi(Memory);
    free(Memory);



    // 
    if ((*Year) > (Past_Year + 5) || (*Year) < 2016 || Past_Year < 2016){
        return 'I';
    }



    // Days of Month
    int Days_Of_Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Leap year
    if (((*Year) % 100) == 0){
        if (((*Year) % 400) == 0){
            Days_Of_Month[2] = 29;
        }
    }else if (((*Year) % 4) == 0){
        Days_Of_Month[2] = 29;
    }
//#########################################################################################################################
// Calculation
//#########################################################################################################################
    // Get the Piece of time
    (*Second)   += ((*Minute) * 60);
    (*Second)   += (((*Hour) * 60) * 60);
    Past_Second += (Past_Minute * 60);
    Past_Second += ((Past_Hour * 60) * 60);
    Past_Second =  ((24 * 60) * 60) - Past_Second;
    (*Second)   += Past_Second;



    // Adjust day
    Past_Day++;
    if (Past_Day > Days_Of_Month[Past_Month]){
        Past_Day = 1;
        Past_Month++;
        if (Past_Month > 13){
            Past_Month = 1;
            Past_Year++;
        }
    }
    Past_Day = Days_Of_Month[Past_Month] - Past_Day;
    Past_Month++;
    if (Past_Month > 13){
        Past_Month = 1;
        Past_Year++;
    }



    // Get Day interval
    for (; Past_Year < (*Year); Past_Year++){
        for (; Past_Month < 13; Past_Month++){
            Past_Day += Days_Of_Month[Past_Month];
        }
        Past_Month = 1;
    }
    for (; Past_Month < (*Month); Past_Month++){
        Past_Day += Days_Of_Month[Past_Month];
    }
    Past_Day += (*Day);
    
    // Convert day to second & Add in *Second
    (*Second) += (((Past_Day * 24) * 60) * 60);



    // Get final result
    if ((*Second) >= 60){
        (*Minute)   = (int)((*Second) / 60);
        (*Second)   = (int)((*Second) % 60);
        if ((*Minute) >= 60){
            (*Hour)     = (int)((*Minute) / 60);
            (*Minute)   = (int)((*Minute) % 60);
            if ((*Hour) >= 24){
                (*Day)  = (int)((*Hour) / 24);
                (*Hour) = (int)((*Hour) % 24);
            }else {
                (*Day) = 0;
            }
        }else {
            (*Day)  = 0;
            (*Hour) = 0;
        }
    }else {
        (*Day)      = 0;
        (*Hour)     = 0;
        (*Minute)   = 0;
    }
    (*Year)     = 0;
    (*Month)    = 0;
    return 'V';
}
