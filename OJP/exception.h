/* Header file for Exception class.
 * 
 * Last edit: 5.11.2013
 * Project divided into seperated files and commented.
 * https://github.com/hasiek/Vsem/tree/master/OJP
 * 
 * Katarzyna Huszcza
 * hatarzyna@gmail.com
 * 
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H
 
class Exception {
private:
	std::string message;
public:
	Exception(const std::string& what):
		message(what){};
	std::string get_reason() const ;
};

#endif
