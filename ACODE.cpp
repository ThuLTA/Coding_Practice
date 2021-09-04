//www.spoj.com/problems/ACODE/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#define MAX 5000
using namespace std;

int countWays(string, int);
int Ways(string, int, int, map<pair<int, int>, int>&);


int main()
{
    int length, res;
    vector<string> arr;
    string input;
    do {
        cin >> input;
        arr.push_back(input);
    } while (input[0] != '0' && input.length()<=5000);
    for (int i = 0; i < arr.size()-1; i++) {
        //length = (arr[i].length() < 5000) ? arr[i].length() : 5000;
        cout<<countWays(arr[i], arr[i].length()) << endl;
    }
    return 0;
}

int countWays(string str, int length) {
    int index = -1; //tránh trường hợp trả về khi index = 0
    map<pair<int, int>, int> check;
    int res = Ways(str, length, index, check);
    return res;
}

int Ways(string str, int length, int index, map<pair<int, int>, int>& check) {
    if (str[0] - '0' == 0) //mọi chuỗi bắt đầu = 0 thì loại (0x || 0-x)
        return 0;
    if (index == 0 || index > 26)
        return 0;
    if (length < 2)
        return 1;
    map<pair<int, int>, int>::const_iterator it_check = check.find(make_pair(length, index));
    if (it_check == check.end()) {
        check[{length, index}] = Ways(&str[1], length - 1, str[0] - '0', check) + Ways(&str[2], length - 2, (str[0] - '0') * 10 + (str[1] - '0'), check);
    }
    return check[{length, index}];
}