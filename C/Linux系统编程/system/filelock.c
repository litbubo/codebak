#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <pthread.h>
#include <fcntl.h>



// struct flock {
//               ...
//               short l_type;    /* Type of lock: F_RDLCK,
//                                   F_WRLCK, F_UNLCK */
//               short l_whence;  /* How to interpret l_start:
//                                   SEEK_SET, SEEK_CUR, SEEK_END */
//               off_t l_start;   /* Starting offset for lock */
//               off_t l_len;     /* Number of bytes to lock */
//               pid_t l_pid;     /* PID of process blocking our lock
//                                   (set by F_GETLK and F_OFD_GETLK) */
//               ...
//           };

int main(int argc, char **argv)
{
    int fd;
    struct flock mylock;
    if(argc < 2)
    {
        printf("intput file!\n");
        exit(1);
    }
    fd = open(argv[1], O_RDWR);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    mylock.l_type = F_RDLCK;
    //mylock.l_type = F_WRLCK;
    
    mylock.l_whence = SEEK_SET;
    mylock.l_start = 0;
    mylock.l_len = 0;
    fcntl(fd, F_SETLKW, &mylock);
    printf("test  \n");
    sleep(10);
    mylock.l_type =  F_UNLCK;
    fcntl(fd, F_SETLKW, &mylock);
    printf("un lock\n");
    close(fd);
    return 0;
}

