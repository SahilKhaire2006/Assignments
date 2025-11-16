#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct HashItem_sak {
    int key_sak;
    string value_sak;
    bool isDeleted_sak;
    bool isEmpty_sak;
    
    HashItem_sak() {
        key_sak = -1;
        value_sak = "";
        isDeleted_sak = false;
        isEmpty_sak = true;
    }
};

class HashTable_sak {
private:
    vector<HashItem_sak> table_sak;
    int size_sak;
    int count_sak;
    double loadFactorThreshold_sak;
    
    int hashFunction_sak(int key_sak) {
        return key_sak % size_sak;
    }
    
    void resizeTable_sak() {
        int oldSize_sak = size_sak;
        vector<HashItem_sak> oldTable_sak = table_sak;
        
        size_sak *= 2;
        table_sak.resize(size_sak);
        count_sak = 0;
        
        for (int i_sak = 0; i_sak < size_sak; i_sak++) {
            table_sak[i_sak] = HashItem_sak();
        }
        
        for (int i_sak = 0; i_sak < oldSize_sak; i_sak++) {
            if (!oldTable_sak[i_sak].isEmpty_sak && !oldTable_sak[i_sak].isDeleted_sak) {
                insert_sak(oldTable_sak[i_sak].key_sak, oldTable_sak[i_sak].value_sak);
            }
        }
        
        cout << "Table resized to " << size_sak << " elements" << endl;
    }
    
public:
    HashTable_sak(int initialSize_sak = 10) {
        size_sak = initialSize_sak;
        count_sak = 0;
        loadFactorThreshold_sak = 0.7;
        table_sak.resize(size_sak);
        
        for (int i_sak = 0; i_sak < size_sak; i_sak++) {
            table_sak[i_sak] = HashItem_sak();
        }
    }
    
    void insert_sak(int key_sak, string value_sak) {
        if ((double)count_sak / size_sak >= loadFactorThreshold_sak) {
            resizeTable_sak();
        }
        
        int index_sak = hashFunction_sak(key_sak);
        int originalIndex_sak = index_sak;
        
        while (!table_sak[index_sak].isEmpty_sak && !table_sak[index_sak].isDeleted_sak) {
            if (table_sak[index_sak].key_sak == key_sak) {
                cout << "Key " << key_sak << " already exists. Updating value." << endl;
                table_sak[index_sak].value_sak = value_sak;
                return;
            }
            index_sak = (index_sak + 1) % size_sak;
            
            if (index_sak == originalIndex_sak) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }
        
        table_sak[index_sak].key_sak = key_sak;
        table_sak[index_sak].value_sak = value_sak;
        table_sak[index_sak].isEmpty_sak = false;
        table_sak[index_sak].isDeleted_sak = false;
        count_sak++;
        
        cout << "Inserted key " << key_sak << " at index " << index_sak << endl;
    }
    
    string search_sak(int key_sak) {
        int index_sak = hashFunction_sak(key_sak);
        int originalIndex_sak = index_sak;
        
        while (!table_sak[index_sak].isEmpty_sak) {
            if (!table_sak[index_sak].isDeleted_sak && table_sak[index_sak].key_sak == key_sak) {
                cout << "Key " << key_sak << " found at index " << index_sak << endl;
                return table_sak[index_sak].value_sak;
            }
            index_sak = (index_sak + 1) % size_sak;
            
            if (index_sak == originalIndex_sak) {
                break;
            }
        }
        
        cout << "Key " << key_sak << " not found" << endl;
        return "NOT_FOUND";
    }
    
    void delete_sak(int key_sak) {
        int index_sak = hashFunction_sak(key_sak);
        int originalIndex_sak = index_sak;
        
        while (!table_sak[index_sak].isEmpty_sak) {
            if (!table_sak[index_sak].isDeleted_sak && table_sak[index_sak].key_sak == key_sak) {
                table_sak[index_sak].isDeleted_sak = true;
                table_sak[index_sak].isEmpty_sak = true;
                count_sak--;
                cout << "Key " << key_sak << " deleted from index " << index_sak << endl;
                return;
            }
            index_sak = (index_sak + 1) % size_sak;
            
            if (index_sak == originalIndex_sak) {
                break;
            }
        }
        
        cout << "Key " << key_sak << " not found for deletion" << endl;
    }
    
    void display_sak() {
        cout << "\nHash Table Contents:" << endl;
        cout << "Index\tKey\tValue\tStatus" << endl;
        cout << "-------------------------" << endl;
        
        for (int i_sak = 0; i_sak < size_sak; i_sak++) {
            cout << i_sak << "\t";
            if (table_sak[i_sak].isEmpty_sak && !table_sak[i_sak].isDeleted_sak) {
                cout << "-\t-\tEMPTY" << endl;
            } else if (table_sak[i_sak].isDeleted_sak) {
                cout << "-\t-\tDELETED" << endl;
            } else {
                cout << table_sak[i_sak].key_sak << "\t" 
                     << table_sak[i_sak].value_sak << "\tOCCUPIED" << endl;
            }
        }
        
        cout << "Load Factor: " << (double)count_sak / size_sak << endl;
        cout << "Total elements: " << count_sak << "/" << size_sak << endl;
    }
    
    double getLoadFactor_sak() {
        return (double)count_sak / size_sak;
    }
};

int main() {
    HashTable_sak ht_sak(5);
    int choice_sak, key_sak;
    string value_sak;
    
    cout << "=== Hash Table with Linear Probing ===" << endl;
    
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