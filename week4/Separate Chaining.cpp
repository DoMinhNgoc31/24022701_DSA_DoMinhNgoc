#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTableChaining {
private:
    int SIZE;
    vector<list<int>> table;

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTableChaining(int size) {
        SIZE = size;
        table.resize(SIZE);
    }

    void insertKey(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool searchKey(int key) {
        int index = hashFunction(key);
        for (auto i : table[index]) {
            if (i == key) return true;
        }
        return false;
    }

    void displayHash() {
        for (int i = 0; i < SIZE; i++) {
            cout << i;
            for (auto x : table[i]) {
                cout << " -> " << x;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTableChaining htChain(7);

    htChain.insertKey(10);
    htChain.insertKey(20);
    htChain.insertKey(15);
    htChain.insertKey(7);
    htChain.insertKey(14); // Sẽ va chạm với 7 tại chỉ số 0

    cout << "\nBang bam sau khi insert:\n";
    htChain.displayHash();

    cout << "\n- find(15): " << (htChain.searchKey(15) ? "Thay" : "Khong thay") << endl;

    cout << "- remove(20)...\n";
    htChain.deleteKey(20);

    cout << "\nBang bam hien tai:\n";
    htChain.displayHash();

    return 0;
}
