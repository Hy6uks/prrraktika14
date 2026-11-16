// Тришкин Артём ЭФБО-07-26
#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
    vector<int> mainStack;
    vector<int> minStack;

public:
    void push(int value) {
        mainStack.push_back(value);
        
        if (minStack.empty() || value <= minStack.back()) {
            minStack.push_back(value);
        } else {
            minStack.push_back(minStack.back());
        }
    }

    void pop() {
        if (!empty()) {
            mainStack.pop_back();
            minStack.pop_back();
        } else {
            cout << "Ошибка: стек пуст!" << endl;
        }
    }

    bool empty() {
        return mainStack.empty();
    }

    int getMin() {
        if (!empty()) {
            return minStack.back();
        }
        return -1;
    }

};

int main() {
    MinStack stack;
    
    stack.push(5);
    stack.push(2);
    stack.push(8);
    
    cout << "Текущий минимум: " << stack.getMin() << endl; 
    
    stack.push(1);
    cout << "Текущий минимум: " << stack.getMin() << endl; 
    
    stack.pop();
    cout << "Текущий минимум после pop: " << stack.getMin() << endl; 
    
    stack.pop();
    cout << "Текущий минимум после pop: " << stack.getMin() << endl;
    
    stack.pop();
    cout << "Текущий минимум после pop: " << stack.getMin() << endl;
    
    return 0;
}