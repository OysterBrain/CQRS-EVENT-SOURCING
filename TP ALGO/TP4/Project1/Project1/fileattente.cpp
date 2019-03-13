#include <iostream>
#include <stdio.h>
#include <string>
#include "FileAttente.h"
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

		cout << "Vous avez ajouter en tete : " << (*fileAttente.tete).personne.nom << endl;
	}
	else {
		Maillon *ancienPointeur;
		ancienPointeur = fileAttente.queue;
		(*ancienPointeur).suivant = new Maillon;

		fileAttente.queue = (*ancienPointeur).suivant;
		(*(fileAttente.queue)).personne.nom = personne.nom;
		(*(fileAttente.queue)).suivant = NULL;

		cout << "Vous avez ajouter en queue : " << (*fileAttente.queue).personne.nom << endl;
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
		cout << "Personne supprimée :" << (*(fileAttente.tete)).personne.nom << endl;
		desInitialiserFile(fileAttente);
	}

	else if (fileAttente.tete != NULL) {
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
		cout << (*(fileAttente.tete)).personne.nom;
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

int calculerLongueur(FileAttente &file) {
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

//supprimerListe


void supListe(FileAttente &file){
	while (file.tete != NULL)
	{
		retirerPersonneTete(file);
	}
}

//fonction dupliquer 
void dupliquerFile(FileAttente file, FileAttente &copieFile){
	Maillon *maillon;
	initialiserFile(copieFile);
	maillon = file.tete;

	while (maillon != NULL)
	{
		ajouterPersonneQueue(copieFile, (*maillon).personne);
		maillon = (*maillon).suivant;
	}
	copieFile.queue = maillon;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//										PILE
///////////////////////////////////////////////////////////////////////////////////////////////////

//initialiser pile

void initialiserPile(Pile &pile ){
	pile.tete = NULL;
	
}

//desinitialiser pile

void desinitialiserPile(Pile &pile) {
	pile.tete = NULL;

}

//fonction empiler

void empilerPile(Pile &pile, FileAttente file){
	MaillonPile *np;
	np = new MaillonPile;
	(*np).suivant = pile.tete;
	pile.tete = np;
	pile.tete->fileAttente = file;
}

void depilerPile(Pile &pile)
{

	MaillonPile *np;
	
	np = pile.tete;
	delete pile.tete;
	initialiserPile(pile);
	pile.tete = np;
	
	
	
}

FileAttente sommetPile(Pile pileundo)
{
	return pile.tete->fileAttente;
}


//fonction undo   



int main() {
	//Variables
	int choix;
	Personne personne;
	string nom;


	initialiserFile(fileAttente);

	do {
		//Programme main
		cout << "FILE D'ATTENTE" << endl;
		cout << "1 : Ajouter une personne en queue" << endl;
		cout << "2 : Retirer la personne en tete" << endl;
		cout << "3 : Consulter la personne en tete de la file" << endl;
		cout << "4 : Calculer la longueur de la file d'attente" << endl;
		cout << "5 : Utiliser la fonction UNDO" << endl;

		cin >> choix;

		switch (choix) {
		case 1:
			cout << "Saisir nom personne" << endl;
			cin >> personne.nom;
			dupliquerFile(fileAttente,copieFile);
			empilerPile(pile, copieFile);
			ajouterPersonneQueue(fileAttente, personne);
			cout << endl << endl;
			break;


		case 2:
			dupliquerFile(fileAttente, copieFile);
			empilerPile(pile, copieFile);
			retirerPersonneTete(fileAttente);
			break;

		case 3:
			consulterPersonneTeteFile(fileAttente);
			break;

		case 4:
			cout << "La longueur de la chaine est : " << calculerLongueur(fileAttente) << endl;
			break;

		case 5:
			cout << "coucou";
			if (pile.tete->fileAttente.tete != NULL)
			{
				supListe(fileAttente);
				cout << "patate" << endl << endl;
				fileAttente = sommetPile(pile);
				cout << "patate" << endl << endl;
				depilerPile(pile);
				cout << "Ceci a ete annulee !" << endl << endl;
			}

			else
			{
				cout << "Aucune action effectuee car aucune file disponible." << endl << endl;
			}
			break;

		default:
			break;
		}

		cout << " voulez vous continuer (1 ou 0) :" << endl;
		cin >> choix;
	} while (choix != 0);

	return 0;
}