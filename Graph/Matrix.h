#ifndef MATRIX_HH
#define MATRIX_HH
#include "pch.h"

class Matrix {
	int lwierzcholkow;
	int lkrawedzi;
	int gestosc;	
	int** tab;
	int* wage;
	int* number;

public:
	//Metody odpowiadajace za tworzenie i edycje macierzy sasiedztwa
	Matrix(int, int);
	int getLWiecholkow();
	int getLKrawedzi();
	int getGestosc();
	void connectNodes();
	void remove();
	void writeMatrix();

	//metody algorytmu Bellmana-Forda
	bool bellman_ford();
	void alg_bellman_forda();
	//metoda testujaca czas dzialania algorytmu
	double time_test();
};

#endif 