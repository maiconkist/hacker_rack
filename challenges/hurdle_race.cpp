#include <bits/stdc++.h>

using namespace std;

int hurdleRace(int k, vector<int> &height) {
    int max_h = *max_element(height.begin(), height.end());
    return k > max_h? 0 : max_h - k;
}

int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    std::stringstream iss(nk_temp);

    int n, k;
    iss >> n;
    iss >> k;

    string K_temp;
    getline(cin, K_temp);

    vector<int> height(n);
    iss = std::stringstream(K_temp);
    int number;
    while (iss >> number)
      height.push_back(number);

    int result = hurdleRace(k, height);

    cout << result << endl;;
    return 0;
}
