#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
    Node* head;
    Node* tail;

    /*
    This problem can also be solved by using Node* head and int size variable
    */

    public:
    Stack() {
        head = NULL;
        tail = NULL;
    }

    int getSize() {
        int count = 0;
        Node* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp -> next;
        }
        return count;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(int element) {
        if(head == NULL) {
            Node* newNode = new Node(element);
            head = newNode;
            tail = newNode;
        } else {
            Node* newNode = new Node(element);
            newNode -> next = head;
            head = newNode;
        }

    }

    int pop() {
        if(head == NULL) { return -1; }
        int data = head -> data;

        if(head -> next == NULL) {
            tail = NULL;
        }
        head = head -> next;
        return data;
    }

    int top() {
        return ((head == NULL) ? -1 : head -> data);
    }
};


int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}