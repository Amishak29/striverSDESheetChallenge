#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    const int N = 3;

    long t;
    cin >> t;

    while (t--) {
        long n;
        cin >> n;

        vector<map<string, int>> v;
        for (long p = 0; p < N; p++) {
            for (long q = 0; q < n; q++) {
                string s;
                cin >> s;
                v[p][s]++;
            }
        }

        vector<long> score(N, 0);
        for (long p = 0; p < N; p++) {
            for (auto it = v[p].begin(); it != v[p].end(); it++) {
                string x = it->first;
                long count = 0;
                for (long q = 0; q < N; q++) {
                    if (q == p) {
                        continue;
                    }
                    count += v[q].count(x);
                }

                if (count == 0) {
                    score[p] += 3;
                } else if (count == 1) {
                    score[p] += 1;
                }
            }
        }

        for (long p = 0; p < N; p++) {
            cout << score[p] << " ";
        }
        cout << endl;
    }

    return 0;
}
