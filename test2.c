#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    printf("\n\n\t\tVOICI MON PID: %d AINSI QUE CELUI DE MON PERE %d\n\n", getpid(), getppid());
   exit(1);
   // return (0);
}

