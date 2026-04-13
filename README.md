# CSC 349: Design and Analysis of Algorithms
## Assignment 1 — Algorithm Analysis
**Due: April 20th**

Analysis of algorithms concerns two broad concepts: correctness and complexity. Given that one or more algorithms all produce the correct output for any given input, we are interested in the resources they each require. In this lab, you will implement three sorting algorithms in C++ and analyze their performance.

---

## Part 1: Submission Process

1.  **Starter Code:** Create a **branch** or a fork of the provided starter code repository.
2.  **Implementation:** Complete the logic in `algorithms.cc`.
3.  **Public URL:** Submit the **public URL** of your GitHub repository (specifically the branch containing your work) to [LMS Link]. 
    * *Note: Ensure your repository is set to Public so the grading scripts can access your code.*

---

## Part 2: Pseudocode & Logic

You must implement the following three algorithms in C++ exactly as described in the provided `algorithms.cc` skeleton.

### 1. SelectionSort ($O(n^2)$)
> 1. let B be an empty sequence
> 2. while A is not empty do:
> 3. &nbsp;&nbsp;&nbsp;let x be min{A}
> 4. &nbsp;&nbsp;&nbsp;let A be A − (x) and B be B ++ (x)
> 5. return B

### 2. MergeSort ($O(n \log n)$)
> 1. let mid be $\lfloor n/2 \rfloor$
> 2. if n = 1 then return A
> 3. else return Merge(MergeSort(left_half), MergeSort(right_half))

### 3. CountingSort ($O(n + k)$)
> 1. let T be an empty frequency array, B be an empty sequence
> 2. for i from min{A} to max{A}: T(i) = 0
> 3. for all a in A: T(a) = T(a) + 1
> 4. for i from min{A} to max{A}:
> 5. &nbsp;&nbsp;&nbsp;for j from 1 to T(i): B = B ++ (i)
> 6. return B

---

## Part 3: Testing & Analysis

### 1. Unit Testing (`test.cc`)
Before analyzing performance, ensure your algorithms actually work.
* **Command:** `g++ -O3 algorithms.cc test.cc -o unit_test && ./unit_test`

### 2. Performance Analysis (`analyzer.cc`)
The code to generate timing data is provided for you. This script will test sequences from size 100 to 10,000 using random integers.
* **Command:** `g++ -O3 algorithms.cc analyzer.cc -o analyze && ./analyze > results.csv`

The generated **`results.csv`** will follow this format:
```csv
Size,Selection,Merge,Counting
100,0.011722,0.039685,6.86176
200,0.044202,0.071844,5.28226
300,0.079629,0.110727,5.245
...
```

---

## Part 4: The Report

You are required to submit a **report.pdf**. You may use any data visualizer you prefer (Microsoft Excel, Google Sheets, Python/Matplotlib, etc.) to process the `results.csv` file.

**The report must include:**
* **Scatter Plot:** A single plot showing the running time of all three algorithms. The horizontal axis ($x$) should be the sequence size, and the vertical axis ($y$) should be the running time in milliseconds.
* **Comparison:** You should have 300 data points total (100 per algorithm).
* **Brief Analysis:** A short paragraph explaining why each curve matches its theoretical complexity ($O(n^2)$, $O(n \log n)$, or $O(n+k)$).

---

## 💡 C++ Survival Tips

* **Iterators:** Functions like `std::min_element` return an iterator. Use `*it` to get the value and `A.erase(it)` to remove the element.
* **Frequency Array:** In CountingSort, remember that the index for a value `x` is `x - min_value`.
* **Slicing:** Use the vector constructor for MergeSort: 
    `std::vector<int> left(A.begin(), A.begin() + mid);`
* **Optimization:** Always include the `-O3` flag when compiling to ensure the hardware is running your code efficiently!