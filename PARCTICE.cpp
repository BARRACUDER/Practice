#include <iostream>
#include <vector>

class fanfic {
private:
    std::vector<int> city;
    int size;
public:
    fanfic(int n) : size(n + 2), city(n + 2, 0) {}
    
    void modify(int i, int d) {
        while (i < size) {
            city[i] += d;
            i = i | (i + 1);
        }
    }
    
    void set(int i, int x) {
        int current = sum(i) - sum(i - 1);
        int d = x - current;
        modify(i, d);
    }
    
    int sum(int i) {
        int res = 0;
        while (i > 0) {
            res += city[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    
    int citysum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    int n, m;
    std::cout << "write number of streets and number of calls: ";
    std::cin >> n >> m;
    std::cout << "write '1 <number> <snow_high>' to change the amount of snow on the street\n";
    std::cout << "write '2 left_street right_street' to see the amount of snow between those streets\n";
    fanfic city(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == 1) {
            city.set(b, c);
            std::cout << "Snow number succesfuly changed\n";
        } else if (a == 2) {
            std::cout << "The sum of snow between streets " << b << " and " << c 
                      << " is: " << city.citysum(b, c) << "\n";
        } else {
            std::cout << "wrong command\n";
        }
    }
    return 0;
}