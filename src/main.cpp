#include <iostream>
#include <vector>

void print(int* numbers, int* status) {
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

bool test(int* numbers, int* status) {
    int sum1 = 0;
    int sum2 = 0;
    
    for (int i=0; i<14; ++i) {
        if (status[i] == 1)
            sum1 += numbers[i];
        else if (status[i] == 2)
            sum2 += numbers[i];
    }
    
    return sum1 == sum2;
}

void probe(int* numbers, int* status, int current) {
    if (current == 13) {
        status[current] = 0;
        if (test(numbers, status))
            print(numbers, status);
            
        status[current] = 1;
        if (test(numbers, status))
            print(numbers, status);
            
        status[current] = 2;
        if (test(numbers, status))
            print(numbers, status);
    } else {
        status[current] = 0;
        probe(numbers, status, current + 1);
        
        status[current] = 1;
        probe(numbers, status, current + 1);
        
        status[current] = 2;
        probe(numbers, status, current + 1);
    }
}

int main() {
    int numbers[] = {501, 440, 607, 788, 132, 758, 651, 264, 18, 407, 263, 179, 906, 338};
    int status[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    probe(numbers, status, 0);
}
