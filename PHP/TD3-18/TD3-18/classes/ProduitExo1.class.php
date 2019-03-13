<?php
class Produit {
 const TVAC =  0.2; //constante de classe
	private $pronum;
	private $prolib;
	private $proprixht;

      public function __construct($num, $libelle, $prix) {
    	$this->setNum($num);
    	$this->setLibelle($libelle);
    	$this->setPrix($prix);
      }

      public function setNum ($num) {
    	if (is_numeric($num)) {
	       $this->pronum=$num;}
        else {
	         echo "Erreur de saisie<br />";
	        }
    	}

    	public function setLibelle ($libelle) {
	       $this->prolib= $libelle;
    	}
    	public function setPrix ($prix) {
	       $this->proprixht=$prix;
    	}
    	public function getLibelle () {
	       return $this->prolib ;
    	}
	     public function getPrix () {
	        return $this->proprixht ;
    	}


    	public function calculerPrixTTC ($prixHT) {
	       return ($prixHT*self::TVAC)+$this->proprixht ; //une écriture pour les constantes de classe
    	}
    	public function calculerPrixTTC2 ($prixHT) {
	       return ($prixHT*produit::TVAC)+$this->proprixht ; //une autre écriture pour les constantes de classe
    	}
	    public function calculerPrixTTC3 ($prixHT) {
	        return ($prixHT*TVA)+$this->proprixht ; //écritre pour les constantes "gobales"
    	}
}
?>
