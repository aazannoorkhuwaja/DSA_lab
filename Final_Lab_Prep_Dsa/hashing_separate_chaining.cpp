//open hashing 
//Can hold more elements than the table size.
#include<iostream>
using namespace std;

class node{
public:
    int key;
    node * next;
    node(int d):key(d),next(NULL){}
};


class chaining_hashing{
private:
    node **table;
    int size;
    int current_elements;

public:
    chaining_hashing(int s):size(s),current_elements(0){
        table=new node*[size];
        for(int i=0;i<size;i++)
        {
            table[i]=NULL;
        }
    }

    // Crucial for Lab Exam: Memory cleanup
    ~chaining_hashing() {
        for (int i = 0; i < size; i++) {
            node* current = table[i];
            while (current != NULL) {
                node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] table; // Delete the array of node pointers
    }

    int hash_fun(int key)
    {
        return (key%size);
    }
    
    // --- 1. INSERT (Fixed: Head Insertion) ---
    void insert(int val)
    {
        int index = hash_fun(val);
        
        // 1. Check for duplicates (Optional, but good practice)
        // if (search(val)) { return; } 

        node *new_node = new node(val);
        
        // 2. Link the new node to the old head
        new_node->next = table[index];
        
        // 3. Update the table pointer to the new node (New Head)
        table[index] = new_node;

        current_elements++;
        cout << "Inserted " << val << " at bucket " << index << endl;
    }

    // --- 2. SEARCH ---
    bool search(int key) {
        int index = hash_fun(key);
        node* current = table[index];

        while (current != NULL) {
            if (current->key == key) {
                cout << "Found " << key << " in bucket " << index << endl;
                return true;
            }
            current = current->next;
        }
        cout << key << " not found." << endl;
        return false;
    }

    // --- 3. REMOVE/DELETE ---
    void remove(int key) {
        int index = hash_fun(key);
        node* current = table[index];
        node* prev = NULL;

        while (current != NULL) {
            if (current->key == key) {
                // Case 1: Deleting the head node
                if (prev == NULL) {
                    table[index] = current->next;
                } 
                // Case 2: Deleting middle/tail node
                else {
                    prev->next = current->next;
                }
                
                delete current;
                current_elements--;
                cout << "Removed " << key << " successfully." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Key " << key << " not found for deletion." << endl;
    }

    // --- 4. DISPLAY ---
    void display() {
        cout << "\n--- HASH TABLE CONTENTS ---\n";
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            node* current = table[i];
            if (current == NULL) {
                cout << "Empty" << endl;
            } else {
                while (current != NULL) {
                    cout << current->key << " -> ";
                    current = current->next;
                }
                cout << "NULL" << endl;
            }
        }
    }
};


int main() {
    // Using size 7 for easy collision creation
    int n = 7; 
    chaining_hashing ht(n);

    cout << "--- Insertions ---\n";
    ht.insert(10); // 10 % 7 = 3
    ht.insert(24); // 24 % 7 = 3 (Collision! Chained at index 3)
    ht.insert(15); // 15 % 7 = 1
    ht.insert(38); // 38 % 7 = 3 (Collision! Chained at index 3)
    
    ht.display();

    cout << "\n--- Deletion Test ---\n";
    ht.remove(24); // Deleting from the middle of the chain
    
    cout << "\n--- Final State ---\n";
    ht.display();
    ht.search(10); // Should still find it
    ht.search(24); // Should not find it
    
    return 0;
}