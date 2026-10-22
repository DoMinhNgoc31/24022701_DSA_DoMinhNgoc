#include <iostream>
using namespace std;

#define MAX_SIZE 10000

class ArrayList {
private:
    int arr[MAX_SIZE];
    int size;

public:
    ArrayList() {
        size = 0;
    }

    // 1. Truy cập
    // Time: O(1)
    // Memory: O(1)
    int truyCap(int i) {
        if (i < 0 || i >= size) {
            cout << "Loi: Vi tri khong hop le!\n";
            return -1;
        }
        return arr[i];
    }

    // 2. Chèn vào vị trí i
    // Time: O(N) - Trong trường hợp xấu nhất (chèn ở đầu)
    // Memory: O(1)
    void chenViTri(int i, int value) {
        if (i < 0 || i > size) {
            cout << "Loi: Vi tri khong hop le!\n";
            return;
        }
        if (size >= MAX_SIZE) {
            cout << "Loi: Danh sach da day!\n";
            return;
        }
        for (int j = size; j > i; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i] = value;
        size++;
    }

    // 3. Chèn phần tử vào đầu
    // Time: O(N)
    // Memory: O(1)
    void chenDau(int value) {
        chenViTri(0, value);
    }

    // 4. Chèn phần tử vào cuối
    // Time: O(1)
    // Memory: O(1)
    void chenCuoi(int value) {
        if (size >= MAX_SIZE) {
            cout << "Loi: Danh sach da day!\n";
            return;
        }
        arr[size] = value;
        size++;
    }

    // 5. Xóa vị trí i
    // Time: O(N) - Trong trường hợp xấu nhất (xóa ở đầu)
    // Memory: O(1)
    void xoaViTri(int i) {
        if (i < 0 || i >= size) {
            cout << "Loi: Vi tri khong hop le!\n";
            return;
        }
        for (int j = i; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--;
    }

    // 6. Xóa phần tử đầu
    // Time: O(N)
    // Memory: O(1)
    void xoaDau() {
        xoaViTri(0);
    }

    // 7. Xóa phần tử cuối
    // Time: O(1)
    // Memory: O(1)
    void xoaCuoi() {
        if (size <= 0) {
            cout << "Loi: Danh sach rong!\n";
            return;
        }
        size--;
    }

    // 8. Duyệt xuôi
    // Time: O(N)
    // Memory: O(1)
    void duyetXuoi() {
        cout << "Duyet xuoi: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 9. Duyệt ngược
    // Time: O(N)
    // Memory: O(1)
    void duyetNguoc() {
        cout << "Duyet nguoc: ";
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayList list;
    list.chenCuoi(10);
    list.chenCuoi(20);
    list.chenDau(5);
    list.chenViTri(2, 15);

    list.duyetXuoi();

    list.xoaDau();
    list.xoaCuoi();
    list.xoaViTri(1);

    list.duyetNguoc();
}
