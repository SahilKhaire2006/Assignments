#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

struct Employee_sak {
    int empId_sak;
    string name_sak;
    string department_sak;
    string designation_sak;
    double salary_sak;
    string phone_sak;
    string email_sak;
    
    Employee_sak() {
        empId_sak = -1;
        name_sak = "";
        department_sak = "";
        designation_sak = "";
        salary_sak = 0.0;
        phone_sak = "";
        email_sak = "";
    }
    
    Employee_sak(int id_sak, string n_sak, string dept_sak, string desg_sak, 
                double sal_sak, string ph_sak, string em_sak) {
        empId_sak = id_sak;
        name_sak = n_sak;
        department_sak = dept_sak;
        designation_sak = desg_sak;
        salary_sak = sal_sak;
        phone_sak = ph_sak;
        email_sak = em_sak;
    }
    
    void display_sak() {
        cout << "| " << setw(8) << empId_sak << " | "
             << setw(20) << name_sak << " | "
             << setw(15) << department_sak << " | "
             << setw(12) << designation_sak << " | "
             << setw(10) << fixed << setprecision(2) << salary_sak << " |" << endl;
    }
    
    void displayDetailed_sak() {
        cout << "| " << setw(8) << empId_sak << " | "
             << setw(20) << name_sak << " | "
             << setw(15) << department_sak << " | "
             << setw(12) << designation_sak << " | "
             << setw(10) << fixed << setprecision(2) << salary_sak << " | "
             << setw(12) << phone_sak << " | "
             << setw(25) << email_sak << " |" << endl;
    }
};

class EmployeeDatabase_sak {
private:
    vector<Employee_sak> table_sak;
    vector<bool> isOccupied_sak;
    vector<bool> isDeleted_sak;
    int size_sak;
    int employeeCount_sak;
    
    int midSquareHash_sak(int empId_sak) {
        long long squared_sak = (long long)empId_sak * empId_sak;
        string squaredStr_sak = to_string(squared_sak);
        int digits_sak = squaredStr_sak.length();
        int middleDigits_sak = min(4, digits_sak);
        int start_sak = (digits_sak - middleDigits_sak) / 2;
        string middleStr_sak = squaredStr_sak.substr(start_sak, middleDigits_sak);
        int middleValue_sak = stoi(middleStr_sak);
        return middleValue_sak % size_sak;
    }
    
    void displayHashCalculation_sak(int empId_sak, int hashIndex_sak) {
        long long squared_sak = (long long)empId_sak * empId_sak;
        string squaredStr_sak = to_string(squared_sak);
        int digits_sak = squaredStr_sak.length();
        int middleDigits_sak = min(4, digits_sak);
        int start_sak = (digits_sak - middleDigits_sak) / 2;
        string middleStr_sak = squaredStr_sak.substr(start_sak, middleDigits_sak);
        
        cout << "Hash Calculation for ID " << empId_sak << ":" << endl;
        cout << "  Squared: " << squared_sak << endl;
        cout << "  String: " << squaredStr_sak << endl;
        cout << "  Middle " << middleDigits_sak << " digits: " << middleStr_sak << endl;
        cout << "  Middle value: " << stoi(middleStr_sak) << endl;
        cout << "  Hash index: " << stoi(middleStr_sak) << " % " << size_sak 
             << " = " << hashIndex_sak << endl;
    }
    
public:
    EmployeeDatabase_sak(int tableSize_sak = 20) {
        size_sak = tableSize_sak;
        employeeCount_sak = 0;
        table_sak.resize(size_sak);
        isOccupied_sak.resize(size_sak, false);
        isDeleted_sak.resize(size_sak, false);
    }
    
