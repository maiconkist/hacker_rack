#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

size_t
doIt(const std::vector<int> r, int d, int m)
{
  if (r.size() < m) return 0;

  int answer{0};
  auto glambda = [r](int min, int max) -> int { return std::accumulate(r.begin() + min, r.begin() + max, 0); };

  int min{0}, max{m};

  do
  {
    if (glambda(min, max) == d)
      answer++;
    ++min; ++max;
  } while (max <= r.size());

  return answer;
}

int main()
{
  int n{0}, m{0}, d{0};

  cin >> n;
  std::vector<int> r(n);

  for (size_t i = 0; i < n; ++i)
    cin >> r[i];

  cin >> d >> m;

  auto resp = doIt(r, d, m);
  cout << resp << endl;

}
