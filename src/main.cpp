#include "Solver.hpp"
#include "ScreenCapture.hpp"
#include "Execute.hpp"
#include "SimulatedMouse.hpp"
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
    if (!(file >> number)) {
        file.close();
        return 0;
    }
    file.close();
    
    return number;
}

int main() {
    std::pair<int, int> positions[] = {            {913, 137},
                                             {817, 253}, {1010, 253},
                                       {720, 369}, {913, 369}, {1106, 369},
                                             {817, 484}, {1010, 484},
                                       {720, 600}, {913, 600}, {1106, 600},
                                             {817, 716}, {1010, 716},
                                                   {913, 831}             };
    
    Solver solver;
    unsigned int numbers[14];
    unsigned int allowedSolution = 0;
    
    // Instruct user to switch to Three Digits, then wait for them to do so.
    std::cout << "You have 10 seconds to switch to Three Digits and open the level you're currently on." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    
    while (true) {
        // Get numbers.
        std::cout << "Get numbers" << std::endl;
        bool same = true;
        for (int i=0; i<14; ++i) {
            unsigned int number = GetNumber(positions[i]);
            std::cout << positions[i].first << ":" << positions[i].second << " - " << number << std::endl;
            if (number != numbers[i])
                same = false;
            numbers[i] = number;
        }
        
        // Don't allow the same solution if it didn't work before.
        if (same) {
            // Click reset button.
            SimulatedMouse::Click(956, 1004);
            std::this_thread::sleep_for(std::chrono::seconds(3));
            
            ++allowedSolution;
            
            std::cout << "Same level" << std::endl;
        } else {
            allowedSolution = 0;
        }
            
        
        // Solve.
        solver.SetNumbers(numbers);
        solver.Solve();
        
        const unsigned char* solution = solver.GetSolution();
        
        for (int i=0; i<14; ++i) {
            for (unsigned char times = 0; times < solution[i]; ++times)
                SimulatedMouse::Click(positions[i].first, positions[i].second);
        }
        
        // Wait until next level has finished loading.
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}
