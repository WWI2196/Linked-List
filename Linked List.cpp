#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    explicit Node(const int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:

    LinkedList() {
        head = nullptr;
    }

    /*~LinkedList() {
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }*/

    void addData_toEnd(const int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) head = newNode;
        else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    /*const int means that the parameter data is a constant integer. The const keyword indicates that the value of data cannot be modified within the function. This means the function promises not to change the value of data.*/

    void addData_toStart(const int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addData_afterValue(const int afterData, const int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        if (!search(afterData)) {
            cout << "Data not found" << endl;
            delete newNode; // free the memory
            return;
        }

        Node* temp = head;

        while (temp != nullptr && temp->data != afterData) {
            temp = temp->next;
        }

        if (temp != nullptr) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void addData_beforeValue(const int afterData, const int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        if (!search(afterData)) {
            cout << "Data not found" << endl;
            delete newNode; // free the memory
            return;
        }

        Node* tempPrv = nullptr;
        Node* temp = head;

        while (temp != nullptr && temp->data != afterData) {
            tempPrv = temp;
            temp = temp->next;
        }

        if (temp == head) {
            newNode->next = temp;
            head = newNode;
        }
        else {
            newNode->next = temp;
            tempPrv->next = newNode;
        }
    }


    void display() const {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        }
        else {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl; // For a new line after printing the list
        }
    }

    bool search(const int data) const {
        if (head == nullptr) return false;

        const Node* temp = head;
        while (temp->next != nullptr) {
            if (temp->data == data) return true;
            temp = temp->next;
        }
        return false;
    }

    /*he function signature void addData_toEnd(const int data) const is valid in terms of C++ syntax, but it indicates that the function is a const member function. A const member function guarantees that it will not modify any member variables of the class. This is useful when you want to ensure that a function does not change the state of the object.*/

    void deleteValue(int data) {
        if(!search(data)) {
			cout << "Data not found" << endl;
			return;
		}

        Node* tempPrv = nullptr;
        Node* temp = head;

        while(temp != nullptr && temp->data != data) {
            tempPrv = temp;
			temp = temp->next;
		}

        if (temp == head) {
            head = temp->next;
            delete temp;
        }
        else {
            tempPrv->next = temp->next;
            delete temp;
        }

    }

};


int main() {

    LinkedList list;

    list.addData_toEnd(2);
    list.addData_toStart(3);
    list.addData_toEnd(4);
    list.addData_toEnd(5);
    list.addData_afterValue(4, 6);
    list.addData_beforeValue(4, 9);
    list.display();

    list.deleteValue(9);
    list.display();

    return 0;
}
