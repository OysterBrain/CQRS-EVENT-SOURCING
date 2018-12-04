package visitor;

import M3105.kebabvisitor.ingredients.*;

public class VisiteurDeRegimeVegetarien implements VisiteurDeRegime{

	@Override
	public boolean visit(Agneau ingredientAgneau) {
		
		return false;
	}

	@Override
	public boolean visit(Crevette ingredientCrevette) {
	
		return false;
	}

	@Override
	public boolean visit(Fromage ingredientFromage) {
		
		return true;
	}

	@Override
	public boolean visit(Oignon ingredientOignon) {
	
		return true;
	}

	@Override
	public boolean visit(Pain ingredientPain) {
		
		return true;
	}

	@Override
	public boolean visit(Salade ingredientSalade) {
		
		return true;
	}

	@Override
	public boolean visit(Sauce ingredientSauce) {
		
		return true;
	}

	@Override
	public boolean visit(Thon ingredientThon) {
	
		return false;
	}

	@Override
	public boolean visit(Tomate ingredientTomate) {
	
		return true;
	}

	@Override
	public boolean visit(Boeuf ingredientBoeuf) {
		
		return false;
	}
	
	
	
	
	
	
	
	

}
