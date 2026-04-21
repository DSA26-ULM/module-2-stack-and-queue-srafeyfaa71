#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    int angka[100];
    for (int i = 0; i < n; i++) {
        cin >> angka[i];
    }

    for (int i = 0; i <= n - k; i++) {
        Queue q;
        init(&q);
        int total = 0;

        for (int j = i; j < i + k; j++) {
            enqueue(&q, angka[j]);
        }

        while (!isEmpty(&q)) {
            total += front(&q);
            dequeue(&q);
        }

        cout << total;
        if (i < n - k) cout << " ";
    }

    cout << endl;
    return 0;
}
