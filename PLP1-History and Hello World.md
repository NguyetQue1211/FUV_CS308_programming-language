### 1. What is the name of your language?
For this CS308 class, I chose C++ to study and research

### 2. When/where was it created, and by whom? Was it written to address a particular problem or need?
C++ (pronounced see plus plus) was developed by Bjarne Stroustrup at Bell Labs as an extension to C, starting in 1979. C++ was standardized in 1998 by the ISO committee (this means the ISO standards committee approved a document describing the C++ language, to help ensure all compilers adhere to the same set of standards).

In the late 1970s, Stroustrup applied the idea of “classes” to the C programming language to create a new language that allows for high level abstraction—but is efficient and close to the hardware. 

### 3. What types of programming is your language primarily used for (ex: web sites, video games, mobile devices, parsing, etc.)? If your language is multi-purpose, provide some examples of different projects it's been used for.
C++ can be used for various purpose: 
    - Build operating system
    - Develop games
    - Build database
    - Applied to machine learning 
    - Applied to scientific research
    - etc 

### 4. Where will you get information about this language when it's time to start programming in it? At the end of your assignment, provide a list of the names of books, website URLs, or any other resources that relate to your language in particular.
**Book:**
- C++ Primer, Fifth Edition by  Stanley B. Lippman, Josée Lajoie, Barbara E. Moo 
- Programming: Principles and Practice Using C++ (2nd Edition) by Bjarne Stroustrup 
- Thinking in C++, Volume 1, 2nd Edition by Bruce Eckel
**Website:** 
w3schools: https://www.w3schools.com/CPP/default.asp
Learn C++: https://www.learncpp.com/

### 5. What did you need to do to install the language?
Here are steps to install the language:
- Download and  install IDE (Visual Studio Code): https://code.visualstudio.com/download
- Install the extension C/C++
- Install a compiler: for me, I use MacOs with already installed GNU Compiler Collection (GCC). 
- For more details, I did follow the guideline of Visual Studio Code official website: https://code.visualstudio.com/docs/languages/cpp
 
### 6. Does this language come with a recommended programming environment? What is it?  If not, how did you pick the one that you'll be using?
There are many C++ IDEs such as: VS Code, Code:: Blocks, Eclipse,  CodeLite, Sublime Text, NetBeans,... However, I chose to use VS Code since I’ve been familiar with this IDE for some courses before. 


### 7. How do you run programs in that language?
- First we create the folder named Hello World 
- Open VS Code in this folder
- Create a file called helloworld.cpp
- Copy and paste this code in the file helloworld.cpp, then save it
    ```
    #include <iostream>
    int main()
    {
        std::cout << "Hello World" << std::endl;
    }
    ```
- Select the Terminal > Run Build Task
- choose C/C++: g++.exe build active file.
- This will compile helloworld.cpp and create an executable file called helloworld.exe, which will appear in the File Explorer.
- From a command prompt or a new VS Code Integrated Terminal,  run the program by typing "./helloworld"

### 8. How do you write comments in your language?
A C++ comment is written in one of the following ways:
- The /* (slash, asterisk) characters, followed by any sequence of characters (including new lines), followed by the */ characters. 
- The // (two slashes) characters, followed by any sequence of characters. A new line not immediately preceded by a backslash terminates this form of comment. Therefore, it is commonly called a "single-line comment."
- The comment characters (/*, */, and //) have no special meaning within a character constant, string literal, or comment. Comments using the first syntax, therefore, cannot be nested.

