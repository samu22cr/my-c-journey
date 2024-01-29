

#include <stdio.h>
#include <threads.h>
#include <time.h>

mtx_t mutex;
cnd_t condition;

int run(void *arg) {

  mtx_lock(&mutex);

  struct timespec timeout;
  timespec_get(&timeout, TIME_UTC); // Get current time
  timeout.tv_sec += 1;              // Timeout 1 second after now

  int result = cnd_timedwait(&condition, &mutex, &timeout);
  //
  // waits for timeout and tries to lock again
  // mutex if not already locked by other thread
  //
  // Meaning that thread CAN lock again mutex without
  // a thrd_signal  !!!!!!!!!
  //


  if (result == thrd_timedout) {
    printf("Condition variable timed out!\n");
  };

  mtx_unlock(&mutex);

  return 0;
}

int main(void) {
  thrd_t child_thread;

  mtx_init(&mutex, mtx_plain);
  cnd_init(&condition);

  thrd_create(&child_thread, run, NULL);
  thrd_detach(child_thread);

  mtx_destroy(&mutex);
  cnd_destroy(&condition);
}
