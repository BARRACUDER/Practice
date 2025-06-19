
#include <iostream>
#include <vector>
#include <string>

int main()
{
	int n, m;
	std::cout << "Enter widht and lenght of rectange:";
	std::cin >> n >> m;
	std::vector<std::vector<int>> matrix(n);
	std::pair<size_t, size_t> first, second;
	bool flag = true;
	std::cout << "Enter rectange:\n";
	for (int i = 0; i < n; i++) {
		matrix[i].resize(m);
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j];
			if (matrix[i][j] == 1) {
				if (flag) {
					first.first = i - 1;
					first.second = j - 1;
					flag = false;
				} else {
				second.first = i + 1;
				second.second = j + 1;
				}
			} 
		}
	}
	std::cout << "First point: " << first.first << " " << first.second << " second point: " << second.first << " " << second.second << "\n";
}
