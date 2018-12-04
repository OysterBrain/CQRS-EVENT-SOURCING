package M3105.kebabvisitor;

import java.util.List;

import M3105.kebabvisitor.ingredients.Ingredient;

public interface Kebab {
	
	List<Ingredient> getIngredients();
	boolean isVegetarien();
	boolean isPescetarien();


}
