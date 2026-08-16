#include <stdio.h>
long long power(long long x, int n){
long long result = 1;
 while (n > 0) {
   if (n % 2 == 1) {
   result = result * x;
  }
 x = x * x;
 n = n / 2;
}
return result;
}
int main() {
 long long x, sum;
int n;
printf("Enter X: ");
scanf("%lld", &x);
printf("Enter n: ");
scanf("%d", &n);
 if (x == 1) {
  sum = n + 1;
} else {
 long long p = power(x, n + 1);
sum = (p - 1) / (x - 1);
 }
 printf("Sum = %lld\n", sum);
 return 0;
}
