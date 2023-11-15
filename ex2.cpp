#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void input_error(void)
{
	cout << "Input data type error. Try again." << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}

void inputOutOfRange_error()
{
	cout << "Out of range error. Try again." << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}

int doubleOverflow_error(double digit)
{
	if (isnan(digit) || isinf(digit)) {
		cout << "Overflow error. Try again." << endl;
		return (1);
	}
	return (0);
}

double digit_input()
{
	double digit;
	while(1) {
		string str;
		size_t pos{};
		cin >> str;
		try {
			digit = stod(str, &pos);
			if (cin && pos == str.size())
				break;
			else {
				input_error();
			}
		}
		catch (invalid_argument const&) {
			input_error();
		}
		catch (out_of_range const&) {
			inputOutOfRange_error();
		}
	}

	return (digit);
}

double find_min(double num1, double num2)
{
	if (num1 >= num2)
		return (num2);
	return (num1);
}

double find_max(double num1, double num2, double num3)
{
	if (num1 >= num2 && num1 >= num3)
		return (num1);
	if (num2 >= num3)
		return (num2);
	return (num3);
}

int main ()
{
	double a;
	double x;
	double y;
	double result;

	do {
		cout << "Enter variable a: " << endl;
		a = digit_input();
		cout << "Enter variable x: " << endl;
		x = digit_input();
		cout << "Enter variable y: " << endl;
		y = digit_input();


		if (a == 0) {
			result = find_max(a, x, y);
		}

		if (a < 0) {
			result = find_min(pow(x, 2),pow(y, 2)) + a;
		}

		if (a > 0) {
			result = fabs(x - y) + y * (x + sqrt(pow(a, 3)));
		}
	} while (doubleOverflow_error(result));

	cout << endl << "Result is: " << result << endl;

	return (0);
}
