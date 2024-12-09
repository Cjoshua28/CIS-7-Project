#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void encrypt(string, string);
void decrypt(string, string);
int userInterface();

int main() {
    cout << "Greetings!\n";
    int operation;
    string msg;
    string key;

    do {
    operation = userInterface();
    switch (operation)
    {
    case 1:
        cout << "Enter message to encrypt: ";
        getline(cin >> ws, msg);
        cout << "Enter key: ";
        getline(cin >> ws, key);
        encrypt(msg, key);
        cout << endl;
        break;
    case 2:
        cout << "Enter message to decrypt: ";
        getline(cin >> ws, msg);
        cout << "Enter key: ";
        getline(cin >> ws, key);
        decrypt(msg, key);
        cout << endl;
        break;
    case 3:
        cout << "Shutting down...";
        continue;
    default:
        break;
    }
    } while (operation != 3);
    return 0;
}

int userInterface() {
    int choice;
    bool validation = false;
    do {
    cout << "1. Encryption" << "\n2. Decryption" << "\n3. Quit" << endl;
    cout << "Please select your operation: ";
    cin >> choice;
    if (choice > 3 || choice < 1) {
        cout << "That is not a valid choice.\n";
    }
    else {
        validation = true;
    }
    }
    while (!validation);

    return choice;
}



void encrypt(string msg, string key) {
    string result = "";
    char c, k, r;
    for (int i = 0; i < msg.size(); i++) {
        c = msg[i];
        k = key[i % key.size()];
        if (isupper(c)) {
            r = ((c - 65) + ((k % 32) - 1)) % 26 + 65;
        }
        else {
            r = ((c - 97) + ((k % 32) - 1)) % 26 + 97;
        }

        result.push_back(r);
    }

    cout << "Encrypted phrase: " << result;
}

void decrypt(string msg, string key) {
    string result = "";
    char c, k, r;
    for (int i = 0; i < msg.size(); i++) {
        c = msg[i];
        k = key[i % key.size()];
        if (isupper(c)) {
            r = ((c - 39) - ((k % 32) - 1)) % 26 + 65;
        }
        else {
            r = ((c - 71) - ((k % 32) - 1)) % 26 + 97;
        }
        result.push_back(r);
    }
    cout << "Decrypted phrase: " << result;
}