#include <iostream>
#include <list>
#include <vector>

using namespace std;

int nextPrime(int n) {
    while (true) {
        bool isPrime = true;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) return n;
        ++n;
    }
}

class HashTableChaining {
    int capacity;
    vector<list<pair<int, int>>> table;

public:
    HashTableChaining(int size) {
        capacity = nextPrime(size);
        table.resize(capacity);
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insertItem(int student_id, int score) {
        int index = hashFunction(student_id);
        table[index].push_back(make_pair(student_id, score));
    }

    void deleteItem(int student_id) {
        int index = hashFunction(student_id);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == student_id) {
                table[index].erase(it);
                break;
            }
        }
    }

    void displayHash() {
        for (int i = 0; i < capacity; ++i) {
            cout << i << ": ";
            for (auto x : table[i])
                cout << "-> [ Student Id: " << x.first << ", Score:" << x.second << "] ";
            cout << endl;
        }
    }
};

class HashTableLinearProbing {
    int capacity;
    vector<pair<int, int>> table;
    vector<bool> isOccupied;

public:
    HashTableLinearProbing(int size) {
        capacity = nextPrime(size);
        table.resize(capacity, make_pair(-1, -1));
        isOccupied.resize(capacity, false);
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insertItem(int student_id, int score) {
        int index = hashFunction(student_id);
        int originalIndex = index;
        while (isOccupied[index]) {
            index = (index + 1) % capacity;
            if (index == originalIndex) return;
        }
        table[index] = make_pair(student_id, score);
        isOccupied[index] = true;
    }

    void deleteItem(int student_id) {
        int index = hashFunction(student_id);
        int originalIndex = index;
        while (isOccupied[index]) {
            if (table[index].first == student_id) {
                table[index] = make_pair(-1, -1);
                isOccupied[index] = false;
                return;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex) return;
        }
    }

    void displayHash() {
        for (int i = 0; i < capacity; ++i) {
            if (isOccupied[i])
                cout << i << ": [ Student Id: " << table[i].first << ", Score:" << table[i].second << "]" << endl;
            else
                cout << i << ": " << endl;
        }
    }
};

int main() {
    HashTableChaining htChaining(6);
    htChaining.insertItem(231, 123);
    htChaining.insertItem(326, 432);
    htChaining.insertItem(212, 523);
    htChaining.insertItem(321, 43);
    htChaining.insertItem(433, 423);
    htChaining.insertItem(262, 111);
    cout << "Hash Table using Separate Chaining:" << endl;
    htChaining.displayHash();
    htChaining.deleteItem(212);
    cout << "After deleting student ID 212:" << endl;
    htChaining.displayHash();

    HashTableLinearProbing htLinear(6);
    htLinear.insertItem(231, 123);
    htLinear.insertItem(326, 432);
    htLinear.insertItem(212, 523);
    htLinear.insertItem(321, 43);
    htLinear.insertItem(433, 423);
    htLinear.insertItem(262, 111);
    cout << "\nHash Table using Linear Probing:" << endl;
    htLinear.displayHash();
    htLinear.deleteItem(212);
    cout << "After deleting student ID 212:" << endl;
    htLinear.displayHash();

    cout<<"23CE058 prepared by Dharmik";

    return 0;
}