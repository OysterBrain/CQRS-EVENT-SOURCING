import java.awt.Button;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JComponent;

public class Joueur {
	private Bouton[][] boutons = new Bouton [10][10];
	private String nom;
	private int x;
	
	public Joueur(Bouton[][] boutons,String nom) {
		this.boutons = boutons;
		this.nom = nom;
	}

	public Bouton getBoutons(int x, int y) {
		return boutons[x][y];
	}

	public void setBoutons(Bouton[][] boutons) {
		this.boutons = boutons;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public void genererGrille() {
		x=0;
		int choix = (int) (Math.random()*(3));
		switch(choix) {
		
		case 1 :{
			//generer cuirassé (4 cases)
			for (int i=4;i<7;i ++) {
				this.boutons[2][i] = new Bouton(2,i);
				this.boutons[2][i].setBackground(Color.BLUE);
				this.boutons[2][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[2][i].setRempli(true);
				this.boutons[2][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.GRAY);
						System.out.println("Vous avez touché le cuirasse");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer porteavion (5 cases)
			for (int i=2;i<7;i ++) {
				this.boutons[i][3] = new Bouton(2,i);
				this.boutons[i][3].setBackground(Color.BLUE);
				this.boutons[i][3].setPreferredSize(new Dimension(40, 40));
				this.boutons[i][3].setRempli(true);
				this.boutons[i][3].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.GREEN);
						System.out.println("Vous avez touché le porte avion");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer contre-torpilleur (3 cases)
			for (int i=2;i<5;i ++) {
				this.boutons[6][i] = new Bouton(2,i);
				this.boutons[6][i].setBackground(Color.BLUE);
				this.boutons[6][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[6][i].setRempli(true);
				this.boutons[6][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.PINK);
						System.out.println("Vous avez touché le contre-torpilleur");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer sous marins (2 cases)
			for (int i=2;i<4;i ++) {
				this.boutons[8][i] = new Bouton(2,i);
				this.boutons[8][i].setBackground(Color.BLUE);
				this.boutons[8][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[8][i].setRempli(true);
				this.boutons[8][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.YELLOW);
						System.out.println("Vous avez touché le porte avion");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer torpilleur (1 cases)
			for (int i=2;i<3;i ++) {
				this.boutons[9][i] = new Bouton(2,i);
				this.boutons[9][i].setBackground(Color.BLUE);
				this.boutons[9][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[9][i].setRempli(true);
				this.boutons[9][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.YELLOW);
						System.out.println("Vous avez touché le porte avion");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			for (int i = 0; i<10; i++) {
				for (int j = 0;j<10;j++) {
					if(this.boutons[i][j] == null) {
						this.boutons[i][j] = new Bouton(i,j);
						this.boutons[i][j].setBackground(Color.BLUE);
					}
				}
			}
			break;
		}
		case 2:{
			//generer cuirassé (4 cases)
			for (int i=5;i<10;i ++) {
				this.boutons[9][i] = new Bouton(2,i);
				this.boutons[9][i].setBackground(Color.BLUE);
				this.boutons[9][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[9][i].setRempli(true);
				this.boutons[9][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.GRAY);
						System.out.println("Vous avez touché le cuirasse");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer porteavion (5 cases)
			for (int i=2;i<7;i ++) {
				this.boutons[i][1] = new Bouton(2,i);
				this.boutons[i][1].setBackground(Color.BLUE);
				this.boutons[i][1].setPreferredSize(new Dimension(40, 40));
				this.boutons[i][1].setRempli(true);
				this.boutons[i][1].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.GREEN);
						System.out.println("Vous avez touché le porte avion");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer contre-torpilleur (3 cases)
			for (int i=3;i<6;i ++) {
				this.boutons[4][i] = new Bouton(2,i);
				this.boutons[4][i].setBackground(Color.BLUE);
				this.boutons[4][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[4][i].setRempli(true);
				this.boutons[4][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.PINK);
						System.out.println("Vous avez touché le contre-torpilleur");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer sous marins (2 cases)
			for (int i=8;i<10;i ++) {
				this.boutons[6][i] = new Bouton(2,i);
				this.boutons[6][i].setBackground(Color.BLUE);
				this.boutons[6][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[6][i].setRempli(true);
				this.boutons[6][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.YELLOW);
						System.out.println("Vous avez touché le porte avion");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer torpilleur (1 cases)
			for (int i=2;i<3;i ++) {
				this.boutons[9][i] = new Bouton(2,i);
				this.boutons[9][i].setBackground(Color.BLUE);
				this.boutons[9][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[9][i].setRempli(true);
				this.boutons[9][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.YELLOW);
						System.out.println("Vous avez touché le porte avion");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			for (int i = 0; i<10; i++) {
				for (int j = 0;j<10;j++) {
					if(this.boutons[i][j] == null) {
						this.boutons[i][j] = new Bouton(i,j);
						this.boutons[i][j].setBackground(Color.BLUE);
					}
				}
			}
			break;
		}
		case 3:{
			//generer cuirassé (4 cases)
			for (int i=2;i<6;i ++) {
				this.boutons[9][i] = new Bouton(2,i);
				this.boutons[9][i].setBackground(Color.BLUE);
				this.boutons[9][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[9][i].setRempli(true);
				this.boutons[9][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.GRAY);
						System.out.println("Vous avez touché le cuirasse");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer porteavion (5 cases)
			for (int i=2;i<7;i ++) {
				this.boutons[i][9] = new Bouton(2,i);
				this.boutons[i][9].setBackground(Color.BLUE);
				this.boutons[i][9].setPreferredSize(new Dimension(40, 40));
				this.boutons[i][9].setRempli(true);
				this.boutons[i][9].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.GREEN);
						System.out.println("Vous avez touché le porte avion");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer contre-torpilleur (3 cases)
			for (int i=2;i<5;i ++) {
				this.boutons[3][i] = new Bouton(2,i);
				this.boutons[3][i].setBackground(Color.BLUE);
				this.boutons[3][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[3][i].setRempli(true);
				this.boutons[3][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.PINK);
						System.out.println("Vous avez touché le contre-torpilleur");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer sous marins (2 cases)
			for (int i=2;i<4;i ++) {
				this.boutons[i][5] = new Bouton(2,i);
				this.boutons[i][5].setBackground(Color.BLUE);
				this.boutons[i][5].setPreferredSize(new Dimension(40, 40));
				this.boutons[i][5].setRempli(true);
				this.boutons[i][5].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.YELLOW);
						System.out.println("Vous avez touché le porte avion");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			//generer torpilleur (1 cases)
			for (int i=1;i<2;i ++) {
				this.boutons[1][i] = new Bouton(2,i);
				this.boutons[1][i].setBackground(Color.BLUE);
				this.boutons[1][i].setPreferredSize(new Dimension(40, 40));
				this.boutons[1][i].setRempli(true);
				this.boutons[1][i].addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						Object o = e.getSource();
						((JComponent) o).setBackground(Color.YELLOW);
						System.out.println("Vous avez touché le porte avion");
						x++;
						if(x==15) {
							System.out.println("gagné");
						}
					}
				});
			}
			for (int i = 0; i<10; i++) {
				for (int j = 0;j<10;j++) {
					if(this.boutons[i][j] == null) {
						this.boutons[i][j] = new Bouton(i,j);
						this.boutons[i][j].setBackground(Color.BLUE);
					}
				}
			}
			break;
			
		}
		}
		
	}

}
