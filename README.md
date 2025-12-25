# Empirical Complexity Analyzer

A C++ benchmarking tool designed to experimentally study the time complexity
of algorithms by observing runtime growth over increasing input sizes.

## Overview
This project investigates how algorithmic complexity manifests in practice.
By profiling execution time across scaled inputs, it highlights the difference
between theoretical asymptotic complexity and real-world performance on modern
hardware.

## Functionality
- Runtime measurement using `std::chrono`
- Automatic input size scaling
- Averaging across multiple runs to reduce noise
- Normalization against common complexity classes
- Comparative analysis of classic algorithms

## Algorithms Included
- Linear scan
- Bubble sort
- Selection sort
- Insertion sort
- Merge sort
- Quick sort
- `std::sort` (introsort)
- Any other algorithms can be added as functions to the main file and tested


## Observations
Algorithms with theoretical complexity `O(n log n)` often exhibit near-linear
behavior for moderate input sizes due to caching, branch prediction, and constant
factors. This project demonstrates the limitations of inferring asymptotic
complexity purely from timing data.

## Build Instructions
```bash
g++ -std=c++17 main.cpp profiler.cpp complexity.cpp -O2
./a.out
