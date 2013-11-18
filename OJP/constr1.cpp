#include <iostream>

using namespace std;

class Example {
public:
	int number;
	char letter;
	double another_number;
	
	Example(int num, char let, double a_num) {
		
		number = num;
		letter = let;
		another_number = a_num;
	} // error: no matching function for call to ‘Example::Example()’
	
};

int main() {
	
	Example example[10]; // kompiluje się
	
	for (int i = 0; i < 10; i++)
		cout << example[i].number << ' '; // -1218059292 1 134514192 0 134514192 -1219777640 1 -1218059292 1 -1216784896
		
	for (int i = 0; i < 10; i++)
		cout << example[i].letter << ' '; // �  � V �  �  T 
		
	for (int i = 0; i < 10; i++)
		cout << example[i].another_number << ' '; // -2.69915e-42 -2.69978e-42 -7.85272e-42 4.85843e-270 -2.69962e-42 4.85854e-270 4.85554e-270 4.85884e-270 -2.69978e-42 -7.84727e-42
	
	return 0;
}
