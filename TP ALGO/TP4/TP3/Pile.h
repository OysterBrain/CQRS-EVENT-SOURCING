#ifndef structurePile
#define structurePile
#include <iostream>
#include <string>
#include "FileAttente.h"

//Structure pile
typedef struct MaillonPile {
	MaillonPile *suivant;
	FileAttente fileAttente;
};

typedef struct Pile {
	MaillonPile *base;
};

//Variables
Pile pile;



#endif