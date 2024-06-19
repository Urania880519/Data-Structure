#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class MaxHeap {
public:
    MaxHeap() : elements(1) {} // Initialize with a dummy element at index 0

    MaxHeap(const std::vector<int>& data) : elements(1) {
        // TODO
        for (int i = 0; i < data.size(); ++i) {
            elements.push_back(data[i]);
        }
        for (int i = sizeOfHeap() / 2; i > 0; --i) {
            heapifyDown(i);
        }
    }

    void insertValueInHeap(int value) {
        // TODO
        
        elements.push_back(value);

        heapifyUp(sizeOfHeap());

    }

    void extractMax() {
        
        int lastElement = elements[1];

        
        elements[1] = lastElement;
        elements.pop_back();
        heapifyDown(1);
        
    }

    int peekTopOfHeap() const {
        // TODO
        return elements[1];
    }

    int sizeOfHeap() const {
        // TODO
        return elements.size()-1;
    }

    bool isEmpty() const {
        // TODO
        if (elements.size() == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

    void print() const {
        // TODO
        for (int i = 1; i <= sizeOfHeap(); ++i) {
            cout << elements[i]<<" ";
        }
        cout << endl;
    }

    // Can add anything you needed

private:
    std::vector<int> elements;

    void heapifyUp(int index) {
        // TODO
        while (index > 1 && elements[index] > elements[parent(index)]) {
            swap(elements[index], elements[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        // TODO
        int largest = index; 
        int l = leftChild(index); 
        int r = rightChild(index); 

        if (l <= elements.size() && elements[l] > elements[largest])
            largest = l;

        
        if (r <= elements.size() && elements[r] > elements[largest])
            largest = r;

        
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
    

    // Can add anything you need

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
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
    maxHeap.insertValueInHeap(value); // insertValueInHeap

    maxHeap.print();

    cin >> s;
    maxHeap.extractMax(); // extractMax

    maxHeap.print();

    return 0;
}
