// Тришкин Артём ЭФБО-07-26
#include <iostream>
#include <string>
using namespace std;

int main(){
    string message; // строка
    getline(cin, message); // считывание строки целиком включая пробелы

    int skobki = 0; // Счётчик скобок
    bool isCorrect = true;

    for (int i = 0; i < message.length(); i++){
        if (message[i] == '('){
            skobki++;
        }
        else if (message[i] == ')'){
            skobki--;
        }
        
        if (skobki < 0) {
            isCorrect = false;
            break;
        }
    }

    if (skobki != 0){
        isCorrect = false;
    }

    if (isCorrect){
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}