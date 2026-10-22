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

class QueueLinkedList {
private:
    Node* head;
    Node* tail;
    int count;

public:
    QueueLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    // Kiểm tra queue rỗng
    // - Time: O(1)
    // - Memory: O(1)
    bool isEmpty() {
        return head == nullptr;
    }

    // Chèn một phần tử vào cuối queue
    // - Time: O(1)
    // - Memory: O(1)
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // Xóa phần tử đầu khỏi queue và trả về phần tử đó
    // - Time: O(1)
    // - Memory: O(1)
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        Node* temp = head;
        int dequeuedValue = temp->data;

        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        count--;
        return dequeuedValue;
    }

    // Trả về giá trị phần tử đầu trong queue mà không xóa
    // - Time: O(1)
    // - Memory: O(1)
    int front() {
        if (isEmpty()) {
            return -1;
        }
        return head->data;
    }

    // Trả về kích thước của queue
    // - Time: O(1)
    // - Memory: O(1)
    int size() {
        return count;
    }
};

int main() {
    QueueLinkedList q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Kich thuoc ban dau: " << q.size() << "\n";
    cout << "Phan tu o dau: " << q.front() << "\n";

    cout << "Thuc hien dequeue: " << q.dequeue() << "\n";
    cout << "Thuc hien dequeue: " << q.dequeue() << "\n";

    cout << "Kich thuoc sau khi xoa: " << q.size() << "\n";
    cout << "Phan tu o dau hien tai: " << q.front() << "\n";

    return 0;
}
