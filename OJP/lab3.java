import javax.swing.*;

import java.awt.Insets;
import java.awt.event.*;

class moj_przycisk extends JButton {
	
	private int stan;
	
	public moj_przycisk() {
		super();
		stan = 0;
	}

	public int get_stan() {
		return stan;
	}

	public void set_stan(int stan) {
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
	
	private moj_przycisk przycisk;
	
	public JMojaFormatka(String belka_tytulowa) {
		super(belka_tytulowa);
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
	
	public void stworz_przycisk_nieaktywny_z_napisem(int x, int y, String etykieta) {
		moj_przycisk przycisk = new moj_przycisk();
		przycisk.setText(etykieta);
		przycisk.setBounds(x, y, WIDTH, HEIGHT);
		przycisk.setMargin(new Insets(0, 0, 0, 0));
		this.add(przycisk);
	}
	
	public void stworz_przycisk_nieaktywny_z_ikona(int x, int y, String sciezka) {
		ImageIcon img = new ImageIcon(sciezka);
		moj_przycisk przycisk = new moj_przycisk();
		przycisk.setIcon(img);
		przycisk.setBounds(x, y, WIDTH, HEIGHT);
		przycisk.setMargin(new Insets(0, 0, 0, 0));
		this.add(przycisk);
	}
	
	public void stworz_przycisk_aktywny(int x, int y) {
		ImageIcon img = new ImageIcon("/home/hasiek/Pictures/OJP26112013/0.gif");
		moj_przycisk przycisk = new moj_przycisk();
		przycisk.setIcon(img);
		//przycisk.setText(String.valueOf(przycisk.get_stan()));
		przycisk.setBounds(x, y, WIDTH, HEIGHT);
		przycisk.addActionListener(this);
		this.add(przycisk);
		
	}
	
	public void rysuj_przyciski() {
		for(int i = 0; i < ROWS; i++) {
			for(int j = 0; j < COLUMNS; j++) {
				if (i == 0 && j == 0)
					stworz_przycisk_nieaktywny_z_napisem(j*WIDTH, i*HEIGHT, " ");	
				else if(i == 0 && j > 0) 
					stworz_przycisk_nieaktywny_z_napisem(j*WIDTH, i*HEIGHT, String.valueOf(j-1));
				else if(j == 0 && i > 0)
					stworz_przycisk_nieaktywny_z_ikona(j*WIDTH, i*HEIGHT, "/home/hasiek/Pictures/OJP26112013/"+String.valueOf(i-1)+".gif");
				else
					stworz_przycisk_aktywny(j*WIDTH, i*HEIGHT);
			}
		}
	}

	public void naprzod() {
		setLayout(null);
		rysuj_przyciski();
		setSize(98,109);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {
		Object co_kliknieto = e.getSource();
		
		// DLACZEGO Z IFEM NIE DZIAŁA?
		
		//if(co_kliknieto == przycisk) {
			moj_przycisk przycisk1 = (moj_przycisk) co_kliknieto;
			przycisk1.klik();
			// przycisk.setText(String.valueOf((przycisk.get_stan()+1)%4));
			String img = "/home/hasiek/Pictures/OJP26112013/"+String.valueOf(przycisk1.get_stan())+".gif";
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