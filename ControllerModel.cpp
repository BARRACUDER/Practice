
#include <iostream>
#include <vector>
#include <string>

int main()
{
	int n;
	std::cout << "Enter the number of calls: ";
	std::cin >> n;
	int a, b, x, y;
	std::vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		std::cout << "Enter the number A, B, x, y: ";
		std::cin >> a >> b >> x >> y;
		ans[i] = std::min(b, x) + std::min(a, std::max(0, x - b) + y);
		std::cout << "The max number of Plates:" << ans[i] << "\n";
	}
}