# ThreeDigitsSolver
Automatic solver of the game Three Digits. For Windows only.

## Usage
1. Clone the GitHub repository
2. Use CMake to generate make/project files.
3. Build.
4. Get [tesseract](https://github.com/tesseract-ocr/tesseract) and copy lept173.dll, tesseract.exe and tessdata/eng.traineddata to ThreeDigitsSolver's build directory.
5. Run Three Digits in fullscreen mode at 1920x1080 and enter a level.
6. Run ThreeDigitsSolver.
7. Switch to Three Digits.

## Limitations
* Doesn't stop after the last level.
* tesseract often has issues distinguishing certain numbers (especially 8, which it often sees as a 6). To mitigate this, ThreeDigitsSolver tries different solutions until one sticks (each level has hundreds of solutions so it's bound to eventually find one that doesn't use the misinterpreted number). As a result, some levels can take a long time. This could probably be solved by training tesseract on Three Digits' font.