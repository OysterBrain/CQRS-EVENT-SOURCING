import java.awt.BorderLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class LogJoueur extends JFrame  implements ActionListener{
	
	 	private JTextField jtfJoueur1;
	    private JTextField jtfJoueur2;
	    private JLabel jlJoueur1;
	    private JLabel jlJoueur2;
	    private JButton btnAnnuler;
	    private JLabel jlError;
	    private JPanel jpInfos;
	    private JButton btnCommencer;
	   
	    



	public LogJoueur() {
	
		this.setSize(800,800);
		this.setTitle("Bataille Navale");
		this.setVisible(true);
		
		jtfJoueur1 = new JTextField();
		jtfJoueur2 = new JTextField();
		jlJoueur1 = new JLabel("nom Joueur1:");
		jlJoueur2 = new JLabel("nom Joueur2:");
		btnCommencer = new JButton("Commencer");
		btnAnnuler = new JButton("Annuler");
		jlError = new JLabel("");
		jpInfos = new JPanel();
		
		jlError.setHorizontalAlignment(JLabel.CENTER);
	
		jpInfos.setLayout(new GridLayout(3,2));
		
		jpInfos.add(jlJoueur1);
		jpInfos.add(jtfJoueur1);
		jpInfos.add(jlJoueur2);
		jpInfos.add(jtfJoueur2);
		jpInfos.add(btnCommencer);
		jpInfos.add(btnAnnuler);
		
		this.setLayout(new BorderLayout());
		
		this.getContentPane().add(jpInfos,BorderLayout.CENTER);
		this.getContentPane().add(jlError, BorderLayout.SOUTH);
		
		
		this.setVisible(true);
		
		
		
		
		
		btnCommencer.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e) {
				
				
				if(jtfJoueur1.getText().equals("")&&jtfJoueur2.getText().equals("")) {
							
					jlError.setText("Entrer le nom des Joueurs");
						
				}
						
				else if(jtfJoueur1.getText().equals("")) {
					jlError.setText("Entrer le nom du Joueur 1");
						
				}
				else if(jtfJoueur2.getText().equals("")) {
					
					jlError.setText("Entrer le nom du Joueur 2 ");
						
				}
					
				if(jtfJoueur1.getText().length()>=2 && jtfJoueur2.getText().length()>=2) {
					remove(jlError);
					remove(jpInfos);
					
					getContentPane().add(new JpTourJoueur(jtfJoueur1.getText(),jtfJoueur2.getText()));
					revalidate();
				
				
				}
				
				
				
				
		}
	});
		
		btnAnnuler.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				
				System.exit(0);
				
			}
			
		});
		
		
		
	
		
	}
		
	
	public static void main (String [] args) {
		new LogJoueur();
	}


	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
	}


	

}
