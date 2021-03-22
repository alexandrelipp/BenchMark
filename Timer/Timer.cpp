#define _CRT_SECURE_NO_DEPRECATE
#include<chrono>
#include<iostream>
#include<thread>
#include<fstream>
#include<ctime>
#include"Timer.h"



Timer::Timer(const char* Name) : Name(Name) {
	p_StartTimePoint = CurrentTimePoint();
}

Timer::~Timer() {
	auto EndTimePoint = CurrentTimePoint();
	long long start = TimePointCount(p_StartTimePoint);
	long long end = TimePointCount(EndTimePoint);
	long long duration_micro = end - start;
	WriteFile(duration_micro);
}
std::chrono::time_point<std::chrono::steady_clock, std::chrono::microseconds> Timer::CurrentTimePoint() {
	return std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now());
}

long long Timer::TimePointCount(std::chrono::time_point<std::chrono::steady_clock, std::chrono::microseconds>& timePoint) {
	return timePoint.time_since_epoch().count();
}

void Timer::WriteFile(long long& duration_micro)
{
	std::ofstream myfile;
	myfile.open("result.txt", std::ios_base::app);
	std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	myfile << Name << "\n" << asctime(std::localtime(&time)) << "\n";
	myfile << "Configuration: ";
#ifdef _DEBUG
	myfile << "DEBUG\n";
#else
	myfile << "RELEASE\n";
#endif // _DEBUG

	myfile << "Time in microseconds: " << duration_micro << "\n";
	myfile << "Time in milliseconds: " << duration_micro * 0.001 << "\n";
	myfile << "Time in seconds: " << duration_micro * 0.000001 << "\n";
	myfile << "-----------------------------------------\n";

}

