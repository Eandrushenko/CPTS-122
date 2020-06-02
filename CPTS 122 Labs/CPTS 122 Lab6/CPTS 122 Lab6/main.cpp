#include "complex.h"

int main(void)
{
	Complex c1(0, 0), c2(0, 0);
	cout << "Enter a complex number in the form \"a + bi\": ";
	cin >> c1;

	cout << "Enter another complex number in the form \"a + bi\": ";
	cin >> c2;

	Complex c3(0, 0);
	c3 = c2 - c1;
	cout << c1 << " - " << c2 << " = " << c3 << endl;

	c3 = c2 + c1;
	cout << c1 << " + " << c2 << " = " << c3 << endl;


	return 0;
}