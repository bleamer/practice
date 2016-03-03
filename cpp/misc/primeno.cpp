// Algorithm to find all prime till no. n
// Note compile with "g++ -std=c++11 primeno.cpp - primeno"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

#define PRIME_UPTO 1000000

vector<int> genPrimes (int n)
{
	int size = floor ( (n - 3) / 2) + 1; // no. of expected primes
	vector<int> primes;
	std::vector<bool> isPrime(size,true); // For starter mark everything as prime and later remove the one that are not
	for (long i = 0; i < size; i++)
	{
		if(isPrime[i])
		{
			// 2i + 1 is always prime
			// 2i, 2i+2 is never prime
			// 2i+3 may be prime or not, isPrime represents 2i+3 is prime or not
			// p = steps in which we should increment the index = 2i+3
			int p = 2*i + 3;
			primes.emplace_back(p); // queue this number as prime

			// p^2 onwards 2i^2+6i+3 is not prime
			for (long j = (2*i*i)+(6*i)+3; j < size; j += p)
			{
				isPrime[j]=false;
			// cout << j << endl;
			} 
		}
	}
	return primes;
}

int main(int argc, char const *argv[])
{
	vector<int> primes = genPrimes(PRIME_UPTO);

	// print all primes
	// for (vector<int>::iterator itr = primes.begin(); itr != primes.end(); ++itr)
	// 	cout << *itr << endl;
	// cout << "Printing primes upto " << PRIME_UPTO << endl;
	return 0;
}