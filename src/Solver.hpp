#pragma once

/// Solves a Three Digits problem.
class Solver {
    public:
        /// Set the numbers to solve.
        /**
         * @param numbers The 14 numbers to solve.
         */
        void SetNumbers(unsigned int* numbers);
        
        /// Solve the problem and output the results.
        void Solve();
        
        /// Print the solution.
        void Print();
        
    private:
        bool Test();
        bool Probe(int current);
        
        unsigned int numbers[14];
        unsigned char status[14];
};
