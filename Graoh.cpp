#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

class Graph {
private:
    std::vector<std::vector<int>> vertices_;
    std::vector<Colors> colors_;

public:
    explicit Graph(int n, int m) {
        vertices_.resize(n);
        colors_.resize(n, White);
        for (int i = 0; i < m; i++) {
            int v1 = 0;
            int v2 = 0;
            std::cin >> v1 >> v2;
            --v1;
            --v2;
            vertices_[v1].push_back(v2);
            vertices_[v2].push_back(v1);
        }
    }
    void DFS(int index) {
        colors_[index] = Grey;
        for (int ner : vertices_[index]) {
            if (colors_[ner] == White) {
                DFS(ner);
            }
        }
        colors_[index] = Black;
    }

    void ComponentCount() {
        int count = 0;
        for (int i = 0; i < static_cast<int>(vertices_.size()); i++) {
            if (colors_[i] == White) {
                DFS(i);
                count++;
            }
        }
        std::cout << "You have " << count - 1 << " Components\n";
    }
};

int main() {
    int n = 0, m = 0;
    std::cout << "write your number of vertices: ";
    std::cin >> n;
    std::cout << "write your number of edges: ";
    std::cin >> m;
    std::cout << "write your edges:\n";
    Graph graph(n, m);
    graph.ComponentCount();
    return 0;
}