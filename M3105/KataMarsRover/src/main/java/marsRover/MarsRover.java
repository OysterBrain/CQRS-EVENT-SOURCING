package marsRover;

public class MarsRover {

	private int x,y;

	private String direction;

	public MarsRover(int x , int y , String direction) {

		this.x=x;
		this.y=y;
		this.direction=direction;
	}

	public void seMouvoirAvancerReculer(String[] commandes) {

		int tailleCommande = commandes.length;

		for (int i=0 ; i< tailleCommande;i++) {

			if(this.direction=="N" || this.direction=="S") {

				if(commandes[i] == "f") {
					if(this.y<=99) {
						this.y =+ 1;

					}else {
						this.y =0;
					}
				}
				else if(commandes[i] == "b") {
					if(this.y>=1) {
						this.y =- 1;

					}else {
						this.y =100;
					}
				}

			}
			else {

				if(commandes[i] == "f") {
					if(this.x<=99) {
						this.x=+1;
					}else {
						this.x=0;
					}
				}
				else if(commandes[i] == "b") {
					if(this.x>=1) {
						this.x=- 1;

					}else {
						this.x=100;
					}
				}
			}
		}

	}

	public void seMouvoirDroiteGauche(String[] commandes) {

		int tailleCommande = commandes.length;
		String[] directionVerif = {"N","E","S","W"};
		int rang=0;

		for (int i=0 ; i<tailleCommande ; i++) {
			if(commandes[i]=="l") {
				rang=-rang;
				if(rang == 0) {
					rang=3;
				}
				this.direction=directionVerif[rang];

			}
			if(commandes[i] =="r") {
				rang=+rang;
				if(rang == 3) {
					rang=0;
				}
				this.direction=directionVerif[rang];

			}
		}

	}


}




