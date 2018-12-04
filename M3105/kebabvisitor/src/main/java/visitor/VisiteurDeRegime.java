package visitor;

import M3105.kebabvisitor.ingredients.*;

public interface VisiteurDeRegime {
	
	
	public boolean visit(Agneau ingredientAgneau) ;
	
	public boolean visit(Crevette ingredientCrevette) ;
	public boolean visit(Fromage ingredientFromage) ;
	public boolean visit(Oignon ingredientOignon) ;
	public boolean visit(Pain ingredientPain) ;
	public boolean visit(Salade ingredientSalade) ;
	public boolean visit(Sauce ingredientSauce) ;
	public boolean visit(Thon ingredientThon) ;
	public boolean visit(Tomate ingredientTomate) ;
	public boolean visit(Boeuf ingredientBoeuf) ;
	
}
