#include "Execute.hpp"

#include <windows.h>

namespace Execute {
    void ExecuteCommandLine(std::string commandLine) {
        char* cmdLine = new char[commandLine.length() + 10];
        for (std::size_t i=0; i<=commandLine.length(); ++i) {
            cmdLine[i] = commandLine[i];
        }
        
        PROCESS_INFORMATION processInformation = {0};
        STARTUPINFO startupInfo = {0};
        startupInfo.cb = sizeof(startupInfo);
        
        // Create the process
        bool result = CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS | CREATE_NO_WINDOW, NULL, NULL, &startupInfo, &processInformation);
        
        if (result) {
            // Successfully created the process.  Wait for it to finish.
            WaitForSingleObject(processInformation.hProcess, INFINITE);
            
            // Close the handles.
            CloseHandle(processInformation.hProcess);
            CloseHandle(processInformation.hThread);
        }
    }
}
