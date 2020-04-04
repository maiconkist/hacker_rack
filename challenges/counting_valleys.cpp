#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>  /* cin */
#include <algorithm>
#include <fstream>   /* ofstream */

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
  int altitude = 0;
  int valleys  = 0;

  for (int i = 0; i < n; ++i){
    switch (s[i]) {
      case 'D': altitude--; break;
      case 'U': altitude++; break;
    }

    if (altitude == 0 && s[i-0] == 'U') valleys++;
  }

  return valleys; 

}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string s;
  getline(cin, s);

  int result = countingValleys(n, s);

  fout << result << "\n";

  fout.close();

  return 0;
}

