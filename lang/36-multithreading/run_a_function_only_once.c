

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#define THREAD_COUNT 5

once_flag of = ONCE_FLAG_INIT;

void run_once_func(void) {
  printf("Only one thread can run me >:v\n");
}

int run(void* arg) {
  int id = *(int*) arg;
  free(arg);
  call_once(&of, run_once_func);
  return id;
}

int main(void) {
  thrd_t t[THREAD_COUNT];

  for (int i = 0; i < THREAD_COUNT; i++) {
    int *thrd_human_identifier = malloc(sizeof* thrd_human_identifier);
    *thrd_human_identifier =  i;
    thrd_create(t + i, run, thrd_human_identifier);
  }

  for (int i = 0; i < THREAD_COUNT; i++) {
    thrd_join(t[i], NULL);
  }

}
