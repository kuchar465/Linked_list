
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <time.h>
#include <cmath>
#include "list.h"
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

struct dane {
	int liczba;
	char znak;

	bool operator <(const dane ob) {
		if (ob.liczba < this->liczba && ob.znak < this->znak) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator ==(const dane ob) {
		if (this->liczba == ob.liczba) {
			return true;
		}
		else {
			return false;
		}
	}
};

void write(dane ob) {
	std::cout << "dana pierwsza: " << ob.liczba << std::endl;
	std::cout << "dana druga: " << ob.znak << std::endl;
}


void pomiarstop(clock_t begin) {
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
}

void pomiarstop(clock_t begin, int time) {
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	double elapsed_secs_ave = (double(end - begin) / CLOCKS_PER_SEC) / time;
	std::cout << elapsed_secs << std::endl;
}

int main() {
	srand(time(NULL));
	int liczba=0, tmp;
	char znak=0;
	clock_t t1 = NULL;
	list<dane> *il = new list<dane>();

	const int repeat = 3;
	for (int i = 1; i <= repeat; i++) {
		const int n = pow(10, i);
		
		t1 = clock();
		for (int i = 0; i < n; i++) {
			dane *ob1 = new dane();
			ob1->liczba = 0 + rand() % (10000 - 0 + 1);
			ob1->znak = 65 + rand() % (122 - 65 + 1);
			il->Add_end(*ob1);
			delete ob1;
		}
		std::cout << "Pomiar add start lub end " << i << " Wynosi: " << std::endl;
		pomiarstop(t1);
		std::cout << "Sredni czas wynosi: " << std::endl;
		pomiarstop(t1, n - 1);
		std::cout << std::endl;
	
		t1 = clock();
		for (int i = 0; i < n; i++) {
			dane *ob1 = new dane();
			tmp = 0 + rand() % ((n-1) - 0 + 1);
			ob1->liczba = 0 + rand() % (10000 - 0 + 1);
			ob1->znak = 65 + rand() % (122 - 65 + 1);
			il->Show_element(tmp);
			delete ob1;
		}
		std::cout << "Pomiar Wyszukanie i-tego elementu " << i << " Wynosi: " << std::endl;
		pomiarstop(t1);
		std::cout << "Sredni czas wynosi: " << std::endl;
		pomiarstop(t1, n - 1);
		std::cout << std::endl;

		t1 = clock();
		for (int i = 0; i < n; i++) {
			dane *ob1 = new dane();
			tmp = 0 + rand() % ((n - 1) - 0 + 1);
			ob1->liczba = 0 + rand() % (10000 - 0 + 1);
			ob1->znak = 65 + rand() % (122 - 65 + 1);
			il->Find_data(*ob1);
			delete ob1;
		}
		std::cout << "Pomiar Wyszukanie elementu " << i << " Wynosi: " << std::endl;
		pomiarstop(t1);
		std::cout << "Sredni czas wynosi: " << std::endl;
		pomiarstop(t1, n - 1);
		std::cout << std::endl;

		t1 = clock();
		for (int i = 0; i < n; i++) {
			dane *ob1 = new dane();
			tmp = 0 + rand() % ((n - 1) - 0 + 1);
			ob1->liczba = 0 + rand() % (10000 - 0 + 1);
			ob1->znak = 65 + rand() % (122 - 65 + 1);
			il->Change_element(tmp, *ob1);
			delete ob1;
		}
		std::cout << "Pomiar podmiana elementu " << i << " Wynosi: " << std::endl;
		pomiarstop(t1);
		std::cout << "Sredni czas wynosi: " << std::endl;
		pomiarstop(t1, n - 1);
		std::cout << std::endl;
	
		t1 = clock();
		for (int i = 0; i < n; i++) {
			il->Delete_end();
		}
		std::cout << "Pomiar delete start lub end " << i << " Wynosi: " << std::endl;
		pomiarstop(t1);
		std::cout << "Sredni czas wynosi: " << std::endl;
		pomiarstop(t1, n - 1);
		std::cout << std::endl;
	

		t1 = clock();
		for (int i = 0; i < n; i++) {
			dane *ob1 = new dane();
			ob1->liczba = 0 + rand() % (10000 - 0 + 1);
			ob1->znak = 65 + rand() % (122 - 65 + 1);
			il->add_sort(*ob1);
			delete ob1;
		}
		std::cout << "Pomiar add sort " << i << " Wynosi: " << std::endl;
		pomiarstop(t1);
		std::cout << "Sredni czas wynosi: " << std::endl;
		pomiarstop(t1, n - 1);
		std::cout << std::endl;
	
		t1 = clock();
		for (int i = 0; i < n/2; i++) {
			dane *ob1 = new dane();
			ob1->liczba = 0 + rand() % (10000 - 0 + 1);
			ob1->znak = 65 + rand() % (122 - 65 + 1);
			il->Find_data_del(*ob1);
			delete ob1;
		}
		std::cout << "Pomiar find and delete " << i << " Wynosi: " << std::endl;
		pomiarstop(t1);
		std::cout << "Sredni czas wynosi: " << std::endl;
		pomiarstop(t1, n - 1);
		std::cout << std::endl;
	
		il->clear();

	}
	delete il;

	
	system("Pause");
	_CrtDumpMemoryLeaks();
	return 0;
};