//
// Created by nathan on 26/11/2021.
//

#include <stdio.h>
#include <stdlib.h>

#include "display.h"
#include "types.h"


void display(Road* road) {
    printf("\033[1;1H\033[2J");
    for (int i = 0; i < road->lenght_road; ++i) {
        if (road->cars[i] != NULL) printf("\033[30;31m >\033[37;0m");
        else printf("\033[37;30m  ");
    }
    printf("\033[37;0m \n");
}
