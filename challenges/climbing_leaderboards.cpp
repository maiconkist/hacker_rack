#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

#include <chrono>
#include <deque>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> Array;
typedef vector<string> ArrayStr;
typedef deque<int> Deque;

/* Set custom comparator: decreasing ordering */
typedef std::set<int, std::greater<int>> Set;

inline size_t find_rank(Set &scores, Set::iterator &it)
{
  size_t pos = std::distance(scores.begin(), it);
  return pos + 1;
}

Array climbingLeaderboard(Set &scores, const Array &alice)
{
  Array solution;

  for (auto it = alice.cbegin(); it != alice.cend(); ++it) {
    auto pos = scores.insert(*it);
    size_t rank = std::distance(scores.begin(), pos.first) + 1;
    solution.push_back(rank);
  }

  return std::move(solution);
}

int main() {
  int number;

  string n_temp;
  getline(cin, n_temp);

  string N_temp;
  getline(cin, N_temp);

  string m_temp;
  getline(cin, m_temp);

  string M_temp;
  getline(cin, M_temp);

  Set leaderboard;
  std::stringstream iss(N_temp);
  while (iss >> number)
    leaderboard.insert(number);

  Array alice_scores;
  iss = std::stringstream(M_temp);
  while (iss >> number)
    alice_scores.push_back(number);

  auto &&result = climbingLeaderboard(leaderboard, alice_scores);

  for (auto &&i : result)
      cout << to_string(i) << "\n";
  return 0;
}
