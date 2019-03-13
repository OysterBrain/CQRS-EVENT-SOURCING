<?php

class ClientManager {
	private $dbo;

		public function __construct($db){
			$this->db = $db;
		}
        public function add($client){
            $requete = $this->db->prepare(
						'INSERT INTO client (clinom, clipre) VALUES (:nom, :prenom);');

            $requete->bindValue(':nom',$client->getNom());
						$requete->bindValue(':prenom',$client->getPrenom());

            $retour=$requete->execute();
						var_dump($requete->debugDumpParams());
						return $retour;
        }

		public function getAllClient(){
            $listeClients = array();

            $sql = 'select clinum, clinom, clipre FROM client ORDER BY 2';

            $requete = $this->db->prepare($sql);
            $requete->execute();

            while ($client = $requete->fetch(PDO::FETCH_OBJ))
                $listeClients[] = new Client($client);

            $requete->closeCursor();
            return $listeClients;
					}
}

?>
