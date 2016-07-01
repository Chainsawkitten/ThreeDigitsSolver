#include "Solver.hpp"

#include <vector>
#include <iostream>

void Solver::SetNumbers(unsigned int* numbers) {
    for (int i=0; i<14; ++i) {
        this->numbers[i] = numbers[i];
        status[i] = 0;
    }
}

void Solver::Solve() {
    Probe(0);
}

void Solver::Print() {
    std::vector<int> first;
    std::vector<int> second;
    
    for (int i=0; i<14; ++i) {
        if (status[i] == 1)
            first.push_back(numbers[i]);
        else if (status[i] == 2)
            second.push_back(numbers[i]);
    }
    
    for (std::size_t i=0; i<first.size(); ++i) {
        std::cout << first[i];
        if (i < first.size() - 1)
            std::cout << " + ";
    }
    std:: cout << " = ";
    for (std::size_t i=0; i<second.size(); ++i) {
        std::cout << second[i];
        if (i < second.size() - 1)
            std::cout << " + ";
    }
    std::cout << std::endl;
}

bool Solver::Test() {
    int sum1 = 0;
    int sum2 = 0;
    
    for (int i=0; i<14; ++i) {
        if (status[i] == 1)
            sum1 += numbers[i];
        else if (status[i] == 2)
            sum2 += numbers[i];
    }
    
    return sum1 > 0 && sum1 == sum2;
}

bool Solver::Probe(int current) {
    if (current == 13) {
        status[current] = 0;
        if (Test())
            return true;
            
        status[current] = 1;
        if (Test())
            return true;
            
        status[current] = 2;
        if (Test())
            return true;
    } else {
        status[current] = 0;
        if (Probe(current + 1))
            return true;
        
        status[current] = 1;
        if (Probe(current + 1))
            return true;
        
        status[current] = 2;
        if (Probe(current + 1))
            return true;
    }
    
    return false;
}
