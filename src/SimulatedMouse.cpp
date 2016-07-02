#include "SimulatedMouse.hpp"

#include <windows.h>
#include <thread>
#include <chrono>

namespace SimulatedMouse {
    void Click(int x, int y) {
        INPUT input;
        input.type = INPUT_MOUSE;
        input.mi.dx = static_cast<long>(static_cast<double>(x) / 1920.0 * 65535.0);
        input.mi.dy = static_cast<long>(static_cast<double>(y) / 1080.0 * 65535.0);
        input.mi.mouseData = 0;
        input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
        input.mi.time = 0;
        input.mi.dwExtraInfo = 0;
        
        SendInput(1, &input, sizeof(INPUT));
        
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
        
        input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        SendInput(1, &input, sizeof(INPUT));
        
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
        
        input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &input, sizeof(INPUT));
        
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
}
