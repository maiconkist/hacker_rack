#include <bits/stdc++.h>

using namespace std;

string angryProfessor(int k, vector<int> &times)
{

  auto x = [](int a){ return a <= 0; };

  int on_time = count_if(times.begin(), times.end(), x);

  return on_time >= k? "NO": "YES";
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        std::stringstream iss(nk_temp);
        int n, k;
        iss >> n; iss >> k;

        string a_temp;
        getline(cin, a_temp);

        vector<int> times;
        int number;
        iss = std::stringstream(a_temp);
        while (iss >> number)
          times.push_back(number);

        string result = angryProfessor(k, times);
        cout << result << "\n";
    }

    return 0;
}
