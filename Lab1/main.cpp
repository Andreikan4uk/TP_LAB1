#include <iostream>
#include "Stack.h"
#include "Deque.h"
#include "List.h"

using namespace std;
void workWithQueue(Queue<int>& queue);
void workWithStack(Stack<int>& stack);
void workWithDeque(Deque<int>& deque);
void workWithList(List<int>& list);
void inputFromFile(Queue<int>& queue, Stack<int>& stack, Deque<int>& deque, List<int>& list);
void printToFile(Queue<int>& queue, Stack<int>& stack, Deque<int>& deque, List<int>& list);

int main()
{
	setlocale(LC_ALL, "Rus");
	Queue<int> queue;
	Stack<int> stack;
	Deque<int> deque;
	List<int> list;

	cout << "Ââåñòè èçíà÷àëüíûå äàííûå èç ôàéëà?(1/0)" << endl;
	int method = safeInput(0, 1);
	if (method == 1)
		inputFromFile(queue, stack, deque, list);

	bool isExit = false;
	while (!isExit) {
		cout << "1. Ðàáîòàòü ñ î÷åðåäüþ" << endl;
		cout << "2. Ðàáîòàòü ñî ñòåêîì" << endl;
		cout << "3. Ðàáîòàòü ñ äåêîì" << endl;
		cout << "4. Ðàáîòàòü ñî ñïèñêîì" << endl;
		cout << "5. Ñîõðàíèòü â ôàéë" << endl;
		cout << "0. Âûõîä" << endl;
		cout << "Âûáåðåòå ïóíêò ìåíþ: ";
		method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			workWithQueue(queue);
			break;
		case 2:
			workWithStack(stack);
			break;
		case 3:
			workWithDeque(deque);
			break;
		case 4:
			workWithList(list);
			break;
		case 5:
			printToFile(queue, stack, deque, list);
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void workWithQueue(Queue<int>& queue) {
	bool isExit = false;
	while (!isExit) {
		cout << "Ðàáîòà ñ î÷åðåäüþ" << endl;
		cout << "1. Äîáàâèòü ýëåìåíò" << endl;
		cout << "2. Èçâëå÷ü ýëåìåíò" << endl;
		cout << "3. Âûâåñòè íà ýêðàí" << endl;
		cout << "4. Îòñîðòèðîâàòü" << endl;
		cout << "0. Íàçàä" << endl;
		cout << "Âûáåðåòå ïóíêò ìåíþ: ";
		int method = safeInput(0, 4);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "Ââåäèòå ÷èñëî, êîòîðîå õîòèòå äîáàâèòü: ";
			tmp = safeInput(0, INT32_MAX);
			queue.push_back(tmp);
			break;
		case 2:
			try {
				cout << "Èçâëå÷åíî ÷èñëî: " << queue.pop_front() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 3:
			queue.printToConsole();
			break;
		case 4:
			queue.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void workWithStack(Stack<int>& stack) {
	bool isExit = false;
	while (!isExit) {
		cout << "Ðàáîòà ñî ñòåêîì" << endl;
		cout << "1. Äîáàâèòü ýëåìåíò" << endl;
		cout << "2. Èçâëå÷ü ýëåìåíò" << endl;
		cout << "3. Âûâåñòè íà ýêðàí" << endl;
		cout << "4. Îòñîðòèðîâàòü" << endl;
		cout << "0. Íàçàä" << endl;
		cout << "Âûáåðåòå ïóíêò ìåíþ: ";
		int method = safeInput(0, 4);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "Ââåäèòå ÷èñëî, êîòîðîå õîòèòå äîáàâèòü: ";
			tmp = safeInput(0, INT32_MAX);
			stack.push_back(tmp);
			break;
		case 2:
			try {
				cout << "Èçâëå÷åíî ÷èñëî: " << stack.pop_back() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 3:
			stack.printToConsole();
			break;
		case 4:
			stack.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void workWithDeque(Deque<int>& deque) {
	bool isExit = false;
	while (!isExit) {
		cout << "Ðàáîòà ñ äåêîì" << endl;
		cout << "1. Äîáàâèòü ýëåìåíò â íà÷àëî" << endl;
		cout << "2. Äîáàâèòü ýëåìåíò â êîíåö" << endl;
		cout << "3. Èçâëå÷ü ýëåìåíò ñ íà÷àëà" << endl;
		cout << "4. Èçâëå÷ü ýëåìåíò ñ êîíöà" << endl;
		cout << "5. Âûâåñòè íà ýêðàí" << endl;
		cout << "6. Îòñîðòèðîâàòü" << endl;
		cout << "0. Íàçàä" << endl;
		cout << "Âûáåðåòå ïóíêò ìåíþ: ";
		int method = safeInput(0, 6);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "Ââåäèòå ÷èñëî, êîòîðîå õîòèòå äîáàâèòü: ";
			tmp = safeInput(0, INT32_MAX);
			deque.push_font(tmp);
			break;
		case 2:
			cout << "Ââåäèòå ÷èñëî, êîòîðîå õîòèòå äîáàâèòü: ";
			tmp = safeInput(0, INT32_MAX);
			deque.push_back(tmp);
			break;
		case 3:
			try {
				cout << "Èçâëå÷åíî ÷èñëî: " << deque.pop_front() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 4:
			try {
				cout << "Èçâëå÷åíî ÷èñëî: " << deque.pop_back() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 5:
			deque.printToConsole();
			break;
		case 6:
			deque.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void workWithList(List<int>& list) {
	bool isExit = false;
	while (!isExit) {
		cout << "Ðàáîòà ñ äåêîì" << endl;
		cout << "1. Äîáàâèòü ýëåìåíò â íà÷àëî" << endl;
		cout << "2. Äîáàâèòü ýëåìåíò â êîíåö" << endl;
		cout << "3. Èçâëå÷ü ýëåìåíò ñ íà÷àëà" << endl;
		cout << "4. Èçâëå÷ü ýëåìåíò ñ êîíöà" << endl;
		cout << "5. Ïîëó÷èòü ýëåìåíò ïî èíäåêñó" << endl;
		cout << "6. Âûâåñòè íà ýêðàí" << endl;
		cout << "7. Îòñîðòèðîâàòü" << endl;
		cout << "0. Íàçàä" << endl;
		cout << "Âûáåðåòå ïóíêò ìåíþ: ";
		int method = safeInput(0, 7);
		int tmp;
		switch (method)
		{
		case 1:
			cout << "Ââåäèòå ÷èñëî, êîòîðîå õîòèòå äîáàâèòü: ";
			tmp = safeInput(0, INT32_MAX);
			list.push_font(tmp);
			break;
		case 2:
			cout << "Ââåäèòå ÷èñëî, êîòîðîå õîòèòå äîáàâèòü: ";
			tmp = safeInput(0, INT32_MAX);
			list.push_back(tmp);
			break;
		case 3:
			try {
				cout << "Èçâëå÷åíî ÷èñëî: " << list.pop_front() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 4:
			try {
				cout << "Èçâëå÷åíî ÷èñëî: " << list.pop_back() << endl;
			}
			catch (string err) {
				cout << err << endl;
			}
			break;
		case 5:
			cout << "Ââåäèòå èíäåêñ: ";
			tmp = safeInput(0, INT32_MAX);
			try {
				cout << "Ïî èíäåêñó " << tmp << " ëåæèò ÷èñëî: " << list[tmp] << endl;
			}
			catch (int err) {
				cout << "Èíäåêñ " << err << " íåäîïóñòèì" << endl;
			}
			break;
		case 6:
			list.printToConsole();
			break;
		case 7:
			list.sort();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void inputFromFile(Queue<int>& queue, Stack<int>& stack, Deque<int>& deque, List<int>& list) {
	string filename;
	if (InputInFileName(filename)) {
		ifstream in(filename);
		try
		{
			queue.inputFromFile(in);
			stack.inputFromFile(in);
			deque.inputFromFile(in);
			list.inputFromFile(in);
		}
		catch (string err)
		{
			cout << err << endl;
		}
		in.close();
	}
}

void printToFile(Queue<int>& queue, Stack<int>& stack, Deque<int>& deque, List<int>& list) {
	string filename;
	InputOutFileName(filename);
	ofstream out(filename);
	queue.printToFile(out);
	stack.printToFile(out);
	deque.printToFile(out);
	list.printToFile(out);
	out.close();
}  
