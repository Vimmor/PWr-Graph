#include "visualization_test.h"

// test szybkosci dzialania algorytmu dla macierzy
void Visualization_test::test_Matrix(int liczbaW, int zageszczenie) {
	float time_table[INSTANCE_QUANTITY];
	float sum=0;

	for (int i = 0; i < INSTANCE_QUANTITY; i++) {
		m = new Matrix(liczbaW, zageszczenie);
		m->connectNodes();
		time_table[i] = m->time_test();
		m->remove();
	}
	for (int i = 0; i < INSTANCE_QUANTITY; i++)
		sum += time_table[i];

	std::cout<<"Wynik dla macierzy sasiedztwa:"<<std::endl;
	std::cout << "Liczba Wierzcholkow:" << liczbaW << " Gestosc grafu:" << zageszczenie << std::endl;
	std::cout << "Sredni czas:" << sum / 100 << std::endl;

}

//test szybkosci dzialania algorytmu dla listy
void Visualization_test::test_List(int liczbaW, int zageszczenie) {
	float time_table[INSTANCE_QUANTITY];
	float sum=0;

	for (int i = 0; i < INSTANCE_QUANTITY; i++) {
		l = new List(liczbaW, zageszczenie);
		l->connectNodes();
		time_table[i] = l->time_test();
		l->remove();
	}
	for (int i = 0; i < INSTANCE_QUANTITY; i++)
		sum += time_table[i];

	std::cout << "Wynik dla listy sasiedztwa:" << std::endl;
	std::cout << "Liczba Wierzcholkow:" << liczbaW << " Gestosc grafu:" << zageszczenie << std::endl;
	std::cout << "Sredni czas:" << sum / 100 << std::endl;
}

//menu uzytkownika
void Visualization_test::menu() {
	srand(time(NULL));
	std::cout << "Program realizujacy problem najkrotszej sciezki za pomoca algorytmu Bellmana-Forda" << std::endl;
	std::cout << "Niezaleznie od wyboru liczby wierzcholkow grafu, algorytm zostanie sprawdzony dla grafow o gestosciach: 25%,50%,75%,100%\n" << std::endl;
	int choice;
	int density_table[4] = {25,50,75,100 };
	do {
		std::cout << "1. Test dzialania programu\n";
		std::cout << "2. Liczba Wiecholkow: 50\n";
		std::cout << "3. Liczba Wiecholkow: 100\n";
		std::cout << "4. Liczba Wiecholkow: 200\n";
		std::cout << "5. Liczba Wiecholkow: 500\n";
		std::cout << "6. Liczba Wiecholkow: 1000\n";
		std::cout << "0. Zakoncz dzialanie programu\n";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			m = new Matrix(10, 50);
			m->connectNodes();
			m->writeMatrix();
			std::cout << std::endl;
			m->alg_bellman_forda();
			m->remove();
			std::cout << std::endl;

			l = new List(10, 50);
			l->connectNodes();
			l->writeList();
			std::cout << std::endl;
			l->alg_bellmana_ford();
			l->remove();
			
			std::cout << std::endl;
			break;
		}
		case 2: {
			for (int i = 0; i < 4; i++) {
				test_Matrix(10, density_table[i]);
				test_List(10, density_table[i]);
			}
			std::cout << std::endl;
			break;
		}
		case 3: {
			for (int i = 0; i < 4; i++) {
				test_Matrix(100, density_table[i]);
				test_List(100, density_table[i]);
			}
			std::cout << std::endl;
			break;
		}
		case 4: {
			for (int i = 0; i < 4; i++) {
				test_Matrix(200, density_table[i]);
				test_List(200, density_table[i]);
			}
			std::cout << std::endl;
			break;
		}
		case 5: {
			for (int i = 0; i < 4; i++) {
				test_Matrix(500, density_table[i]);
				test_List(500, density_table[i]);
			}
			std::cout << std::endl;
			break;
		}
		case 6: {
			for (int i = 0; i < 4; i++) {
				test_Matrix(1000, density_table[i]);
				test_List(1000, density_table[i]);
			}
			std::cout << std::endl;
			break;
		}
		case 0: break;
		default: {
			std::cout << "Wybrales zly numer, sprobuj ponownie." << std::endl;
			break;
		}
		}
	} while (choice != 0);
}

