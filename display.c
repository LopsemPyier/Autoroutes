//
// Created by nathan on 26/11/2021.
//

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "display.h"
#include "types.h"


void display_continue(Road* road, int wait) {
    display(road);
    printf("\n");
    fflush(stdout);
    sleep(wait);
}

void display(Road* road) {
    printf("\033[1;1H\033[2J");
    for (int i = 0; i < road->length_road; ++i) {
        if (road->cars[i] != NULL) printf("\033[31;40m >\033[0m");
        else printf("\033[37;40m  ");
    }
    printf("\033[0m \n");
}
