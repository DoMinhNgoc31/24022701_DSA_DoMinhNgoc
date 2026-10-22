#include <iostream>

using namespace std;

const int MAX_SIZE = 10000;

class QueueList {
private:
    int arr[MAX_SIZE];
    int count;

public:
    QueueList() {
        count = 0;
    }

    // 1. Kiểm tra queue rỗng
    // - Time: O(1)
    // - Memory: O(1)
    bool isEmpty() {
        return count == 0;
    }

    // 2. Chèn một phần tử vào queue
    // - Time: O(N)
    // - Memory: O(1)
    void enqueue(int item) {
        if (count >= MAX_SIZE) {
            return;
        }

        for (int i = count; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = item;
        count++;
    }

    // 3. Xóa phần tử khỏi queue và trả về phần tử đó
    // - Time: O(1)
    // - Memory: O(1)
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        int dequeuedValue = arr[count - 1];
        count--;

        return dequeuedValue;
    }

    // 4. Trả về giá trị phần tử chuẩn bị được lấy ra khỏi queue
    // - Time: O(1)
    // - Memory: O(1)
    int front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[count - 1];
    }

    // 5. Trả về kích thước của queue
    // - Time: O(1)
    // - Memory: O(1)
    int size() {
        return count;
    }
};

int main() {
    QueueList q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Kich thuoc Queue: " << q.size() << endl;
    cout << "Phan tu dau Queue (front): " << q.front() << endl;
    cout << "Lay ra (dequeue): " << q.dequeue() << endl;
    cout << "Lay ra tiep: " << q.dequeue() << endl;

    return 0;
}
