//
// Created by nathan on 26/11/2021.
//

#ifndef AUTOROUTES_TYPES_H
#define AUTOROUTES_TYPES_H


typedef struct Road
{
    int size_road;
    int length_road;
    int speed_limit;
    struct Car**  cars; //taille : size_road (nb ligne ) * lenght Road (nb colonnes)

} Road;

typedef struct Inter
{
    struct Road* incident;
    int time_feu;
    struct Car** inside; // 2x2 pour le milieu de l'intersection

} Inter;

typedef struct Car
{
    int speed;
    struct Road* trajet; // GPS

} Car;

typedef struct City {
    struct Inter* node;
} City;


#endif //AUTOROUTES_TYPES_H²
