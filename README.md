# Simple Shell
![Latest commit](https://img.shields.io/github/last-commit/EskiasYilma/simple_shell?style=round-square)

---

  _____ _           ___      _                 __   ___ _        _ _
 |_   _| |_  ___   / __|__ _| |_ ___ ___  ___ / _| / __| |_  ___| | |
   | | | ' \/ -_) | (_ / _' |  _/ -_|_-< / _ \  _| \__ \ ' \/ -_) | |
   |_| |_||_\___|  \___\__,_|\__\___/__/ \___/_|   |___/_||_\___|_|_|

---

## Background Context

Write a simple UNIX command interpreter.

---

## Output

* Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

Example of error with sh:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with your program hsh:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
---

## Files

File|Description
---|---
[main.c]|Main entry point for shell
[read_n_tokenize.c]|reads from prompt, tokenizes input and creates a main loop
[main.h]|header
[builtin_modules.c]|Handle Built-in modules/functions
[string_modules.c]|Handle string manipulation 
[helper_modules.c]|Helper modules/functions
[exec_commands.c]|Evaluate and Execute commands 
[environment_modules.c]|Handle getting environment variables/keys_value_pairs and find full path of an executable
[_putchar.c]|A custom implementation of putchar 
[man_1_simple_shell]|Man page for simple shell

---

## Project Requirements

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to
- Write a `README` with the description of your project
- You should have an `AUTHORS` file at the root of your repository, listing all individuals having contributed content to the repository. Format, see `Docker`

---

## List of allowed functions and system calls

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    getpid (man 2 getpid)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)

## Testing

Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```


## Completed Tasks

### 0. Betty would be proud
* Write a beautiful code that passes the Betty checks

### 1. Simple shell 0.1
* Write a UNIX command line interpreter.
* Your Shell should:
	- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
	- The prompt is displayed again each time a command has been executed.
	- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
	- The command lines are made only of one word. No arguments will be passed to programs.
	- If an executable cannot be found, print an error message and display the prompt again.
	- Handle errors.
	- You have to handle the "end of file" condition (Ctrl+D)

### 2. Simple shell 0.2
* Handle command lines with arguments

### 3. Simple shell 0.3
* Handle the PATH

### 4. Simple shell 0.4
* Implement the exit built-in, that exits the shell
* Usage: exit
* You dont have to handle any argument to the built-in exit

### 5. Simple shell 1.0
* Implement the env built-in, that prints the current environment

### 8. Simple shell 0.4.1 (partially done)
* handle arguments for the built-in exit
* Usage: `exit status`, where `status` is an integer used to exit the shell

### 10. cd (partially done)
* Simple shell 1.0 +

Implement the builtin command cd:

    - Changes the current directory of the process.
    - Command syntax: cd [DIRECTORY]
    - If no argument is given to cd the command must be interpreted like cd $HOME
    - You have to handle the command cd -
    - You have to update the environment variable PWD when you change directory

---

## Authors
* **Eskias Yilma** - [EskiasYilma](https://github.com/EskiasYilma)
* **Rahel Tesfaye** - [RahelPTech](https://github.com/RahelPTech)