    void addEmployee_sak() {
        if (employeeCount_sak >= size_sak) {
            cout << "Database is full! Cannot add more employees." << endl;
            return;
        }
        
        int empId_sak;
        string name_sak, department_sak, designation_sak, phone_sak, email_sak;
        double salary_sak;
        
        cout << "\nEnter Employee Details:" << endl;
        cout << "Employee ID: ";
        cin >> empId_sak;
        int searchIndex_sak;
        if (searchEmployeeIndex_sak(empId_sak, searchIndex_sak)) {
            cout << "Error: Employee with ID " << empId_sak << " already exists!" << endl;
            return;
        }
        
        cin.ignore(); 
        cout << "Name: ";
        getline(cin, name_sak);
        cout << "Department: ";
        getline(cin, department_sak);
        cout << "Designation: ";
        getline(cin, designation_sak);
        cout << "Salary: ";
        cin >> salary_sak;
        cout << "Phone: ";
        cin >> phone_sak;
        cout << "Email: ";
        cin >> email_sak;
        
        int index_sak = midSquareHash_sak(empId_sak);
        int originalIndex_sak = index_sak;
        int probes_sak = 0;
        
        displayHashCalculation_sak(empId_sak, index_sak);
        
        while (isOccupied_sak[index_sak] && !isDeleted_sak[index_sak]) {
            index_sak = (index_sak + 1) % size_sak;
            probes_sak++;
            
            if (index_sak == originalIndex_sak) {
                cout << "Database is full! Cannot add employee." << endl;
                return;
            }
        }
        
        table_sak[index_sak] = Employee_sak(empId_sak, name_sak, department_sak, 
                                           designation_sak, salary_sak, phone_sak, email_sak);
        isOccupied_sak[index_sak] = true;
        isDeleted_sak[index_sak] = false;
        employeeCount_sak++;
        
        cout << "Employee record added successfully!" << endl;
        cout << "Stored at index: " << index_sak << endl;
        cout << "Probes required: " << probes_sak << endl;
    }
    
    bool searchEmployeeIndex_sak(int empId_sak, int& foundIndex_sak) {
        int index_sak = midSquareHash_sak(empId_sak);
        int originalIndex_sak = index_sak;
        int probes_sak = 0;
        
        while (isOccupied_sak[index_sak] || isDeleted_sak[index_sak]) {
            probes_sak++;
            if (isOccupied_sak[index_sak] && !isDeleted_sak[index_sak] && 
                table_sak[index_sak].empId_sak == empId_sak) {
                foundIndex_sak = index_sak;
                cout << "Search completed in " << probes_sak << " probes" << endl;
                return true;
            }
            
            index_sak = (index_sak + 1) % size_sak;
            
            if (index_sak == originalIndex_sak) {
                break;
            }
        }
        
        return false;
    }
    
    void searchEmployee_sak() {
        int empId_sak;
        cout << "Enter Employee ID to search: ";
        cin >> empId_sak;
        
        int foundIndex_sak;
        if (searchEmployeeIndex_sak(empId_sak, foundIndex_sak)) {
            cout << "\nEmployee Record Found:" << endl;
            cout << "+----------+----------------------+-----------------+--------------+------------+" << endl;
            cout << "| Emp ID   | Name                 | Department      | Designation  | Salary     |" << endl;
            cout << "+----------+----------------------+-----------------+--------------+------------+" << endl;
            table_sak[foundIndex_sak].display_sak();
            cout << "+----------+----------------------+-----------------+--------------+------------+" << endl;
            cout << "Location: Index " << foundIndex_sak << " in hash table" << endl;
            cout << "Home index (Mid Square): " << midSquareHash_sak(empId_sak) << endl;
        } else {
            cout << "Employee with ID " << empId_sak << " not found!" << endl;
        }
    }
    
