#include <iostream>
#include <vector>

using namespace std;

enum SlotStatus { EMPTY, DELETED, OCCUPIED };

class HashTableOpenAddressing {
private:
    int SIZE;
    vector<int> table;
    vector<SlotStatus> status;

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTableOpenAddressing(int size) {
        SIZE = size;
        table.resize(SIZE, 0);
        status.resize(SIZE, EMPTY);
    }

    void insertKey(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (status[(index + i) % SIZE] == OCCUPIED && i < SIZE) {
            if (table[(index + i) % SIZE] == key) return;
            i++;
        }

        if (i == SIZE) {
            cout << "Lỗi: Bảng băm đã đầy!\n";
            return;
        }

        int probeIndex = (index + i) % SIZE;
        table[probeIndex] = key;
        status[probeIndex] = OCCUPIED;
    }

    bool searchKey(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (status[(index + i) % SIZE] != EMPTY && i < SIZE) {
            if (status[(index + i) % SIZE] == OCCUPIED && table[(index + i) % SIZE] == key) {
                return true;
            }
            i++;
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (status[(index + i) % SIZE] != EMPTY && i < SIZE) {
            if (status[(index + i) % SIZE] == OCCUPIED && table[(index + i) % SIZE] == key) {
                status[(index + i) % SIZE] = DELETED; // Đánh dấu data bị xóa
                return;
            }
            i++;
        }
    }

    void displayHash() {
        for (int i = 0; i < SIZE; i++) {
            if (status[i] == OCCUPIED)
                cout << i << " : " << table[i] << endl;
            else if (status[i] == DELETED)
                cout << i << " : [Bi xoa]" << endl;
            else
                cout << i << " : [Trong]" << endl;
        }
    }
};

int main() {
    HashTableOpenAddressing htOpen(11);

    htOpen.insertKey(388); // => T[3]
    htOpen.insertKey(130); // => T[9]
    htOpen.insertKey(13);  // => T[2]
    htOpen.insertKey(14);  // => T[3] => T[4]
    htOpen.insertKey(926); // => T[2] => T[3] => T[4] => T[5]
    htOpen.insertKey(47);  // => T[3] => T[4] => T[5] => T[6]

    cout << "\nBang bam sau khi insert:\n";
    htOpen.displayHash();

    cout << "\n- find(47): " << (htOpen.searchKey(47) ? "Thay" : "Khong thay") << endl;

    cout << "- remove(926)...\n";
    htOpen.deleteKey(926);

    cout << "- find(47) sau khi xoa 926: " << (htOpen.searchKey(47) ? "Thay" : "Khong thay") << endl;

    cout << "- remove(388)...\n";
    htOpen.deleteKey(388);

    cout << "- find(926): " << (htOpen.searchKey(926) ? "Thay" : "Khong thay") << endl;

    cout << "\nBang bam hien tai:\n";
    htOpen.displayHash();

    return 0;
}
