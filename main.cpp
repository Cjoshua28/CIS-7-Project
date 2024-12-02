#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void encyrpt(string key, string msg);

int main() {
    string key = "hi";
    string msg = "ANything";

    encyrpt(key, msg);
}

void encyrpt(string key, string msg) {
    string result = "";
    for (int i = 0; i < msg.size(); i++) {
        char c = msg[i];
        char k = key[i % key.size()];
        char r;
        if (isupper(c)) {
            r = ((c + ((k % 32) - 1)) - 64) % 26 + 64 ;
        }
        else {
            r = ((c + ((k % 32) - 1)) - 96) % 26 + 96;
        }

        result.push_back(r);
    }

    cout << result;
}

void decrypt(string key, string msg) {

}