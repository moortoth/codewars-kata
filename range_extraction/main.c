#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STR_SIZE 0x4000

char *range_extraction(const int *args, size_t n)
{  
    char* res = malloc(STR_SIZE);
    strcpy(res, "");

    size_t j = 0;

    for (size_t i = 0; i < n; i = j)
    {
        sprintf(res, "%s%d", res, args[i]);

        j = i;

        do {
            ++j;
        }
        while (args[j] - args[j - 1] == 1 && j < n);

        if (j - i > 1)
            sprintf(res, "%s%s%d", res, j - 2 == i ? "," : "-", args[j - 1]);
        if (j < n)
            sprintf(res, "%s,", res);
    }

    return res;
}

void main(int argc, char* argv[])
{
    char* res = range_extraction((const int[]){ -6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20 }, 20ul);
    // "-6,-3-1,3-5,7-11,14,15,17-20"
    res = range_extraction((const int[]){ -3,-2,-1,2,10,15,16,18,19,20 }, 10ul);
    //"-3--1,2,10,15,16,18-20"
    res = range_extraction((const int[]){ -5,-4,-3,-2,-1,0,1,2,3,4,5 }, 11ul);
    //"-5-5"
    res = range_extraction((const int[]){ -5,-4,-2,-1,1,2,4,5 }, 8ul);
    //"-5,-4,-2,-1,1,2,4,5"
    res = range_extraction((const int[]){ 9 }, 1ul);
    //"9"
}