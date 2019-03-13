#include <iostream>
#include <stdio.h>
#include <string>
#include "FileAttente.h"
#include "Pile.h"
using namespace std;

//Méthode qui initialise une file
//
//Entrée : une file non initialisée
//Sortie : une file initialisée
//
//Pré condition : Avoir une file
//Post condition : Une file initalisée
void initialiserFile(FileAttente &fileAttente) {
	fileAttente.tete = nullptr;
	fileAttente.queue = nullptr;
}

FileAttente nouvelleListe() {
	FileAttente fileAttente;
	initialiserFile(fileAttente);
	return FileAttente();
}

void desInitialiserFile(FileAttente &fileAttente) {
	fileAttente.tete = nullptr;
	fileAttente.queue = nullptr;
}


FileAttente ajouterPersonneQueue(FileAttente fileAttente, Personne personne) {

	if (fileAttente.queue == nullptr) {
		fileAttente.queue = new Maillon;
		fileAttente.queue->personne = personne;
		fileAttente.queue->suivant = nullptr;
		fileAttente.tete = fileAttente.queue;
	}
	else {
		Maillon *mp;
		mp = new Maillon;

		mp->personne = personne;
		mp->suivant = nullptr;
		fileAttente.queue->suivant = mp;
		fileAttente.queue = mp;
	}
	return fileAttente;
}


FileAttente retirerPersonneTete(FileAttente fileAttente) {

	Maillon *m;
	m = fileAttente.tete;
	fileAttente.tete = m->suivant;
	return fileAttente;
}

// Procédure qui affiche le nom de la personne en tête de la file d'attente
// Cette procédure contrôle que fileAttente.tete n'est pas NULL
//
// Entrée : fileAttente
// Sortie : rien
//
// Précondition : avoir une variable fileAttente de type FileAttente
// Postcondition : rien

void consulterPersonneTeteFile(FileAttente fileAttente) {
	if (fileAttente.tete != nullptr) {
		cout << "Le nom de la personne en tete est : ";
		cout << (*(fileAttente.tete)).personne.nom ;
		cout << endl;
	}
	else {
		cout << "La file est vide " << endl;
	}
}

// Fonction qui calcule le nombre de maillons
//
// Entrée : file
// Sortie : file
//
// Précondition : avoir une variable file de type FileAttente
// Postcondition : renvoie le nombre de maillons

int calculerLongueur(FileAttente f)
{
	Maillon *buffer;
	int longueur = 0;
	buffer = f.tete;
	while (buffer != nullptr) {
		buffer = buffer->suivant;
		longueur++;
	}
	return longueur;
}

string personneTeteFile(FileAttente file) {
	return file.tete->personne.nom;
}

//Pile 

void initialiserPile(Pile &pile) {
	pile.base = nullptr;
}

Pile nouvellePile() {
	Pile pile;
	initialiserPile(pile);
	return pile;
}

void desinitialiserPile(Pile &pile) {
	pile.base = nullptr;
}

Pile empiler(Pile pile, FileAttente file) {
	if (pile.base == nullptr) {
		pile.base = new MaillonPile;
		
		pile.base->fileAttente = fileAttente;
		pile.base->suivant = nullptr;
	}
	else {
		/*
		MaillonPile *mp;
		mp = new MaillonPile;
		mp->fileAttente = fileAttente;
		mp->suivant = pile.base;
		pile.base = mp;
		*/

		MaillonPile *mp;

		mp = new MaillonPile;
		(*mp).suivant = pile.base;
		pile.base = mp;
		(*mp).fileAttente = file;

	}
	return pile;
}

Pile depiler(Pile pile) {
	MaillonPile *mp;

	mp = pile.base;
	pile.base = mp->suivant;
	return pile;
}

FileAttente basePile(Pile pile) {
	return pile.base->fileAttente;
}

bool pileEstVide(Pile pile) {
	return pile.base == nullptr;
}

bool fileEstVide(FileAttente file) {
	return calculerLongueur(file) == 0;
}



void main() {
	//Variables
	int choix;
	Personne personne;
	FileAttente file;
	Pile pile;

	pile = nouvellePile();
	file = nouvelleListe();

	do {
		//Programme main
		cout << "FILE D'ATTENTE" << endl;
		cout << "1 : Ajouter une personne en queue" << endl;
		cout << "2 : Retirer la personne en tête" << endl;
		cout << "3 : Consulter la personne en tête de la file" << endl;
		cout << "4 : Calculer la longueur de la file d'attente" << endl;
		cout << "5 : Undo" << endl;
		cin >> choix;

		switch (choix) {
		case 1:
			cout << "Saisir nom personne" << endl;
			cin >> personne.nom;

			pile = empiler(pile, file);
			file = ajouterPersonneQueue(file, personne);
			break;

		case 2:
			if (fileEstVide(file)) {
				cout << "File vide" << endl;
			}
			else {
				pile = empiler(pile, file);
				
				file = retirerPersonneTete(file);
			}
			break;

		case 3:
			consulterPersonneTeteFile(file);
			break;

		case 4:
			cout << "La longueur de la file est : " << calculerLongueur(file) << endl;
			break;

		case 5:

			if (pileEstVide(pile)) {
				cout << "Aucune action dans la pile" << endl;
			}
			else {
				file = basePile(pile);

				pile = depiler(pile);
							
				cout << "undo" << endl;
			}
			break;

		default:

			break;
		}

		cout << " voulez vous continuer 1/0 :"<<endl;
		cin >> choix;
	} while (choix != 0);


}