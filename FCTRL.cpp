// www.spoj.com/problems/FCTRL/
//

#include <iostream>
#define MAXt 100000
#define MAXn 1000000000
using namespace std;


unsigned countZero(unsigned);

int main()
{
    unsigned t, n;
    do {
        cin >> t;
    } while (t <= 0 || t > MAXt);
    for (unsigned i = 1; i <= t; i++) {
        do {
            cin >> n;
        } while (n<1 || n>MAXn);
        cout << countZero(n) << endl;
    }
    return 0;
}

unsigned countZero(unsigned n) {
    unsigned count = 0;
    unsigned p = 5;
    while (n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}