#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void encrypt(string, string);
void decrypt(string, string);

int main() {
    cout << "Greetings!";

    int operation = userInterface();
    string key;
    string msg;
    switch (operation)
    {
    case 1:
        cout << "Enter message to encrypt: ";
        cin >> msg;
        cout << "Enter key: ";
        cin >> key;
        encrypt(msg, key);
        break;
    case 2:
        cout << "Enter message to decrypt: ";
        cin >> msg;
        cout << "Enter key: ";
        cin >> key;
        decrypt(msg, key);
        break;
    default:
        break;
    }
}

int userInterface() {
    int choice;
    bool validation = false;
    do {
    cout << "1. Encryption" << "\n2. Decryption" << "\n3. Quit" << endl;
    cout << "Please select your operation: ";
    cin >> choice;
    if (choice > 3 || choice < 1) {
        cout << "That is not a valid choice.";
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

    cout << result;
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
    cout << result;
}