#ifndef VISUALIZATION_TEST_HH
#define VISUALIZATION_TEST_HH
#include "Matrix.h"
#include "List.h"
#include "pch.h"

//Klasa do wykonania testow 
class Visualization_test {
	List* l;
	Matrix* m;
public:
	void test_Matrix(int, int);
	void test_List(int, int);
	void menu();
};
#endif 
