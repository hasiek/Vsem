/* Header file for Man class.
 * 
 * Last edit: 5.11.2013
 * Project divided into seperated files and commented.
 * https://github.com/hasiek/Vsem/tree/master/OJP
 * 
 * Katarzyna Huszcza
 * hatarzyna@gmail.com
 * 
 */

class Man {
private:
	static bool is_a_mammal;
	const std::string pesel;
	std::string name;
	int age;
	std::string marital_status;
	std::string hometown;
	
public:
	Man();
	// Man(string name_to_set, int age_to_set, string status, string hometown_to_set);
	Man(std::string pesel_to_set, std::string name_to_set, int age_to_set, std::string status = "N/A", std::string hometown_to_set = "N/A");
	
	std::string get_pesel() const;
	
	std::string get_name() const;
	void set_name(const std::string& name_to_set);
	
	int get_age() const;
	void set_age(int age_to_set);
	
	std::string get_status() const;
	void set_status(const std::string& status);
	
	std::string get_hometown() const;
	void set_hometown(const std::string& hometown_to_set);
	
	static bool get_is_a_mammal();
	
	bool is_adult() const;
	void birthday(int years = 1);
	int will_retire_in() const;
	std::string info() const;
	void serialize(std::ostream& save) const;
	static Man deserialize(std::istream& save);
	
};
