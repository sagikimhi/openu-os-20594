# Maman01

## Question 1

Add the `ps` system call to the XV6 operating system kernel.

### Requirements

- [ ] the system call name must be `cps1xx` where xx are the last 2 digits of my
      ID.
- [ ] the implementation must be done in a file called _ps.c_ **unlike** the
      system call name itself which is called `cps1xx` and not `ps`
- [ ] The system call number must be equal to the digits following cps. e.g.
if your last two ID digits are 27 then system call code must be 27.

### Restrictions

- [ ] **DO NOT** modify _syscall.h_, instead, understand the structure of data in
  _syscall.c_ and find another way to bypass the limitations imposed by this
  restriction.
- [ ] **DO** modify _usys.s_, make use of the custom changes already made to it to
  implement the _fork_ syscall as an example.

### Allowed Changes

- [ ] ps.c - create and modify as needed.
- [ ] proc.c - modify as needed.
- [ ] syscall.c - modify exactly 2 lines.
- [ ] usys.S - modify as needed.
- [ ] sysproc.c - modify as needed.
- [ ] user.h - modify exactly 1 line.
- [ ] defs.h - modify exactly 1 line.
- [ ] Makefile - modify to fit and support the latest modifications.

### Output Requirements

- [ ] The _PPID_ field of _INIT_ **must be equal to 0.**
- [ ] The output contents must be identical to the university's image solution.
- [ ] All processes that were ever created on the system need to be printed,
      running processes are displayed as _"RUNNING"_, all others are displayed as
      _"SLEEPING"_
- [ ] The title of the output must be printed via:

    ```c
    cprintf("name \t pid \t state \t \t ppid \t size \n");
    ```

    **Side-Note:** In order to be able to print _PPID_ and _SIZE_ fields, one must
    fetch their values from the operating system's PCB (Process-Control-Block)
    structure.

### Before Uploading the Solution

Before uploading your solution, validate the following:

- [ ] Rebuild and rerun the entire system emulation and OS to ensure it
      compiles and that the outputs are all valid.
- [ ] After running `make clean` run `make qemu` and ensure that the output is
      still valid.
- [ ] Shut down the QEMU emulator, and run the tests with `./runtests.exp
my.log`, you may need to modify the file permissions of _runtests.exp_ to
      successfully run the tests.
- [ ] Make sure that the script exit status is zero (e.g. `echo $?`).

### Uploading the Solution

To upload the solution, the below requirements must be met:

- [ ] The files shall be zipped into a zip archive called ex01.zip
- [ ] A comment must be included in every source file in the zip with
      a general description of the file, student name, and ID.
- [ ] The following files are the only ones that may be modified or added to
      and are the only files that must be zipped as part of the solution: _usys.S_,
      _defs.h_, _user.h_, _ps.c_, _proc.c_, _syscall.c_, _sysproc.c_, _Makefile_

### After Uploading the Solution

After uploading your solution, re-validate it:

- [ ] Unzip the ex01.zip archive you created.
- [ ] Extract original maman01.zip files into a brand new directory.
- [ ] Extract and copy all files from ex01.zip solution into the new xv6
      directory.
- [ ] Re run the build and ensure it builds without any errors or warnings and
      runs correctly producing correct output results as specified in previous
      sections of this README file.
