#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
//#include <sys.h>
//#include <stat.h>
#include <unistd.h>
//headers
void print_array(int *a, size_t size);
int rand_num();
//funcs
int main(){
  //populating array
  int array[10];
  int i;
  for (i = 0; i<10; i++){
    array[i] = rand_num();
  }
  //what array looks like:
  printf("\ninitial values in array: \n");
  print_array(array, 10);
  //write array to file
  printf("\nwriting numbers to file rand_file.txt\n");
  int my_file = open("rand_file.txt", O_CREAT | O_WRONLY, 0644);
  int error_catch;
  error_catch = write(my_file, array, 10 * sizeof(int));
  if (error_catch != 10 * sizeof(int)){
    printf("error! write only wrote %d bytes instead of %lu!\n", error_catch, 10 * sizeof(int));
  }
  close(my_file);
  //read file contents to a new array
  printf("\nreading numbers from rand_file.txt\n");
  int second_array[10];
  my_file = open("rand_file.txt", O_RDONLY);
  //just for ease of debugging
  for (i = 0; i<10; i++){
    second_array[i] = 0;
  }
  error_catch = read(my_file, second_array, 10 * sizeof(int));
  if (error_catch != 10 * sizeof(int)){
    printf("error! read only read %d bytes instead of %lu!\n", error_catch, 10 * sizeof(int));
  }
  close(my_file);
  //printing out contents of the 2nd array
  printf("\nwritten then read values in 2nd array: \n");
  print_array(second_array, 10);
  return 0;
}
//
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
//
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
