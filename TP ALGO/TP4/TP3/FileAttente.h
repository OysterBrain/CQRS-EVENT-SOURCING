#ifndef structureFileAttente
#define structureFileAttente
#include <iostream>
#include <string>
using namespace std;

//Type de données
typedef struct Personne {
	string nom;
};

typedef struct Maillon {
	Maillon *suivant;
	Personne personne;
};

typedef struct FileAttente {
	Maillon *tete;
	Maillon *queue;
};

//Variables file d'attente
FileAttente fileAttente;
Personne personne;

#endif