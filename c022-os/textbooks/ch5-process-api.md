# Process API

## fork

when call fork(), OS create a new process.
the two process is all same, and return from fork() function. 

but according the `man fork()`, when it create success. 
* the child process receives a return code of **0**
* the parent process receives the PID of the newly-created child process

## wait

call wait() to delay its execution, until target proccess is completed

wait for any child process
> wait(NULL) will block parent process until any of its children has finished

wait for all child process completed
> POSIX defines a function: wait(NULL)；. It's the shorthand for waitpid(-1, NULL, 0);
> `while ((wpid = wait(&status)) > 0);`

## exec
work with `fork()`
> the *exec* family function will replace the current processs image with new process image.
so the rest codes of original process, will not execution.

**execvp**
> The first argument, by convention, should point to the file name associated with the file being exe-cuted.  The list of arguments must be terminated by a NULL pointer.

## why
>  the separation of fork() and exec() is essential in building a UNIX shell

### shell work flow
cmd: fork							 -> wait -> output
		\ -> pre-env -> exec -> exit /

### redirected
> Specifically, UNIX systems start looking for free file descriptors at zero.  In this case, STDOUT FILENO will be the first available one and thus get assigned when open() is called. Subsequent writes by the child process to the standard output file descriptor, for example by routines such as printf(), will then be routed transpar- ently to the newly-opened file instead of the screen.


## extension

### init
The process 1, and PID=1
> the very first process (called init) is started by the kernel at booting time and never terminates

### Zombie Process
> A child that terminates, but has not been waited for becomes a "zombie".

### Orphan Process
> running process whose parent process has finished or terminated 

#### Re-parenting 
> In most cases, the new parent is the `init` process, one with the PID 1.

#### Daemon Process 
is an intintionally orphaned process

> A daemon process is usually created by a process forking a child process and then immediately exiting, thus causing init to adopt the child process. In a Unix environment, the parent process of a daemon is often, but not always, the init process.

### references
* [create-zombie-process](https://stackoverflow.com/questions/25172425/create-zombie-process)
* [orphan-zombie-daemon-process](https://www.gmarik.info/blog/2012/orphan-vs-zombie-vs-daemon-processes/)
* [zombie and orphan is os](https://shivammitra.com/operating%20system/zombie-and-orphan-process-in-opearting-system/#)
* [wait(NULL) work](https://stackoverflow.com/questions/42426816/how-does-waitnull-exactly-work)
* [wait for all child](https://stackoverflow.com/questions/19461744/how-to-make-parent-wait-for-all-child-processes-to-finish)
