#ifndef LIST_HH
#define LIST_HH

#include "pch.h"

//Jeden czlon listy (element)
struct limb {
	limb* next;
	int node;
	int weight;
};

class List {
	int lwierzcholkow;
	int lkrawedzi;
	int gestosc;
	int** pom;
	limb** tab;
	limb* p;
	int* wage;
	int* number;

public:
	//Metody odpowiadajace za tworzenie i edycje listy sasiedztwa
	List(int, int);
	int getLwiecholkow();
	int getLkrawedzi();
	int getGestosc();
	void connectNodes();
	void writeList();
	void remove();

	//metody algorytmu Bellmana-Forda
	bool bellman_ford();
	void alg_bellmana_ford();

	//metoda testujaca czas dzialania algorytmu
	double time_test();
};

#endif

