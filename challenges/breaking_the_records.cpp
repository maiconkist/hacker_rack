#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

std::tuple<int, int> doIt(const vector<int> a)
{
    int max = a[0];
    int min = a[0];
    
    
    size_t best = 0;
    size_t worst= 0;
    
    for (auto i: a)
    {
        if (i > max){
            max = i;
            best++;
        }
        
        if (i < min){
            min = i;
            worst++;
        }
    }
    
    return {best, worst};
}

int main() {
    int n;
    
    cin >> n;
    std::vector<int> r(n);
    
    for (auto i = 0; i  < n; ++i)
        cin >> r[i];

    size_t best, worst;
    tie(best, worst) = doIt(r);

    std::cout << best << " " << worst << std::endl;
    return 0;
}
