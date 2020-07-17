// Compiled with: gcc -std=c11 -Wall -pthread -lm

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

bool check_if_idx_is_unique(int idx)
{
    
}

struct counter {
    int value;
    int count;
};

struct counter_list {
    struct counter curr;
    struct counter* next;
}

int main(void)
{
    struct counter_list*;
    memset(sample_counts, 0, SAMPLE_SIZE * sizeof(struct counter));
    
    while ( GetNext() != -1 )
    {
        
    }
    
    
    for (int j = 0; j++; j < SAMPLE_SIZE)
    {
        int value = GetNext();

    }
    
    
    
        
 
    
    
    
    printf("Hello, world!\n");
    return 0;
}
