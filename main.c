// Compiled with: gcc -std=c11 -Wall -pthread -lm

/* xXxXxxXxXxX Don't touch from here. xXxXxXxXxXxXxx */

#include <stdio.h>

#define SAMPLE_SIZE 11

int
GetNext() {
  static int i = 0;
  static int sample_input[SAMPLE_SIZE] =
    { 0xf12, 0xea2, 0x684, 0x217, 0xfff, 0x1f5, 0xf12, 0xea2, 0x684, 0xfff, 0x1f5 };
 
  if (i < SAMPLE_SIZE)
      return sample_input[i++];
  else
      return -1;
}

/* xXxXxxXxXxX Don't touch up til' here. xXxXxXxXxXxXxx */

/** Solution proudly stolen from
 * https://www.geeksforgeeks.org/find-unique-element-element-occurs-k-times-except-one/
 * Adapted for the task at hand by opiechow \m/
 */

/* Bit count array size optimization -
    I can see that the oldest bit set in the input is 0x800;
    So I only need count 12 bits = 3 nibbles */
#define BITS_NUM 12
/* Static vars are 0-ed at init, h00ray */
static int count[BITS_NUM];
/* Let's add some readabilty */
#define STREAM_END_MARKER -1

/**
 *  Function setting the bit count array appropriately for each sample.
 *  @val: input from the mocked stream
 */
void feed_the_bit_counter(int val) {
  // AND(bitwise) each element of the array
  // with each set digit (one at a time)
  // to get the count of set bits at each
  // position
  for (int i = 0; i < BITS_NUM; i++) {
    if ((val & (1 << i)) != 0) {
      count[i] += 1;
    }
  }
}

/** Now consider all bits whose count is
 * not multiple of k to form the required
 * number.
 * @return: the long awaited result.
 */
int get_teh_result() {
  /* I can see the k from the input */
  int k = 2;

  unsigned result = 0;
  for (int i = 0; i < BITS_NUM; i++)
    result += (count[i] % k) * (1 << i);
  return result;
}

int main(void) {
/* Now I won't mix the condition and increment ;) */
  for (;;)
  {
      int sample = GetNext();
      if (sample == STREAM_END_MARKER) {
          break;
      }
      feed_the_bit_counter(sample);
  }

  printf("Unique val: 0x%x\n", get_teh_result());
  return 0;
}
