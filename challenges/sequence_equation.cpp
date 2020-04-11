#include <bits/stdc++.h>
#include <sstream>

int index_of(const std::vector<int> &seq, int val)
{
  auto it = std::find(seq.begin(), seq.end(), val);
  if (it != seq.end()) {
    int i =  std::distance(seq.begin(), it);
    return i;
  }

  return -1;
}

std::vector<int> permutationEquation(std::vector<int> &seq)
{
  std::vector<int> result;

  for (size_t i = 0; i < seq.size(); ++i) {
    int ix  = index_of(seq, i);
    int iix = index_of(seq, ix);
    result.push_back(iix+1);
  }
  return std::move(result);
}

int main()
{
  std::string tmp;
  int number;
  getline(std::cin, tmp);

  int n_length = stoi(tmp);

  getline(std::cin, tmp);
  std::stringstream iss(tmp);
  std::vector<int> seq;
  while (iss >> number)
    seq.push_back(number - 1);

  std::vector<int> result = permutationEquation(seq);

  for (const auto &r: result)
    std::cout << r << std::endl;


  return EXIT_SUCCESS;
}
