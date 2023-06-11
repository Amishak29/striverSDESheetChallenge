#include <iostream>
using namespace std;

void PrintName(int i, int n) {
    if (n == 0) {
        return;
    }
    cout << "Amisha" << endl;
    PrintName(i, n-1);
}

int main() {
    int n;
    cin >> n;
    PrintName(1, n);
    return 0;
}
