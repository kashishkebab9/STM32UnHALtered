#include <iostream>
#include <memory>

// This file is so that we can play around with smart pointers, beginning with Shared and Unique Ptrs, specifically
//
// A std::shared_ptr is a pointer that allows multiple pointers to have ownership over a resource, once all of the 
// pointers have been deleted, the object itself will be deleted
//
// A std::unique_ptr is a pointer that allows one AND ONLY one pointer to have ownership over a resource. This 
// resource can be moved using std::move. Once the single owner has been deleted, that's when the object dies

// The idea of ownership is "who is responsible for destroying the object at the end of its use/lifetime"
// Unique pointers 
int main() {


  return 0;
}
