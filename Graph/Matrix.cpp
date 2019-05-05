#include "Matrix.h"

Matrix::Matrix(int liczbaW, int zageszczenie) :lwierzcholkow(liczbaW), gestosc(zageszczenie) {
	lkrawedzi = (liczbaW * zageszczenie * (liczbaW - 1)) / 200;
	tab = new int* [liczbaW];

	for (int i = 0; i < liczbaW; i++) {
		tab[i] = new int[liczbaW];
	}

	for (int i = 0; i < liczbaW; i++) {
		for (int j = 0; j < liczbaW; j++) {
			tab[i][j] = 0;
		}
	}
}

int Matrix::getLWiecholkow() {
	return lwierzcholkow;
}

int Matrix::getGestosc() {
	return gestosc;
}

int Matrix::getLKrawedzi() {
	return lkrawedzi;
}

void Matrix::connectNodes() {
	int tmp = lkrawedzi;
	if (gestosc < 100) {
		while (tmp) {
			int i = rand() % lwierzcholkow;
			int j = rand() % lwierzcholkow;
			if (j > i && !tab[i][j]) {
				tmp--;
				tab[i][j] = rand() % 10 + 1;
			}
			else if (i > j && !tab[j][i]) {
				tmp--;
				tab[j][i] = rand()%10 + 1;
			}
		}
	}
	else {
		for (int i = 0; i < lwierzcholkow; i++) {
			for (int j = 0; j < lwierzcholkow; j++) {
				if (j > i) {
					tab[i][j] = rand() % 10 + 1;
				}
			}
		}
	}
}

void Matrix::remove() {
	for (int i = 0; i < lwierzcholkow; i++)
		delete[] tab[i];
	delete[] tab;
}

void Matrix::writeMatrix() {

	std::cout << "Macierz sasiedztwa:";
	std::cout << std::endl<< "    ";
	for (int i = 0; i < lwierzcholkow; i++)
		std::cout << std::setw(3) << i;

	std::cout << std::endl;
	std::cout << "  ";
	for (int i = 0; i < lwierzcholkow + 1; i++)
		std::cout << std::setw(3) << "_";

	std::cout << std::endl;
	for (int i = 0; i < lwierzcholkow; i++) {
		std::cout << std::setw(3) << i << "|";
		for (int j = 0; j < lwierzcholkow; j++)
			std::cout << std::setw(3) << tab[i][j];
		std::cout << std::endl;
	}
}	  

bool Matrix::bellman_ford() {
	wage = new int[lwierzcholkow];
	number = new int[lwierzcholkow];
	for (int i = 0; i < lwierzcholkow; i++) {
		wage[i] = MAX;
		number[i] = -1;
	}
	wage[0] = 0;

	for (int i = 1; i <= lwierzcholkow; i++) {
		for (int j = 0; j < lwierzcholkow; j++) {
			for (int x = 0; x < lwierzcholkow; x++) {
				if ((tab[j][x] != 0) && (wage[x]) >= (wage[j] + tab[j][x])) {
					number[x] = j;
					wage[x] = wage[j] + tab[j][x];
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

void Matrix::alg_bellman_forda() {
	int* stos;
	if (bellman_ford()) {
		stos = new int[lwierzcholkow];      //Tworzenie stosu
		int pom = 0;
		for (int i = 0; i < lwierzcholkow; i++) {
			std::cout << i << ": ";
			for (int j = i; j != -1; j = number[j])
				stos[pom++] = j;
			while (pom) {
				std::cout << stos[--pom] << " ";
			}
			std::cout << "wage:" << wage[i] << std::endl;
		}
		delete[] stos;
	}
	else
		std::cout << "There is a negative cycle, try again." << std::endl;
	delete number;
	delete wage;
}

float Matrix::time_test() {
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