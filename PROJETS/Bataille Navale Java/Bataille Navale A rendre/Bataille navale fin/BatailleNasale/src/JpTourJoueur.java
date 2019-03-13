import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class JpTourJoueur extends JPanel{
	public JLabel nomJoueur; 
	public JLabel nomJoueur2; 
	public JButton tourSuivant;
	private JLabel tours;
	public test grille1;
	public test grille2;
	private Joueur joueur1;
	private boolean tour = false;
	
	public JpTourJoueur(String nomJ ,String nomJ2) {
		nomJoueur = new JLabel(nomJ);
		nomJoueur2 = new JLabel(nomJ2);
		tours = new JLabel("Tour : ");
		tourSuivant = new JButton("Tour Suivant");
		grille1 = new test();
		grille2 = new test();
		this.setLayout(new BorderLayout());
		this.tourSuivant.setPreferredSize(new Dimension(40, 40));
		this.add(nomJoueur,BorderLayout.WEST);
		this.add(tours, BorderLayout.EAST);
		
		this.add(grille1,BorderLayout.CENTER);
		this.add(tourSuivant, BorderLayout.SOUTH);
		
		this.tourSuivant.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				
				if(tour) {
					
					removeAll();
					
					repaint();
					
					revalidate();
					
					add(nomJoueur2,BorderLayout.WEST);
					add(grille2,BorderLayout.CENTER);
					add(tourSuivant, BorderLayout.SOUTH);
					
					tour = false;
				}
				else {
					removeAll();
					repaint();
					revalidate();
					add(nomJoueur,BorderLayout.WEST);
					add(grille1,BorderLayout.CENTER);
					add(tourSuivant, BorderLayout.SOUTH);
					tour = true;
				}
				
			}
		});
		
	}

	
}
