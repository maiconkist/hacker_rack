#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int migratoryBirds(const vector <int> &ar)
{
    std::map<int, int> count = { {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} };
    
    for (auto a : ar)
        count[a]++;  


    auto pr = std::max_element(std::begin(count), std::end(count),
        [] (const auto & p1, const auto & p2) { return p1.second < p2.second;});

    return pr->first;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(ar);
    cout << result << endl;
    return 0;
}