    void updateEmployee_sak() {
        int empId_sak;
        cout << "Enter Employee ID to update: ";
        cin >> empId_sak;
        
        int foundIndex_sak;
        if (searchEmployeeIndex_sak(empId_sak, foundIndex_sak)) {
            cout << "\nCurrent Employee Details:" << endl;
            cout << "+----------+----------------------+-----------------+--------------+------------+" << endl;
            cout << "| Emp ID   | Name                 | Department      | Designation  | Salary     |" << endl;
            cout << "+----------+----------------------+-----------------+--------------+------------+" << endl;
            table_sak[foundIndex_sak].display_sak();
            cout << "+----------+----------------------+-----------------+--------------+------------+" << endl;
            
            cout << "\nEnter New Details:" << endl;
            cin.ignore();
            
            string input_sak;
            cout << "Name [" << table_sak[foundIndex_sak].name_sak << "]: ";
            getline(cin, input_sak);
            if (!input_sak.empty()) table_sak[foundIndex_sak].name_sak = input_sak;
            
            cout << "Department [" << table_sak[foundIndex_sak].department_sak << "]: ";
            getline(cin, input_sak);
            if (!input_sak.empty()) table_sak[foundIndex_sak].department_sak = input_sak;
            
            cout << "Designation [" << table_sak[foundIndex_sak].designation_sak << "]: ";
            getline(cin, input_sak);
            if (!input_sak.empty()) table_sak[foundIndex_sak].designation_sak = input_sak;
            
            cout << "Salary [" << table_sak[foundIndex_sak].salary_sak << "]: ";
            getline(cin, input_sak);
            if (!input_sak.empty()) table_sak[foundIndex_sak].salary_sak = stod(input_sak);
            
            cout << "Phone [" << table_sak[foundIndex_sak].phone_sak << "]: ";
            getline(cin, input_sak);
            if (!input_sak.empty()) table_sak[foundIndex_sak].phone_sak = input_sak;
            
            cout << "Email [" << table_sak[foundIndex_sak].email_sak << "]: ";
            getline(cin, input_sak);
            if (!input_sak.empty()) table_sak[foundIndex_sak].email_sak = input_sak;
            
            cout << "Employee record updated successfully!" << endl;
        } else {
            cout << "Employee with ID " << empId_sak << " not found!" << endl;
        }
    }
    
    void deleteEmployee_sak() {
        int empId_sak;
        cout << "Enter Employee ID to delete: ";
        cin >> empId_sak;
        
        int foundIndex_sak;
        if (searchEmployeeIndex_sak(empId_sak, foundIndex_sak)) {
            isDeleted_sak[foundIndex_sak] = true;
            isOccupied_sak[foundIndex_sak] = false;
            employeeCount_sak--;
            cout << "Employee record deleted successfully!" << endl;
        } else {
            cout << "Employee with ID " << empId_sak << " not found!" << endl;
        }
    }
    
    void displayAllEmployees_sak() {
        if (employeeCount_sak == 0) {
            cout << "No employee records found!" << endl;
            return;
        }
        
        cout << "\nAll Employee Records (" << employeeCount_sak << " employees):" << endl;
        cout << "+----------+----------------------+-----------------+--------------+------------+" << endl;
        cout << "| Emp ID   | Name                 | Department      | Designation  | Salary     |" << endl;
        cout << "+----------+----------------------+-----------------+--------------+------------+" << endl;
        
        for (int i_sak = 0; i_sak < size_sak; i_sak++) {
            if (isOccupied_sak[i_sak] && !isDeleted_sak[i_sak]) {
                table_sak[i_sak].display_sak();
            }
        }
        cout << "+----------+----------------------+-----------------+--------------+------------+" << endl;
    }
    
    void displayAllEmployeesDetailed_sak() {
        if (employeeCount_sak == 0) {
            cout << "No employee records found!" << endl;
            return;
        }
        
        cout << "\nAll Employee Records - Detailed (" << employeeCount_sak << " employees):" << endl;
        cout << "+----------+----------------------+-----------------+--------------+------------+--------------+---------------------------+" << endl;
        cout << "| Emp ID   | Name                 | Department      | Designation  | Salary     | Phone        | Email                     |" << endl;
        cout << "+----------+----------------------+-----------------+--------------+------------+--------------+---------------------------+" << endl;
        
        for (int i_sak = 0; i_sak < size_sak; i_sak++) {
            if (isOccupied_sak[i_sak] && !isDeleted_sak[i_sak]) {
                table_sak[i_sak].displayDetailed_sak();
            }
        }
        cout << "+----------+----------------------+-----------------+--------------+------------+--------------+---------------------------+" << endl;
    }
    
