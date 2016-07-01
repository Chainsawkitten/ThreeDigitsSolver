#pragma once

#include <string>

/// Contains functionality to execute another program.
namespace Execute {
    /// Execute a command line and wait for it to finish.
    /**
     * @param cmdLine The command line to execute.
     * @return Whether successful.
     */
    void ExecuteCommandLine(std::string commandLine);
}
