import javax.swing.JButton;

public class Bouton extends JButton{

	private int coordx;
	private int coordy;
	private boolean clique;
	private Boolean rempli = false;
	
	public Bouton(int coordx, int coordy, boolean clique,Boolean rempli) {
		this.coordx = coordx;
		this.coordy = coordy;
		this.clique = clique;
		this.rempli = rempli;
	}
	public Boolean getRempli() {
		return rempli;
	}
	public void setRempli(Boolean rempli) {
		this.rempli = rempli;
	}
	public Bouton(int coordx, int coordy) {
		super();
		this.setCoordx(coordx);
		this.setCoordy(coordy);
	}
	public int getCoordx() {
		return coordx;
	}
	public void setCoordx(int coordx) {
		this.coordx = coordx;
	}
	public int getCoordy() {
		return coordy;
	}
	public void setCoordy(int coordy) {
		this.coordy = coordy;
	}
	public boolean isClique() {
		return clique;
	}
	public void setClique(boolean clique) {
		this.clique = clique;
	}
	
	
}
