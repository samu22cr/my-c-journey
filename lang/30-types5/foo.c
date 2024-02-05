#include <stdio.h>

#define TYPESTR(x)                                                             \
  _Generic((x),                                                                \
      int: "int",                                                              \
      long: "long",                                                            \
      float: "float",                                                          \
      double: "double",                                                        \
      default: "something else")

struct coord {
  int x, y;
};

// void print_coord(struct coord c) { printf("%d, %d\n", c.x, c.y); }
void print_coord(struct coord *c) { printf("%d, %d\n", c->x, c->y); }

int sum(int p[], int count) {
  int total = 0;
  for (int i = 0; i < count; i++) {
    total += p[i];
  }
  return total;
}

void foo(int *address) {}

int main(void) {
  printf("...\n");

  // without unnamed objects
  // int a[] = {1, 2, 3, 4};
  // int s = sum(a, 4);

  // with unnamed objects
  // int s = sum((int []){1,2,3,4}, 4);

  // without unnamed structs
  //  struct coord c = { .x=10, .y=20 };
  //  print_coord(c);

  // with unnamed structs
  // print_coord((struct coord){.x = 10, .y = 20});

  // pointers to unnamed objects
  // print_coord(&(struct coord){.x = 11, .y = 20}); // prints "10, 20"
  //
  // Additionally, this can be a nice way to pass even pointers to simple
  // objects: Pass a pointer to an int with value 3490
  // foo(&(int){3490});

  // Generic Selections
  //
  //
  // int i;
  // float f;
  // char c;
  //
  // char *s = _Generic(c,
  //     int: "that variable is an int",
  //     float: "that variable is a float",
  //     default: "that variable is some type");

  // printf("%s\n", s);
  //
  //

  int i;
  long l;
  float f;
  double d;
  char c;

  printf("i is type %s\n", TYPESTR(i));
  printf("l is type %s\n", TYPESTR(l));
  printf("f is type %s\n", TYPESTR(f));
  printf("d is type %s\n", TYPESTR(d));
  printf("c is type %s\n", TYPESTR(c));
}
