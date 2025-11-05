# Operating Systems 2026a (20594)

This is an **unofficial** repository (made by a student) for students taking
the Operating Systems course (20594) by the Open University of Israel this
semester (2026a).

The repository is meant to be used as a template, rather than as an active
repository.

Within each 'maman' directory you will find all of the resources provided by
the university for the relevant assignment, as well as a Dockerfile that will
create an image with all of the dependencies required to build and run your
solution for the assignment.

The workflow for working with this repository is as follows:

1. From the root directory of the repository, `cd` into the relevant maman
   directory, for demonstration purposes, we will choose maman01:

   ```bash
   cd maman01
   ```

2. Read the instructions of the assignment located within the relevant 'maman'
   directory, any additional reading materials and resources can be found
   under the 'resources' directory.
3. First and foremost, make sure that you are able to build and run the
   initial unmodified version provided by the university:

   **Running on Windows/MacOS with Intel Core:**

   ```bash
   # Build the container, and tag it as 'maman01-xv6' (i.e. assign the name
   # 'maman01-xv6' to the container image)
   docker build -t maman01-xv6 .
   # Start and attach to the container's running process (bash)
   docker run --rm -it maman01-xv6
   ```

   **Running on MacOS with Apple Silicon:**

   ```bash
   # Build the container, and tag it as 'maman01-xv6' (i.e. assign the name
   # 'maman01-xv6' to the container image)
   docker buildx build --platform linux/amd64 -t maman01-xv6 .
   # Start and attach to the container's running process (bash)
   docker run --rm -it --platform linux/amd64 maman01-xv6
   ```

   You are now attached to a container running a minimalistic variant of
   Ubuntu-24.04 with all necessary dependencies to consistently build your
   custom XV6 operating system source files and run them inside QEMU emulator.

   From here on, simply follow the university's original instructions for
   building and running the XV6 operating system as if you were doing so from
   the Ubuntu virtual machine provided by the university.

   For example, to build and run the XV6 operating system of maman01, run:

   ```bash
   # building maman01 XV6 which is missing the `ps` command
   make clean qemu # runs `make clean`, followed by `make qemu`

   # building the university's soultion with `ps` command implemented
   make clean qemuss # runs `make clean`, followed by `make qemuss`
   ```

4. Begin working on your solution and modifying the necessary source files
   under 'xv6-XX' where XX stands for your relevant maman identifier
   (e.g. if you are solving maman01, then source files would be located at
   `maman01/xv6-01`
5. Once you are ready to test your solution, simply start the container again
   is shown in step 3.
6. Return to step 4 and continue following the steps until you have a working
   solution.

Good Luck!

**P.S:** do not create pull requests with working solutions! The university
forbids sharing solutions! This repository was created out of my own curiosity
and good will, and I'd appreciate not getting punished for doing so.

## Maman01 Checklist (for Question 1)

Add the `ps` system call to the XV6 operating system kernel.

**WARNING:** _I manually made this checklist myself. It may be incomplete,
incorrect, and important info may be missing - use with caution and always
validate against the original instructions provided by the university_

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
