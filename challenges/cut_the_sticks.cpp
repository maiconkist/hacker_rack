/*
 * Link: https://www.hackerrank.com/challenges/cut-the-sticks/problem
 *
 */
/*
 *  Author: MK
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> cut_the_sticks(vector<int> &&sticks)
{
  vector<int> result;

  std::sort(sticks.begin(), sticks.end());

  int cur_sticks;
  do {
    /*  count number of sticks greater than 0 */
    cur_sticks = std::count_if(sticks.begin(), sticks.end(), [](int i) {return i > 0;});

    if (cur_sticks == 0)
      break;

    result.push_back(cur_sticks);

    /*  Cut the sticks by the smallest one.
     *  Because the vectoris sorted, it is the first element;
     *  */
    int smallest = sticks[0];
    std::for_each(sticks.begin(), sticks.end(), [smallest](int &elem) { elem -= smallest; });

    /*  remove  */
    sticks.erase(std::remove(sticks.begin(), sticks.end(), 0), sticks.end());

  } while (cur_sticks > 0);

  return result;
}

int main()
{
  string n_sticks;
  vector<int> sticks;

  /*  read number of sticks */
  getline(cin, n_sticks);

  /*  read sticks len and add to vector */
  {
    string sticks_tmp;

    getline(cin, sticks_tmp);

    stringstream iss(sticks_tmp);
    int num;
    while (iss >> num)
      sticks.push_back(num);
  }

  auto result = cut_the_sticks(std::move(sticks));

  for (auto &i : result)
    cout << i << endl;


  exit(EXIT_SUCCESS);
}
