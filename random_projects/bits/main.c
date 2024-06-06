#include <stdint.h>
#include <stdio.h>
// 32 bit
void show_bits(int8_t number) {
  uint8_t mask = 1 << 7;
  while (mask) {
    printf("%d", (number & mask) != 0);
    mask >>= 1;
  }
  printf("\n");
}

int main(void) {
  show_bits(3);
  show_bits(-3);
  return 0;
}
