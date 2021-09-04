## Component of a process
1. address space
2. register (program counter -PC, stack pointer -SP...)
3. I/O infomation

## Process Api
* Create
	1. Load: load code from disk
	2. Initail: run-time stack, heap
	3. I/O: standard input, output, error file descriptors
	4. Start: jumping to the `main()`
* Destory
* Miscellaneous Control
* Wait
* Status

## Process States
Running
Ready
Blocked

## Data Struct
OS behold a **process list** for all process to track which process is running
Each entry is found in what is sometimes called a **process control block (PCB)**, which is really just a structure that contains information about a specific process.

``` c
// the registers xv6 will save and restore
// to stop and subsequently restart a process
struct context {
	int eip;
	int esp;
	int ebx;
	int ecx;
	int edx;
	int esi;
	int edi;
	int ebp;
};

// the different states a process can be in
enum proc_state { UNUSED, EMBRYO, SLEEPING,
				RUNNABLE, RUNNING, ZOMBIE };

// the information xv6 tracks about each process
// including its register context and state
struct proc {
	char *mem; // Start of process memory
	uint sz; // Size of process memory
	char *kstack; // Bottom of kernel stack

	// for this process
	enum proc_state state; // Process state
	int pid; // Process ID
	struct proc *parent; // Parent process
	void *chan; // If !zero, sleeping on chan
	int killed; // If !zero, has been killed
	struct file *ofile[NOFILE]; // Open files
	struct inode *cwd; // Current directory
	struct context context; // Switch here to run process
	struct trapframe *tf; // Trap frame for the
	// current interrupt
};
```

