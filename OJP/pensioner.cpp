/* Implementation of Pensioner class.
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
#include "pensioner.h"
#include "exception.h"

Pensioner::Pensioner():
	Man(),
	pension(0),
	grandchildren(0){};

Pensioner::Pensioner(std::string pesel_to_set, std::string name_to_set, int age_to_set, std::string status, std::string hometown_to_set, int pension_to_set, int how_many_grandchildren):
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

bool Pensioner::if_conjugal_discount(const std::string& marital_status) const {
	
	return marital_status == "married";
		
}

/*
 * Method counts the discount that a pensioner has (if they do).
 */

double Pensioner::count_discount(bool if_discount, int pension) const {
	
	if (if_discount == true)
		return pension * 0.15;
	else
		return 0.0;
		
}

double Pensioner::raise_pension(int pension) {
	
	return pension += pension * 0.1;
	
}

/*
 * Method returns further information about Pensioner object.
 * Exception is thrown when stream brokes.
 */

std::string Pensioner::info() const {
	
	std::stringstream stream;
	stream << ", PENSION: " << pension << ", GRANDCHILDREN: " << grandchildren << std::endl;
	if (!stream)
		throw Exception("Couldn't get the info about the Pensioner.");
	return (Man::info()) + stream.str();
	
}

/*
 * Method for Pensioner object serialization.
 * Exception is thrown when stream brokes.
 */

void Pensioner::serialize(std::ostream& save) const {
	
	Man::serialize(save);
	save << pension << '\n';
	save << grandchildren << '\n';
	if(!save)
		throw Exception("Serialisation issue in Pensioner class.");
	
}

/*
 * Method for deserialization of Pensioner object.
 * Exception is thrown when stream brokes.
 */

Pensioner Pensioner::deserialize(std::istream& save) {
	
	Man pensioner = Man::deserialize(save);
	
	std::string pension_s;
	getline(save, pension_s);
	
	int pension;
	std::istringstream temp(pension_s);
	temp >> pension; 
	
	std::string grandchildren_s;
	getline(save, grandchildren_s);
	
	int grandchildren;
	std::istringstream temp1(grandchildren_s);
	temp1 >> grandchildren; 
	
	if(!save)
		throw Exception("Couldn't deserialize Pensioner object.");
		
	Pensioner deserialized = Pensioner(pensioner.get_pesel(), pensioner.get_name(), pensioner.get_age(), pensioner.get_status(), pensioner.get_hometown(), pension, grandchildren);
	return deserialized;
	
}
