#include <iostream>
#include <vector>

using namespace std;

int butterflies(int n, vector<int>& a) {
    int turns = 0;
    int extraMove = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            turns++;
            if (extraMove > 0) {
                extraMove--;
            }
            extraMove++;
        } else {
            turns++;
        }
    }

    return turns - extraMove + 1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int result = butterflies(N, A);
        cout << result << endl;
    }

    return 0;
}
