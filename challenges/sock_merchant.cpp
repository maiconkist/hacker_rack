#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t
doIt(std::vector<int> &c)
{
    size_t answer{0};
    std::sort(std::begin(c), std::end(c), [](int i1, int i2){ return i1 < i2;});
    
    size_t it = 0;
    while (it < c.size() - 1)
    {
        if (c[it] == c[it+1]){
            answer +=1;
            it += 2;
        } else
            it++;
    }
    
    return answer;
}

int main() {
    size_t n;
    cin >> n;
    
    std::vector<int> c(n);
    
    for (size_t i = 0; i < n; i++)
        cin >> c[i];
    
    size_t answer = doIt(c);
    std::cout << answer << std::endl;
    
    return 0;
}
