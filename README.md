# [Bah-lang](https://bah-lang.xyz)

## Installation
> Note that Windows and MacOS (darwin) releases may be delayed compared to Linux releases.

To install bah on your machine, get the terminal warmed up 🔥 , stretch your fingers up 🏋‍♂ and paste this 😎:
### Linux
```sh
git clone https://github.com/ithirzty/bah
cd ./bah
sudo ./linux_install.sh
```
If the installation fails for whatever reason, you will need to recompile the Bah compiler
before installing it. Dont worry this is simple, simply run:
```sh
sudo ./linux_compile_install.sh
```

### Windows
**Please make sure that you have [mingw gcc](https://sourceforge.net/projects/mingw/) installed.**
```bat
git clone https://github.com/ithirzty/bah
cd ./bah
.\windows_install.bat
```
If the installation fails for whatever reason, you will need to recompile the Bah compiler
before installing it. Dont worry this is simple, simply run:
```bat
.\windows_compile_install.bat
```

### MacOS (darwin)
```bat
git clone https://github.com/ithirzty/bah
cd ./bah
.\darwin_install.bat
```
If the installation fails for whatever reason, you will need to recompile the Bah compiler
before installing it. Dont worry this is simple, simply run:
```bat
.\darwin_compile_install.bat
```


[![installation tutorial](./extra/install_thumb.jpg)](https://youtu.be/druJwBluvLc)

## Updating
To update, execute the following:
```sh
./linux_update.sh
```
If the repository is updated, this script will pull the main branch and install everything.

## Usage
Files containing bah code have the `.bah` extenstion.
- To compile your program, use `bah myFile.bah`.
- To translate your program as C code, use `bah myFile.bah -c`.
- To set an output name to your program, use the `bah myFile.bah -o myCompiledProgram`.
- To get the current installed version, use `bah -v`.
- To compile as a static library, use `bah myFile.bah -l`.
- To compile your program as a dynamically linked program, use `bah myFile.bah -d`.

### Hello, world!
```c
#include "iostream.bah" //includes the library containing 'println'
main(args []cpstring) int //declare the main (the entry-point to the program)
{
    println("Hello, world!") //print "Hello, world!" + a new line
    return 0 //exit the program with '0' meaning that it executed without error
}
```

## Why?
Bah is a really fast language that is low level enough for most cases while being really simple.
As well as being easy to learn, you can create 
- website
    - [bah-lang website](https://bah-lang.xyz)
- compilers
    - [bah compiler](https://github.com/ithirzty/bah)
- interpreters
    - [Brainfuck interpreter](https://github.com/ithirzty/bah-brainfuck)
- web apps
    - [bah-lang doc](https://github.com/ithirzty/bah-website)
- libraries
    - [vbah](https://github.com/ithirzty/vbah), a graphics library.
    - [bah-bmp](https://github.com/ithirzty/bah-bmp), an image edition library.
    - [bah-cjson](https://github.com/ithirzty/bah-cjson), a chuncked json library.
- and many more.
> You did something awesome in bah? Add it to the list!


### Awesome features
Bah also supports awesome features like reflection (simillar to Go approach).

This enables you to do things that would be impossible in C
such as scanning JSON content to a variable (event structs and arrays), and marshalling vars to JSON.
All of that with a single function call!

## Extras
Here is how fast bah v1.0 (build 15) compiles itself on a ThinkPad x220 (a 16 years old machine)
![compilation times](extra/bah_comp_time.png)

## How does it work?
Information on how a Bah compiler should operate can be found [here](how.md)