#include "Matrix.h"

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
			int x = rand() % lwierzcholkow;
			int y = rand() % lwierzcholkow;
			if (y > x && !tab[y][x]) {
				tmp--;
				tab[y][x] = rand() % 9 + 1;
			}
		}
	}
	else {
		for (int i = 0; i < lwierzcholkow; i++) {
			for (int j = 0; j < lwierzcholkow; j++) {
				if (j > i) {
					tab[i][j] = rand() % 9 + 1;
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
	for (int i = 0; i < lwierzcholkow; i++) {
		std::cout << std::endl << std::setw(2);
		for (int j = 0; i < lwierzcholkow; j++) {
			std::cout << std::setw(2) << tab[i][j];
		}
	}
}