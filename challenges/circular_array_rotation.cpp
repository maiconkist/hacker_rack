#include <bits/stdc++.h>
#include <cstdlib>
#include <shared_mutex>
using namespace std;

typedef vector<int> Vector;

vector<int> circularArrayRotation(Vector &arrN, int k,
                                  Vector &arrQ)
{
#ifndef USE_ALGORITHM
  Vector tmp(arrN.size());

  for (int i = 0; i < arrN.size(); i++)
    tmp[(i+k) % arrN.size()] = arrN[i];

  Vector result;
  for (auto &q: arrQ)
    result.push_back(tmp[q]);
#endif

#if USE_ALGORITHM
  k = k % arrN.size();
  std::rotate(arrN.begin(), arrN.end() - k, arrN.end());

  Vector result;
  for (auto &q: arrQ)
    result.push_back(arrN[q]);
#endif

  return std::move(result);
}


int main()
{
  string stmp;
  int n, k, query;
  int tmp;

  /*  read n, k, q */
  getline(cin, stmp);
  std::stringstream iss(stmp);
  iss >> n;
  iss >> k;
  iss >> query;

  /*  read N */
  getline(cin, stmp);
  iss = std::stringstream(stmp);
  Vector arrN;
  while (iss >> tmp)
    arrN.push_back(tmp);

  /*  read Q */
  Vector arrQ;
  for (size_t it = 0; it < query; ++it)
    while (cin >> tmp)
      arrQ.push_back(tmp);

  Vector result = circularArrayRotation(arrN, k, arrQ);

  for (auto &r: result)
    std::cout << r << endl;

  return EXIT_SUCCESS;
}
