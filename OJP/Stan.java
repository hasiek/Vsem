import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;


public class Stan implements Serializable {
	
	private EnumStanow stany[][] = new EnumStanow[5][6];
	
	public Stan() {
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 6; j++) {
				stany[i][j] = EnumStanow.PUSTY_CZARNY;
			}
		}
		
	}

	public int getStan(int x, int y) {
		return stany[y][x].stan;
	}

	public void setStan(int stany, int x, int y) {
		EnumStanow wartosc;
		if(stany == 0)
			wartosc = EnumStanow.PUSTY_CZARNY;
		else if(stany == 1)
			wartosc = EnumStanow.PUSTY_BIALY;
		else if(stany == 2)
			wartosc = EnumStanow.KROPKA_CZARNA;
		else
			wartosc = EnumStanow.KROPKA_BIALA;
		this.stany[y][x] = wartosc;
	}
	
	public void klik(int x, int y) {
		int stan = stany[y][x].stan;
		stan = (stan+1) % 4;
		setStan(stan, x, y);
		
	}
	
	public void zapisz(String sciezka) throws IOException {
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(sciezka));
		out.writeObject(this);
		out.close();
	}
	
	public static Stan odtworz(String sciezka) throws IOException, FileNotFoundException, ClassNotFoundException {
		ObjectInputStream in = new ObjectInputStream(new FileInputStream(sciezka));
		Stan odczytany = (Stan) in.readObject();
		in.close();
		return odczytany;
	}

}
