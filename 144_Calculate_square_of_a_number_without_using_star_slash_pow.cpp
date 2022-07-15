/*
144_Calculate_square_of_a_number_without_using_star_slash_pow.cpp
Given an integer n, calculate the square of a number without using *, / and pow(). 

https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
Method: bit manipulation. n << m == n * 2^m
*/

#include <bits/stdc++.h>
using namespace std;
 
// return square
int square1(int n) { return n*n; }

// add it up n times
int square2(int n) {
	if(n < 0) n = -n;	// handle negative numbers

	int temp = n;
	int res = 0;
	while(n--)
		res += temp;

	return res;
}

// Bit manipulation
// n << m = n x 2^m
int square3(int n) {
	if(n < 0) n = -n;	// handle negative numbers

	bitset<32> a(n);
	int res = 0;

	for(int i=0; i<32; i++) {
		if(a[i]) res += n << i;
	}

	return res;
}

// Bit manipulation
// n << m = n x 2^m
int square(int n) {
	if(n < 0) n = -n;	// handle negative numbers or n = abs(n);

	int temp = n;
	int res = 0;
	int pos = 0;

	while(temp) {			// while there exist binary number temp
		if(temp & 1) {		// If last bit is 1
			res = res + (n<<pos);	// add 2^pos to result like 5x2^0 + 5x2^2... 
		}
		pos++;
		temp = temp >> 1;	// right shift the binary
	}

	return res;
}

 
int main()
{
    for (int n =-5; n <= 5; n++)
        cout << "n = " << n << ", n^2 = " << square(n)
             << endl;

	// cout << square(5) << endl;
    return 0;
}