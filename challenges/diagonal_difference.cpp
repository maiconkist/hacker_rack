#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int diagonal_difference(int n, vector< vector<int> > matrix)
{
	int d1(0), d2(0);

	for (int i = 0; i < n; ++i){
		d1 += matrix[i][i];	
		d2 += matrix[i][n-1-i];
	}
	return abs(d1 - d2);
}


int main(){
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }

    int res = diagonal_difference(n, a);
    cout << res << endl;

    return 0;
}
