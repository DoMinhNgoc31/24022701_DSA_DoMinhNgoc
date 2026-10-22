#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // 1. Truy cập phần tử tại vị trí i
    // - Time: O(N) trong trường hợp xấu nhất
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
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // 3. Chèn phần tử vào cuối
    // - Time: O(1) do đã duy trì con trỏ tail, không cần duyệt từ đầu
    // - Memory: O(1)
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // 4. Chèn vào vị trí i
    // - Time: O(N)
    // - Memory: O(1)
    void insertAt(int i, int val) {
        if (i == 0) {
            insertHead(val);
            return;
        }
        Node* temp = head;
        for (int k = 0; temp != nullptr && k < i - 1; k++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;

        if (temp->next == nullptr) {
            insertTail(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // 5. Xóa phần tử đầu
    // - Time: O(1)
    // - Memory: O(1)
    void deleteHead() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    // 6. Xóa phần tử cuối
    // - Time: O(1)
    // - Memory: O(1)
    void deleteTail() {
        if (tail == nullptr) return;

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
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
        for (int k = 0; temp != nullptr && k < i; k++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;

        if (temp == tail) {
            deleteTail();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
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
    // - Memory: O(1)
    void traverseBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertHead(10);
    list.insertTail(20);
    list.insertTail(30);
    list.insertAt(1, 15);

    cout << "Duyet xuoi: ";
    list.traverseForward();

    cout << "Duyet nguoc: ";
    list.traverseBackward();

    list.deleteAt(2);
    list.deleteTail();
    list.deleteHead();

    cout << "Duyet xuoi sau khi xoa: ";
    list.traverseForward();

    return 0;
}
