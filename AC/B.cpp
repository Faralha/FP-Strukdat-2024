#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void swapKthNode(int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return;
        }
    
        int length = 0;
        Node* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            length++;
        }
    
        if (k > length) {
            return;
        }
    
        Node* prev1 = nullptr;
        Node* curr1 = head;
        int count1 = 1;
        while (curr1 != nullptr && count1 < k) {
            prev1 = curr1;
            curr1 = curr1->next;
            count1++;
        }
    
        Node* prev2 = nullptr;
        Node* curr2 = head;
        int count2 = 1;
        while (curr2 != nullptr && count2 < length - k + 1) {
            prev2 = curr2;
            curr2 = curr2->next;
            count2++;
        }
    
        if (curr1 == nullptr || curr2 == nullptr || curr1 == curr2) {
            return;
        }
    
        if (prev1 != nullptr) {
            prev1->next = curr2;
        } else {
            head = curr2;
        }
    
        if (prev2 != nullptr) {
            prev2->next = curr1;
        } else {
            head = curr1;
        }
    
        temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
    }
};

int main() {
    LinkedList myList;

    int value;
    while ((cin >> value) && (value != -1)) {
        myList.insert(value);
    }

    int k;
    cin >> k;
    myList.swapKthNode(k);

    myList.print();

    return 0;
}