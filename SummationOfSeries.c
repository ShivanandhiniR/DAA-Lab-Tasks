#include <stdio.h>
int main() {
 int x,n,i;
 long long sum = 0, power = 1;
printf("Enter X: ");
 scanf("%d", &x);
 printf("Enter n: ");
  scanf("%d", &n);
for (i=0;i<=n;i++){
    sum = sum + power;
    power = power * x;
    }
printf("Sum = %lld\n", sum);
 return 0;
}
