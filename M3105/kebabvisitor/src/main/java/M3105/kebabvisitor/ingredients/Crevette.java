package M3105.kebabvisitor.ingredients;

import M3105.kebabvisitor.Kebab;
import visitor.VisiteurDeRegime;

public class Crevette extends Ingredient {

    public Crevette(String nom, Kebab kebab) {
        super(nom,kebab);
  
    }
    
    @Override
    public boolean isVegetarien() {
        return false;
    }

    @Override
    public boolean isPescetarien() {
        return super.isPescetarien();
        /* utilisation de super pour respecter la spec du pattern
		ce qui Ã©quivaut en fait Ã  faire appel au kebab interne
		c-a-d que l'on pourrait Ã©crire de maniÃ¨re plus lisible : return this.kebab.isVegetarien();
        Remarquez que, dans le contexte de ce projet, cette mÃ©thode n'ajoute pas de nouveau comportement : 
        elle ne fait rien d'autre que d'appeler la mÃ©thode de la superclasse.
        Donc, dans le contexte de ce projet, si on voulait optimiser l'Ã©criture du programme, 
        ce ne serait mÃªme pas la peine d'Ã©crire (de redÃ©finir) dans cette classe isPescetarien
        car son comportement n'apporte rien de nouveau ... ;-) */
    }

	@Override
	public void accept(VisiteurDeRegime visiteur) {
		visiteur.visit(this);
		
	}
    
  
}
