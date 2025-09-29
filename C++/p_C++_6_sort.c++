#include <bits/stdc++.h>
using namespace std;

// ===============================
// Sorting Algorithms in C++
// ===============================

// 📌 1. Built-in Sort (STL sort)
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// ⚡ Uses IntroSort (QuickSort + HeapSort + InsertionSort internally)
void builtInSort(vector<int> arr) {
    sort(arr.begin(), arr.end());
    cout << "Built-in Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// 📌 2. Bubble Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Slow, mostly for learning
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Bubble Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// 📌 3. Selection Sort
// Time Complexity: O(n^2)
// Space Complexity: O(1)
void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    cout << "Selection Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// 📌 4. Insertion Sort
// Time Complexity: O(n^2) worst, O(n) best (already sorted)
// Space Complexity: O(1)
void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// 📌 5. Merge Sort
// Time Complexity: O(n log n)
// Space Complexity: O(n) (extra arrays for merging)
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// 📌 6. Quick Sort
// Time Complexity: O(n log n) average, O(n^2) worst (bad pivot)
// Space Complexity: O(log n) recursive stack
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    builtInSort(arr);
    bubbleSort(arr);
    selectionSort(arr);
    insertionSort(arr);

    // Merge Sort example
    vector<int> arrMS = {5, 2, 9, 1, 5, 6};
    mergeSort(arrMS, 0, arrMS.size() - 1);
    cout << "Merge Sort: ";
    for (int x : arrMS) cout << x << " ";
    cout << endl;

    // Quick Sort example
    vector<int> arrQS = {5, 2, 9, 1, 5, 6};
    quickSort(arrQS, 0, arrQS.size() - 1);
    cout << "Quick Sort: ";
    for (int x : arrQS) cout << x << " ";
    cout << endl;

    return 0;
}
