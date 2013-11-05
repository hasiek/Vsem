/* Implementation of Student class.
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
#include "student.h"
#include "exception.h"

Student::Student():
	Man(),
	university("N/A"),
	year_of_studies(0),
	if_public_school(true),
	promoter(){};

Student::Student(std::string pesel_to_set, std::string name_to_set, int age_to_set, std::string status, std::string hometown_to_set, std::string uni, int year, bool if_public, std::string promoter_pesel, std::string promoter_name, int promoter_age):
		Man(pesel_to_set, name_to_set, age_to_set, status, hometown_to_set),
		university(uni),
		year_of_studies(year),
		if_public_school(if_public),
		promoter(promoter_pesel, promoter_name, promoter_age){};

std::string Student::get_university() const {
	
	return university;
	
}

void Student::set_university(const std::string& uni) {
	
	university = uni;
	
}

int Student::get_year() const {
	
	return year_of_studies;
	
}

void Student::set_year(int year) {
	
	if(year < 1)
		throw Exception("You try to set inproper year of studies!");
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

void Student::set_promoter(const std::string& pesel_to_set, const std::string& name_to_set, int age_to_set) {
	
	promoter.set_name(name_to_set);
	promoter.set_age(age_to_set);
	
}

int Student::finishing_year() const {
	
	return 5 - year_of_studies;
	
}

/*
 * Method returns the price that student should pay for a ticket.
 * Exception thrown when the negative value as a base price is given.
 */

double Student::students_discount(int ticket_price) const {
	
	if(ticket_price < 0) {
		std::stringstream temp;
		temp << ticket_price;
		throw Exception("The price can't be negative.");
	}
	return ticket_price * 0.5;
	
}

std::string Student::is_working(bool is_he) const {
	
	if (is_he == true) 
		return "Working student";
	else
		return "Non-working student";

}

/* 
 * Method returns further information about Student object.
 * Exception is thrown when stream brokes.
 */

std::string Student::info() const {
	
	std::stringstream stream;
	stream << ", UNIVERSITY: " << university << ", YEAR OF STUDIES: " << year_of_studies << ", IS IN PUBLIC SCHOOL: " << ((if_public_school) ? "Yes" : "No") << ", PROMOTER " << promoter.info() << std::endl;
	if (!stream)
		throw Exception("Couldn't get the info about the Student object!");
	return (Man::info()) + stream.str();
}

/*
 * Method for serialization of a Student object.
 * When stream brokes, exception is thrown.
 */

void Student::serialize(std::ostream& save) const {
	
	Man::serialize(save);
	save << university << '\n';
	save << year_of_studies << '\n';
	save << if_public_school << '\n';
	promoter.serialize(save);
	if(!save)
		throw Exception("Problems with serialisation in Student class occured.");
}

/*
 * Method for deserialization of Student object
 * Exception is thrown when stream brokes.
 */

Student Student::deserialize(std::istream& save) {
	
	Man student = Man::deserialize(save);
	
	std::string university;
	getline(save, university);
	
	std::string year_s;
	getline(save, year_s);
	
	int year;
	std::istringstream temp(year_s);
	temp >> year; 
	
	std::string public_school_s;
	getline(save, public_school_s);
	
	bool public_school;
	public_school = (public_school_s == "1" ? true : false);
	
	Man promoter = Man::deserialize(save);
	
	if(!save)
		throw Exception("Couldn't deserialize Student object.");
		
	Student deserialized = Student(student.get_pesel(), student.get_name(), student.get_age(), student.get_status(), student.get_hometown(), university, year, public_school, promoter.get_pesel(), promoter.get_name(), promoter.get_age());
	return deserialized;
	
}
