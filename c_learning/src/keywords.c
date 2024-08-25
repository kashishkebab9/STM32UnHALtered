/*
 * The purpose of this script is to have some concrete C examples to understand keywords I've never used before
*/
#include <stdio.h>

/*
 * The static keyword is used to instantiate a variable that you don't want exposed
 * to the rest of the code but maintains its values between runs of the function.
 * Counter is not touched anywhere else but, with two runs in main, we increment counter
 * from 0 to 1 to 2.
*/
void static_example(int a) {
  static int counter = 0;
  counter += a;
  printf("Static Counter: %d\n", counter);
}

/*
 * For functions, a static function is a function that is limited to the scope of its
 * translation unit (file scope). Adding an include essentiall pastes that file to the top
 * so that should be able to work still.
*/
void static_fn_example();
void global_fn_example();

/*
 * The extern keyword allows you to use variables/functions from external translation units
 * in extern_example.c, I have a variable extern_example and print_extern_example function
 * that I didn't want to redefine here, so I brought that functionality over with extern.
 * Note they do have to linked together during compilation
*/
extern int extern_example;
extern void print_extern_example();


int main() {
  // Static Variable Example
  int a = 1;
  static_example(a);
  static_example(a);

  // Static Function Example
  // static_fn_example(); --> Compiler Error: function is static and therefore file scoped only
  global_fn_example();

  // Extern function and variable example
  print_extern_example(a);

  return 1;
}
