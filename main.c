#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"


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

    return 0;
}