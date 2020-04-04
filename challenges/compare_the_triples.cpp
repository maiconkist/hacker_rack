#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

vector < int > solve(int a0, int a1, int a2, int b0, int b1, int b2){
    // Complete this function
    vector<int> score(2);
    vector < tuple<int, int> > tups;
    
    tups.push_back( make_tuple(a0, b0)); 
    tups.push_back( make_tuple(a1, b1));
    tups.push_back( make_tuple(a2, b2));
    
    for (vector<tuple<int, int> >::iterator it = tups.begin(); it != tups.end(); ++it )
    {
        if (get<0>(*it) > get<1>(*it))
            score[0]++;
        else if (get<0>(*it) < get<1>(*it))
            score[1]++;
    }
    return score;
}

int main() {
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    vector < int > result = solve(a0, a1, a2, b0, b1, b2);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;
    

    return 0;
}
