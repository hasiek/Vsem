import javax.swing.*;

import java.awt.Insets;
import java.awt.event.*;

class MojPrzycisk extends JButton {
	
	private int stan;
	
	public MojPrzycisk() {
		super();
		stan = 0;
	}

	public int getStan() {
		return stan;
	}

	public void setStan(int stan) {
		this.stan = stan;
	}
	
	public void klik() {
		
		stan = (stan+1)%4;
		
	}
}

class JMojaFormatka extends JFrame implements ActionListener {

	private static final int WIDTH = 16;
	private static final int HEIGHT = 16;
	private static final int COLUMNS = 6;
	private static final int ROWS = 5;
	
	private MojPrzycisk przycisk;
	
	public JMojaFormatka(String belkaTytulowa) {
		super(belkaTytulowa);
	}

	/*public void stworz_menu() {
		belka_menu = new JMenuBar();
		menu_plik = new JMenu("Plik");
		element_menu_testuj = new JMenuItem("Testuj");
		element_menu_testuj.addActionListener(this);
		element_menu_zakoncz = new JMenuItem("Zakoncz");
		element_menu_zakoncz.addActionListener(this);
		menu_plik.add(element_menu_testuj);
		menu_plik.add(element_menu_zakoncz);
		belka_menu.add(menu_plik);
		this.setJMenuBar(belka_menu);
	}*/
	
	public void stworzPrzyciskNieaktywnyZNapisem(int x, int y, String etykieta) {
		MojPrzycisk przycisk = new MojPrzycisk();
		przycisk.setText(etykieta);
		przycisk.setBounds(x, y, WIDTH, HEIGHT);
		przycisk.setMargin(new Insets(0, 0, 0, 0));
		this.add(przycisk);
	}
	
	public void stworzPrzyciskNieaktywnyZIkona(int x, int y, String sciezka) {
		ImageIcon img = new ImageIcon(sciezka);
		MojPrzycisk przycisk = new MojPrzycisk();
		przycisk.setIcon(img);
		przycisk.setBounds(x, y, WIDTH, HEIGHT);
		przycisk.setMargin(new Insets(0, 0, 0, 0));
		this.add(przycisk);
	}
	
	public void stworzPrzyciskAktywny(int x, int y) {
		ImageIcon img = new ImageIcon("/home/hasiek/Pictures/OJP26112013/0.gif");
		MojPrzycisk przycisk = new MojPrzycisk();
		przycisk.setIcon(img);
		//przycisk.setText(String.valueOf(przycisk.get_stan()));
		przycisk.setBounds(x, y, WIDTH, HEIGHT);
		przycisk.addActionListener(this);
		this.add(przycisk);
		
	}
	
	public void rysujPrzyciski() {
		for(int i = 0; i < ROWS; i++) {
			for(int j = 0; j < COLUMNS; j++) {
				if (i == 0 && j == 0)
					stworzPrzyciskNieaktywnyZNapisem(j*WIDTH, i*HEIGHT, " ");	
				else if(i == 0 && j > 0) 
					stworzPrzyciskNieaktywnyZNapisem(j*WIDTH, i*HEIGHT, String.valueOf(j-1));
				else if(j == 0 && i > 0)
					stworzPrzyciskNieaktywnyZIkona(j*WIDTH, i*HEIGHT, "/home/hasiek/Pictures/OJP26112013/"+String.valueOf(i-1)+".gif");
				else
					stworzPrzyciskAktywny(j*WIDTH, i*HEIGHT);
			}
		}
	}

	public void naprzod() {
		setLayout(null);
		rysujPrzyciski();
		setSize(98,109);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {
		Object coKliknieto = e.getSource();
		
		// DLACZEGO Z IFEM NIE DZIAŁA?
		
		//if(coKliknieto == przycisk) {
			MojPrzycisk przycisk1 = (MojPrzycisk) coKliknieto;
			przycisk1.klik();
			// przycisk.setText(String.valueOf((przycisk.get_stan()+1)%4));
			String img = "/home/hasiek/Pictures/OJP26112013/"+String.valueOf(przycisk1.getStan())+".gif";
			przycisk1.setIcon(new ImageIcon(img));
		//}
	}
}

public class lab3 {

	public static void main(String[] args) {
		JMojaFormatka mojaformatka = new JMojaFormatka("Program testowy");
		mojaformatka.naprzod();
	}

}