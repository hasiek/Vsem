/* Main function illustrating the functionality of the project.
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

using namespace std;

#include "man.h"
#include "student.h"
#include "pensioner.h"
#include "exception.h"

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
	
	return 0;
}
