#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

typedef unsigned long long mtype;

void calculate_min_max(mtype &min,  mtype &max, const vector<mtype> arr)
{
    mtype sum(0);

    sum = accumulate(arr.begin(), arr.end(), 0);
    max = sum - *min_element(arr.begin(), arr.end());
    min = sum - *max_element(arr.begin(), arr.end());
}

int main() {
    vector<mtype> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }
 
    mtype min(0), max(0);
    calculate_min_max(min, max, arr);
    cout << min << " " << max << endl;
    return 0;
}
