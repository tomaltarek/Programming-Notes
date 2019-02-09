# Distributing your codes

*Goal: *
We will write some codes and distribute them to the outside world. 


## Introduction
Reusability is the heart of modern software industry. We should not write a piece of code that somebody else somewhere in the world has already written. In simple word, we should not reinvent the wheel. 
But not all the codes in the world are open-sourced. Sometimes we may need to buy codes written by other programmers. 
In this note, we will show some examples how to distribute source code in binary format. Codes in this note are are written in C++ . For compiling codes we have used CodeBlocks IDE and Developer Command Prompt for VS 2017. 


## How codes are generated?
First off, we need a source file. We can use any editor of our choice (notepad etc) to write a source code. There are tons of programming languages on this planet to write a source file. Below is an example of a source file written in C++ 

```C++
#Include <iostream>
Using namespace std; 
Void tiger()
{
cout<<”Grrrrrrrrrrrrr””<<endl; 
```

Suppose you have written this extraordinary code, By writing this, you have become the  absolute owner of this intellectual property. Now you can sell this to others for five bucks. If you can sell it to 100 other programmers, you can cashed five hundred dollars. 

If you carefully look, on the above code, there is no main method. Therefore you cannot make an .exe version out of it. That was even not your intention when you made this code. Your intention was provide this to others in the form of other type of binaries. 

If we compile this code, an object file (with .o extension ) will be produced. The object file is the binary file you will sell to other programmers. Your clients will have no idea whatsoever what is written in the void tiger() method. Because you are not giving your source code (with .cpp extension). 

## What your clients do with your code?
Well, your clients can make a program with int main(), and there , they can use your object file. In their source code, they have to refer (with the help of a header file may be) your object file, and during compilation process they have to link your object file. At the end they will be able to produce an application where they can listen to how a tiger sounds. 


## A better way other than raw object file
Well, it is lots of pain to link an object file with a source file. Your client won't like that hassels. It is a good idea to give the binaries in the form of a library. 

A library is nothing but a collections of object files. Libraries are easy to link with. 

### Example 1
I this example we will produce/compile codes without an IDE. 

**Step 1: (What seller will do)**

Make a folder anywhere. 
With your favourite editor, create a file, name it tiger.cpp. The file will look like this. 

```C++
#include<iostream>
using namespace std;

__declspec(dllexport) void tiger()
{
    cout<<"Grrrrrrrrrrrr"<<endl;
}

```
If you have Visual studio installed, yo can use **Developer Command Prompt VS 2017** to compile your code. In this way you should not set the environment variables for your compiler. On the search box, type Developer Command Prompt VS 2017. 

With CD command go to your folder where you created tiger.cpp 

To compile your file , type: *cl /c tiger.cpp* 
That will produce the binary file *tiger.obj.*

Now to create a library out of this object file type: *lib/out:myLibrayName.lib tiger.obj* 

This will produce a library file myLibray.lib 


This is the library you are going to sell to your client. Usually with a library you need to provide a header file (with .h extension) , that is easy to make. On your folder just create a file tiger.h , the file content will look like this: 
Void tiger()

A header file is kind of an interface, it declares all the methods your library file will define. By looking at the header file the client will have some idea what your library is about. The header file is a kind of documentation too. Although our header file has only one line, in reality header files are not really that short. You can have a look on a Standard library header file. 

There you go, take file dollars from your client client and hand them two files
myLibrary.lib
Tiger.h 


**Step 2: (What your client will do?)**

Your client will dump the library file and header file in a folder. He will create a source  file of his own, for simplicity let's create a source file on the same folder and name it main.cpp. This file has a int main() method which means this would be an application. 

From the main.cpp file, the client can refer to your library. The program will look like this. 

```C++
#include “tiger.h” 

Int main()
{
tiger();
}
```


After writing the program the client will compile and link the program with the myLibrary.lib 

On the command prompt , he has to write: cl main.cpp /link myLibrary.lib

Thus main.exe application will create. 
The output of the program will look like this: 
```
OUTPUT Grrrrrrrrrrrr
```

## Example 2: 
We can do the same thing as described in example 1 with the help of a IDE. We will use CodeBlocks. 

**Step 1 (What seller will do)** 

Create a project of type static library. 
The project will create a source file main.c. Right click and remove the file from the project. Then add tiger.cpp file. Put the following code on that file: 


```C++
#include<iostream>
using namespace std;

__declspec(dllexport) void tiger()
{
    cout<<"Grrrrrrrrrrrr"<<endl;
}
```

Build the project. Go to the project folder, on bin/Debug folder a library file will be created. NOTICE that this time the file extension is not .lib, it is .a which means archive file. MingGW produce library file with .a extension. 

Make a header file  as you did in example 1, along with the header file, provide your library to the client. 

**Step 2:**
On an IDE , suppose in CodeBlocks , client will create a console application project. On that project he will link your library fille. To do this he will right click on the project and go to build options. Then on linker settings he will attach the library file, then saved the project. 

The client will create his own source file, to refer your library he has to include the header file on his source file. 

*@tomal tarek, Feb 8, 2019, তমাল তারেক, ৮/২/২০১৯*
