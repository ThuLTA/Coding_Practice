// www.spoj.com/problems/NSTEPS/
//

#include <iostream>
using namespace std;

int coordinates(unsigned, unsigned);

int main()
{
    unsigned t, x, y;

    do {
        cin >> t;
    } while (t <= 0);

    for (unsigned i = 1; i <= t; i++) {
        cin >> x >> y;
        if (coordinates(x, y) == -1)
            cout << "No Number" << endl;
        else
            cout << coordinates(x, y) << endl;
    }
    return 0;
}

int coordinates(unsigned x, unsigned y) {
    if (x == 0 && y == 0)
        return 0;
    if (x == y || x == (y + 2))
        return (x + y - y % 2);
    return -1;
}