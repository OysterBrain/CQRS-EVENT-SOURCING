import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.EventObject;

import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JPanel;

public class test extends JPanel {
	private Bouton[][] boutons = new Bouton[10][10];
	private JPanel  panel;
	private Joueur joueur1 = new Joueur(boutons,"c");
	private int i,j;
	public test () {
		
		
		joueur1.genererGrille();
		panel = new JPanel(new GridLayout(10,10));
		
		
		
		for( i = 0;i<10;i++) {
			for (j =0;j<10;j++) {
				panel.add(joueur1.getBoutons(i,j));
				}
				
			}		
		this.add(panel);	
		
	}
		
	
	
}
