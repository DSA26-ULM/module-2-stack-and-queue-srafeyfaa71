#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Stack s;
    init(&s);
    string input;

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == "+" || input == "-" || input == "*" || input == "/") {
            int bil2 = peek(&s); pop(&s);
            int bil1 = peek(&s); pop(&s);

            if (input == "+") push(&s, bil1 + bil2);
            else if (input == "-") push(&s, bil1 - bil2);
            else if (input == "*") push(&s, bil1 * bil2);
            else if (input == "/") push(&s, bil1 / bil2);
        } else {
            push(&s, stoi(input));
        }
    }
    cout << peek(&s) << endl; 
    return 0;
}
