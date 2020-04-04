#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t n, p;
    
    cin >> n >> p;
    if (p % 2 == 1)p--;
    
    size_t from_start = (p/2);
    size_t from_end   = (n-p)/2;
        
    std::cout << std::min(from_start, from_end) << std::endl;
    
    return 0;
}
