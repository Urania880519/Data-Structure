#include <iostream>
using namespace std;
class CircularQueue {
public:
    CircularQueue(int size):size(size){
        
        
        arr = (int*)calloc(size, sizeof(int));
        
        front = 0;
        rear = 0;
    }

    void enQueue(int data) {
        
        if (isFull()) {
            cout << "Queue is full" << endl;
        }
        else {
            
            arr[rear] = data;
            rear += 1;
        }
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        }
        else {
            for (int i = 1; i < rear; i++) {
                arr[i - 1] = arr[i];
            }
            rear -= 1;
        }

    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else {
            return arr[front];
        }

    }

    bool isEmpty() {
        if (front == rear) {
            return 1;
        }
        else {
            return 0;
        }
    }

    bool isFull() {
        if (rear == size) {
            return 1;
        }
        else {
            return 0;
        }
    }

    void expand(int newSize) {
        int* newarr;
        newarr = (int*)calloc(newSize, sizeof(int));
        for (int i = 0; i < rear; i++) {
            newarr[i] = arr[i];
        }
        size = newSize;
        arr = newarr;
    }

private:
    int* arr;
    int front, rear, size;
};

int main(void) {
    CircularQueue q(5);
    q.enQueue(1);

    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.expand(6);
    q.enQueue(6);
    q.deQueue();
    std::cout << q.peek() << std::endl;
    q.deQueue();
    std::cout << q.peek() << std::endl;
    q.enQueue(10);
    std::cout << q.peek() << std::endl;
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    std::cout << q.peek() << std::endl;
    q.deQueue();
    std::cout << q.peek() << std::endl;
    q.deQueue();
}