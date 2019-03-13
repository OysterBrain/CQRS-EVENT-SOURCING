<?php
$pdo=new Mypdo();
$proManager = new ProduitManager($pdo);
$produits=$proManager->getAllProduit();
?>
<div class="sstitre"><h2>Liste des produits</h2></div>

<table>
	<tr><th>Numéro</th><th>Nom</th><th>Prix</th></tr>
	<?php //$produits est un tableau d'objet produit
	foreach ($produits as $produit){ //$produit est un objet produit?>
		<tr><td><?php echo $produit->getProNum();?>
		</td><td><?php echo $produit->getProLib();?>
		</td><td><?php echo $produit->getProPrixHT();?>
		</td></tr>
	<?php }?>
	</table>
	<br />
