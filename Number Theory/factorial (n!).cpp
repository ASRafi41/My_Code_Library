// CPP program for calculating factorial
// of a number using Stirling
// Approximation
#include <bits/stdc++.h>
using namespace std;

// function for calculating factorial
long int stirlingFactorial(int n)
{
	if (n == 1)
		return 1;
	long int z;
	float e = 2.71; // value of natural e

	// evaluating factorial using
	// stirling approximation
	z = sqrt(2 * 3.14 * n) * pow((n / e), n);
	return z;
}

// driver program
int main()
{
    ///This formula will not give the exact value of the factorial
    ///because, it is just the approximation of the factorial.

	cout << stirlingFactorial(1) << endl;
	cout << stirlingFactorial(2) << endl;
	cout << stirlingFactorial(3) << endl;
	cout << stirlingFactorial(4) << endl;
	cout << stirlingFactorial(5) << endl;
	cout << stirlingFactorial(6) << endl;
	cout << stirlingFactorial(7) << endl;
	return 0;
}

