#include <sstream>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<int> Array;

int pickingNumbers(Array numbers)
{
  size_t pivot = 0;
  size_t iter;

  size_t sol = 0;
  size_t best_sol = 1;

  std::sort(numbers.begin(), numbers.end());

  iter = pivot;
  while (++iter < numbers.size()) {
    if (numbers[iter] - numbers[pivot] > 1) {
      pivot++;
      iter = pivot;
    }

    best_sol = max(best_sol, iter - pivot + 1);
  }

  cout << best_sol << endl;
  return best_sol;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(n_temp);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<int> myNumbers;
    int number;
    std::stringstream iss(a_temp_temp);
    while (iss >> number)
      myNumbers.push_back(number);

    int result = pickingNumbers(myNumbers);

    fout << result << "\n";
    fout.close();

    return 0;
}
