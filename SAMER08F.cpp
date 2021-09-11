// www.spoj.com/problems/SAMER08F/

#include <iostream>
using namespace std;

unsigned countSquare(unsigned);

int main()
{
    unsigned n;
    do {
        do {
            cin >> n;
        } while (n>100);
        if (n != 0)
            cout << countSquare(n) << endl;
    } while (n != 0);
    return 0;
}


unsigned countSquare(unsigned n) {
    unsigned count = 0;
    while (n > 0) {
        count += n * n;
        n--;
    }
    return count;
}
