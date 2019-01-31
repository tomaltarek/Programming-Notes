# Signal 

Unlike exception,a signal can raise from outside of a program, may be from operating system or some user's action- who knows. 

Common example of a signal is, when we run a program in console, when we press Ctl+C, the program termintates. Therefore Ctl+C is a signal interruption. 

In C, to deal with signal interruption, it has header **<signal.h>**

On this header file, there is a function - **signal** that can take two arguments, the first argument is an integer, the second one is a pointer to a function - this is the function you will wirte to handle the signal.  

Let us see, with a simple program how we handle a signal. 

We will write a program that will simulate a signal raising environment. 
First have a look what header files we need 
```C
#include <stdio.h>
#include <stdlib.h>
#include<signal.h>
#include<time.h>
```

