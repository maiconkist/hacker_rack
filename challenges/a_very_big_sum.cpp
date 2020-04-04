#include <vector>
#include <iostream>

using namespace std;

long aVeryBigSum(int n, vector <long> ar) {
    // Complete this function
    long res = 0;
    for (vector<long>::iterator it = ar.begin(); it != ar.end(); ++it){
        res += *it;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<long> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    long result = aVeryBigSum(n, ar);
    cout << result << endl;
    return 0;
}
