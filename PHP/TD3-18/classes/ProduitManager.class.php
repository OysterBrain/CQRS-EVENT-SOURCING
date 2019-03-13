<?php
class ProduitManager{
	private $db;
		public function __construct($db){
			$this->db = $db;
		}
    public function add($produit){
            $requete = $this->db->prepare(
			     'INSERT INTO produit (prolib, proprixht) VALUES (:nom, :prix);');

            $requete->bindValue(':nom',$produit->getProLib());
			      $requete->bindValue(':prix',$produit->getProPrixHT());

            $retour=$requete->execute();
			return $retour;
        }

		public function getAllProduit(){
            $listeProduits = array();

            $sql = 'SELECT pronum, prolib, proprixht FROM produit ORDER BY prolib';

            $requete = $this->db->prepare($sql);
            $requete->execute();

            while ($produit = $requete->fetch(PDO::FETCH_OBJ))
              {  $listeProduits[] = new Produit ($produit);}

            $requete->closeCursor();

            return $listeProduits;
        }
}
?>
