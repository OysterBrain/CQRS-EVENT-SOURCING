package M3105.kebabvisitor.ingredients;

import java.util.List;

import M3105.kebabvisitor.Kebab;

public class Boeuf extends Ingredient {
	
	
	 public Boeuf(String nom, Kebab kebab) {
	        super(nom,kebab);
	    }
	  
	    @Override
	    public boolean isVegetarien() {
	        return false;
	    }

	    @Override
	    public boolean isPescetarien() {
	        return false;
	    }

	
}