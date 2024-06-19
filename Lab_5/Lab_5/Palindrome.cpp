#include <iostream>

using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(NULL) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(NULL) {}

    void push_back(int data) {
        //TODO
        ListNode* node = new ListNode(data);

        if (head == NULL) {
            head = node;
        }
        else {
            ListNode* current = head;
            while (current->next) {

                current = current->next;
            }

            current->next = node;
        }

    }

    bool isPalindrome() {
        //TODO
        ListNode* cur = head;
        

        ListNode* r_head = reverse(head);
        ListNode* curr = r_head;
        
        while (cur && curr)
        {
            if (cur->data != curr->data) {
                return false;
            }
            cur = cur->next;
           
            curr = curr->next;
            
        }
        return true;
        
    }

    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }


    ~LinkedList() {
        ListNode* current = head;
        while (current != NULL) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList lst;
    int length, num;

    cin >> length;

    for (int i = 0; i < length; i++) {
        cin >> num;
        lst.push_back(num);
    }

    bool result = lst.isPalindrome();
    cout << (result ? "Yes" : "No") << endl;

    return 0;
}