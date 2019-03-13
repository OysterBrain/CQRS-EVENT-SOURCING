#include <iostream>
#include <stdio.h>
#include <string>
#include "FileAttente.h"
#include "Pile.h"
using namespace std;

// Proc�dure qui initialise fileAttente de type FileAttente
//
// Entr�e : fileAttente
// Sortie : fileAttente
//
// Pr�condition : rien
// Postcondition : fileAttente est initialis�e

void initialiserFile(FileAttente &fileAttente) {
	fileAttente.tete = NULL;
	fileAttente.queue = NULL;
}


// Proc�dure qui d�sinitialise fileAttente de type FileAttente
//
// Entr�e : fileAttente
// Sortie : fileAttente
//
// Pr�condition : rien
// Postcondition : fileAttente est desinitialis�e

void desInitialiserFile(FileAttente &fileAttente) {
	fileAttente.tete = NULL;
	fileAttente.queue = NULL;
}

// Proc�dure qui ajoute une personne � la fin de la liste d'attente.
//
// Entr�e : fileAttente, personne
// Sortie : fileAttente
//
// Pr�condition : une variable fileAttente de type FileAttente
//                personne
// Postcondition : Une personne a �t� ajout�e � la fin de la liste.

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

// Proc�dure qui supprime la personne en t�te de file
// La proc�dure v�rifie qu'il y a d�j� des maillons
//
// Entr�e : fileAttente
// Sortie : fileAttente
//
// Pr�condition : avoir une variable fileAttente de type FileAttente
// Postcondition : La personne en t�te de liste est supprim�e. Le pointeur de t�te est d�cal� d'un cran.


void retirerPersonneTete(FileAttente &fileAttente) {
	Maillon *maillon;

	if (fileAttente.tete == NULL) {
		cout << "Aucune personne en t�te" << endl;
	}

	else if (fileAttente.tete == fileAttente.queue) {		
		cout <<"Personne supprim�e :" << (*(fileAttente.tete)).personne.nom << endl;
		desInitialiserFile(fileAttente);
	}

	else if(fileAttente.tete != NULL){
		maillon = fileAttente.tete;

		if (fileAttente.tete->suivant != NULL) {
			fileAttente.tete = (*maillon).suivant;

			cout << " Personne supprim�e :" << (*(fileAttente.tete)).personne.nom << endl;
			
			delete maillon;

		}
	}
}

// Proc�dure qui affiche le nom de la personne en t�te de la file d'attente
// Cette proc�dure contr�le que fileAttente.tete n'est pas NULL
//
// Entr�e : fileAttente
// Sortie : rien
//
// Pr�condition : avoir une variable fileAttente de type FileAttente
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
// Entr�e : file
// Sortie : file
//
// Pr�condition : avoir une variable file de type FileAttente
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
		cout << "2 : Retirer la personne en t�te" << endl;
		cout << "3 : Consulter la personne en t�te de la file" << endl;
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