#include <stdio.h>
#include <stdlib.h>

unsigned long long int FibIterative(int n) {
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   unsigned long long int first = 0, second = 1, next_value;
   for (int i = 3; i <= n; i++) {
      next_value = first + second;
      first = second;
      second = next_value;
   }
   return second;
}

unsigned long long int FibRecursive(int n) {
   if(n == 1){
      return 0;
   } else if (n == 2) {
      return 1;
   } else {
      
      return (FibRecursive(n-1) + FibRecursive(n-2));
   }
}

int main(int argc, char *argv[]) {
   int value = atoi(argv[1]);

   int N = value;

   if (argv[2][0] == 'i') {
     unsigned long long int result = FibIterative(N);
      printf("%llu", result);
   } else if (argv[2][0] == 'r') {
      unsigned long long int result = FibRecursive(N);
      printf("%llu", result);
   }
   return 0;

}