    void displayDatabaseStatus_sak() {
        cout << "\nDatabase Status:" << endl;
        cout << "Index | Emp ID   | Home Index | Status" << endl;
        cout << "------+----------+------------+----------" << endl;
        
        int occupied_sak = 0, deleted_sak = 0, empty_sak = 0;
        
        for (int i_sak = 0; i_sak < size_sak; i_sak++) {
            cout << setw(5) << i_sak << " | ";
            
            if (isOccupied_sak[i_sak] && !isDeleted_sak[i_sak]) {
                int homeIndex_sak = midSquareHash_sak(table_sak[i_sak].empId_sak);
                cout << setw(8) << table_sak[i_sak].empId_sak << " | "
                     << setw(10) << homeIndex_sak << " | ";
                
                if (homeIndex_sak == i_sak) {
                    cout << "HOME";
                } else {
                    cout << "PROBED";
                }
                cout << endl;
                occupied_sak++;
            } else if (isDeleted_sak[i_sak]) {
                cout << setw(8) << " - " << " | " << setw(10) << " - " << " | DELETED" << endl;
                deleted_sak++;
            } else {
                cout << setw(8) << " - " << " | " << setw(10) << " - " << " | EMPTY" << endl;
                empty_sak++;
            }
        }
        
        cout << "\nDatabase Statistics:" << endl;
        cout << "Total slots: " << size_sak << endl;
        cout << "Occupied slots: " << occupied_sak << endl;
        cout << "Deleted slots (tombstones): " << deleted_sak << endl;
        cout << "Empty slots: " << empty_sak << endl;
        cout << "Load Factor: " << fixed << setprecision(2) << (double)employeeCount_sak / size_sak << endl;
        cout << "Table utilization: " << fixed << setprecision(1) 
             << ((double)occupied_sak / size_sak) * 100 << "%" << endl;
    }
    
    void testHashFunction_sak() {
        cout << "\nMid Square Hash Function Test:" << endl;
        cout << "Employee ID -> Squared -> Middle Digits -> Hash Index" << endl;
        cout << "-----------------------------------------------------" << endl;
        
        vector<int> testIds_sak = {123, 456, 789, 101, 202, 303, 1234, 5678, 9999};
        
        for (int id_sak : testIds_sak) {
            int hash_sak = midSquareHash_sak(id_sak);
            cout << setw(10) << id_sak << " -> " << setw(10) << (id_sak * id_sak) 
                 << " -> " << setw(10) << hash_sak << endl;
        }
    }
};

int main() {
    EmployeeDatabase_sak edb_sak(20);
    int choice_sak;
    
    cout << "=== Employee Database Management System ===" << endl;
    cout << "Using Mid Square Hash Function with Linear Probing" << endl;
    
    do {
        cout << "\nMain Menu:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Search Employee" << endl;
        cout << "3. Update Employee" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Display All Employees (Summary)" << endl;
        cout << "6. Display All Employees (Detailed)" << endl;
        cout << "7. Display Database Status" << endl;
        cout << "8. Test Hash Function" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice_sak;
        
        switch (choice_sak) {
            case 1:
                edb_sak.addEmployee_sak();
                break;
                
            case 2:
                edb_sak.searchEmployee_sak();
                break;
                
            case 3:
                edb_sak.updateEmployee_sak();
                break;
                
            case 4:
                edb_sak.deleteEmployee_sak();
                break;
                
            case 5:
                edb_sak.displayAllEmployees_sak();
                break;
                
            case 6:
                edb_sak.displayAllEmployeesDetailed_sak();
                break;
                
            case 7:
                edb_sak.displayDatabaseStatus_sak();
                break;
                
            case 8:
                edb_sak.testHashFunction_sak();
                break;
                
            case 9:
                cout << "Thank you for using Employee Database System!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice_sak != 9);
    
    return 0;
}