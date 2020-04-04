#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct input_d
{
    int s;
    int t;
    int a;
    int b;
    int m;
    int n;
    vector<int> apples;
    vector<int> oranges;
};

int solve(int tpos, int hl, int hr, vector<int> data)
{
    int count = 0;
    std::for_each( data.begin(), data.end(), [tpos](int & x) { x += tpos; });

    std::for_each( data.begin(), data.end(), [&count, hl, hr](int  x) { if (x >= hl & x <= hr) count++;});
    
    return count;
}

vector<int> solve_all(input_d &data)
{
    vector<int> res(2);
    
    res[0] = solve(data.a, data.s, data.t, data.apples);
    res[1] = solve(data.b, data.s, data.t, data.oranges);
    
    return res;
}

int main(){
    input_d data;
    cin >> data.s >> data.t;
    cin >> data.a >> data.b;
    cin >> data.m >> data.n;
    vector<int> apple(data.m);
    for(int apple_i = 0;apple_i < apple.size();apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(data.n);
    for(int orange_i = 0; orange_i < orange.size();orange_i++){
       cin >> orange[orange_i];
    }
    
    data.apples = apple;
    data.oranges = orange;
    
    
    vector<int> result = solve_all(data);
    
    cout << result[0] << endl;
    cout << result[1] << endl;
    
    
    return 0;
}
