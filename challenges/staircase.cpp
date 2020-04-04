#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_staircase(int n)
{
    for (int i = 0; i < n; ++i) {
        string line;
        for (int k = 0; k < (n - i - 1); ++k) line += ' ';
        for (int k = 0; k <= i; ++k) line += '#';
        cout << line << endl;
    }
    
}

int main(){
    int n;
    cin >> n;
    print_staircase(n);
    return 0;
}
