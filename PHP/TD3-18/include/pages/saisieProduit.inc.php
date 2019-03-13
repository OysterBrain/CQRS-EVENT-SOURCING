<?php
var_dump ($_POST);
if (empty($_POST["prolib"])){
?>
<div class="sstitre"><h2>Ajouter un produit</h2></div>

<form action="index.php?page=5" id="insert" method="post">

	Libellé :  <input type="text" name="prolib"  size="10">
	<br /><br />
	Prix :  <input type="text" name="proprixht" size="10">
	<br /><br />
	<input type="submit" value="Ajouter"/>
	<input type="reset" value="Annuler"/>
</form>
<br />
<?php
} else
{











$pdo=new Mypdo();
$proManager = new ProduitManager($pdo);
$produit = new Produit($_POST);
//$_POST correspond à un tableau associatif indicé par les names des input
// array(2) { ["prolib"]=> string(6) "écran" ["proprixht"]=> string(2) "34" }
$retour=$proManager->add($produit);
//on appelle la méthode add en lui passant un objet produit

if ($retour !=0) //retour contient le nombre de lignes affectées
 echo "insertion effectuée" ;
 else
 echo "problème";
}
