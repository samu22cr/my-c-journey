#include <stdio.h>
#include <stdlib.h>
#include <threads.h>


mtx_t mutexFuel;
cnd_t condFuel;
int fuel = 0;

void *fuel_filling(void *arg) {
  for (int i = 0; i < 5; i++) {
    mtx_lock(&mutexFuel);
    fuel += 30;
    printf("Filled fuel... %d\n", fuel);
    mtx_unlock(&mutexFuel);
    cnd_broadcast(&condFuel);
  }
  return 0;
}

void *car(void *arg) {
  mtx_lock(&mutexFuel);
  while (fuel < 40) {
    printf("No fuel. Waiting...\n");
    cnd_wait(&condFuel, &mutexFuel);
  }
  fuel -= 40;
  printf("Got fuel. Now left: %d\n", fuel);
  mtx_unlock(&mutexFuel);
  return 0;
}

int main(int argc, char *argv[]) {
  pthread_t th[6];
  mtx_init(&mutexFuel, NULL);
  cnd_init(&condFuel);
  for (int i = 0; i < 6; i++) {
    if (i == 4 || i == 5) {
      if (thrd_create(&th[i], NULL, &fuel_filling) != 0) {
        perror("Failed to create thread");
      }
    } else {
      if (thrd_create(&th[i], NULL, &car) != 0) {
        perror("Failed to create thread");
      }
    }
  }

  for (int i = 0; i < 6; i++) {
    if (thrd_join(th[i], NULL) != 0) {
      perror("Failed to join thread");
    }
  }
  mtx_destroy(&mutexFuel);
  cnd_destroy(&condFuel);
  return 0;
}
