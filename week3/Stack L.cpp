#include <iostream>

using namespace std;

const int MAX_SIZE = 10000;

class StackStaticArray {
private:
    int arr[MAX_SIZE];
    int topIndex;

public:
    StackStaticArray() {
        topIndex = -1;
    }

    // 1. Kiểm tra Stack rỗng
    // - Time: O(1)
    // - Memory: O(1)
    bool isEmpty() {
        return topIndex == -1;
    }

    // 2. Chèn một phần tử vào Stack
    // - Time: O(1)
    // - Memory: O(1)
    void push(int item) {
        if (topIndex >= MAX_SIZE - 1) {
            return;
        }
        arr[++topIndex] = item;
    }

    // 3. Xóa phần tử cuối và trả về phần tử đó
    // - Time: O(1)
    // - Memory: O(1)
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        return arr[topIndex--];
    }

    // 4. Trả về kích thước hiện tại của Stack
    // - Time: O(1)
    // - Memory: O(1)
    int size() {
        return topIndex + 1;
    }

    // 5. Trả về giá trị phần tử cuối
    // - Time: O(1)
    // - Memory: O(1)
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return arr[topIndex];
    }
};

int main() {
    StackStaticArray myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Kich thuoc hien tai: " << myStack.size() << endl;
    cout << "Phan tu tren cung: " << myStack.top() << endl;
    cout << "Lay phan tu ra: " << myStack.pop() << endl;
    cout << "Kich thuoc sau khi pop: " << myStack.size() << endl;

    return 0;
}
