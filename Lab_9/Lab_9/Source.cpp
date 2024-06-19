#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    MaxHeap() : elements(1) {} 

    MaxHeap(const std::vector<int>& data) : elements(1) {
        for (int i = 0; i < data.size(); ++i) {
            elements.push_back(data[i]);
        }
        for (int i = sizeOfHeap() / 2; i > 0; --i) {
            heapifyDown(i);
        }
    }

    void insertValueInHeap(int value) {
        elements.push_back(value);
        heapifyUp(sizeOfHeap());
    }

    void extractMax() {
        if (isEmpty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        int maxElement = elements[1];
        elements[1] = elements[sizeOfHeap()];
        elements.pop_back();
        heapifyDown(1);
        print();
    }

    void print() const {
        for (int i = 1; i <= sizeOfHeap(); ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

private:
    std::vector<int> elements;

    void heapifyUp(int index) {
        while (index > 1 && elements[index] > elements[parent(index)]) {
            swap(elements[index], elements[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left <= sizeOfHeap() && elements[left] > elements[largest]) {
            largest = left;
        }
        if (right <= sizeOfHeap() && elements[right] > elements[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(elements[index], elements[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int index) const {
        return index / 2;
    }

    int leftChild(int index) const {
        return 2 * index;
    }

    int rightChild(int index) const {
        return 2 * index + 1;
    }

    int sizeOfHeap() const {
        return elements.size() - 1;
    }

    bool isEmpty() const {
        return sizeOfHeap() == 0;
    }
};

int main() {
    int t;
    cin >> t;
    std::vector<int> data(t);
    for (int i = 0; i < t; ++i) {
        int value;
        cin >> value;
        data[i] = value;
    }

    MaxHeap maxHeap(data); 
    maxHeap.print();

    string s;
    int value;
    cin >> s >> value;
    maxHeap.insertValueInHeap(value); 

    maxHeap.print();

    cin >> s;
    maxHeap.extractMax(); 

    return 0;
}
