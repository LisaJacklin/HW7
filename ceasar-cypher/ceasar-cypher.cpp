// ceasar-cypher.cpp 
// Lisa Jacklin 
// CS 201
// 11/16/2021
//

#include <iostream>

int main()
{
    char message[100], ch;
    int i, key;
    std::cout << "Enter a message to encrypt: ";
    std::cin.getline(message, 100);
    std::cout << "Enter key: ";
    std::cin >> key;
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    std::cout << "Encrypted message: " << message;
    return 0;
}