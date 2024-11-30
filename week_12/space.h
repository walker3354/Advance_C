#ifndef __SPACE_H__ 
#define __SPACE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define N 5

typedef struct Score
{   
    int score;
    int loc;
    int used;      // to record if the space is used    
}tTypeScore;

void get_score_space (tTypeScore **pp_score); //get the space from score_buf, return the allocated number
void return_score_space (int location);  //return the space of the used score_buf

#endif