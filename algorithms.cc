#include "algorithms.h"
#include <limits>
#include <algorithm> // For std::min_element, std::max_element
#include <vector>    // For std::vector

/**
 * SELECTION SORT
 * Logic: Find the smallest, move it to the new list, repeat.
 */
std::vector<int> SelectionSort(std::vector<int> A) {
    std::vector<int> B;

    while (!A.empty()) {
        auto it = std::min_element(A.begin(), A.end());
        B.push_back(*it);
        A.erase(it);
    }
    return B;
}

/**
 * MERGE (Helper for MergeSort)
 * Logic: Combine two already-sorted lists into one.
 */
std::vector<int> Merge(std::vector<int> left, std::vector<int> right) {
    std::vector<int> result;
    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

/**
 * MERGE SORT
 * Logic: Split in half, recurse, then merge.
 */
std::vector<int> MergeSort(std::vector<int> A) {
    // Base Case: A list of 1 (or 0) is already sorted
    if (A.size() <= 1) return A;

    size_t mid = A.size() / 2;

    std::vector<int> left(A.begin(), A.begin() + mid);
    std::vector<int> right(A.begin() + mid, A.end());

    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left, right);
}

/**
 * COUNTING SORT
 * Logic: Count how many times each number appears.
 */
std::vector<int> CountingSort(std::vector<int> A) {
    if (A.empty()) return {};

    int min_value = *std::min_element(A.begin(), A.end());
    int max_value = *std::max_element(A.begin(), A.end());

    int range = max_value - min_value + 1;
    std::vector<int> T(range, 0);
    std::vector<int> B;

    for (int num : A) {
        T[num - min_value]++;
    }

    for (int i = 0; i < range; i++) {
        while (T[i] > 0) {
            B.push_back(i + min_value);
            T[i]--;
        }
    }

    return B;
}