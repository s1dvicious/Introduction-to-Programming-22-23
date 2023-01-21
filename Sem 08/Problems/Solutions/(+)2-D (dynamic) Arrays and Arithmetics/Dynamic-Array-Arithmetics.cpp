#include <iostream>
using namespace std;

void allocate(int**& ptr, size_t n, size_t m) {

	ptr = new int* [n];

	for (size_t i = 0; i < n; ++i) {

		ptr[i] = new int [m];

	}
}

void input(int** ptr, size_t n, size_t m) {


	for (size_t i = 0; i < n; ++i) {

		for (size_t j = 0;j < m; ++j) {

			std::cin>>ptr[i][j];
		}
	}

}

void print(int** ptr, size_t n, size_t m) {


	for (size_t i = 0; i < n; ++i) {

		for (size_t j = 0; j < m; ++j) {

			std::cout << ptr[i][j]<<" ";

		}
		std::cout << std::endl;
	}

}

int** getTransposed(int** matrix2d, size_t n_cols, size_t m_rows) {

	int** transposed = new int* [m_rows];

	for (size_t i = 0; i < m_rows; ++i) {

		transposed[i] = new int[n_cols];

		for (size_t j = 0; j < n_cols; ++j) {

			transposed[i][j] = matrix2d[j][i];

		}

	}

	return transposed;
}

void deallocate(int** ptr, size_t n, size_t m) {

	for (size_t i = 0; i < n; ++i) {
		delete[] ptr[i];
	}

	delete[] ptr;
}

int** multiplicateMatrices(const int** matr1, size_t n1, size_t m1,
	int** matr2, size_t n2, size_t m2) {

	if (m1 != n2) {
		std::cout << "Cannot be multiplied!";
		return nullptr;
	}

	//n1 x m2
	int** mult = new int* [n1];

	for (size_t i = 0; i < n1; ++i) {

		mult[i] = new int[m2];
		for (size_t j = 0; j < m2; ++j) {

			mult[i][j] = 0;

			for (size_t k = 0; k < n1; ++k) {

				mult[i][j] += matr1[i][m1] * matr2[m1][j];

			}

		}

	}
	return mult;
}

