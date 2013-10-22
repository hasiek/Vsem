#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Man {
private:
	static bool is_a_mammal;
	const string pesel;
	string name;
	int age;
	string marital_status;
	string hometown;
	
public:
	Man();
	// Man(string name_to_set, int age_to_set, string status, string hometown_to_set);
	Man(string pesel_to_set, string name_to_set, int age_to_set, string status = "N/A", string hometown_to_set = "N/A");
	
	string get_pesel() const;
	
	string get_name() const;
	void set_name(const string& name_to_set);
	
	int get_age() const;
	void set_age(int age_to_set);
	
	string get_status() const;
	void set_status(const string& status);
	
	string get_hometown() const;
	void set_hometown(const string& hometown_to_set);
	
	static bool get_is_a_mammal();
	
	bool is_adult() const;
	void birthday(int years = 1);
	int will_retire_in() const;
	string info() const;
	void serialize(ostream& save);
	static Man deserialize(istream& save);
	
};

class Student : public Man {
private:
	string university;
	int year_of_studies;
	bool if_public_school;
	Man promoter;
public:
	Student();
	Student(string pesel_to_set, string name_to_set, int age_to_set, string status, string hometown_to_set, string uni, int year, bool if_public, string promoter_pesel, string promoter_name, int promoter_age);
	
	string get_university() const;
	void set_university(const string& uni);
	
	int get_year() const;
	void set_year(int year);
	
	bool get_public() const;
	void set_public(bool if_public);
	
	Man get_promoter() const;
	void set_promoter(const string& pesel_to_set, const string& name_to_set, int age_to_set);
	
	int finishing_year() const; // function returns in how many years student will graduate
	double students_discount(int ticket_price) const;
	string is_working(bool is_he) const;
	string info() const;
	
};

class Pensioner : public Man {
private:
	int pension;
	int grandchildren;
public:
	Pensioner();
	Pensioner(string pesel_to_set, string name_to_set, int age_to_set, string status, string hometown_to_set, int pension_to_set, int how_many_grandchildren);
		
	int get_pension() const;
	void set_pension(int pension_to_set);
	
	int get_grandchildren() const;
	void set_grandchildren(int how_many_grandchildren);
	
	bool if_conjugal_discount(const string& marital_status) const;
	double count_discount(bool if_discount, int pension) const;
	double raise_pension(int pension);
	string info() const;
	
};

bool Man::is_a_mammal = true;

Man::Man():
	pesel("N/A"),
	name("John Doe"),
	age(30),
	marital_status("N/A"),
	hometown("N/A"){};

Man::Man(string pesel_to_set, string name_to_set, int age_to_set, string status, string hometown_to_set):
	pesel(pesel_to_set),
	name(name_to_set),
	age(age_to_set),
	marital_status(status),
	hometown(hometown_to_set){};
	
string Man::get_pesel() const {

	return pesel;
	
}

string Man::get_name() const {
	
	return name;
	
}

void Man::set_name(const string& name_to_set) {
	
	name = name_to_set;
	
}

int Man::get_age() const {
	
	return age;
	
}

void Man::set_age(int age_to_set) {
	
	age = age_to_set;
	
}

string Man::get_status() const {
	
	return marital_status;
	
}

void Man::set_status(const string& status) {
	
	marital_status = status;
	
}

string Man::get_hometown() const {
	
	return hometown;
	
}

void Man::set_hometown(const string& hometown_to_set) {
	
	hometown = hometown_to_set;
	
}

bool Man::get_is_a_mammal() {
	
	return is_a_mammal;
	
}

bool Man::is_adult() const {
	
	return age >= 18;
}

void Man::birthday(int years) {
	
	age += years;
	
}

int Man::will_retire_in() const {
	
	return 65 - age;
	
}

string Man::info() const{
	
	stringstream stream;
	stream << "INFO: " << "IS A MAMMAL: " << ((is_a_mammal) ? "yes" : "false") << ", PESEL: " << pesel << ", NAME: " << name << ", AGE: " << age << ", MARITAL STATUS: " << marital_status << ", HOMETOWN: " << hometown;
	return stream.str();
	
}

