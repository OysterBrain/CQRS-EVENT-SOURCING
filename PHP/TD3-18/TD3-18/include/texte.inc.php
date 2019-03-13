<div id="texte">
<?php
if (!empty($_GET["page"]))
	$page=$_GET["page"];
	else $page=0;
switch ($page) {
// Clients
case 0:
	// inclure ici la page accueil photo
	include_once('pages/accueil.inc.php');
	break;
	
case 1:
	// inclure ici la page insertion nouveau client
	include_once('pages/saisieClient.inc.php');
    break;

case 2:
	// inclure ici la page liste des clients
	include_once('pages/lecCli.inc.php');
    break;
case 3:
	// inclure ici la page modification des clients
	    echo "page 3";
    break;
case 4:
	// inclure ici la page suppression clients
	    echo "page 4";
    break;
// Produits
case 5:
	// inclure ici la page insertion nouveau produit
   include_once('pages/saisieProduit.inc.php');
    break;
case 6:
	// // inclure ici la page liste des produits
	include_once('pages/lecProduit.inc.php');
    break;
default:
	include_once('pages/accueil.inc.php');
}	
?>
</div>
