#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

    void printBackwardRecursion(Node* node) {
        if (node == nullptr) return;
        printBackwardRecursion(node->next);
        cout << node->data << " ";
    }

public:
    LinkedList() {
        head = nullptr;
    }

    // 1. Truy cập phần tử tại vị trí i
    // - Time: O(N) trong trường hợp xấu nhất (truy cập vị trí cuối)
    // - Memory: O(1)
    int access(int i) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == i) return temp->data;
            count++;
            temp = temp->next;
        }
        return -1;
    }

    // 2. Chèn phần tử vào đầu
    // - Time: O(1)
    // - Memory: O(1)
    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 3. Chèn phần tử vào cuối
    // - Time: O(N)
    // - Memory: O(1)
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 4. Chèn vào vị trí i (0-based index)
    // - Time: O(N)
    // - Memory: O(1)
    void insertAt(int i, int val) {
        if (i == 0) {
            insertHead(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int k = 0; temp != nullptr && k < i - 1; k++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 5. Xóa phần tử đầu
    // - Time: O(1)
    // - Memory: O(1)
    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 6. Xóa phần tử cuối
    // - Time: O(N)
    // - Memory: O(1)
    void deleteTail() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // 7. Xóa vị trí i
    // - Time: O(N)
    // - Memory: O(1)
    void deleteAt(int i) {
        if (head == nullptr) return;
        if (i == 0) {
            deleteHead();
            return;
        }
        Node* temp = head;
        for (int k = 0; temp != nullptr && temp->next != nullptr && k < i - 1; k++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) return;

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // 8. Duyệt xuôi
    // - Time: O(N)
    // - Memory: O(1)
    void traverseForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 9. Duyệt ngược
    // - Time: O(N)
    // - Memory: O(N)
    void traverseBackward() {
        printBackwardRecursion(head);
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertHead(10);
    list.insertTail(20);
    list.insertTail(30);
    list.insertAt(1, 15);

    cout << "Duyet xuoi: ";
    list.traverseForward();

    cout << "Duyet nguoc: ";
    list.traverseBackward();

    list.deleteAt(1);
    list.deleteTail();
    list.deleteHead();

    cout << "Duyet xuoi sau khi xoa: ";
    list.traverseForward();
}
