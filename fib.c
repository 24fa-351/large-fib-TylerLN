#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long int OverFlow(unsigned long long int current, unsigned long long int next)
{
   return (current > ULLONG_MAX - next);
}

unsigned long long int FibIterative(int n)
{
   if (n == 1)
   {
      return 0;
   }
   else if (n == 2)
   {
      return 1;
   }

   unsigned long long int first = 0;
   unsigned long long int second = 1;
   unsigned long long int next_value;

   for (int i = 3; i <= n; i++)
   {
      if (OverFlow(first, second))
      {
         printf("Overflow at %d\n", i);
         return 0;
      }
      next_value = first + second;
      first = second;
      second = next_value;
   }
   return second;
}

unsigned long long int FibRecursive(int n)
{
   if (n == 1)
   {
      return 0;
   }
   else if (n == 2)
   {
      return 1;
   }

   unsigned long long int current = FibRecursive(n - 1);
   unsigned long long int next = FibRecursive(n - 2);

   if (OverFlow(current, next))
   {
      printf("Overflow occured at index %d\n", n);
      return 0;
   }
   return current + next;
}

int main(int argc, char *argv[])
{
   int user_input = atoi(argv[1]);

   if (argv[2][0] == 'i')
   {
      unsigned long long int result = FibIterative(user_input);
      printf("%llu", result);
   }
   else if (argv[2][0] == 'r')
   {
      unsigned long long int result = FibRecursive(user_input);
      printf("%llu", result);
   }
   return 0;
}