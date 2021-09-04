
#include <iostream>
#include <vector>

using namespace std;

void sinhnhiphan(vector<int>&);
void xuat(vector<int>);


int main()
{
    int n;
    cout << "Nhap do dai day nhi phan: ";
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < pow(2, n); i++)
    {
        xuat(arr);
        sinhnhiphan(arr);
    }
    return 0;
}

void sinhnhiphan(vector<int> &arr) { //chú ý (&) lưu lại giá trị vector sau khi thoát hàm
    ++arr[arr.size() - 1]; //tăng giá trị <1>
    for (int i = arr.size() - 1; i > 0; i--) { //duyệt từ giá trị <1> lên 
        if (arr[i] > 1) { //nếu > 1
            arr[i - 1]++; //thì lần lượt tăng giá trị đứng trước nó lên
            arr[i] = 0; //sau đó chuyển nó về 0 để đến hình dạng tiếp theo.
        }
    }
}

void xuat(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i];
    cout << endl;
}
