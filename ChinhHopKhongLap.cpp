#include <iostream>
#include <vector>
using namespace std;

int k, n;

int giaithua(int);
void chinhhopkhonglap(vector<int>&);
void xuat(vector<int>);

int main()
{
    cout << "Input n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;
    vector<int> arr;
    for (int i = 0; i < k; i++)
        arr.push_back(i + 1);
    int i = (giaithua(n) / giaithua(n - k));
    while (i > 0) {
        xuat(arr);
        chinhhopkhonglap(arr);
        i--;
    }
    return 0;
}

void chinhhopkhonglap(vector<int>& arr) {
    arr[k - 1]++;
    for (int i = k - 1; i > 0; --i) {
        if (arr[i] > n) {
            ++arr[i - 1];
            for (int j = 0; j < k; j++)
                if (arr[j] == arr[i - 1])
                    arr[j-1]++;
        }
    }
}

void xuat(vector<int> arr) {
    for (int i = 0; i < k; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

int giaithua(int x) {
    int s = 1;
    if (x == 1)
        return 1;
    for (int i = 2; i <= x; i++)
        s *= i;
    return s;
}