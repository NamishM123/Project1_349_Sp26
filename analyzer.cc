#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "algorithms.h"

int main() {
    // Setup random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-500000, 500000);

    // CSV Header
    std::cout << "Size,Selection,Merge,Counting" << std::endl;

    for (int n = 100; n <= 10000; n += 100) {
        std::vector<int> data;
        for (int i = 0; i < n; ++i) {
            data.push_back(dis(gen));
        }

        // Measure Selection Sort
        auto start = std::chrono::high_resolution_clock::now();
        SelectionSort(data); 
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff_sel = end - start;

        // Measure Merge Sort
        start = std::chrono::high_resolution_clock::now();
        MergeSort(data);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff_merge = end - start;

        // Measure Counting Sort
        start = std::chrono::high_resolution_clock::now();
        CountingSort(data);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff_count = end - start;

        std::cout << n << "," 
                  << diff_sel.count() << "," 
                  << diff_merge.count() << "," 
                  << diff_count.count() << std::endl;
    }

    return 0;
}