# Signal 

Unlike exception,a signal can raise from outside of a program, may be from operating system or some user's action- who knows. 

Common example of a signal is, when we run a program in console, when we press Ctl+C, the program termintates. Therefore Ctl+C is a signal interruption. 

In C, to deal with signal interruption, it has header **<signal.h>**

On this header file, there is a function - **signal** that can take two arguments, the first argument is an integer, the second one is a pointer to a function - this is the function you will wirte to handle the signal.  

Let us see, with a simple program how we handle a signal. 

We will write a program that will simulate a signal raising environment. 
We will raise **SIGINT** signal. SIGINT is an interactive attention signal 

From our main program we will try printing numbers from 1 to 100. 
When the loop is busy printing the numbers, inside the loop we introduced some logic- before before printing a number, we created a random number (any number from 1 to 30), if that random number is equal to 10, then we raised the signal which means program will just exit without further doing. But we will not let it happen. We introduced a function by whihc we will handle the signal. Below is the function, have a look. 

```C
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

```
And below is the main program where we call the above function 

```C
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

```


