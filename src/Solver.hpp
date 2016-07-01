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
        /**
         * @param allowedSolution First allowed solution (zero indexed).
         */
        void Solve(unsigned int allowedSolution);
        
        /// Print the solution.
        void Print();
        
        /// Get the solution.
        /**
         * @return How many times each number should be clicked.
         */
        const unsigned char* GetSolution() const;
        
    private:
        bool Test();
        bool Probe(int current);
        
        unsigned int numbers[14];
        unsigned char status[14];
        
        unsigned int solution;
        unsigned int allowedSolution;
};
