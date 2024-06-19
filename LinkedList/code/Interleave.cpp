#include <iostream>

using namespace std;

class LinkedList;

class ListNode {
private:
    int data;
    ListNode* next;
public:
    ListNode() : data(0), next(nullptr) {}
    ListNode(int a) : data(a), next(nullptr) {}

    friend class LinkedList;
};

class LinkedList {
public:
    LinkedList() : first(nullptr) {}
    void PrintList();
    void Push_back(int x);
    void Interleave(LinkedList& list2);

private:
    ListNode* first;
};

void LinkedList::PrintList() {
    if (first == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    ListNode* current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Push_back(int x) {
    //todo
    ListNode* node= new ListNode(x);
    
    if (first == NULL) {
        first = node;
    }
    else {
        ListNode* current = first;
        while (current->next) {

            current = current->next;
        }

        current->next = node;
    }
    

}

void LinkedList::Interleave(LinkedList& list2) {
    //todo
    ListNode* cur = first;
    
    int len_1 = 0;
    while (cur!=nullptr)
    {
        len_1 += 1;
        cur = cur->next;
    }
    
    ListNode* cur_2 = list2.first;
    int len_2 = 0;
    while (cur_2 != nullptr) {
        len_2 += 1;
        cur_2 = cur_2->next;
    }
    
    if (len_1 != 0) {
        if (len_1 >= len_2) {
            ListNode* current = first;

            ListNode* current_2 = list2.first;
            for (int i = 0; i < len_2; i++) {
                ListNode* temp = current->next;
                ListNode* temp_2 = current_2->next;
                current->next = current_2;
                current_2->next = temp;
                current = temp;
                current_2 = temp_2;
            }

        }
        else {
            ListNode* current = first;
            ListNode* current_2 = list2.first;
            for (int i = 0; i < len_1 - 1; i++) {
                ListNode* temp = current->next;
                ListNode* temp_2 = current_2->next;
                current->next = current_2;
                current_2->next = temp;
                current = temp;
                current_2 = temp_2;
            }
            current->next = current_2;
        }
    }
    else {
        first = list2.first;
    }
}

int main() {
    LinkedList list1;
    LinkedList list2;
    int count1, count2, num;

    cin >> count1;
    for (int i = 0; i < count1; i++) {
        cin >> num;
        list1.Push_back(num);
    }

    cin >> count2;
    for (int i = 0; i < count2; i++) {
        cin >> num;
        list2.Push_back(num);
    }
    

    list1.Interleave(list2);
    list1.PrintList();

    return 0;
}