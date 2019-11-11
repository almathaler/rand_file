#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys.h>
#include <stat.h>
#include <unistd.h>

void print_array(int *a, size_t size);

int main(){

  return 0;
}

void print_array(int *a, size_t size){
  int i = size-1;
  printf("[%d", a[i]);
  i--;
  while (i >= 0){
    printf(", %d", a[i]);
    i--;
  }
  printf("]\n");
}
