#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// -- global variables --
std::vector< std::vector<int> > reports;

// -- functions --
void part1();
void part2();

int main(void) {
    // read in day2 input
    reports.reserve(1000);
    std::fstream file("day2.txt");

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::vector<int> row;
            int value;
            while (ss >> value) {
                row.push_back(value);
            }
            reports.push_back(row);
        }
        file.close();
    }
    
    part1();
    part2();
    return 0;
}

void part1() {
    // @@NOTE: reports are safe if...
    //  - levels are all increasing or all decreasing
    //  - any two adjacent levels differ by at least one and at most three

    int num_safe = 0;
    for (int i = 0; i < reports.size(); i++) {
        bool isIncreasing;
        bool isSafe = true;
        for (int j = 0; j < reports[i].size()-1; j++) {
            int first = reports[i][j];
            int second = reports[i][j+1];

            if (j == 0) {
                isIncreasing = (first < second);
            }             

            // increasing
            if (first < second) {
                if (!isIncreasing) {
                    isSafe = false;
                    continue;
                }
            }  
            // decreasing
            else {
                if (isIncreasing) {
                    isSafe = false;
                    continue;
                }
            }
            int diff = abs(first - second);
            if (!(1 <= diff && diff <= 3))
                isSafe = false;
                
        }
        if (isSafe) num_safe++;
    }
    
    std::cout << "part1 - safe: " << num_safe << std::endl;
}
 
void part2() {
    return;
}
