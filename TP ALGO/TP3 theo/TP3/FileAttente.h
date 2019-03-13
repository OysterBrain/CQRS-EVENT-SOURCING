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

//Variables
FileAttente fileAttente;
Personne personne;

//Fonctions
void initialiserFile(FileAttente &fileAttente);
void desInitialiserFile(FileAttente &fileAttente);

void ajouterPersonneQueue(FileAttente &fileAttente,Personne personne);
void retirerPersonneTete(FileAttente &fileAttente);
void consulterPersonneTeteFile(FileAttente fileAttente);
int calculerLongueur(FileAttente &fileAttente);

#endif