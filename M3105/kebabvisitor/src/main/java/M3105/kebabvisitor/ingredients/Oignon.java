package M3105.kebabvisitor.ingredients;

import M3105.kebabvisitor.Kebab;
import visitor.VisiteurDeRegime;

public class Oignon extends Ingredient {

	public Oignon(String nom, Kebab kebab) {
		super(nom, kebab);
	}

	@Override
	public boolean isVegetarien() {
		return super.isVegetarien();
	}

	@Override
	public boolean isPescetarien() {
		return super.isPescetarien();
	}

	@Override
	public void accept(VisiteurDeRegime visiteur) {
		visiteur.visit(this);
		
	}

}
