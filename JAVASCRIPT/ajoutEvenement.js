function ajouteEvent(objet, typeEvent, nomFonction, typePropagation){
	if (objet.addEventListener){
		objet.addEventListener(typeEvent, nomFonction, typePropagation);
		}
		else if (objet.attachEvent) 		{
			objet.attachEvent('on'+typeEvent, nomFonction);
		}
}

function clickBouton() {
	var boutonBleu = document.getElementById('bouton');
	var boutonValider = document.getElementById('valider');
	var liste = document.getElementById("choix2");
	var boutonGauche = document.getElementById("gauche");
	var boutonDroit = document.getElementById("droite");
	ajouteEvent(boutonBleu, 'click',changeCouleur, false);
	ajouteEvent(boutonValider, 'click',ajouterValeur, false);
	ajouteEvent(liste, 'change',miseAjour, false);
	ajouteEvent(boutonGauche, 'click',gaucheADroite, false);
	ajouteEvent(boutonDroit, 'click',droiteAGauche, false);
 }



 window.onload=function () {
 clickBouton();
}
 function gaucheADroite(){
	 var select =	document.getElementById("liste1").options.selectedIndex;
	 var libelle = document.getElementById("liste1").options[select].text;
	 var valeur =	document.getElementById("liste1").value;
	 var longueur2 = document.getElementById("liste2").options.length;
	 var ajout = new Option(libelle,valeur);

  document.getElementById("liste2").options[longueur2]= ajout;
	 document.getElementById("liste1").options[select]= null;
 }


 function droiteAGauche(){
 	var select =	document.getElementById("liste2").options.selectedIndex;
 	var libelle = document.getElementById("liste2").options[select].text;
 	var valeur =	document.getElementById("liste2").value;
 	var longueur2 = document.getElementById("liste1").options.length;
 	var ajout = new Option(libelle,valeur);

  document.getElementById("liste1").options[longueur2]= ajout;
 	document.getElementById("liste2").options[select]= null;
 }

function miseAjour() {
	var select =	document.getElementById("choix2").options.selectedIndex;
	var libelle = document.getElementById("choix2").options[select].text;
	var valeur =	document.getElementById("choix2").value;

	document.getElementById("lib2").value = libelle;
	document.getElementById("valeur2").value =valeur;



}

function ajouterValeur(){
	var longueur = document.getElementById("choix").options.length;
	var text = 	document.getElementById("lib").value;
  var valeur = 	document.getElementById("valeur").value;
	var ajout = new Option(text,valeur);

	document.getElementById("choix").options[longueur]= ajout;




}
 function changeCouleur()
 {
 text=document.getElementById('texte');
 bouton=document.getElementById('bouton')
 if(text.style.color=='blue'){
 		text.style.color='black';
		bouton.value="bleu";
	}
else {
	 text.style.color='blue';
	 bouton.value="noir";

 }
}
