package M3105.kebabvisitor;

import java.util.LinkedList;
import java.util.List;

import M3105.kebabvisitor.ingredients.Ingredient;

public class Assiette implements Kebab{
	

	public List<Ingredient> getIngredients() {
		return new LinkedList<>();
	}

	public boolean isVegetarien() {
		return true;
	}

	public boolean isPescetarien() {
		return true;
	}

}

