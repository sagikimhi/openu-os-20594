//Demonstates signal usage
//Can stop with ctrl-z and kill -9 <pid>

#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void my_signal_handler(int signum) {  // Can be the same handler for many different signals
    switch(signum) {
    case SIGINT: { printf("Can't stop me!\n"); break; }
    case SIGUSR1: { printf("Catch SIGUSR1\n"); }
       }
           }

int register_signal_handling() {
    struct sigaction new_action;
    memset(&new_action, 0, sizeof(new_action));
    new_action.sa_handler = my_signal_handler; // Assign the new sinal handler, overwrite default behavior for ctrl+c
    //new_action.sa_handler = SIG_IGN; // Just ignore  ctrl+c
    sigaction(SIGUSR1, &new_action, NULL); // Regirter the new signal handler  
    return sigaction(SIGINT, &new_action, NULL);// The same signal handler for other signal 
    //signal(SIGINT, my_signal_handler); // can use this way also, more simple, but
        //when  a signal occurs, it is implementation-defined whether if it is the equivalent of a:
        //signal(<sig>, SIG_DFL);(going back to default).
		//If it is so, you need to re-register it in signal handler. In this system not needed.
    }

int main(int argc, char *argv[]) {
    if (register_signal_handling() == -1)
      { perror("Signal handle registration failed"); exit(EXIT_FAILURE); }
    int i = 0;
    int pid = getpid();
    while(i < 30) { 
       printf("Process %d, iteration %d\n", pid, ++i); sleep(2);
       if ( i== 5 || i == 10) raise (SIGUSR1); // == kill(getpid(),SIGUSR1);
	          // kill isn't kills, only sending signal
       }
    return EXIT_SUCCESS;
    }
	
//Check yourself
//1)Why can't this program be stopped by CTRL-C ?
//2)What is the difference between SIGNAL() and SIGACTION()?
   //Do these functions make registration of the signal or send the signal?
//3)Does a signal handler is activated immediately when the signal happens or only when the process is in a "waiting" state?
//4)Can a signal handler be activated by a regular call or only by OS?
//5)What happens after a signal handler finishes? Does the process continue running? From which point?
//6)Can all kinds of signals be ignored?
//7)If there is one signal handler for many different signals,how you can take different actions for every kind of signal?
//8)How you can go back to the default procedure of taking care of the signal?
//9)Can the whole process be finished by the signal handler or does it have to go back to main?