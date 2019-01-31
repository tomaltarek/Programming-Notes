/*
@tomal tarek,arcola, 2019

The program will print 1 to 100
But we did some simulation and for that
A signal can be raised any time and the program tends to exit

We implemented signal handling that will allow users to continue printing
rest of the numbers.

*/

#include <stdio.h>
#include <stdlib.h>
#include<signal.h>
#include<time.h>

// Signal handler prototype
void signalHandler(int sigValue);

int main(void)
{
    int i,x;
    // registering the signal handler
    signal(SIGINT,signalHandler);
    srand(time(NULL));
    puts("This program should print 1 to 100 if no signal interrupt occurs..");

    for (i=1;i<=100;i++)
    {
        printf("%4d",i);
        // simulation has been created with the help of random numbers
        x=1+rand()%30;
        if (x==10)
        {
            raise(SIGINT);
        }
    }
}

void signalHandler(int sigValue)
{
    int response;
    printf("\nOops! we hit signal interruption...");
    printf("\n\npress 1 to continue, any other number to exit : ");
    scanf("%d",&response);
    if(response==1)
        {
         // registering the handler again to catch next signal
         signal(SIGINT,signalHandler);
        }
   else exit(EXIT_SUCCESS);

}
