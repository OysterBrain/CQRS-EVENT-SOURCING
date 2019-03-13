#ifndef structureListeChaînee
#define structureListeChaînee
#include <iostream>


typedef struct Maillon {
	Maillon *suivant;
	int numero;
};

typedef struct Liste {
	Maillon *tete;
};


#endif