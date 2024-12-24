#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

void part1() {
    std::fstream file("d1.txt");
    std::vector<int> left, right;
    left.reserve(1000), right.reserve(1000);

    // read file input
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            left.push_back(stoi(line.substr(0, 5)));
            right.push_back(stoi(line.substr(8, 13)));
        }
        file.close();
    } else {
        std::cout << "failed to open file" << std::endl;
        exit(-1);
    }
    
    // sort both lists
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
   
    // pair and find diff
    long long res = 0;
    for (int i = 0; i < 1000; i++) {
        res += abs(left[i] - right[i]);
    } 

    std::cout << res << std::endl;
}

void part2() {
    std::fstream file("d1.txt");
    std::vector<int> left, right;
    left.reserve(1000), right.reserve(1000);

    // read file input
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            left.push_back(stoi(line.substr(0, 5)));
            right.push_back(stoi(line.substr(8, 13)));
        }
        file.close();
    } else {
        std::cout << "failed to open file" << std::endl;
        exit(-1);
    }

    // store right list values into value:count pair
    std::unordered_map<int, int> umap;
    for (int i = 0; i < 1000; i++) {
        umap[right[i]]++;
    }

    int similarity = 0;
    for (int i = 0; i < 1000; i++) {
        similarity += umap[left[i]] * left[i];
    }
    std::cout << "similarity: " << similarity << std::endl;
}

int main() {
    //part1();
    part2();
    return 0;
}
