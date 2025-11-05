// This code demonstates waiting for the specific signal, read man.
  // to wait for any signal it's possible to use pause()
  // SIGUSR1 is "virtual" signal that not associated with any "real"(like SIGINT) event in the system.
  // its "meaning" depends only on code logic(when and by who sended and whenant by who  waited).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    printf("I'm father %d\n", getpid());
    int pid = fork();
    if ( pid == 0 ) {  // the son
	   int sig;
	   sigset_t waitset;
	   sigemptyset( &waitset );
       sigaddset( &waitset, SIGUSR1); // init waiting list
       sigprocmask( SIG_BLOCK, &waitset, NULL ); // signal have to be blocked for sigwait to work as desired
	       // if not blocked, it depends on implementation, in this system the process will ended.
	       // comment and explain, read man
	   printf("I'm the son %d waiting for father's signal\n", getpid());         
       int result = sigwait(&waitset, &sig) ; // wait for signal
       if(result == 0 && sig == SIGUSR1) // only to demionstrate the params, one condition may be enough
          printf( "Got it, sigwait() returned for signal %d , ending\n", sig );
       else  printf( "sigwait() returned error number %d\n", errno );
     }
	 else {  // the father
	   int status;
       char s='a';
       sleep(1); // only for ordered output
	   while(s!='s') { printf("Enter s to signal the son "); scanf("%s", &s); }	
       printf("Stopping the son\n");
	   kill(pid,SIGUSR1); // send signal to the son by its pid. kill is one of big misconceptions
	         //it does not really kills, but rather sends signal, only sending SIGKILL(==-9) really kills.
       wait(&status);
       }
    return EXIT_SUCCESS;
    }
	
//Check yourself
//1)What's the difference between synchronous and asynchronous signals? How are they generated?
//2)Is SIGUSR activated by OS or by a user process? Who initiates its send?
   //Who delivers it to the process(user process or OS)?
//3)Can we activate any function by using kill(), even if it wasn't registerted by signal() or sigaction()?
//4)Can we register any function we want as a signal handler or only special functions?
//5)Can we use pause() without registering any signal handler?
    