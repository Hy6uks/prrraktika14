// Тришкин Артём ЭФБО-07-26
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// функция для перевода букв в нижний регистр
char toLower(char c) {
    if (c >= 'А' && c <= 'Я') return c + 32; // русские
    if (c >= 'A' && c <= 'Z') return c + 32; // английские
    if (c == 'Ё') return 'ё';                // отдельно буква ё
    return c; // если не заглавная, возвращаем как есть
}

// проверка символа на букву или дефис
bool isLetter(char c) {
    return (c >= 'а' && c <= 'я') || (c >= 'a' && c <= 'z') || c == 'ё' || c == '-';
}

// проверка уникальности и вывода
void checkAndPrint(string word, vector<string>& uniqueWords) {
    if (word.empty()) return; // если слово пустое ничего не делаем

    // ищем слово в списке уже найденных
    for (int i = 0; i < uniqueWords.size(); i++) {
        if (uniqueWords[i] == word) {
            return;
        }
    }
    
    // если не нашли добавляем в список и выводим на экран
    uniqueWords.push_back(word);
    cout << word << endl;
}

int main() {
    string text;
    getline(cin, text); // считываем всю строку

    vector<string> uniqueWords; // здесь будем хранить уникальные слова
    string currentWord = "";    // текущее собираемое слово

    for (int i = 0; i < text.length(); i++) {
        char c = toLower(text[i]); // сразу переводим символ в нижний регистр

        if (isLetter(c)) {
            currentWord += c; // если это буква/дефис и добавляем в слово
        } else {
            // если встретили пробел или знак препинания - слово закончилось
            checkAndPrint(currentWord, uniqueWords);
            currentWord = ""; // очищаем для следующего слова
        }
    }

    // проверяем последнее слово в строке
    checkAndPrint(currentWord, uniqueWords);

    return 0;
}