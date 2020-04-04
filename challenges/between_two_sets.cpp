#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

auto
getTotalX(const vector <int> &a, const vector <int> &b)
{

  // min value is highest value in A,
  // max value is lowest value in B
  auto min_val =  * std::max_element(a.begin(), a.end());
  auto max_val =  * std::min_element(b.begin(), b.end());
  std::vector<int> values_found;

  // iterate over all values in between.
  for (auto i = min_val; i <= max_val; ++i)
    {
      // loop across A values
      std::vector<int>::const_iterator ita = a.begin();
      for (; ita != a.end(); ++ita)
        {
          if (i % *ita != 0)
            break;
        }

      // all A is a factor of value i
      if (ita == a.end())
        {
          // Check if value i is a factor of all B
          std::vector<int>::const_iterator itb = b.begin();
          for (; itb != b.end(); ++itb)
            {
              if (*itb % i != 0)
                break;
            }

          // Yes, it is a valid valued
          if (itb == b.end())
            values_found.push_back(i);
        }
    }

  return values_found.size();
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
