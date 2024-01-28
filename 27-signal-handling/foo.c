#include <signal.h>


void handle_signal(int signal) {

}

int main(void) {

    // char s[1024];
    // signal(SIGINT, SIG_IGN); // Ignore SIGINT, caused by ^C
    // printf("Try hitting^C... (hit RETURN to exit)\n");
    // fgets(s, sizeof s, stdin);


    // Dont use signal(), better to use
    // my OSs  built-in signal handling system
    signal(SIGINT, handle_signal);



}
