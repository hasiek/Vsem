/* Implementation of Man class.
 * 
 * Last edit: 5.11.2013
 * Project divided into seperated files and commented.
 * https://github.com/hasiek/Vsem/tree/master/OJP
 * 
 * Katarzyna Huszcza
 * hatarzyna@gmail.com
 * 
 */

#include <iostream>
#include <sstream>
#include <fstream>

#include "man.h"
#include "exception.h"

bool Man::is_a_mammal = true;

Man::Man():
	pesel("N/A"),
	name("John Doe"),
	age(30),
	marital_status("N/A"),
	hometown("N/A"){};

Man::Man(std::string pesel_to_set, std::string name_to_set, int age_to_set, std::string status, std::string hometown_to_set):
	pesel(pesel_to_set),
	name(name_to_set),
	age(age_to_set),
	marital_status(status),
	hometown(hometown_to_set){};
	
std::string Man::get_pesel() const {

	return pesel;
	
}

std::string Man::get_name() const {
	
	return name;
	
}

void Man::set_name(const std::string& name_to_set) {
	
	name = name_to_set;
	
}

int Man::get_age() const {
	
	return age;
	
}

void Man::set_age(int age_to_set) {
	
	if (age_to_set < 0) 
		throw Exception("The age can't be negative.");
	age = age_to_set;
	
}

std::string Man::get_status() const {
	
	return marital_status;
	
}

void Man::set_status(const std::string& status) {
	
	marital_status = status;
	
}

std::string Man::get_hometown() const {
	
	return hometown;
	
}

void Man::set_hometown(const std::string& hometown_to_set) {
	
	hometown = hometown_to_set;
	
}

bool Man::get_is_a_mammal() {
	
	return is_a_mammal;
	
}

bool Man::is_adult() const {
	
	return age >= 18;
}

void Man::birthday(int years) {
	
	if(years < 0) 
		throw Exception("You can't get younger!");
	age += years;
	
}

/*
 *  Method returns an integer representing in how many years the person will retire.
 */

int Man::will_retire_in() const {
	
	return 65 - age;
	
}

/* 
 * Method returns information about an object.
 * When stream brokes, the exception is thrown. 
 */

std::string Man::info() const{
	
	std::stringstream stream;
	stream << "INFO: " << "IS A MAMMAL: " << ((is_a_mammal) ? "yes" : "false") << ", PESEL: " << pesel << ", NAME: " << name << ", AGE: " << age << ", MARITAL STATUS: " << marital_status << ", HOMETOWN: " << hometown;
	if (!stream) 
		throw Exception("Something went wrong with your stream in info() from Man class.");
	return stream.str();
	
}

/* 
 * Method for serialization of an object.
 * When stream brokes, the exception is thrown.
 * 
 */

void Man::serialize(std::ostream& save) const {
	
	save << ((is_a_mammal) ? "true" : "false") << '\n';
	save << pesel << '\n';
	save << name << '\n';
	save << age << '\n';
	save << marital_status << '\n';
	save << hometown << '\n';
	if (!save) 
		throw Exception("Something went wrong with your stream in serialisation of Man object.");
	
}

/*
 * Method for deserialization of an object.
 * When stream brokes, the exception is thrown.
 */

Man Man::deserialize(std::istream& save) {
	
	std::string garbage;
	
	std::string is_mammal_s;
	getline(save, is_mammal_s);
	
	/*
	 * Testing couts commented out.
	 * TODO: Remove, when no longer needed.
	 */


	std::string pesel;
	getline(save, pesel);
	// cout << pesel << endl;

	std::string name;
	getline(save, name);
	// cout << name << endl;

	std::string age_s;
	getline(save, age_s);

	int age;
	std::istringstream temp(age_s);
	temp >> age; 
	// cout << age << endl;
	
	std::string marital_status;
	getline(save, marital_status);
	// cout << marital_status << endl;

	std::string hometown;
	getline(save, hometown);
	// cout << hometown << endl;
	
	if (!save)
		throw Exception("Something went wrong in deserialization of Man object.");
	
	Man deserialized = Man(pesel, name, age, marital_status, hometown);
	return deserialized;
}
