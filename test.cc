#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "algorithms.h"

// Helper to check if the result matches a standard sort
bool verify(std::string name, std::vector<int> result, std::vector<int> expected) {
    if (result == expected) {
        std::cout << "  [PASS] " << name << std::endl;
        return true;
    } else {
        std::cout << "  [FAIL] " << name << " (Result did not match expected output)" << std::endl;
        return false;
    }
}

void run_suite(std::string test_name, std::vector<int> input) {
    std::cout << "Running: " << test_name << "..." << std::endl;
    
    // Create the "Golden Standard" using built-in sort
    std::vector<int> expected = input;
    std::sort(expected.begin(), expected.end());

    verify("SelectionSort", SelectionSort(input), expected);
    verify("MergeSort",     MergeSort(input),     expected);
    verify("CountingSort",  CountingSort(input),  expected);
    std::cout << "------------------------------------" << std::endl;
}

int main() {
    // Test Case 1: Standard Mixed
    run_suite("Mixed Positive/Negative", {2, -1, 9, 8, 5, -3, 0, 8});

    // Test Case 2: Already Sorted
    run_suite("Already Sorted", {1, 2, 3, 4, 5});

    // Test Case 3: Reverse Sorted
    run_suite("Reverse Sorted", {10, 5, 0, -5, -10});

    // Test Case 4: Single Element
    run_suite("Single Element", {42});

    // Test Case 5: All Same Elements
    run_suite("Duplicates", {7, 7, 7, 7});

    return 0;
}