#ifndef structureListeCha�nee
#define structureListeCha�nee
#include <iostream>


typedef struct Maillon {
	Maillon *suivant;
	int numero;
};

typedef struct Liste {
	Maillon *tete;
};


#endif