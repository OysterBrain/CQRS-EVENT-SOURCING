#ifndef structureFileAttente
#define structureFileAttente
#include <iostream>
#include <string>
using namespace std;

//Type de données
typedef struct Personne {
	string nom;
}Personne;

typedef struct Maillon {
	Maillon *suivant;
	Personne personne;
}Maillon;

typedef struct FileAttente {
	Maillon *tete;
	Maillon *queue;
};

typedef struct Pile {

	MaillonPile *tete;
	

}Pile;
typedef struct MaillonPile {
	FileAttente fileAttente;
	MaillonPile *suivant;
}MaillonPile;

//Variables
FileAttente fileAttente;
FileAttente copieFile;
Personne personne;
Pile pile;

//Fonctions file
void initialiserFile(FileAttente &fileAttente);
void desInitialiserFile(FileAttente &fileAttente);
void supListe(FileAttente &file);

void ajouterPersonneQueue(FileAttente &fileAttente, Personne personne);
void retirerPersonneTete(FileAttente &fileAttente);
void consulterPersonneTeteFile(FileAttente fileAttente);
int calculerLongueur(FileAttente &fileAttente);

//Fonctions pile 
void initialiserPile(Pile &pile);
void desinitialiserPile(Pile &pile);
FileAttente sommetPile(Pile pileundo);

void empilerPile(Pile &pile, FileAttente file);
void depilerPile(Pile &pile);
#endif