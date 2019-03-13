#include "Header.h"
#include <iostream>
using namespace std;

void initialiserListe(Liste *liste) {
	(*liste).tete = NULL;
}


int calculerTailleListe(Liste liste) {
	int taille;
	Maillon *mp;
	mp = new Maillon;

	mp = (liste.tete);
	taille = 0;

	if (liste.tete != nullptr) {
		do {
			mp = (*mp).suivant;
			taille++;

		} while (mp != liste.tete);
	}
	return taille;
}


void desinitListe(Liste *liste) {
	Maillon *mp;
	Maillon *sp;
	int taille;

	taille = calculerTailleListe(*liste);

	mp = (*liste).tete;

	for (int i = 0; i < taille; taille++) {
		sp = mp;
		mp = (sp->suivant);

		sp = nullptr;
		free(sp);
	}
}


void afficherListe(Liste liste) {
	Maillon *dp;
	int numero;

	numero = 0;
	dp = (liste.tete);

	do {
		cout << "Position : " <<numero <<" Valeur  : " << (*dp).numero << endl;
		numero++;
		dp = (*dp).suivant;
	}while(dp != liste.tete);
}

void rotationListe(Liste *liste) {
	
	(*liste).tete = (*(*liste).tete).suivant;
}

void insererMaillon(int valeur, Liste *liste) {
	Maillon *np;
	Maillon *dp;
	Maillon *sp;

	np = new Maillon;
	(*np).numero = valeur;

	if ((*liste).tete != NULL) {
		(*np).suivant = (*liste).tete;
		dp = (*liste).tete;

		while ((*dp).suivant != (*liste).tete) {
			dp = (*dp).suivant;
		}

		(*dp).suivant = np;
	}
	else {
		(*np).suivant = np;
	}
	(*liste).tete = np;
}


int main() {

	Liste listeCirculaire;

	initialiserListe(&listeCirculaire) ;

	//Variables
	int choix;

	do {
		//Programme main
		cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << endl;
		cout << "LISTE CIRCULAIRE" << endl;
		cout << "1 : Ajouter un element" << endl;
		cout << "2 : Afficher la liste " << endl;
		cout << "3 : Rotation d'un cran" << endl;
		cout << "4 : Nombre de maillons" << endl;

		cin >> choix;

		switch (choix) {
		case 1:

			int numéro;
			cout << "Choisissez l'entier a ajouter : ";
			cin >> numéro;
			insererMaillon(numéro , &listeCirculaire);
			break;
		case 2:
			cout << "-- -- -- -- -- -- -- -- -- -- -- --"<<endl;
			cout << "VOICI VOTRE LISTE : "<<endl;
			afficherListe(listeCirculaire);

			break;

		case 3:

			cout << "-- -- -- -- -- -- -- -- -- -- -- --"<<endl;
			if (calculerTailleListe(listeCirculaire) <= 1) {
				cout << "ERREUR il n'y a pas assez d'element pour effectuer une rotation"<<endl;
			}
			else {
				cout << "VOICI LA ROTATION D'UN CRAN DE VOTRE LISTE : " << endl;
				rotationListe(&listeCirculaire);
				afficherListe(listeCirculaire);
			}
			break;

		case 4:

			
			cout<< "Dans votre liste il y a : "<<calculerTailleListe(listeCirculaire)<<" element(s)"<<endl;
			break;

		default:
			cout << "Veuillez choisir un chiffre entre 1 et 4";
			break;
		}

		cout << " voulez vous continuer 1/0 :" << endl;
		cin >> choix;

	} while (choix != 0);
	desinitListe(&listeCirculaire);
	system("PAUSE");
}

