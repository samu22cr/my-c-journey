#include <stdio.h>
#include <threads.h>

#ifdef __STDC_NO_THREADS__
#define THREADS_AVAILABLE 0
#error I need threads to build this program!
#else
#define THREADS_AVAILABLE 1
#endif

int run(void *arg) {
  int *a = arg;
  printf("CHILD THREAD: Running thread with arg %d\n", *a);
  return 12; // this value gets assigned to 2nd arg of thrd_join(thrd_t, *int)
}

int main() {

  thrd_t thread_id; // thrd_t is an opaque object type
  int arg = 3490;
  printf("Launching thread....\n");

  // stores thread id in thrt_t variable managed by the programmer
  thrd_create(&thread_id, run, &arg);
  printf("Doing other things while the thread runs\n");
  printf("Waiting for thread to complete...\n");


  int thread_exit_return_value;
  // wait here for the specified thread to return and assign the
  // returned valiue to the variable above
  thrd_join(thread_id, &thread_exit_return_value);
  printf("Thread exited with return value %d\n", thread_exit_return_value);

}
