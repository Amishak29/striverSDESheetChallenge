#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int X, Y;
        cin >> X >> Y; 
        int games = 0;
        while (X < Y) {
            X += 8;  
            games++;
        }

        cout << games<< endl;
    }

    return 0;
}
