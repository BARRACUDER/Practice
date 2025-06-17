#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void Moon_Generate(std::vector<std::vector<int>> &Moon, size_t height) {
    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 1;
    int max = 100;
    std::uniform_int_distribution<> rand(min, max);
    Moon.resize(height);
    for (size_t i = 0; i < height; i++) {
        Moon[i].resize(i + 1);
        for (size_t j = 0; j <= i; j++) {
            Moon[i][j] = rand(gen);
        }
    }
}
void find_Path(std::vector<std::vector<int>> &Moon, 
    std::vector<std::vector<int>> &Dp_Moon, size_t height, int &time, std::vector<int> &Path) {
    Dp_Moon.resize(height);
    for (size_t i = 0; i < height; i++) {
        Dp_Moon[i].resize(i + 3, 99999999);
    }
    Dp_Moon[0][0] = Moon[0][0];
    for (size_t i = 1; i < height; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            int min_prev = 9999;
            if (j > 0) min_prev = std::min(min_prev, Dp_Moon[i-1][j-1]);
            if (j < i) min_prev = std::min(min_prev, Dp_Moon[i-1][j]);
            if (j < i-1) min_prev = std::min(min_prev, Dp_Moon[i-1][j+1]);
            Dp_Moon[i][j] = Moon[i][j] + min_prev;
        }
    }
    size_t current = std::min_element(Dp_Moon[height - 1].begin(), Dp_Moon[height - 1].end()) - Dp_Moon[height - 1].begin();
    Path.push_back(Moon[height-1][current]);
    time = Dp_Moon[height - 1][current];
    for (int i = height-2; i >= 0; --i) {
        if (current == 0) {
            current = std::min_element(Dp_Moon[i].begin(), Dp_Moon[i].begin() + 2) - Dp_Moon[i].begin(); 
        } else {
            current = std::min_element(Dp_Moon[i].begin() + current - 1, Dp_Moon[i].begin() + current + 1) - Dp_Moon[i].begin();
        }
        
        Path.push_back(Moon[i][current]);
    }

    std::reverse(Path.begin(), Path.end());
}
int main() {
    size_t height;
    std::cout << "Enter the height of the pyramid: ";
    std::cin >> height;
    std::vector<std::vector<int>> Moon(height), Dp_Moon(height);
    std::vector<int> Path;
    Moon_Generate(Moon, height);
    int time;
    find_Path(Moon, Dp_Moon, height, time, Path);
    std::cout << "your Pyramid:\n";
    for (auto i : Moon) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Your Time: " << time << "\n";
    std::cout << "Your Path: ";
    for (auto j : Path) {
        std::cout << j << " ";
    }
    std::cout << "\n";
    return 0;
}