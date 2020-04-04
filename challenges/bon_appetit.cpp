#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

std::string
doIt(const vector<int> c, size_t k, size_t b)
{
    
    size_t sum = std::accumulate(c.begin(), c.end(), 0);

    if ( (sum - c[k])/2 == b)
        return "Bon Appetit";
    else
        return std::to_string(b - (sum-c[k])/2);
}

int main() {
    
    size_t n, k, b;
    
    cin >> n >> k;
    std::vector<int> c(n);
    
    for (size_t i = 0; i < n; ++i)
        cin >> c[i];
    
    cin >> b;
    
    std::string resp = doIt(c, k, b);

    std::cout << resp << std::endl;
    
    return 0;
}
