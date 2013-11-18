#include "man.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;




Pensioner::Pensioner():
	Man(),
	pension(0),
	grandchildren(0){};

Pensioner::Pensioner(string pesel_to_set, string name_to_set, int age_to_set, string status, string hometown_to_set, int pension_to_set, int how_many_grandchildren):
		Man(pesel_to_set, name_to_set, age_to_set, status, hometown_to_set),
		pension(pension_to_set),
		grandchildren(how_many_grandchildren){};

int Pensioner::get_pension() const {
	
	return pension;
	
}

void Pensioner::set_pension(int pension_to_set) {
	
	if(pension_to_set < 0)
		throw Exception("It is a bit too low, don't you think? (negative pension error)");
	pension = pension_to_set;
	
}

int Pensioner::get_grandchildren() const {
	
	return grandchildren;
	
}

void Pensioner::set_grandchildren(int how_many_grandchildren) {
	
	if (how_many_grandchildren < 0)
	throw Exception("The number of grandchildren can't be negative.");
	grandchildren = how_many_grandchildren;
	
}

bool Pensioner::if_conjugal_discount(const string& marital_status) const {
	
	return marital_status == "married";
		
}

double Pensioner::count_discount(bool if_discount, int pension) const {
	
	if (if_discount == true)
		return pension * 0.15;
	else
		return 0.0;
		
}

double Pensioner::raise_pension(int pension) {
	
	return pension += pension * 0.1;
	
}

string Pensioner::info() const {
	
	stringstream stream;
	stream << ", PENSION: " << pension << ", GRANDCHILDREN: " << grandchildren << endl;
	string to_be_returned = (Man::info()) + stream.str();
	string* check = &to_be_returned;
	if (!check)
		throw Exception("Couldn't get the info about the Pensioner.");
	return to_be_returned;
	
}

void Pensioner::serialize(ostream& save) const {
	
	Man::serialize(save);
	save << pension << '\n';
	save << grandchildren << '\n';
	if(!save)
		throw Exception("Serialisation issue in Pensioner class.");
	
}

Pensioner Pensioner::deserialize(istream& save) {
	
	Man pensioner = Man::deserialize(save);
	
	string pension_s;
	getline(save, pension_s);
	
	int pension;
	istringstream temp(pension_s);
	temp >> pension; 
	
	string grandchildren_s;
	getline(save, grandchildren_s);
	
	int grandchildren;
	istringstream temp1(grandchildren_s);
	temp1 >> grandchildren; 
	
	if(!save)
		throw Exception("Couldn't deserialize Pensioner object.");
		
	Pensioner deserialized = Pensioner(pensioner.get_pesel(), pensioner.get_name(), pensioner.get_age(), pensioner.get_status(), pensioner.get_hometown(), pension, grandchildren);
	return deserialized;
	
}

int main() {
	
	try {
		Man hairdresser("73013010295", "Mary", 30, "married", "New York");
		Student lawyer2b = Student("93020211964", "John", 20, "single", "Cambridge", "Cambridge University", 3, true, "58041267987", "Mark", 55);
		Pensioner johns_granny("31121267854", "Else", 72, "widow", "Yorkshire", 2500, 4);
		Man unknown = Man();
		const Man android = Man();
		lawyer2b.set_age(-33);
	}
	catch(Exception& e) {
			cout << e.get_reason() << endl;
	}
	
	/* cout << "John's grandmother is " << johns_granny.get_name() << '.' << endl;
	cout << "John's promoter is " << lawyer2b.get_promoter().get_name() << '.' << endl;
	hairdresser.birthday(5);
	cout << "Mary is " << hairdresser.get_age() << " years old." << endl;
	cout << "Else lived in " << johns_granny.get_hometown() << '.' << endl;
	johns_granny.set_hometown("London");
	cout << "Now Else lives in " << johns_granny.get_hometown() << '.' << endl;
	cout << "Unknown man is " << unknown.get_name() << '.' << endl;
	
	cout << "Android's name is " << android.get_name() << '.' << endl;
	// android.set_name("Antoni"); - an error occurs while trying to use this function
	cout << johns_granny.info() << endl; */
	
	/* filebuf fb;
	fb.open("serial.txt", ios::out);
	ostream save(&fb);
	lawyer2b.serialize(save);
	fb.close();
	cout << lawyer2b.info() << endl;
	
	filebuf fb1;
	fb1.open("serial.txt", ios::in);
	istream out(&fb1);
	Student clone = Student::deserialize(out);
	
	cout << clone.info() << endl; */
	
	return 0;
	
}
