
#include <iostream>
#include <vector>
#include <string>

int main()
{
	int n, k;
	std::cout << "Enter lenght of the word and number of transposition:";
	std::cin >> n >> k;
	std::vector<int> partition(n), ans(n, 0);
	std::string word;
	std::cout << "Enter transposition code:\n";
	for (int i = 0; i < n; i++) {
		std::cin >> partition[i];
		partition[i]--;
	}
	std::cout << "Enter transposited word:\n";
	std::cin >> word;
	for (int i = 0; i < n; i++) {
		int num = i;
		for (int j = 0; j < k; j++) {
			num = partition[num];
		}
		ans[num] = i;
	}
	std::cout << "Your restored word:\n";
	for (int i = 0; i < n; i++) {
		std::cout << word[ans[i]];
	}
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
