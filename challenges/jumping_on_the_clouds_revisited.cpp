#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <iostream>  /* cin */
#include <algorithm>
#include <fstream>   /* ofstream */
#include <climits>

using namespace std;

const int INITIAL_ENERGY = 100;

typedef vector<int> Clouds;

int jumpingOnCloudsRevisited(const Clouds &c, int k, int e)
{
  int i = 0;

  do {
    i = (i + k) % c.size();

    e -= 1;                  /* jump */
    if (c[i] == 1) e -= 2;   /* land on thundercloud */

  } while (i != 0 && e > 0);

  return e;
}

int main()
{
  int n, k;
  Clouds clouds;

  std:string tmp;
  getline(cin, tmp);

  std::stringstream iss(tmp);
  iss >> n;
  iss >> k;

  getline(cin, tmp);
  iss = std::stringstream(tmp);

  int number;
  while (iss >> number)
    clouds.push_back(number);

  int result = jumpingOnCloudsRevisited(clouds, k, INITIAL_ENERGY);
  std::cout << result << std::endl;

  return EXIT_SUCCESS;
}
