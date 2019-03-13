#include <iostream>
#include <stdio.h>
#include <string>
#include "FileAttente.h"
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
		cout << "Personne supprim�e :" << (*(fileAttente.tete)).personne.nom << endl;
		desInitialiserFile(fileAttente);
	}

	else if (fileAttente.tete != NULL) {
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
		cout << (*(fileAttente.tete)).personne.nom;
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