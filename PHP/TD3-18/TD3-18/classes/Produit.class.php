<?php
class Produit {
	private $pronum;
	private $prolib;
	private $proprixht;

    public function __construct($valeurs = array()) {
    	if (!empty($valeurs))
           $this->affecte($valeurs);
    }

	 public function affecte($donnees){
        foreach ($donnees as $attribut => $valeur){
            switch ($attribut){
                case 'pronum': $this->setProNum($valeur); break;
                case 'prolib': $this->setProLib($valeur); break;
                case 'proprixht': $this->setProPrixHT($valeur); break;
            }
        }
    }

	public function getProNum(){
		return $this->pronum;
	}

	public function setProNum($id){
		$this->pronum = $id;
	}

	public function getProLib(){
		return $this->prolib;
	}

	public function setProLib($nom){
		$this->prolib = $nom;
	}

	public function getProPrixHT(){
		return $this->proprixht;
	}

	public function setProPrixHT($prenom){
		$this->proprixht = $prenom;
	}
}
?>
