/* Header file for Student class.
 * 
 * Last edit: 5.11.2013
 * Project divided into seperated files and commented.
 * https://github.com/hasiek/Vsem/tree/master/OJP
 * 
 * Katarzyna Huszcza
 * hatarzyna@gmail.com
 * 
 */
 
#include "man.h"
 
#ifndef STUDENT_H
#define STUDENT_H

class Student : public Man {
private:
	std::string university;
	int year_of_studies;
	bool if_public_school;
	Man promoter;
public:
	Student();
	Student(std::string pesel_to_set, std::string name_to_set, int age_to_set, std::string status, std::string hometown_to_set, std::string uni, int year, bool if_public, std::string promoter_pesel, std::string promoter_name, int promoter_age);
	
	std::string get_university() const;
	void set_university(const std::string& uni);
	
	int get_year() const;
	void set_year(int year);
	
	bool get_public() const;
	void set_public(bool if_public);
	
	Man get_promoter() const;
	void set_promoter(const std::string& pesel_to_set, const std::string& name_to_set, int age_to_set);
	
	int finishing_year() const;
	double students_discount(int ticket_price) const;
	std::string is_working(bool is_he) const;
	std::string info() const;
	void serialize(std::ostream& save) const;
	static Student deserialize(std::istream& save);
	
};

#endif
