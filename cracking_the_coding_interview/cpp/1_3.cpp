#include <iostream>
#include <string>

// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please use a character array so that you can perform this operation in place.) 


std::string soln_fn(std::string input, int true_length){
  // BRUTE FORCE
  std::string output = "";

  for (int i = 0; i < true_length; i++) {
    if (input[i] != ' ') {
      output.push_back(input[i]);
    } else {
      output.push_back('%');
      output.push_back('2');
      output.push_back('0');
    }
  }

  std::cout << "output: " << output << std::endl;
  return output;
}

int main() {
  
  std::string test = "Mr John Smith      ";
  soln_fn(test, 13);


  return 0;
}
