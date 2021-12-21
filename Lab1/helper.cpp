#include "helper.h"

bool checkStringToInt(std::string s)
{
	for (auto letter : s)
		if (letter < '0' || letter > '9')
			return false;
	return true;
}

bool checkFilename(std::string file)
{
	if (file.size() < 4 && file[0] != '0') {
		std::cout << "Èìÿ ôàéëà ñëèøêîì êîğîòêîå.\n";
		return false;
	}
	if ((((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
		&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'a') || (file[0] == 'A')) && ((file[1] == 'u') || (file[1] == 'U'))
			&& ((file[2] == 'x') || (file[2] == 'X')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'p') || (file[0] == 'P')) && ((file[1] == 'r') || (file[1] == 'R'))
			&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
			&& ((file[2] == 'm') || (file[2] == 'M')) && ((file[3] == '1') || (file[3] == '2')
				|| (file[3] == '3') || (file[3] == '4') || (file[3] == '5') || (file[3] == '6')
				|| (file[3] == '7') || (file[3] == '8') || (file[3] == '9')) && ((file[4] == '.')
					|| (file[4] == '\0'))) || (((file[0] == 'l') || (file[0] == 'L')) && ((file[1] == 'p')
						|| (file[1] == 'P')) && ((file[2] == 't') || (file[2] == 'T')) && ((file[3] == '1')
							|| (file[3] == '2') || (file[3] == '3') || (file[3] == '4') || (file[3] == '5')
							|| (file[3] == '6') || (file[3] == '7') || (file[3] == '8') || (file[3] == '9'))
						&& ((file[4] == '.') || (file[4] == '\0'))))
	{
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Äàííîå èìÿ ôàéëà èñïîëüçóåòñÿ Windows.\n";
		return false;
	}
	int i = file.size();
	if ((file[i] == '\0') && (file[i - 1] == 't') && (file[i - 2] == 'x') && (file[i - 3] == 't') && (file[i - 4] == '.'))
		return true;
	else
	{
		if (file[i - 1] != '0')
			std::cout << "Ôàéë äîëæåí èìåòü ôîğìàò .txt\n";
		return false;
	}
}

bool InputInFileName(std::string& filename)
{
	std::ifstream file;
	bool isCorrect;
	std::cout << "Ââåäèòå íàçâàíèå ôàéëà (ñ ğàñøèğåíèåì)(0 - îòêàç): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	if (isCorrect)
		file.open(filename);
	while (!file.is_open() && filename[0] != '0')
	{

		if (isCorrect)
			std::cout << "Òàêîãî ôàéëà íå ñóùåñòâóåò.\n";
		std::cout << "Ââåäèòå íàçâàíèå ïîâòîğíî (ñ ğàñøèğåíèåì): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
		if (isCorrect)
			file.open(filename);
	}
	file.close();
	if (filename[0] != '0') {
		std::cout << "Ôàéë óñïåøíî îòêğûò\n";
		return true;
	}
	else {
		std::cout << "Âû îòêàçàëèñü îò ââîäà äàííûõ èç ôàéëà\n";
		return false;
	}
}

void InputOutFileName(std::string& filename)
{
	std::ifstream file;
	bool isCorrect;
	std::cout << "Ââåäèòå íàçâàíèå ôàéëà (ñ ğàñøèğåíèåì): ";
	std::cin >> filename;
	while (!checkFilename(filename))
	{
		std::cout << "Ââåäèòå íàçâàíèå ïîâòîğíî (ñ ğàñøèğåíèåì): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
	}
	std::cout << "Ôàéë óñïåøíî îòêğûò\n";
}  
