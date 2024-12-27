// Check Permutation: Given two strings, write a method to decide if one is a permutation ofthe other.

#include <iostream>
#include <string>
#include <map>

bool soln_fn(std::string string_1, std::string string_2) {

  std::map<char, int> char_counter_map;
  // first iterate through string_1 and populate the map
  for (char character: string_1) {
    if (char_counter_map.find(character) != char_counter_map.end()) {
      // it exists
      char_counter_map[character]++;
    } else {
      // it doesn't exist
      char_counter_map[character] = 1;
    }
  }
  std::map<char, int> char_checker_map;
  for (char character: string_2) {
    if (char_checker_map.find(character) != char_checker_map.end()) {
      // it exists
      char_checker_map[character]++;
    } else {
      // it doesn't exist
      char_checker_map[character] = 1;
    }
  }

  for (const auto& [key, value]: char_counter_map) {
    std::cout << "Key to check: " << key << std::endl;
    std::cout << "Value to check: " << value << std::endl;
    if (char_checker_map[key] != value) {
      std::cout << "Key in verifier: " << char_checker_map[key] << std::endl;
      std::cout << "Value in verifier: " << char_checker_map[value] << std::endl;
      std::cout << "false" << std::endl;
      return false;
    }
  }
  std::cout << "true" << std::endl;
  return true;
}

int main() {
  std::string string_1 = "wop";
  std::string string_2 = "water";
  soln_fn(string_1, string_2);


  return 0;
}
