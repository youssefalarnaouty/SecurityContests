#include <iostream>
#include <math.h>

using namespace std;

unsigned long long temp;

unsigned long long gcd(unsigned long long max, unsigned long long min) {
	//Base Case
	if (min == 0)
		return max;
	
	temp = max - (max / min) * min;
	max = min;
	min = temp;

	//Recursive function
	gcd(max, min);
}

int main() {
	
	unsigned long long max, min;
	unsigned long long in1, in2;

	cin >> in1 >> in2;

	if (in1 > in2) {
		max = in1;
		min = in2;
	}
	else {
		max = in2;
		min = in1;
	}

	cout << gcd(max, min);

	
	return 0;
}
