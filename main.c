#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "display.h"


/*----------------------------------------------------------------
cars : liste de pointeurs de taille road.size_road
blocked : liste de bool de taille road.size_road
*/
Car** avance (Road* road, Car** coming_cars, bool* blocked){

    Car** return_value = malloc ((road->size_road) * sizeof(Car*));

    // traite la fin de la route
    for (int i = 0; i < road->size_road; i++) {
        if (blocked[i]) {
            return_value[i] = NULL;
        } else {
            int j = (road->length_road - 1) + i*(road->length_road); //bout de la ieme ligne
            return_value[i] = (road->cars)[j];
            (road->cars)[j] = NULL;
        }
    }

    // avance le milieu si possible
    for (int i = (road->length_road-2); i>0; i--){
        for (int j = 0; j < road->size_road;j++){
            if (road->cars[i + 1 + j*(road->length_road)] == NULL){
                road->cars[i + 1 + j*(road->length_road)] = road->cars[i + j*(road->length_road)];
            }
        }
    }

    // remplis le debut si possible
    for (int j=0; j < road->size_road; j++) {
        if (road->cars[j*(road->length_road)] == NULL){
                road->cars[(road->length_road)] = coming_cars[j];
        }
    }

    return return_value;
}


int main(void){
    int n = 10;
    Car* cars = (Car*) malloc(sizeof(Car)*n);

    Road road;
    road.speed_limit = 10;
    road.length_road = 10;
    road.size_road = 1;
    road.cars = (Car**) malloc(sizeof(Car*)*road.length_road);

    for (int i = 0; i < road.length_road; ++i) {
        road.cars[i] = NULL;
    }


    display_continue(&road, 1);
    road.cars[0] = &cars[0];
    display_continue(&road, 1);
    road.cars[3] = &cars[1];
    display_continue(&road, 1);
    road.cars[4] = &cars[2];
    display_continue(&road, 1);
    road.cars[8] = &cars[3];
    display_continue(&road, 1);

    return 0;
}