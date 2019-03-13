<?php
define("TVA", 0.2); //constante "globale"

require_once("classes/ProduitExo1.class.php");

$produit=new Produit(1,"Micro-ordinateur 17p",645);

 echo 'libellé : '.$produit->getLibelle()."<br />";
 echo 'prix HT : '.$produit->getPrix()."<br />";
 echo 'prix TTC : '.$produit->calculerPrixTTC($produit->getPrix())."<br />";
    //avec constantes de classe
 echo 'prix TTC : '.$produit->calculerPrixTTC2($produit->getPrix())."<br />";
   //avec constantes de classe
 echo 'prix TTC : '.$produit->calculerPrixTTC3($produit->getPrix())."<br />";
 // utilisation de la constante gobale
  ?>
