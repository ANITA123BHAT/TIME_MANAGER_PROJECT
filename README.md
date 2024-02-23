Video on Linux system overview: https://learning.oreilly.com/videos/linux-under-the/9780134663500/

Socket tutorial: https://beej.us/guide/bgnet/html/split-wide/

How to create simple makefile: https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

 

Assignment (submission date : 15-Feb-2023):

--------------------------------------------------------------

Create a linux service called time-manager which shall expose the following API:

int64_t getTime()

It would return the current time in epoch format.

The API should be provided in a shared library & header file.

The shared library shall talk to the time-manager service using socket.

Demonstrate the working of the service using a test application.

 

The code file/directory structure will be as below (use the attached time_manager.tar.gz):

uie86219@lpk-ee211850-vm:~/Training/time_manager$ tree

.

├── daemon (will contain the code for the time manager service)

│   ├── Makefile

│   ├── src

│   │   └── time_manager_daemon.c

│   └── time_manager.service

├── lib (will contain the code for the shared library )

│   ├── include

│   │   └── time_manager.h

│   ├── Makefile

│   └── src

│       └── time_manager_lib.c

└── test (will contain the code for the test application)

    ├── Makefile

    └── sample_application.c
