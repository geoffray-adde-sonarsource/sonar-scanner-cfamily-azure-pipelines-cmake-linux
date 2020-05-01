#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct {
  int a;
  int b;
  int c;
  char buf[64];
} ABC;

void init(ABC *abc);
void f_right(const ABC *abc);

void f_wrong(const ABC *abc) {
    const size_t size = sizeof(ABC);
    write(1, &abc, size);
}

int main() {
    ABC abc;
    init(&abc);
    const ABC *ptr = &abc;
    char secret[]="this is my secret";

    f_wrong(ptr);
    write(1, "\n", 1);
    f_right(ptr);

    return 0;
}

void f_right(const ABC *abc) {
    const size_t size = sizeof(ABC);
    write(1, abc, size);
}

void init(ABC *abc) {
    abc->a = 0;
    abc->b = 1;
    abc->c = 42;
    memset(abc->buf, '0', 64);
}
