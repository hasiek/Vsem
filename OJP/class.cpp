#include <iostream>

using namespace std;

class Man {
private:
	string name;
	int age;
	string marital_status;
	string hometown;
	
public:
	Man();
	// Man(string name_to_set, int age_to_set, string status, string hometown_to_set);
	Man(string name_to_set, int age_to_set, string status = "N/A", string hometown_to_set = "N/A");
	
	string get_name();
	void set_name(string name_to_set);
	
	int get_age();
	void set_age(int age_to_set);
	
	string get_status();
	void set_status(string status);
	
	string get_hometown();
	void set_hometown(string hometown_to_set);
	
	bool is_adult();
	void birthday(int years = 1);
	int will_retire_in();
	
};

class Student : public Man {
private:
	string university;
	int year_of_studies;
	bool if_public_school;
	Man promoter;
public:
	Student();
	Student(string name_to_set, int age_to_set, string status, string hometown_to_set, string uni, int year, bool if_public, string promoter_name, int promoter_age);
	
	string get_university();
	void set_university(string uni);
	
	int get_year();
	void set_year(int year);
	
	bool get_public();
	void set_public(bool if_public);
	
	Man get_promoter();
	void set_promoter(string name_to_set, int age_to_set);
	
	int finishing_year(); // function returns in how many years student will graduate
	double students_discount(int ticket_price);
	string is_working(bool is_he);
	
};

class Pensioner : public Man {
private:
	int pension;
	int grandchildren;
public:
	Pensioner();
	Pensioner(string name_to_set, int age_to_set, string status, string hometown_to_set, int pension_to_set, int how_many_grandchildren);
		
	int get_pension();
	void set_pension(int pension_to_set);
	
	int get_grandchildren();
	void set_grandchildren(int how_many_grandchildren);
	
	bool if_conjugal_discount(string marital_status);
	double count_discount(bool if_discount, int pension);
	double raise_pension(int pension);
	
};

Man::Man() {
	
	name = "John Doe";
	age = 30;
	marital_status = "N/A";
	hometown = "N/A";
	
}

Man::Man(string name_to_set, int age_to_set, string status, string hometown_to_set) {
	
	name = name_to_set;
	age = age_to_set;
	marital_status = status;
	hometown = hometown_to_set;
	
}

string Man::get_name() {
	
	return name;
	
}

void Man::set_name(string name_to_set) {
	
	name = name_to_set;
	
}

int Man::get_age() {
	
	return age;
	
}

void Man::set_age(int age_to_set) {
	
	age = age_to_set;
	
}

string Man::get_status() {
	
	return marital_status;
	
}

void Man::set_status(string status) {
	
	marital_status = status;
	
}

string Man::get_hometown() {
	
	return hometown;
	
}

void Man::set_hometown(string hometown_to_set) {
	
	hometown = hometown_to_set;
	
}

bool Man::is_adult() {
	
	return age >= 18;
}

void Man::birthday(int years) {
	
	age += years;
	
}

int Man::will_retire_in() {
	
	return 65 - age;
	
}

Student::Student() {
	
	university = "N/A";
	year_of_studies = 0;
	if_public_school = true;
	promoter = Man();
	
}

Student::Student(string name_to_set, int age_to_set, string status, string hometown_to_set, string uni, int year, bool if_public, string promoter_name, int promoter_age):
		Man(name_to_set, age_to_set, status, hometown_to_set),
		university(uni),
		year_of_studies(year),
		if_public_school(if_public),
		promoter(promoter_name, promoter_age){};

string Student::get_university() {
	
	return university;
	
}

void Student::set_university(string uni) {
	
	university = uni;
	
}

int Student::get_year() {
	
	return year_of_studies;
	
}

void Student::set_year(int year) {
	
	year_of_studies = year;
	
}

bool Student::get_public() {
	
	return if_public_school;
	
}

void Student::set_public(bool if_public) {
	
	if_public_school = if_public;
	
}

Man Student::get_promoter() {
		
		return promoter;
		
}

void Student::set_promoter(string name_to_set, int age_to_set) {
	
	promoter.set_name(name_to_set);
	promoter.set_age(age_to_set);
	
}

int Student::finishing_year() {
	
	return 5 - year_of_studies;
	
}

double Student::students_discount(int ticket_price) {
	
	return ticket_price * 0.5;
	
}

string Student::is_working(bool is_he) {
	
	if (is_he == true) 
		return "Working student";
	else
		return "Non-working student";

}

Pensioner::Pensioner() {
	
	Man();
	pension = 0;
	grandchildren = 0;
	
}

Pensioner::Pensioner(string name_to_set, int age_to_set, string status, string hometown_to_set, int pension_to_set, int how_many_grandchildren):
		Man(name_to_set, age_to_set, status, hometown_to_set),
		pension(pension_to_set),
		grandchildren(how_many_grandchildren){};

int Pensioner::get_pension() {
	
	return pension;
	
}

void Pensioner::set_pension(int pension_to_set) {
	
	pension = pension_to_set;
	
}

int Pensioner::get_grandchildren() {
	
	return grandchildren;
	
}

void Pensioner::set_grandchildren(int how_many_grandchildren) {
	
	grandchildren = how_many_grandchildren;
	
}

bool Pensioner::if_conjugal_discount(string marital_status) {
	
	if (marital_status == "married")
		return true;
	else
		return false;
		
}

double Pensioner::count_discount(bool if_discount, int pension) {
	
	if (if_discount == true)
		return pension * 0.15;
	else
		return 0.0;
		
}

double Pensioner::raise_pension(int pension) {
	
	return pension += pension * 0.1;
	
}

int main() {
	
	Man hairdresser = Man("Mary", 30, "married", "New York");
	Student lawyer2b = Student("John", 20, "single", "Cambridge", "Cambridge University", 3, true, "Mark", 55);
	Pensioner johns_granny("Else", 72, "widow", "Yorkshire", 2500, 4);
	Man unknown = Man();
	
	cout << "John's grandmother is " << johns_granny.get_name() << '.' << endl;
	cout << "John's promoter is " << lawyer2b.get_promoter().get_name() << '.' << endl;
	hairdresser.birthday();
	cout << "Mary is " << hairdresser.get_age() << " years old." << endl;
	cout << "Else lived in " << johns_granny.get_hometown() << '.' << endl;
	johns_granny.set_hometown("London");
	cout << "Now Else lives in " << johns_granny.get_hometown() << '.' << endl;
	cout << "Unknown man is " << unknown.get_name() << '.' << endl;

}
