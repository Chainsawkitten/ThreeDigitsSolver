#include "Solver.hpp"
#include "ScreenCapture.hpp"
#include "Execute.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <windows.h>

unsigned int GetNumber(std::pair<int, int> position) {
    // Capture relevant part of screen.
    ScreenCapture::CapturePart(position.first, position.second, 93, 35, "temp.bmp");
    
    // Use tesseract to get text.
    Execute::ExecuteCommandLine("tesseract.exe temp.bmp out");
    
    // Read text file and get the number.
    std::ifstream file("out.txt");
    unsigned int number;
    file >> number;
    file.close();
    
    return number;
}

int main() {
    std::pair<int, int> positions[] = {           {913, 137},
                                                  {817, 253}, {1010, 253},
                                                  {720, 369}, {913, 369}, {1106, 369},
                                                  {817, 484}, {1010, 484},
                                                  {720, 600}, {913, 600}, {1106, 600},
                                                  {817, 716}, {1010, 716},
                                                  {913, 831}              };
    
    Solver solver;
    unsigned int numbers[14] = {501, 440, 607, 788, 132, 758, 651, 264, 18, 407, 263, 179, 906, 338};
    
    // Instruct user to switch to Three Digits, then wait for them to do so.
    std::cout << "You have 10 seconds to switch to Three Digits and open the level you're currently on." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    
    // Test getting number.
    unsigned int testNumber = GetNumber(positions[0]);
    std::cout << "Got number: " << testNumber << std::endl;
}
