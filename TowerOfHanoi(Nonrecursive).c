#include <stdio.h>
void moveDisk(int disk, char from, char to)
{
printf("Move disk %d from %c to %c\n", disk, from, to);
}
int main()
{
int n, totalMoves, i;
printf("Enter number of disks: ");
scanf("%d", &n);
totalMoves = (1 << n) - 1;
char source = 'A', auxiliary = 'B', destination = 'C';
 if (n % 2 == 0)
 {
char temp = destination;
destination = auxiliary;
auxiliary = temp;
}
 for (i = 1; i <= totalMoves; i++)
 {
 int disk;
if (i % 3 == 1)
 {
  disk = (i % n) + 1;
  moveDisk(disk, source, destination);
  }
  else if (i % 3 == 2)
 {
  disk = (i % n) + 1;
 moveDisk(disk, source, auxiliary);
 }
 else
 {
disk = (i % n) + 1;
 moveDisk(disk, auxiliary, destination);
}
}
return 0;
}
