//*************************************************************************************************************************
// System API
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/vfs.h>
#include <fcntl.h>
#include <time.h>
#include <ctype.h>
//*************************************************************************************************************************
// Module
#include "/root/03_C/00_Trick/03_Module/File_Read.h"
#include "/root/03_C/00_Trick/03_Module/Delay.h"
//*************************************************************************************************************************
// Body
#include "06_Status_Network.h"
#include "05_Status_Cpu.h"
#include "04_Status_Memory.h"
#include "03_Status_Disk.h"
#include "02_Interface.h"
//*************************************************************************************************************************
int main(const int ORDER_TOTAL, const char *ORDERs[]){
    while (1){
        Interface();
    }
    return 0;
}
