#include <stdint.h>
#include <stdio.h>

enum myEnum : uint64_t;

enum myEnum : uint64_t {
    A,
    B,
    C = 3 << 63
};

int main() {
    printf("%d\n", sizeof(enum myEnum));
    return 0;
}