#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string user, pass;
    cout << "\n--- Registration ---\n";
    cout << "Enter Username: ";
    cin >> user;
    cout << "Enter Password: ";
    cin >> pass;

    ofstream file("database.txt", ios::app);
    if (file.is_open()) {
        file << user << " " << pass << endl;
        file.close();
        cout << "Registration Successful!\n";
    } else {
        cout << "Error: File open nahi ho rahi!\n";
    }
}

bool loginUser() {
    string user, pass, u, p;
    cout << "\n--- Login ---\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    ifstream file("database.txt");
    if (!file) {
        cout << "Error: Pehle Register karein, database file nahi mili!\n";
        return false;
    }

    while (file >> u >> p) {
        if (u == user && p == pass) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

int main() {
    int choice;
    while(true) { // Loop taaki bar-bar run na karna pade
        cout << "\n1. Register\n2. Login\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) registerUser();
        else if (choice == 2) {
            if (loginUser()) cout << "LOGIN SUCCESS!\n";
            else cout << "LOGIN FAILED!\n";
        }
        else break;
    }
    return 0;
}