void Man::serialize(ostream& save) {
	
	save << ((is_a_mammal) ? "true" : "false") << '\n';
	save << pesel << '\n';
	save << name << '\n';
	save << age << '\n';
	save << marital_status << '\n';
	save << hometown << '\n';
	
}

Man Man::deserialize(istream& save) {
	
	string garbage;
	
	string is_mammal_s;
	getline(save, is_mammal_s);
	
	// Testing couts in comments

	string pesel;
	getline(save, pesel);
	// cout << pesel << endl;

	string name;
	getline(save, name);
	// cout << name << endl;

	string age_s;
	getline(save, age_s);

	int age;
	istringstream temp(age_s);
	temp >> age; 
	// cout << age << endl;
	
	string marital_status;
	getline(save, marital_status);
	// cout << marital_status << endl;

	string hometown;
	getline(save, hometown);
	// cout << hometown << endl;
	
	Man deserialized = Man(pesel, name, age, marital_status, hometown);
	return deserialized;
}

Student::Student():
	Man(),
	university("N/A"),
	year_of_studies(0),
	if_public_school(true),
	promoter(){};

Student::Student(string pesel_to_set, string name_to_set, int age_to_set, string status, string hometown_to_set, string uni, int year, bool if_public, string promoter_pesel, string promoter_name, int promoter_age):
		Man(pesel_to_set, name_to_set, age_to_set, status, hometown_to_set),
		university(uni),
		year_of_studies(year),
		if_public_school(if_public),
		promoter(promoter_pesel, promoter_name, promoter_age){};

string Student::get_university() const {
	
	return university;
	
}

void Student::set_university(const string& uni) {
	
	university = uni;
	
}

int Student::get_year() const {
	
	return year_of_studies;
	
}

void Student::set_year(int year) {
	
	year_of_studies = year;
	
}

bool Student::get_public() const {
	
	return if_public_school;
	
}

void Student::set_public(bool if_public) {
	
	if_public_school = if_public;
	
}

Man Student::get_promoter() const {
		
		return promoter;
		
}

void Student::set_promoter(const string& pesel_to_set, const string& name_to_set, int age_to_set) {
	
	promoter.set_name(name_to_set);
	promoter.set_age(age_to_set);
	
}

int Student::finishing_year() const {
	
	return 5 - year_of_studies;
	
}

double Student::students_discount(int ticket_price) const {
	
	return ticket_price * 0.5;
	
}

string Student::is_working(bool is_he) const {
	
	if (is_he == true) 
		return "Working student";
	else
		return "Non-working student";

}

string Student::info() const {
	
	stringstream stream;
	stream << ", UNIVERSITY: " << university << ", YEAR OF STUDIES: " << year_of_studies << ", IS IN PUBLIC SCHOOL: " << ((if_public_school) ? "Yes" : "No") << ", PROMOTER " << promoter.info() << endl;
	return (Man::info()) + stream.str();
}

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
	
	pension = pension_to_set;
	
}

int Pensioner::get_grandchildren() const {
	
	return grandchildren;
	
}

void Pensioner::set_grandchildren(int how_many_grandchildren) {
	
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
	return (Man::info()) + stream.str();
	
}

int main() {
	
	Man hairdresser("73013010295", "Mary", 30, "married", "New York");
	Student lawyer2b = Student("93020211964", "John", 20, "single", "Cambridge", "Cambridge University", 3, true, "58041267987", "Mark", 55);
	Pensioner johns_granny("31121267854", "Else", 72, "widow", "Yorkshire", 2500, 4);
	Man unknown = Man();
	const Man android = Man();
	
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
	
	filebuf fb;
	fb.open("serial.txt", ios::out);
	ostream save(&fb);
	hairdresser.serialize(save);
	fb.close();
	
	filebuf fb1;
	fb1.open("serial.txt", ios::in);
	istream out(&fb1);
	Man hairdresser_clone = Man::deserialize(out);
	
	cout << hairdresser_clone.info() << endl;
	
	return 0;
	
}
