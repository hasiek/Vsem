#include <iostream>
#include <fstream>

using namespace std;

class Example {
public:
	int* array;
	ofstream stream;
	Example() {
		
		array = new int[10];
		stream << " ";
	}
private:
	Example(const Example& object) {
		
		array = new int[10];
		for (int i = 0; i < 10; i++)
			array[i] = object.array[i];
		stream << object.stream;
		
	}
	Example operator=(const Example& example) {
		
		Example copied;
		for(int i = 0; i < 10; i++)
			copied.array[i] = example.array[i];
		copied.stream << example.stream;
		return copied;
		
	}
	/* Example object: 
	* 0 0 0 0 0 0 0 0 0 0 
	* Copied object: 
	* 0 0 0 0 0 0 0 0 0 0 
	* Example object: 
	* 0 0 0 0 0 0 0 0 0 0 
	* Copied object: 
	* 0 1 2 3 4 5 6 7 8 9 */
	
	
};

int main() {
	
	Example example;
	Example copy(example); // konstruktor kopiujący
	Example copy1 = example; // konstruktor kopiujący
	Example copy2;
	copy2 = example; // operator "="
	
	/*cout << "Example object: " << endl;
	for(int i = 0; i < 10; i++)
		cout << example.array[i] << ' ';
	
	cout << "\nCopied object: " << endl;
	for(int i = 0; i < 10; i++)
		cout << copy.array[i] << ' ';
		
	for (int i = 0; i < 10; i++)
		copy.array[i] += i;
		
	cout << "\nExample object: " << endl;
	for(int i = 0; i < 10; i++)
		cout << example.array[i] << ' ';
	
	cout << "\nCopied object: " << endl;
	for(int i = 0; i < 10; i++)
		cout << copy.array[i] << ' '; */
		
	/* Example object: 
	* 0 0 0 0 0 0 0 0 0 0 
	* Copied object: 
	* 0 0 0 0 0 0 0 0 0 0 
	* Example object: 
	* 0 1 2 3 4 5 6 7 8 9 
	* Copied object: 
	* 0 1 2 3 4 5 6 7 8 9 */
	
	return 0;
}

// Próba skopiowania strumienia zsyntetyzowanym konstruktorem kopiującym
/* /usr/include/c++/4.7/bits/ios_base.h: In copy constructor ‘std::basic_ios<char>::basic_ios(const std::basic_ios<char>&)’:
*  /usr/include/c++/4.7/bits/ios_base.h:788:5: error: ‘std::ios_base::ios_base(const std::ios_base&)’ is private
*  /usr/include/c++/4.7/bits/basic_ios.h:64:11: error: within this context
*/
