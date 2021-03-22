#include<iostream>
#include "Timer.h";


int main() {
	int not_constant = 100;
	const int CONSTANT = 100;

	{
		Timer timer("10000 non-constant int");
		for (int i = 0;i < 10000;i++) {
			std::cout << not_constant;
		}
	}
	{
		Timer timer("10000 constant int");
		for (int i = 0;i < 10000;i++) {
			std::cout << CONSTANT;
		}
	}
}