#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
//#include <sys.h>
//#include <stat.h>
#include <unistd.h>

void print_array(int *a, size_t size);
int rand_num();
int main(){
  int array[10];
  int i;
  for (i = 0; i<10; i++){
    array[i] = rand_num();
  }
  print_array(array, 10);
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

int rand_num(){
  int num;
  int error_catch;
  int fd = open("/dev/random", O_RDONLY);
  error_catch = read(fd, &num, sizeof(int));
  if (error_catch < 0 || error_catch != sizeof(int)){
    printf("error in rand_num! error_catch: %d\n", error_catch);
  }
  error_catch = close(fd);
  if (error_catch == -1){
    printf("error in rand_num! error in closing /dev/random\n");
  }
  return num;
}
