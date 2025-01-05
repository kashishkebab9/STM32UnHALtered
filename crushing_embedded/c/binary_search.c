#include <stdio.h>

struct binaryNode {
  struct binaryNode* right_node;
  struct binaryNode* left_node;
};


struct binaryTree {
  //we need this struct to hold a pointer to a node, a node will hold two pointers
  //either to children nodes or, null if they themselves are leaves
  struct binaryNode* rootNode;
  
};


int main() {

  int arr[] = {
    84735, 592834, 28476, 391736, 145623, 972485, 238745, 67289, 384927, 918374,
    745827, 302849, 584920, 173849, 290384, 948203, 284730, 561839, 723890, 184927,
    284637, 902384, 467281, 104738, 283745, 876924, 129083, 294827, 764930, 847392,
    918374, 203948, 582746, 387210, 485927, 693028, 104827, 920384, 485927, 163829,
    572038, 294018, 389205, 194827, 384920, 590184, 204917, 492817, 173849, 290384,
    489201, 590184, 174892, 490183, 287301, 482917, 501938, 384920, 194827, 920384,
    582746, 847920, 293840, 918274, 283940, 675829, 382917, 590182, 203948, 927482,
    102948, 582746, 593821, 482719, 574920, 394827, 590182, 192847, 384920, 485927,
    910482, 294018, 483920, 182947, 294827, 374829, 581092, 284920, 920183, 590284,
    104827, 384920, 102938, 578201, 485927, 394827, 495817, 104827, 592810, 384920
  };

  // This is my implementation without any studying
  // My understanding of binary search is that we must first sort the array 
  // from smallest to largest val 
  // Then start dividing the array into a binary tree


  return 0;
}
