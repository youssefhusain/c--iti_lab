#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class Employee {
    int id;
    char name[100];
public:
    Employee() {
        strcpy(name, "");
        id = 0;
    }
    Employee(const char* n, int i) {
        strcpy(name, n);
        id = i;
    }

    friend istream& operator>>(istream& in, Employee& emp) {
        cout << "Enter name of employee: ";
        in >> emp.name;
        cout << "Enter id of " << emp.name << ": ";
        in >> emp.id;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Employee emp) {
        out << "ID of " << emp.name << " is " << emp.id << endl;
        return out;
    }

    void read_from_file(const string& path) {
        ifstream infile(path);
        if (!infile) {
            cerr << "Error opening file" << endl;
            return;
        }
        infile >> name >> id;
        infile.close();
    }

    void read_from_binary_file(const string& path) {
        ifstream infile(path, ios::binary);
        if (!infile) {
            cerr << "Error opening file" << endl;
            return;
        }
        infile.read(reinterpret_cast<char*>(this), sizeof(Employee));
        infile.close();
    }

    void write_to_binary_file(const string& path) const {
        ofstream outfile(path, ios::binary);
        if (!outfile) {
            cerr << "Error opening file" << endl;
            return;
        }
        outfile.write(reinterpret_cast<const char*>(this), sizeof(Employee));
        outfile.close();
    }

    void write_to_file(const string& path) const {
        ofstream outfile(path);
        if (!outfile) {
            cerr << "Error opening file" << endl;
            return;
        }
        outfile << name << " " << id << endl;
        outfile.close();
    }
};

int main() {
    Employee emp1;
    cin >> emp1;
    cout << emp1;

    string text_file_path = "employee.txt";
    string binary_file_path = "employee.dat";
    emp1.write_to_file(text_file_path);
    emp1.write_to_binary_file(binary_file_path);
    Employee emp2;
    emp2.read_from_binary_file(binary_file_path);
    cout << emp2;

    return 0;
}
