#include <bits/stdc++.h>

using namespace std;

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void insert(vector<int>& arr, int key) {
    arr.push_back(key);
    int i = arr.size() - 1;
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Heap underflow!" << endl;
        return -1;
    }
    int root = arr[0];
    arr[0] = arr.back();
    arr.pop_back();
    minHeapify(arr, arr.size(), 0);
    return root;
}

void printHeap(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> minHeap;
    insert(minHeap, 10);
    insert(minHeap, 20);
    insert(minHeap, 15);
    insert(minHeap, 40);
    insert(minHeap, 50);
    insert(minHeap, 100);
    printHeap(minHeap);

    int minElement = extractMin(minHeap);
    if (minElement != -1) {
        cout << "Extracted min element: " << minElement << endl;
        printHeap(minHeap);
    }
    return 0;
}

