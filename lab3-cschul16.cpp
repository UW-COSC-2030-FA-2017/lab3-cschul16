// Chris Schultz
// COSC 2030
// Lab 03
// Oct 2017

#include <iostream>
#include <iomanip>
using namespace std;

// function to compute sum of consecutive integers
template <typename T>
T computeSum(T input) {
	T sum = 1, temp = 1;
	while (temp < input) {
		temp++;
		sum = (sum + temp);
	}
	return sum;
}

// function to compute factorial of integer input
template <typename T>
T computeFact(T input) {
	T product = 1, temp = 1;
	while (temp < input) {
		temp++;
		product = (product * temp);
	}
	return product;
}

// function to compute ratio 1 - (1/n) for inputs (1-n)
template <typename T>
T computeRatio(T input) {
	T ratio = 1, temp = 1;
	while (temp < input) {
		temp++;
		ratio = ratio + (1 / temp);
	}
	return (ratio -1);
}


int main() {
	short int inShort;
	long int inLong;
	float inFloat;
	double inDoub;
	
	cout << "***************Short Int Sum***************" << endl;
	cout << "Please enter an integer input! " << endl;
	cout << "I'll compute the sum of integers 1 through the input! ";
	cin >> inShort;
	cout << "The sum of the integers 1 through the input is " << 
		computeSum<short int>(inShort) << "!" << endl << endl;

	// (1) If the user inputs 10, the computation comes to 55, which is correct.

	// (2) If the sum becomes negative, then there was an overflow. 
	//     For me, the value that caused this was 256, which returns -32640.

	cout << "***************Long Int Sum***************" << endl;
	cout << "Please enter another integer input and I'll compute another sum! ";
	cin >> inLong;
	cout << "The sum of the integers 1 through the input is " << 
		computeSum<long int>(inLong) << "!" << endl << endl;
	
	// (3) Using a long int for the sum, the value for me that caused 
	//     an overflow here was 9594032, which returns -2139738408.

	cout << "***************Factoral Float***************" << endl;
	cout << "Please enter an integer input! " << endl;
	cout << "I'll compute the product of integers 1 through the input! ";
	cin >> inLong;
	cout << "The product of the integers 1 through the input is " << 
		computeFact<float>(inLong) << "!" << endl << endl;

	// (4) When the product becomes infinity, there has been an overflow.
	//     The input value that caused an overflow for me was 35, which returned inf. 
	//     An input of 34 returned 2.95233e+38.

	cout << "**************Factoral Double***************" << endl;
	cout << "Please enter another input and I'll compute another product! ";
	cin >> inLong;
	cout << "The product of the integers 1 through the input is " << 
		computeFact<double>(inLong) << "!" << endl << endl;

	// (5) Using a double for the product, the value for me that caused 
	//     an overflow was 171, which returned inf.
	
	cout << "***************Ratio Float***************" << endl;
	cout << "Please enter a number, and I'll do some computations!" << endl;
	cout << "Where the result is the sum of (1/n) for all values between 1 and the input! ";
	cin >> inFloat;
	cout << "The resulting ratio is " << setprecision(15) << 
		computeRatio<float>(inFloat) << "!" << endl << endl;

	cout << "***************Ratio Double***************" << endl;
	cout << "Please enter another number and I'll compute the ratio again! ";
	cin >> inDoub;
	cout << "The resulting ratio is " << setprecision(15) << 
		computeRatio<double>(inDoub) << "!" << endl << endl;

	// (6) For input 20, the expected function value will be 2.597739657143681911483.
	//     With a floating point value, it returned 2.59773969650269.
	//     With a double value, it returned 2.59773965714368.
	//     This is because a float is less precise than a double, so the
	//     accuracy quickly dips, while a double stays more precise.

	for (float i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}

	// (7) The numeric errors occur immediately when 3.4 comes out to 3.40000009536743.
	//     A float's precision is very limited, so every time the loop increments
	//     and adds 0.2, it's not actually adding 0.2; instead, it ends up adding
	//     something like 0.20000005. That is just enough so that the final value
	//     ends up as 4.39999961853027, when it should have cut off at 4.2.

	for (double i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}
	// (8) When we change "float" to "double" in that code segment, the error
	//     is fixed, and the function outputs what it is supposed to, because
	//     of the increased accuracy of a double compared to a float. If I was
	//     to increase the precision to some crazy high decimal place, or run the
	//     loop enough times, the accuracy would fall like the float, however.

	return 0;
}