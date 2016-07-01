#pragma once

#include <windows.h>

/// Screen capturing functionality.
namespace ScreenCapture {
    /// Capture a part of the screen.
    /**
     * @param x X position of the area to capture.
     * @param y Y position of the area to capture.
     * @param w Width of the area to capture.
     * @param h Height of the area to capture.
     * @param fname Filename to save bitmap to.
     * @return Whether the capture was successful.
     */
    bool CapturePart(int x, int y, int w, int h, LPCSTR fname);
}
