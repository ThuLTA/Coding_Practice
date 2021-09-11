// www.spoj.com/problems/FCTRL/
//

#include <iostream>
#include <vector>
#define MAX 100
using namespace std;


vector<unsigned> smallFactorials(unsigned);

int main()
{
    unsigned t, n;
    do {
        cin >> t;
    } while (t <= 0 || t > MAX);
    for (unsigned i = 1; i <= t; i++) {
        do {
            cin >> n;
        } while (n<1 || n>MAX);
        vector<unsigned> save = smallFactorials(n);
        for (int vt = 0; vt < save.size(); vt++)
            cout << save[vt];
        cout << endl;
    }
    return 0;
}

vector<unsigned> smallFactorials(unsigned n) {
    vector<unsigned> save = { 1 };
    if (n == 1)
        return save;
    unsigned div = 1;
    for (int i = 2; i <= n;i++) {
        unsigned time = 0;
        unsigned d = 0;
        for (int vt = save.size() - 1; vt >= 0; vt--) {
            time = save[vt] * i + d;
            d = time / 10;
            save[vt] = time % 10;
        }
        while (d > 0) {
            save.insert(save.begin(), d % 10);
            d /= 10;
        }
    }
    return save;
}