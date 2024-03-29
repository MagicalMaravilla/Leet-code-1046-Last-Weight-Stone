#include <iostream>  // Includes the Standard I/O header for input/output operations
#include <vector>    // Includes the vector container class from the Standard Template Library
#include <queue>     // Includes the queue class for using priority_queue
#include <cassert>   // Includes the assert function used for validation in tests

using namespace std; // Uses the standard namespace to avoid prefixing std::

// Function to compute the weight of the last stone left after collision or return 0 if none.
int lastStoneWeight(vector<int>& stones) {
    if (stones.empty()) { // Check if the input vector is empty and return 0 immediately
        return 0;
    }

    priority_queue<int> maxHeap; // Initialize a max-heap to store and sort stones by weight
    for (int stone : stones) {   // Iterate through the vector of stones
        if (stone > 0) {         // Only add positive weights to the max-heap
            maxHeap.push(stone);
        }
    }

    // Loop until there is one or no stone left in the max-heap
    while (maxHeap.size() > 1) {
        int stoneOne = maxHeap.top(); maxHeap.pop(); // Extract the heaviest stone
        int stoneTwo = maxHeap.top(); maxHeap.pop(); // Extract the second heaviest stone

        // If the two stones have different weights
        if (stoneOne != stoneTwo) {
            maxHeap.push(stoneOne - stoneTwo); // Push the weight difference back into the max-heap
        }
    }

    // If the heap is empty return 0, otherwise return the weight of the last stone
    return maxHeap.empty() ? 0 : maxHeap.top();
}

// Function to run a series of predefined test cases to validate the solution
void runTests() {
    vector<vector<int>> testCases = { // Define a vector of test cases
        {2, 7, 4, 1, 8, 1}, {1}, {8, 8}, {}, {10}, {0, 0, 1, 1}, {1000000, 1000000}
    };

    vector<int> expectedResults = {  // Define expected results for each test case
        1, 1, 0, 0, 10, 0, 0
    };

    // Iterate through each test case
    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Running Test Case " << i+1 << " - "; // Output the test case number
        int result = lastStoneWeight(testCases[i]);  // Run the lastStoneWeight function
        assert(result == expectedResults[i]);        // Assert the result matches the expected outcome
        cout << "Passed! Last stone weight: " << result << endl; // Output the result
    }
}

// Main function to execute the test runner
int main() {
    runTests(); // Call the test runner
    return 0;   // End of program
}
