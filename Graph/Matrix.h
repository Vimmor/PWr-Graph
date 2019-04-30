#ifndef GRAPH_HH
#define GRAPH_HH
#include "pch.h"

class Matrix {
	int lwierzcholkow;
	int lkrawedzi;
	int gestosc;
	
public:
	int** tab;
	Matrix(int, float);
	int getLWiecholkow();
	int getLKrawedzi();
	int getGestosc();
	void connectNodes();
	void remove();
	void writeMatrix();
};

Matrix::Matrix(int liczbaW, float zageszczenie) :lwierzcholkow(liczbaW),gestosc(zageszczenie) {
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

#endif 