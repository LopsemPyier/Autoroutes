typedef struct
{
    int size_road;
    int lenght_road;
    int speed_limit;
    Car**  cars; //taille : size_road (nb ligne ) * lenght Road (nb colonnes)
    
} Road;

typedef struct
{
    Road* incident;
    int time_feu;
    Car** inside; // 2x2 pour le milieu de l'intersection
    
}Inter;

typedef struct
{
    int speed;
    Road* trajet; // GPS 
    
}Car;

typedef struct {
    Inter* node;
} City;



int main(void){

    return 1;
}