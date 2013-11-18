/* Header file for Pensioner class.
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
 
#ifndef PENSIONER_H
#define PENSIONER_H

class Pensioner : public Man {
private:
	int pension;
	int grandchildren;
public:
	Pensioner();
	Pensioner(std::string pesel_to_set, std::string name_to_set, int age_to_set, std::string status, std::string hometown_to_set, int pension_to_set, int how_many_grandchildren);
		
	int get_pension() const;
	void set_pension(int pension_to_set);
	
	int get_grandchildren() const;
	void set_grandchildren(int how_many_grandchildren);
	
	bool if_conjugal_discount(const std::string& marital_status) const;
	double count_discount(bool if_discount, int pension) const;
	double raise_pension(int pension);
	std::string info() const;
	void serialize(std::ostream& save) const;
	static Pensioner deserialize(std::istream& save);
	
};

#endif
