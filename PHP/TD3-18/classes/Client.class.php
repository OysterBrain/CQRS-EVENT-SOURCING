<?php
class Client {
// Attributs
private $clinum;
private $clinom;
private $clipre;

public function __construct($valeurs = array()){
	if (!empty($valeurs))
			//print_r ($valeurs);
			 $this->affecte($valeurs);
}
public function affecte($donnees){
			foreach ($donnees as $attribut => $valeur){
					switch ($attribut){
							case 'clinum': $this->setCliNum($valeur); break;
							case 'clinom': $this->setNom($valeur); break;
							case 'clipre': $this->setPrenom($valeur); break;
					}
			}
	}
public function getCliNum() {
        return $this->clinum;
    }
public function setCliNum($id){
        $this->clinum=$id;
    }

public function getNom(){
        return $this->clinom;
    }
public function setNom($nom){
        $this->clinom = $nom;
    }

public function getPrenom(){
        return $this->clipre;
    }

public function setPrenom($prenom){
        $this->clipre = $prenom;
    }
}
