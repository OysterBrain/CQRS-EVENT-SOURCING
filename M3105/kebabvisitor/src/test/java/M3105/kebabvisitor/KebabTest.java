package M3105.kebabvisitor;

import static org.assertj.core.api.Assertions.assertThat;

import org.junit.Before;
import org.junit.Test;

import M3105.kebabvisitor.ingredients.*;

public class KebabTest { 

 private Kebab kebabCarnivore;
 private Kebab kebabVegetarien;
 private Kebab kebabPoisson;
 private Kebab kebabCrevette;
 private Kebab kebabBoeuf;
 
 @Before
 public void setUp() {

     kebabCarnivore = new Assiette();
     kebabCarnivore = new Pain("pita",kebabCarnivore);
     kebabCarnivore = new Oignon("oignon blanc",kebabCarnivore);
     kebabCarnivore = new Sauce("sauce algÃ©rienne",kebabCarnivore);
     kebabCarnivore = new Agneau("agneau de prÃ©-salÃ©",kebabCarnivore);
     kebabCarnivore = new Tomate("tomate rouge",kebabCarnivore);
    
         
     kebabVegetarien = new Sauce("sauce algÃ©rienne",
     					new Tomate("tomate rouge",
     						new Oignon("oignon blanc",
     								new Fromage("gruyere",
     										new Pain("pita",
     											new Assiette())))));
     
     kebabPoisson = new Thon("poisson",
     				new Sauce("sauce algÃ©rienne",
     						new Fromage("gruyere",
     								new Oignon("oignon blanc",
     										new Fromage("cheddar",
     												new Oignon("oignon blanc",
     														new Pain("pita",
     																new Assiette())))))));
     
     
     kebabCrevette = new Salade("laitue",
     					new Tomate("tomate rouge",
     							new Crevette ("petite crevette",
     									new Fromage("cheddar",
     											new Sauce("sauce algÃ©rienne",
														new Oignon("oignon blanc",
																new Pain("pita",
																		new Assiette())))))));
     
     
     kebabBoeuf = new Boeuf("Boeuf du limousin",
					new Sauce("sauce Marocaine",
						new Fromage("gruyere",
								new Oignon("oignon blanc",
										new Fromage("cheddar",
												new Oignon("oignon rouge",
														new Pain("kekab",
																new Assiette())))))));
     
     


 }
 

 @Test
 public void un_kebab_contient_bien_les_noms_de_tous_les_ingredients_ajoutes() {
 	assertThat(kebabCarnivore.getIngredients()).extracting("nom").
   						containsExactly("pita","oignon blanc", "sauce algÃ©rienne", "agneau de prÃ©-salÃ©", "tomate rouge");

 	assertThat(kebabVegetarien.getIngredients()).extracting("nom")
								.containsExactly("pita","gruyere","oignon blanc","tomate rouge","sauce algÃ©rienne");
 	
  	assertThat(kebabPoisson.getIngredients()).extracting("nom")
								.containsExactly("pita","oignon blanc","cheddar","oignon blanc","gruyere","sauce algÃ©rienne","poisson");
 
  	assertThat(kebabCrevette.getIngredients()).extracting("nom")
		.containsExactly("pita","oignon blanc","sauce algÃ©rienne","cheddar","petite crevette","tomate rouge","laitue");
  	
  	assertThat(kebabBoeuf.getIngredients()).extracting("nom")
	.containsExactly("kekab","oignon rouge","cheddar","oignon blanc","gruyere","sauce Marocaine","Boeuf du limousin");
 }


 //Vegetarien
 @Test
 public void isVegetarien_devrait_retourner_vrai_pour_kebabVegetarien() {
     assertThat(kebabVegetarien.isVegetarien()).isTrue();
  }

 @Test
 public void isVegetarien_devrait_retourner_faux_pour_kebabCarnivore() {
     assertThat(kebabCarnivore.isVegetarien()).isFalse();
 }

 @Test
 public void isVegetarien_devrait_retourner_faux_pour_kebabPoisson() {
     assertThat(kebabPoisson.isVegetarien()).isFalse();
 }
 
 @Test
 public void isVegetarien_devrait_retourner_faux_pour_kebabCrevette() {
     assertThat(kebabCrevette.isVegetarien()).isFalse();
 }

 //Pescetarien
 @Test
 public void isPescetarien_devrait_retourner_faux_pour_kebabCarnivore() {
     assertThat(kebabCarnivore.isPescetarien()).isFalse();
 }

 @Test
 public void isPescetarien_devrait_retourner_vrai_pour_kebabVegetarien() {
     assertThat(kebabVegetarien.isPescetarien()).isTrue();
 }

 @Test
 public void isPescetarien_devrait_retourner_vrai_pour_kebabPoisson() {
     assertThat(kebabPoisson.isPescetarien()).isTrue();
 }
 
 @Test
 public void isPescetarien_devrait_retourner_vrai_pour_kebabCrevette() {
     assertThat(kebabCrevette.isPescetarien()).isTrue();
 }
 
 @Test 
 public void isPescetarien_devrait_retourner_faux_pour_kebabBoeuf() {
	 assertThat(kebabCarnivore.isPescetarien()).isFalse();
 }
 
 @Test
 public void isVegetarien_devrait_retourner_faux_pour_kebabBoeuf() {
     assertThat(kebabBoeuf.isVegetarien()).isFalse();
 }
 

}
