#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long int overflow_check(unsigned long long int current,
                                      unsigned long long int next) {
    return (current > ULLONG_MAX - next);
}

unsigned long long int fib_iterative(int fib_index) {
    if (fib_index == 1)
        return 0;
    else if (fib_index == 2)
        return 1;

    unsigned long long int first  = 0;
    unsigned long long int second = 1;
    unsigned long long int next_value;

    for (int ix = 3; ix <= fib_index; ix++) {
        if (overflow_check(first, second)) {
            printf("overflow_check at %d\n", ix);
            return 0;
        }
        next_value = first + second;
        first      = second;
        second     = next_value;
    }

    return second;
}

unsigned long long int fib_recursive(int recursive_index) {
    if (recursive_index == 1)
        return 0;
    else if (recursive_index == 2)
        return 1;

    unsigned long long int current = fib_recursive(recursive_index - 1);
    unsigned long long int next    = fib_recursive(recursive_index - 2);

    if (overflow_check(current, next)) {
        printf("Overflow occured at index %d\n", recursive_index);
        return 0;
    }

    return current + next;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./fib <number> <i/r>\n");
        return 1;
    }

    int user_input = atoi(argv[1]);

    if (argv[2][0] == 'i') {
        unsigned long long int result = fib_iterative(user_input);
        printf("%llu", result);
    } else if (argv[2][0] == 'r') {
        unsigned long long int result = fib_recursive(user_input);
        printf("%llu", result);
    }

    return 0;
}