<?php
//var_dump ($_POST);
if (empty($_POST["clinom"])){//premier appel
?>
<div class="sstitre"><h2>Ajouter un client</h2></div>

<form action="index.php?page=1" id="insert" method="post">

	Nom :  <input type="text" name="clinom"  id="clinom" size="10">
	<br /><br />
	Prénom :  <input type="text" name="clipre" id="clipre" size="10">
	<br /><br />
	<input type="submit" value="Ajouter"/>
	<input type="reset" value="Annuler"/>
</form>
<br />
<?php
} else
{
$pdo=new Mypdo();
$clientManager = new ClientManager($pdo);
$client = new Client($_POST);
$retour=$clientManager->add($client);
//on appelle la méthode add en lui passant un objet client

if ($retour !=0) //retour contient le nombre de lignes affectées
 echo "insertion effectuée" ;
 else
 echo "problème";
}
