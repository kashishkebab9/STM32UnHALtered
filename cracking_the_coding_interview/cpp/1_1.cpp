#include <iostream>
#include <map>
#include <string>

// Is Unique: Implement an algorithm to determine if a string has all unique
// characters. What if you cannot use additional data structures?

bool soln_fn(std::string problem){
  std::cout << "Input String: " << problem << std::endl; 

  for (int i = 0; i < problem.size() - 1; i++) {
    char test_case = problem[i];
    for (int j = i + 1; j < problem.size(); j++) {
      if (problem[j] == test_case) {
        std::cout << "Found repeated Char!" << std::endl; 
        return false;
      }
    }
  }
  std::cout << "All Unique Char!" << std::endl; 
  return true;
}

int main() {

  std::string problem_string_1 = "bedroom";
  std::string problem_string_2 = "algorithm";

  soln_fn(problem_string_1);
  soln_fn(problem_string_2);


  return 0;
}
