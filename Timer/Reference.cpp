#include<iostream>
#include<string>
#include<chrono>
#include"Timer.h"
//passing a string by ref vs without




void PrintByRef(std::string& string) {
	std::cout << string << "\n";
}

void PrintByCopy(std::string string) {
	std::cout << string << "\n";
}



//int main() {
//	std::string string = "Hello!";
//	{
//		Timer timer("1000 string by copy");
//		for (int i = 0;i < 1000;i++) {
//			PrintByCopy(string);
//		}
//	}
//	{
//		Timer timer("1000 string by ref");
//		for (int i = 0;i < 1000;i++) {
//			PrintByRef(string);
//		}
//	}
//}