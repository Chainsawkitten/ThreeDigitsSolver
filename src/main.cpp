#include "Solver.hpp"
#include "ScreenCapture.hpp"

int main() {
    unsigned int numbers[] = {501, 440, 607, 788, 132, 758, 651, 264, 18, 407, 263, 179, 906, 338};
    Solver solver;
    
    // Test solver.
    solver.SetNumbers(numbers);
    solver.Solve();
    solver.Print();
    
    // Test taking screenshot.
    ScreenCapture::CapturePart(0, 0, 400, 300, "test.bmp");
}
