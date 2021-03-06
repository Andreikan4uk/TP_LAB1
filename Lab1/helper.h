#pragma once
#include <iostream>
#include <fstream>

template <typename T>
T safeInput(T minInput, T maxInput) {
	while (true)
	{
		T method;
		std::cin >> method;
		if (std::cin.fail() || method < minInput || method > maxInput)
		{
			std::cin.clear();
			std::cout << "Íåâåðíûé ââîä.\nÏîâòîðèòå ñíîâà: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}

bool checkStringToInt(std::string s);
bool InputInFileName(std::string& filename);
void InputOutFileName(std::string& filename); 
