#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int front, int mid, int end) {
    int leftSize = mid - front + 1;
    int rightSize = end - mid;

    int* left_v = new int[leftSize];
    int* right_v = new int[rightSize];

    for (int i = 0; i < leftSize; i++) {
        left_v[i] = v[i + front];
    }
    for (int j = 0; j < rightSize; j++) {
        right_v[j] = v[mid + 1 + j];
    }

    int i = 0, j = 0, k = front;

    while (i < leftSize && j < rightSize) {
        if (left_v[i] <= right_v[j]) {
            v[k] = left_v[i];
            i++;
        }
        else {
            v[k] = right_v[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        v[k] = left_v[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        v[k] = right_v[j];
        j++;
        k++;
    }

    delete[] left_v;
    delete[] right_v;
}


void mergeSort(vector<int>& v, int front, int end) {
    //TO-DO
    if (front < end) {
        int mid = (front + end) / 2;
        mergeSort(v, front, mid);
        mergeSort(v, mid + 1, end);
        merge(v, front, mid, end);
    }

}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //TO-DO
    mergeSort(arr, 0, n-1);

    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}