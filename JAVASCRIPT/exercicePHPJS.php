function ajouteEvent(objet, typeEvent, nomFonction, typePropagation){
	if (objet.addEventListener){
		objet.addEventListener(typeEvent, nomFonction, typePropagation);
		}
		else if (objet.attachEvent) 		{
			objet.attachEvent('on'+typeEvent, nomFonction);
		}
}

function clickBouton() {

	ajouteEvent(window, 'load',fonctionPhp, false);
	
 }



 window.onload=function () {
 clickBouton();
}

function fonctionPhp(){
  document.write(''voici la date du serveur : "+ "<?php echo date("d/m/Y H:i:s"). ;?>";


}
