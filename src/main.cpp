#include "Solver.hpp"

int main() {
    unsigned int numbers[] = {501, 440, 607, 788, 132, 758, 651, 264, 18, 407, 263, 179, 906, 338};
    
    Solver solver;
    solver.SetNumbers(numbers);
    solver.Solve();
    solver.Print();
}
