#include <iostream>
#include <fstream>
#include "sieve.h"
#include "input.h"

int main() {
	std::fstream not_prime,even,odd,input;

	not_prime.open("not_prime.txt",std::ios::out|std::ios::trunc);
	even.open("even.txt",std::ios::out|std::ios::trunc);
	odd.open("odd.txt",std::ios::out|std::ios::trunc);

	ask();

	
	input.open("input.txt",std::ios::in);

	sieve(100);

	int number;

	while(input >> number) {
		if(!isPrime(number))
			not_prime << number << " ";
		if(number & 1)
			odd << number << " ";
		if( !(number & 1) )
			even << number << " ";
	}
	not_prime << std::endl;
	odd << std::endl;
	even << std::endl;

	std::cout << "Done" << std::endl;

	return 0;
}