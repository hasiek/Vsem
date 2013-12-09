import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.filechooser.FileNameExtensionFilter;


public class JMojaFormatka extends JFrame implements ActionListener, Serializable {
	
	private static final int WIDTH = 32;
	private static final int HEIGHT = 32;
	private static final int COLUMNS = 6;
	private static final int ROWS = 5;
	private final String wybraneRozsz = "out";
	
	private JMenuBar belkaMenu;
	private JMenu menuPlik;
	private JMenuItem elementZapisz;
	private JMenuItem elementZakoncz;
	private JMenuItem elementWczytaj;
	private JFileChooser wczytywacz;
	
	private Stan stany;
	
	public JMojaFormatka(String belkaTytulowa) {
		super(belkaTytulowa);
		stany = new Stan();
	}
	
	public void stworzMenu() {
		belkaMenu = new JMenuBar();
		menuPlik = new JMenu("Plik");
		elementZapisz = new JMenuItem("Zapisz");
		elementZapisz.addActionListener(this);
		elementWczytaj = new JMenuItem("Wczytaj");
		elementWczytaj.addActionListener(this);
		elementZakoncz = new JMenuItem("Koniec");
		elementZakoncz.addActionListener(this);
		menuPlik.add(elementZapisz);
		menuPlik.add(elementWczytaj);
		menuPlik.add(elementZakoncz);
		belkaMenu.add(menuPlik);
		this.setJMenuBar(belkaMenu);
	}
	
	public JButton przyciskBaza(int x, int y) {
		JButton przycisk = new JButton();
		przycisk.setBounds(x, y, WIDTH, HEIGHT);
		przycisk.setMargin(new Insets(0, 0, 0, 0));
		return przycisk;
	}
	
	public void stworzPrzyciskNieaktywnyZNapisem(int x, int y, String etykieta) {
		JButton przycisk = przyciskBaza(x, y);
		przycisk.setText(etykieta);
		this.add(przycisk);
	}
	
	public void stworzPrzyciskNieaktywnyZIkona(int x, int y, String sciezka) {
		ImageIcon img = new ImageIcon(sciezka);
		JButton przycisk = przyciskBaza(x, y);
		przycisk.setIcon(img);
		this.add(przycisk);
	}
	
	public void stworzPrzyciskAktywny(int x, int y) {
		int stan = stany.getStan(x/WIDTH, y/HEIGHT);
		ImageIcon img = new ImageIcon("/home/hasiek/Pictures/OJP26112013/"+String.valueOf(stan)+".gif");
		JButton przycisk = przyciskBaza(x, y);
		przycisk.setIcon(img);
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
	
	public void przerysujPrzyciski() {
		for(int i = 3; i < ROWS+2; i++) {
			for(int j = 2; j < COLUMNS+1; j++) {
				int stan = stany.getStan(j-1, i-2);
				JButton przycisk = (JButton) this.findComponentAt(j*WIDTH, i*HEIGHT);
				przycisk.setIcon(new ImageIcon("/home/hasiek/Pictures/OJP26112013/"+String.valueOf(stan)+".gif"));
			}
		}
	}
	
	public void stworz_wczytywacz() {
		wczytywacz = new JFileChooser();
		FileNameExtensionFilter filtr = new FileNameExtensionFilter("."+wybraneRozsz, wybraneRozsz);
		wczytywacz.setFileFilter(filtr);
	    wczytywacz.setDialogTitle("Wybierz plik:");
	    this.getContentPane().add(wczytywacz);
	    wczytywacz.setVisible(true);
	}
	
	public void naprzod() {
		setLayout(null);
		stworzMenu();
		rysujPrzyciski();
		stworz_wczytywacz();
		setSize(200,220);
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e) {
		Object coKliknieto = e.getSource();
		if(coKliknieto == elementZakoncz)
			System.exit(0);
		else if(coKliknieto == elementWczytaj) {
			try {
				wczytywacz.showOpenDialog(null);
				String plik = wczytywacz.getSelectedFile().getAbsolutePath();
				stany = Stan.odtworz(plik);
				przerysujPrzyciski();
			} catch (ClassNotFoundException
					| IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
		else if(coKliknieto == elementZapisz) {
			try {
				wczytywacz.showSaveDialog(null);
				String plik = wczytywacz.getSelectedFile().getAbsolutePath();
				stany.zapisz(plik);
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
		else {
			JButton przycisk = (JButton) coKliknieto;
			int x = przycisk.getBounds().x/WIDTH;
			int y = przycisk.getBounds().y/HEIGHT;
			stany.klik(x, y);
			String img = "/home/hasiek/Pictures/OJP26112013/"+String.valueOf(stany.getStan(x, y))+".gif"; 
			przycisk.setIcon(new ImageIcon(img));
		}
	}

}
