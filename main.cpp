#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void encyrpt(string, string);
void decrypt(string, string);

int main() {
    string key = "hi";
    string msg = "HVfboquo";

    decrypt(key, msg);
}

void encyrpt(string key, string msg) {
    string result = "";
    char c, k, r;
    for (int i = 0; i < msg.size(); i++) {
        c = msg[i];
        k = key[i % key.size()];
        if (isupper(c)) {
            r = ((c + ((k % 32) - 1)) - 64) % 26 + 64;
        }
        else {
            r = ((c + ((k % 32) - 1)) - 96) % 26 + 96;
        }

        result.push_back(r);
    }

    cout << result;
}

void decrypt(string key, string msg) {
    string result = "";
    char c, k, r;
    for (int i = 0; i < msg.size(); i++) {
        c = msg[i];
        k = key[i % key.size()];
        if (isupper(c)) {
            r = ((c - ((k % 32) - 1)) - 64) % 26 + 64;
        }
        else {
            r = ((c - ((k % 32) - 1)) - 96) % 26 + 96;
        }
        result.push_back(r);
    }
    cout << result;
}