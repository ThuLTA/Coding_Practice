#include <iostream>
#include <vector>
using namespace std;

int k, n;


void chinhhoplap(vector<int>&);
void xuat(vector<int>);

int main()
{
    cout << "Input n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;
    vector<int> arr(k, 1);
    int i = pow(n, k);
    while (i > 0) {
        xuat(arr);
        chinhhoplap(arr);
        i--;
    }
    return 0;
}

void chinhhoplap(vector<int>& arr) {
    arr[k-1]++;
    for (int i = k - 1; i > 0; --i) {
        if (arr[i] > n) {
            ++arr[i - 1];
            for (int j = i; j < k; j++)
                arr[j] = 1;
        }
    }
}
void xuat(vector<int> arr) {
    for (int i = 0; i < k; i++)
        cout << arr[i] << "\t";
    cout << endl;
}