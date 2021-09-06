// www.spoj.com/problems/AGGRCOW/
// Solution: www.youtube.com/watch?v=wSOfYesTBRk

#include <iostream>
#include <algorithm> //sort
#include<vector>
#define MAXn 100000
#define MAXx 1000000000
using namespace std;


int maxDistance(vector<int>, int, int);

int main()
{
    int n, cows;
    int t;
    vector<int> stalls;
    do {
        cin >> t;
    } while (t <= 0);

    while (t > 0) {
        do {
            cin >> n >> cows;
        } while (n < 2 || n>MAXn || cows > n || cows < 2);

        int x;
        for (int i = 0; i < n; i++) {
            do {
                cin >> x;
            } while (x < 0 || x>MAXx);
            stalls.push_back(x);
        }

        cout << maxDistance(stalls, n, cows) << endl;
        stalls.clear();
        t--;
    }
}

int maxDistance(vector<int> stalls, int n, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = stalls[1] - stalls[0];
    int hig = stalls[n - 1] - low;//distance max
    int mid;
    int maxD = -1;
    while (low <= hig) {
        mid = low + (hig - low) / 2;
        int count = 1; //current cow
        vector<int>::iterator it = stalls.begin(); //always at begin() element.
        while (count < cows) { //stopping condition
            it = lower_bound(it, stalls.end(), (*it) + mid); //index of first element not greater than *(it) + mid
            // *(it) + mid: next element with distance
            if (it == stalls.end()) //not find out...
                break;
            count++;
        }
        if (count == cows) {
            maxD = mid; //mid always increase
            low = mid + 1; //because low increase
        }
        else {
            hig = mid - 1;
        }
    }
    return maxD;
}

//
//int maxDistance(vector<int> stalls, int n, int cows) {
//    if (cows == n)
//        return 1; //số lượng cows = số lượng chuồng ==> khoảng cách max=1
//    int low = stalls[0];
//    int hig = stalls[n - 1] - stalls[0]; //khoảng cách lớn nhất
//    int maxD = -1; //để mọi giá trị tìm được đều > -1
//    while (low < hig) {
//        int mid = low + (hig - low) / 2;
//        int count = 1; //đánh dấu con bò hiện tại đang xét
//        while (count < cows) { //nhỏ hơn số lượng bò
//            vector<int>::iterator it = stalls.begin(); //vị trí bắt đầu
//            it = lower_bound(it, stalls.end(), (*it) + mid); //index đầu tiên có stalls[index] <= mid
//            if (it == stalls.end())
//                break;
//            count++;
//        }
//
//        if (count == cows) {
//            low = mid + 1;
//            maxD = mid;
//        }
//        else {
//            hig = mid - 1;
//        }
//    }
//    return maxD;
//}
//
