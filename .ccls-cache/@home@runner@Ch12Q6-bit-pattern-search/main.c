// Program to find a bit pattern within another unsigned int and to return the starting bit if it exists

#include <stdio.h>

// Declare Functions
int int_size (void);
int bitpat_search (unsigned int, unsigned int, int);

int main(void) {

  unsigned int pat = 13; // 4 bits // 1101
  unsigned int in = 13 << 4;
  int num = 5;

  printf ("       1111222222222233\n");
  printf ("       6789012345678901\n");
  printf ("in:  %#.16b\n", in);
  printf ("pat: %#.16b\n", pat);
  
  printf ("Patern starts at bit: %d\n", bitpat_search(in, pat, num));
  
  return 0;
}

// Define Functions
int int_size (void) {
  unsigned int test = ~0; // All ones

  int i = 0;
  while (test != 0) {
    test >>= 1;
    i++;
  }

  return i;
}

// Starting from the leftmost bits "0" -> "int_size - numBits"
int bitpat_search (unsigned int source, unsigned int pattern, int numBits) {
  pattern <<= int_size() - numBits;
  for (int i = 0; i < int_size() - numBits; i++, pattern >>= 1) {
    if ((source & pattern) == pattern)
      return i;
  }
  return -1;
}