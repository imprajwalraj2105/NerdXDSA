#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->val;
    }

    void put(int key, int value) {

        // If key exists → update
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }

        // Create new node
        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);

        // Remove LRU
        if (mp.size() > capacity) {
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;  // 🔥 important fix
        }
    }
};

int main() {
    int cap, q;
    cin >> cap >> q;

    LRUCache cache(cap);

    while (q--) {
        string op;
        cin >> op;

        if (op == "PUT") {
            int k, v;
            cin >> k >> v;
            cache.put(k, v);
        } else { // GET
            int k;
            cin >> k;
            cout << cache.get(k) << endl;
        }
    }
}