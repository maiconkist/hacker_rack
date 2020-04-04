#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef std::multimap<int, int> mmii;

auto
doIt(const std::vector<int> &a, size_t dsum)
{
    size_t resp{0};

    mmii aux;
    
    for (size_t i = 0; i < a.size()-1;  ++i)
        for (size_t j = i+1; j < a.size(); ++j)
            if ( (a[i] + a[j]) % dsum == 0) resp++;
    return resp;
}

int main() {
    int n, k;
    
    cin >> n >> k;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; ++i)
        cin >> a[i];
    
    int resp = doIt(a, k);
    
    std::cout <<  resp << std::endl;
    
    return 0;
}

