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

class StackLinkedList {
private:
    Node* head;
    int count;

public:
    StackLinkedList() {
        head = nullptr;
        count = 0;
    }

    // 1. Kiểm tra Stack rỗng
    // - Time: O(1)
    // - Memory: O(1)
    bool isEmpty() {
        return head == nullptr;
    }

    // 2. Chèn một phần tử vào Stack
    // - Time: O(1)
    // - Memory: O(1)
    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        count++;
    }

    // 3. Xóa phần tử cuối và trả về phần tử đó
    // - Time: O(1)
    // - Memory: O(1)
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        Node* temp = head;
        int poppedValue = temp->data;

        head = head->next;
        delete temp;
        count--;

        return poppedValue;
    }

    // 4. Trả về kích thước của Stack
    // - Time: O(1)
    // - Memory: O(1)
    int size() {
        return count;
    }

    // 5. Trả về giá trị phần tử cuối mà không xóa
    // - Time: O(1)
    // - Memory: O(1)
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return head->data;
    }
};

int main() {
    StackLinkedList stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Kich thuoc hien tai: " << stack.size() << "\n";
    cout << "Phan tu tren cung: " << stack.top() << "\n";

    cout << "Thuc hien pop: " << stack.pop() << "\n";
    cout << "Thuc hien pop: " << stack.pop() << "\n";

    cout << "Kich thuoc sau khi pop: " << stack.size() << "\n";
    cout << "Phan tu tren cung moi: " << stack.top() << "\n";

    return 0;
}
