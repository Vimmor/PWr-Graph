#include "List.h"

List::List(int liczbaW, int zageszczenie) :lwierzcholkow(liczbaW), gestosc(zageszczenie) {
	tab = new limb * [liczbaW];
	lkrawedzi = (liczbaW * zageszczenie * (liczbaW - 1)) / 200;

	for (int i = 0; i < liczbaW; i++) {
		tab[i] = NULL;
	}

	pom = new int* [liczbaW];
	for (int i = 0; i < liczbaW; i++) {
		pom[i] = new int[liczbaW];
	}
	
	for (int i = 0; i < liczbaW; i++) {
		for (int j = 0; j < liczbaW; j++) {
			pom[i][j] = 0;
		}
	}
}

int List::getLwiecholkow() {
	return lwierzcholkow;
}

int List::getLkrawedzi() {
	return lkrawedzi;
}

int List::getGestosc() {
	return gestosc;
}
//Metoda, ktora laczy wierzcholki ze soba i nadaje im wagi
void List::connectNodes() {
	int tmp = lkrawedzi;
	int wage;
	limb* p;
	if (gestosc < 100) {
		while (tmp) {
			int x = rand() % lwierzcholkow;
			int y = rand() % lwierzcholkow;
			wage = rand() % 10 + 1;
			if (x > y && !pom[y][x]) {
				p = new limb;
				p->node = x;
				p->weight = wage;
				p->next = tab[y];
				tab[y] = p;
				pom[y][x] = 1;
				tmp--;
			}
			 else if(y > x && !pom[x][y]) {
				p = new limb;
				p->node = y;
				p->weight = wage;
				p->next = tab[x];
				tab[x] = p;
				pom[x][y] = 1;
				tmp--;
			}
		}
	}
	else {
		for (int i = 0; i < lwierzcholkow; i++) {
			for (int j = 0; j < lwierzcholkow; j++) {
				if (j > i) {
				    wage = rand() % 10 + 1;
					p = new limb;
					p->node = j;
					p->weight = wage;
					p->next = tab[i];
					tab[i] = p;
					pom[i][j] = 1;
				}
			}
		}
	}
}
// metoda wypisujaca liste na standardowe wyjscie
void List::writeList() {
	std::cout << "Lista sasiedztwa:" << std::endl;
	limb* p = new limb;
	for (int i = 0; i < lwierzcholkow; i++)
	{
		std::cout << "Tab[" << i << "] =";
		p = tab[i];
		while (p)
		{
			std::cout << std::setw(3) << p->node;
			p = p->next;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "Wagi czlonow:" << std::endl;
	for (int i = 0; i < lwierzcholkow; i++)
	{
		std::cout << "Tab[" << i << "] =";
		p = tab[i];
		while (p)
		{
			std::cout << std::setw(3) << p->weight;
			p = p->next;
		}
		std::cout << std::endl;
	}
}
// zwolnienie pamieci
void List::remove() {
	limb* k;
	limb* p = new limb;
	for (int i = 0; i < lwierzcholkow; i++) {
		p = tab[i];
		while (p) {
			k = p;
			p = p->next;
			delete k;
		}
	}
	for (int i = 0; i < lwierzcholkow; i++) {
		delete[] pom[i];
	}
	delete[] tab;
	delete[] pom;
	delete[] wage;
	delete[] number;
}
// algorytm bellmana - forda
bool List::bellman_ford() {
	limb* tmp;

	for (int i = 0; i < lwierzcholkow; i++) {
		number = new int[lwierzcholkow];
		wage = new int[lwierzcholkow];
	}
	for (int i = 0; i < lwierzcholkow; i++) {
		number[i] = -1; // Oznaczamy w ten sposob brak poprzednika
		wage[i] = MAX; //standardowo wszystkie ustawiamy na MAX
	}
	wage[0] = 0; // wierzcholek startowy 

	for (int i = 0; i < lwierzcholkow; i++) {
		for (int j = 0; j < lwierzcholkow; j++) {
			for (tmp = tab[j]; tmp; tmp = tmp->next) {
				if (wage[tmp->node] > wage[j] + tmp->weight) {
					number[tmp->node] = j;
					wage[tmp->node] = wage[j] + tmp->weight;
				}
			}
		}
	}
	for (int i = 0; i < lwierzcholkow; i++) {
		if (wage[i] < 0)
			return false;
	}
	return true;
}
//metoda wypisuje koszt drogi z zerowego wierzcholka do innych wierzcholkow
void List::alg_bellmana_ford() {
	int* stos;
	if (bellman_ford()) {
		stos = new int[lwierzcholkow];
		int pom = 0;
		for (int i = 0; i < lwierzcholkow; i++) {
			std::cout << i << ": ";
			for (int j = i; j != -1; j = number[j]) {
				stos[pom++] = j;
			}
			while (pom) {
				std::cout << stos[--pom] << " ";
			}
			std::cout << "Wage: " << wage[i] << std::endl;
		}
		delete[] stos;
	}
	else
		std::cout << "There is a negative cycle, try again." << std::endl;
}
//timer
float List::time_test() {
	clock_t start, stop;
	float time;
	bool check;

	start = std::clock();
	check = bellman_ford();
	stop = std::clock();

	if (check==true) {
		time = (float)(stop - start) / CLOCKS_PER_SEC;
		return time;
	}
	else
		return -1;
}