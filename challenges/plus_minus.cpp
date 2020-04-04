#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void calculate_per(float &pos, float &neg, float &zero, vector<int> arr)
{

    pos  = std::count_if(arr.begin(), arr.end(), std::bind2nd(std::greater<int>(), 0));
    neg  = std::count_if(arr.begin(), arr.end(), std::bind2nd(std::less<int>(), 0));
    zero = std::count_if(arr.begin(), arr.end(), [](int c){return c == 0;});

    pos /= arr.size();
    neg /= arr.size();
    zero /= arr.size();
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    
    
    float pos(0), neg(0), zero(0);
    
    calculate_per(pos, neg, zero, arr);
    
    cout << pos << endl;
    cout << neg << endl;
    cout << zero << endl;
    
    return 0;
}

