#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

// Part 3: SelectionSort - O(n^2)
std::vector<int> SelectionSort(std::vector<int> A);

// Part 3: MergeSort - O(n log n)
std::vector<int> MergeSort(std::vector<int> A);

// Part 3: CountingSort - O(n + (max-min))
std::vector<int> CountingSort(std::vector<int> A);

#endif