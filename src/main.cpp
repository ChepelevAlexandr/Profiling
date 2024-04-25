#include <iostream>
#include <vector>
#include <random>
#include <chrono>

const int size = 500;

void generateMATRIX(const int size, std::vector<std::vector<int>>& matrix) {
	matrix.resize(size, std::vector<int>(size));

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			matrix[i][j] = dis(gen);
		}
	}
};

void OnColumns(const std::vector<std::vector<int>>& matrix) {
	int num = 0;
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size; i++) {
			num += matrix[j][i];
		}
	}
	std::cout << "By columnns " << num << std::endl;
}

void OnLines(const std::vector<std::vector<int>>& matrix) {
	int num = 0;
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size; i++) {
			num += matrix[i][j];
		}
	}
	std::cout << "By lines " << num << std::endl;
}


int main()
{

	std::vector<std::vector<int>> matrix;
	generateMATRIX(size, matrix);

	auto timeStartOnLines = std::chrono::high_resolution_clock::now();
	OnLines(matrix);
	auto timeEndOnLines = std::chrono::high_resolution_clock::now();

	auto timeStartOnColumns = std::chrono::high_resolution_clock::now();
	OnColumns(matrix);
	auto timeEndOnColumns = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> durationOnLines = timeEndOnLines - timeStartOnLines;
	std::cout << "time spent iterating over rows: " << durationOnLines.count() << " seconds" << std::endl;

	std::chrono::duration<double> durationOnColumns = timeEndOnColumns - timeStartOnColumns;
	std::cout << "time spent iterating over columns: " << durationOnColumns.count() << " seconds" << std::endl;

	return 0;
}

