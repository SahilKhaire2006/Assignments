#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node_sak {
    int key_sak;
    string value_sak;
    Node_sak* next_sak;
    
    Node_sak(int k_sak, string v_sak) {
        key_sak = k_sak;
        value_sak = v_sak;
        next_sak = nullptr;
    }
};

class HashTable_sak {
private:
    vector<Node_sak*> table_sak;
    int size_sak;
    int count_sak;
    
    int hashFunction_sak(int key_sak) {
        return key_sak % size_sak;
    }
    
public:
    HashTable_sak(int initialSize_sak = 10) {
        size_sak = initialSize_sak;
        count_sak = 0;
        table_sak.resize(size_sak, nullptr);
    }
    
    void insert_sak(int key_sak, string value_sak) {
        int index_sak = hashFunction_sak(key_sak);
        Node_sak* current_sak = table_sak[index_sak];
        
        // Check if key already exists
        while (current_sak != nullptr) {
            if (current_sak->key_sak == key_sak) {
                cout << "Key " << key_sak << " already exists. Updating value from '" 
                     << current_sak->value_sak << "' to '" << value_sak << "'" << endl;
                current_sak->value_sak = value_sak;
                return;
            }
            current_sak = current_sak->next_sak;
        }
        
        // Insert new node at beginning of chain
        Node_sak* newNode_sak = new Node_sak(key_sak, value_sak);
        newNode_sak->next_sak = table_sak[index_sak];
        table_sak[index_sak] = newNode_sak;
        count_sak++;
        
        cout << "Inserted key " << key_sak << " at bucket " << index_sak << endl;
    }
    
    string search_sak(int key_sak) {
        int index_sak = hashFunction_sak(key_sak);
        Node_sak* current_sak = table_sak[index_sak];
        int position_sak = 0;
        
        while (current_sak != nullptr) {
            if (current_sak->key_sak == key_sak) {
                cout << "Key " << key_sak << " found at bucket " << index_sak 
                     << ", position " << position_sak << endl;
                return current_sak->value_sak;
            }
            current_sak = current_sak->next_sak;
            position_sak++;
        }
        
        cout << "Key " << key_sak << " not found" << endl;
        return "NOT_FOUND";
    }
    
    void delete_sak(int key_sak) {
        int index_sak = hashFunction_sak(key_sak);
        Node_sak* current_sak = table_sak[index_sak];
        Node_sak* prev_sak = nullptr;
        
        while (current_sak != nullptr) {
            if (current_sak->key_sak == key_sak) {
                if (prev_sak == nullptr) {
                    // Deleting head node
                    table_sak[index_sak] = current_sak->next_sak;
                } else {
                    // Deleting middle or tail node
                    prev_sak->next_sak = current_sak->next_sak;
                }
                
                cout << "Deleted key " << key_sak << " from bucket " << index_sak << endl;
                delete current_sak;
                count_sak--;
                return;
            }
            prev_sak = current_sak;
            current_sak = current_sak->next_sak;
        }
        
        cout << "Key " << key_sak << " not found for deletion" << endl;
    }
    
    void display_sak() {
        cout << "\nHash Table Contents:" << endl;
        cout << "Bucket\tChain Contents" << endl;
        cout << "----------------------" << endl;
        
        int emptyBuckets_sak = 0;
        int maxChainLength_sak = 0;
        
        for (int i_sak = 0; i_sak < size_sak; i_sak++) {
            cout << i_sak << "\t";
            
            if (table_sak[i_sak] == nullptr) {
                cout << "EMPTY";
                emptyBuckets_sak++;
            } else {
                Node_sak* current_sak = table_sak[i_sak];
                int chainLength_sak = 0;
                
                while (current_sak != nullptr) {
                    cout << "[" << current_sak->key_sak << ":" << current_sak->value_sak << "]";
                    if (current_sak->next_sak != nullptr) {
                        cout << " -> ";
                    }
                    current_sak = current_sak->next_sak;
                    chainLength_sak++;
                }
                
                if (chainLength_sak > maxChainLength_sak) {
                    maxChainLength_sak = chainLength_sak;
                }
            }
            cout << endl;
        }
        
        cout << "\nStatistics:" << endl;
        cout << "Total elements: " << count_sak << endl;
        cout << "Table size: " << size_sak << endl;
        cout << "Load Factor: " << getLoadFactor_sak() << endl;
        cout << "Empty buckets: " << emptyBuckets_sak << endl;
        cout << "Maximum chain length: " << maxChainLength_sak << endl;
    }
    
    double getLoadFactor_sak() {
        return (double)count_sak / size_sak;
    }
    
    ~HashTable_sak() {
        // Clean up all linked lists
        for (int i_sak = 0; i_sak < size_sak; i_sak++) {
            Node_sak* current_sak = table_sak[i_sak];
            while (current_sak != nullptr) {
                Node_sak* temp_sak = current_sak;
                current_sak = current_sak->next_sak;
                delete temp_sak;
            }
        }
    }
};

int main() {
    HashTable_sak ht_sak(7);
    int choice_sak, key_sak;
    string value_sak;
    
    cout << "=== Hash Table with Separate Chaining ===" << endl;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert key-value pair" << endl;
        cout << "2. Search for key" << endl;
        cout << "3. Delete key" << endl;
        cout << "4. Display hash table" << endl;
        cout << "5. Get load factor" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice_sak;
        
        switch (choice_sak) {
            case 1:
                cout << "Enter key: ";
                cin >> key_sak;
                cout << "Enter value: ";
                cin >> value_sak;
                ht_sak.insert_sak(key_sak, value_sak);
                break;
                
            case 2:
                cout << "Enter key to search: ";
                cin >> key_sak;
                value_sak = ht_sak.search_sak(key_sak);
                if (value_sak != "NOT_FOUND") {
                    cout << "Value: " << value_sak << endl;
                }
                break;
                
            case 3:
                cout << "Enter key to delete: ";
                cin >> key_sak;
                ht_sak.delete_sak(key_sak);
                break;
                
            case 4:
                ht_sak.display_sak();
                break;
                
            case 5:
                cout << "Current load factor: " << ht_sak.getLoadFactor_sak() << endl;
                break;
                
            case 6:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice_sak != 6);
    
    return 0;
}