#include "complexity.h"
#include <iostream>
#include <vector>
#include<algorithm>
void bubbleSort(std::vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
    return;
}

void selectionSort(std::vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIdx])
                minIdx = j;
        }
        std::swap(v[i], v[minIdx]);
    }
    return;
}

void insertionSort(std::vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
    return;
}
void merge(std::vector<int>& v, int l, int m, int r) {
    std::vector<int> left(v.begin() + l, v.begin() + m + 1);
    std::vector<int> right(v.begin() + m + 1, v.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
            v[k++] = left[i++];
        else
            v[k++] = right[j++];
    }
    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];
}

void mergeSortHelper(std::vector<int>& v, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortHelper(v, l, m);
    mergeSortHelper(v, m + 1, r);
    merge(v, l, m, r);
}

void mergeSort(std::vector<int>& v) {
    if (!v.empty())
        mergeSortHelper(v, 0, v.size() - 1);
    return;
}
int partition(std::vector<int>& v, int low, int high) {
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (v[j] < pivot) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[high]);
    return i + 1;
}

void quickSortHelper(std::vector<int>& v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quickSortHelper(v, low, pi - 1);
        quickSortHelper(v, pi + 1, high);
    }
}

void quickSort(std::vector<int>& v) {
    if (!v.empty())
        quickSortHelper(v, 0, v.size() - 1);
        return;
}
void stdSort(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
    return;
}
void linearScan(std::vector<int>& v) {
    long long sum = 0;
    for (int x : v)
        sum += x;
    return;
}
void emptyAlgo(std::vector<int>& v) {return;}
int main() {

    std::cout << "Analyzing Bubble Sort:\n";
    Complex::asymptotic(bubbleSort);
        std::cout << "Analyzing Selection Sort:\n";
    Complex::asymptotic(selectionSort);
        std::cout << "Analyzing insertion Sort:\n";
    Complex::asymptotic(insertionSort);
        std::cout << "Analyzing Merge Sort:\n";
    Complex::asymptotic(mergeSort);
        std::cout << "Analyzing Quick Sort:\n";
    Complex::asymptotic(quickSort);
        std::cout << "Analyzing Linear Scan:\n";
    Complex::asymptotic(linearScan);
    std::cout << "Analyzing Standard sort:\n";
    Complex::asymptotic(stdSort);



    return 0;
}