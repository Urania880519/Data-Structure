#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    MyQueue() {

    }

    void enQueue(int x) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }


        stack1.push(x);


        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }

        cout << "Enqueued " << x << endl;
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int top_value = stack1.top();
        stack1.pop();
        cout << "Dequeued " << top_value << endl;
        return top_value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        cout << "Front element: " << stack1.top() << endl;
        return stack1.top();
    }

    bool isEmpty() {
        return stack1.empty();
    }
};

int main() {
    MyQueue queue;
    string command;

    while (cin >> command) {
        if (command == "enqueue") {
            int value;
            cin >> value;
            queue.enQueue(value);
        }
        else if (command == "dequeue") {
            queue.deQueue();
        }
        else if (command == "peek") {
            queue.peek();
        }
        else if (command == "empty") {
            if (queue.isEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                cout << "Queue is not empty" << endl;
            }
        }
        else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
