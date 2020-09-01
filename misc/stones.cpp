#include <bits/stdc++.h>

using namespace std;

int heap[3000];
int heapSize;

void heapify(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heapSize && heap[left] > heap[largest]) largest = left;

    if (right < heapSize && heap[right] > heap[largest]) largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

int lastStoneWeight(vector<int>& stones) {
    heapSize = stones.size();
    int t = 0;
    for (auto s : stones) heap[t++] = s;

    // create heap
    for (int k = heapSize / 2 - 1; k > 0; k--) heapify(k);

    while (heapSize > 1) {
        int a = heap[0];
        int b = max(heap[1], heap[2]);
        int idx = 1;

        if (b == heap[2]) idx = 2;

        
    }

    return 0;
}

int main(int argc, char const* argv[]) {
    cout << lastStoneWeight(vector<int>{2, 3, 4, 5, 6, 7});
}