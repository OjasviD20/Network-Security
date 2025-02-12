/**
* @file         DH Key Exchange
* @Author       Ojasvi DSilva
* @date         November 13, 2023
* @brief 		The program performs basic key exchange 
*/

#include <iostream> // for input and output
#include <cstdlib> // for generating random numbers
using namespace std;


// Modular exponentiation 
unsigned long long modExp(unsigned long long m, unsigned long long e, unsigned long long N)
{

	unsigned long long result = 1;

	while (e > 0) {
		if (e % 2 == 1)
		{
			result = (result * m) % N;

		}
		e = e / 2;
		m = (m * m) % N;


	}
	// returning final result.
	return (result % N);
}

int main()
{
	
	string Con;
	do {
		long long int P, G, A, a, B, b, ka, kb;
		cout << "Please enter value for Prime `P': ";
		cin >> P;
		cout << "Please enter value for Generator `G': ";
		cin >> G;

		cout << "Person A enter Secret Key: ";
		cin >> a;
		cout << "Person B enter Secret Key: ";
		cin >> b;

		A = modExp(G, a, P);
		B = modExp(G, b, P);

		ka = modExp(B, a, P);
		kb = modExp(A, b, P);
		cout << "Secret key for Person A is: " << ka << endl;
		cout << "Secret key for Person B is: " << kb << endl;
		
		cout << "Would you like to try again 'Y' or 'N' " << endl;
		cin >> Con;
	} while (Con == "Y" || Con == "y");

	return 0;
}
	



