#include "space.h"

tTypeScore score_buf[N]; // preallocated memory space

void get_score_space(tTypeScore **pp_score) {
    for (int i = 0; i < N; i++) {
        if (score_buf[i].used == 0) {
            score_buf[i].used = 1;
            *pp_score = &score_buf[i];
            score_buf[i].loc = i;
            printf("     get_score_space(): giving space numbered %d\n", i);
            break;
        }
    }
    return;
}

void return_score_space(int loc) {
    if (loc >= 0 && loc < N) {
        printf("     return_score_space(): return space numbered %d\n", loc);
        score_buf[loc].used = 0;
    }
}