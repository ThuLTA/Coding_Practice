// www.spoj.com/problems/ADDREV/
//

#include <iostream>
using namespace std;

unsigned reversed(unsigned);
unsigned solution(unsigned, unsigned);

int main()
{
    unsigned t, a, b, res;
    do {
        cin >> t;
    }while(t <= 0 || t > 10000);
    for (unsigned i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << solution(a, b) << endl;
    }
    return 0;
}

unsigned solution(unsigned a, unsigned b) {
    return reversed(reversed(a) + reversed(b));
}

unsigned reversed(unsigned a) {
    unsigned r = 0;
    while (a > 0) {
        r = r * 10 + a % 10;
        a /= 10;
    }
    return r;
}