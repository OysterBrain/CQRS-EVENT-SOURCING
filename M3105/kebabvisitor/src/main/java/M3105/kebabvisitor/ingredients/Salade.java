package M3105.kebabvisitor.ingredients;

import M3105.kebabvisitor.Kebab;

public class Salade extends Ingredient {

	public Salade(String nom, Kebab kebab) {
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

}

