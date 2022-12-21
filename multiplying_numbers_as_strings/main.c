#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *multiply(char *a, char *b) {
  int max_len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
  size_t res_len = strlen(a) + 1 + strlen(b) + 1;
  char* res = calloc(res_len + 1, sizeof(char));

  for (int i = 0; i < max_len || ; ++i) {
    char a_digit = strlen(a) - 1 - i < 0 ? 0 : a[strlen(a) - 1 - i];
    char b_digit = strlen(b) - 1 - i < 0 ? 0 : b[strlen(b) - 1 - i];
    char product = a_digit * b_digit;
    res[res_len ]
  }

  return "";
}

int main (int argc, char ** argv) {
  return 0;
}