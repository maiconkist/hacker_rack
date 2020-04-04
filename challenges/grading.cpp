#include <bits/stdc++.h>

using namespace std;

vector <int> solve(vector < int > grades){    
    for (vector<int>::iterator it = grades.begin(); it != grades.end(); ++it){
        if (*it >= 38 ) {
            int next_m = (*it) + 5 - ((*it + 5) % 5);
            if (next_m - *it < 3)
                *it = next_m;
        }
    }
    
    return grades;
    
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       cin >> grades[grades_i];
    }
    vector < int > result = solve(grades);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    

    return 0;
}
