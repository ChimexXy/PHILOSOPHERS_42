#include <sys/time.h>
#include <stdio.h>

// struct    timeval  {
//   time_t        tv_sec ;   //used for seconds
//   suseconds_t       tv_usec ;   //used for microseconds
// } timeval;

int main() {
  struct timeval current_time;
  gettimeofday(&current_time, NULL);

  printf("time : %ld\n", current_time.tv_usec * 1000 + current_time.tv_sec / 1000 - current_time.tv_usec * 1000 + current_time.tv_sec / 1000);

  return 0;
}