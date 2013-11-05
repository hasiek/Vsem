/* Implementation of Exception class.
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
 
#include "exception.h"

/*
 * Method which returns the string containing further information about the exception thrown.
 */

std::string Exception::get_reason() const {
	
	return message;
	
}
