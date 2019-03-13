#include <iostream>
#include <stdio.h>
#include <string>
#include "FileAttente.h"
#include "Pile.h"
using namespace std;

// Procédure qui initialise fileAttente de type FileAttente
//
// Entrée : fileAttente
// Sortie : fileAttente
//
// Précondition : rien
// Postcondition : fileAttente est initialisée

void initialiserFile(FileAttente &fileAttente) {
	fileAttente.tete = NULL;
	fileAttente.queue = NULL;
}


// Procédure qui désinitialise fileAttente de type FileAttente
//
// Entrée : fileAttente
// Sortie : fileAttente
//
// Précondition : rien
// Postcondition : fileAttente est desinitialisée

void desInitialiserFile(FileAttente &fileAttente) {
	fileAttente.tete = NULL;
	fileAttente.queue = NULL;
}

// Procédure qui ajoute une personne à la fin de la liste d'attente.
//
// Entrée : fileAttente, personne
// Sortie : fileAttente
//
// Précondition : une variable fileAttente de type FileAttente
//                personne
// Postcondition : Une personne a été ajoutée à la fin de la liste.

void ajouterPersonneQueue(FileAttente &fileAttente, Personne personne) {

	if (fileAttente.tete == NULL) {
		Maillon *nouveauMaillon;
		nouveauMaillon = new Maillon;

		(*nouveauMaillon).personne.nom = personne.nom;
		(*nouveauMaillon).suivant = NULL;

		fileAttente.tete = nouveauMaillon;
		fileAttente.queue = nouveauMaillon;

		cout << "Vous avez ajouter en tete : " << (*fileAttente.tete).personne.nom<<endl;
	}
	else {
		Maillon *ancienPointeur;
		ancienPointeur = fileAttente.queue;
		(*ancienPointeur).suivant = new Maillon;

		fileAttente.queue = (*ancienPointeur).suivant;
		(*(fileAttente.queue)).personne.nom = personne.nom;
		(*(fileAttente.queue)).suivant = NULL;

		cout << "Vous avez ajoute en queue : " << (*fileAttente.queue).personne.nom<<endl;
	}
}

// Procédure qui supprime la personne en tête de file
// La procédure vérifie qu'il y a déjà des maillons
//
// Entrée : fileAttente
// Sortie : fileAttente
//
// Précondition : avoir une variable fileAttente de type FileAttente
// Postcondition : La personne en tête de liste est supprimée. Le pointeur de tête est décalé d'un cran.


void retirerPersonneTete(FileAttente &fileAttente) {
	Maillon *maillon;

	if (fileAttente.tete == NULL) {
		cout << "Aucune personne en tête" << endl;
	}

	else if (fileAttente.tete == fileAttente.queue) {		
		cout <<"Personne supprimée :" << (*(fileAttente.tete)).personne.nom << endl;
		desInitialiserFile(fileAttente);
	}

	else if(fileAttente.tete != NULL){
		maillon = fileAttente.tete;

		if (fileAttente.tete->suivant != NULL) {
			fileAttente.tete = (*maillon).suivant;

			cout << " Personne supprimée :" << (*(fileAttente.tete)).personne.nom << endl;
			
			delete maillon;

		}
	}
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
	if (fileAttente.tete != NULL) {
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

int calculerLongueur(FileAttente &file){
	int l;
	Maillon *sp;
	l = 0;

	sp = file.tete;

	if (file.tete == NULL)
	{
		return 0;
	}
	else
	{
		while (sp != file.queue)
		{
			sp = (*sp).suivant;
			l++;
		}
	}
	return l + 1;
}

//Pile 
void initialiserPile(Pile &pile) {
	pile.base = NULL;
}

void desinitialiserPile(Pile &pile) {
	pile.base = NULL;
}

void empiler(Pile &pile, FileAttente file) {
	MaillonPile *mp;

	mp = new MaillonPile;
	(*mp).suivant = pile.base;
	pile.base = mp;
	(*mp).fileAttente = file;
}

void depiler(Pile &pile) {
	MaillonPile *mp;

	mp = (*pile.base).suivant;
	delete pile.base;
	pile.base = mp;
	
}

void dupliquer(FileAttente file, FileAttente &copieFile) {
	Maillon *np;
	initialiserFile(copieFile);
	np = file.tete;

	while (np != file.queue) {
		ajouterPersonneQueue(copieFile, (*np).personne);
		np = (*np).suivant;
	}
	copieFile.queue = np;
}

void supListe(FileAttente &file) {
	while (file.queue != NULL) {
		retirerPersonneTete(file);
	}
}

FileAttente base(Pile &pile) {
	return (*pile.base).fileAttente;
}
/*
void ajouterInstructionSommetPile(Pile &pile, FileAttente file) {
	if (pile.base == NULL) {
		MaillonPile *nouveauMaillonPile;
		nouveauMaillonPile = new MaillonPile;

		(*nouveauMaillonPile).fileAttente = file;
		(*nouveauMaillonPile).suivant = NULL;

		pile.base = nouveauMaillonPile;

		cout << "Ajout base pile" << endl;
	}
	else {
		MaillonPile *ancienPointeurPile;
		ancienPointeurPile = pile.base;
		(*ancienPointeurPile).suivant = new MaillonPile;

		pile.base = (*ancienPointeurPile).suivant;
		(*ancienPointeurPile).suivant->fileAttente = file;
		(*ancienPointeurPile).suivant->suivant = NULL;

		cout << "Ajout sommet" << endl;
	}
	
}

void retirerInstructionSommetPile(Pile &pile) {
	if (pile.base == NULL) {
		cout << "La pile est vide" << endl;
	}
	else {
		cout << "depilement de : " << (*pile.base).fileAttente.tete << endl;

		MaillonPile *temp;
		temp = pile.base;

		pile.base = pile.base->suivant;

		
	}
}

int hauteurPile(Pile &pile) {
	int i = 0;
	MaillonPile *mp;
	mp = new MaillonPile;

	if (pile.base == NULL) {
		return 0;
	}
	else {
		while (mp != NULL) {
			mp = mp->suivant;
			i++;
		}
	}
	return i + 1;
}
*/


void main() {
	//Variables
	int choix;
	Personne personne;
	string nom;
	FileAttente file;
	Pile pile;
	FileAttente copieFile;

	//Initialisation
	initialiserFile(file);
	initialiserFile(copieFile);
	initialiserPile(pile);

	copieFile = file;

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
			
			//dupliquer(file, copieFile);
			copieFile = file;

			empiler(pile, copieFile);
			
			ajouterPersonneQueue(file, personne);
			break;

		case 2:
			file = copieFile;

			retirerPersonneTete(file);

			//dupliquer(file, copieFile);
			//empiler(pile, file);
			break;

		case 3:
			consulterPersonneTeteFile(file);
			break;

		case 4:
			cout << "La longueur de la chaine est : " << calculerLongueur(file) << endl;
			break;

		case 5:/*
			if (pile.base != NULL) {
				supListe(file);
				cout << "sbeul" << endl;
				//dupliquer((*pile.base).fileAttente, file);
				cout << "sbeul" << endl;
				depiler(pile);
				cout << "undo" << endl;
			}
			else {
				cout << "pile vide" << endl;
			}
			*/
			file = copieFile;
			break;

		default:
			break;
		}

		cout << " voulez vous continuer 1/0 :"<<endl;
		cin >> choix;
	} while (choix != 0);
	desinitialiserPile(pile);
	desInitialiserFile(file);
	desInitialiserFile(copieFile);
}