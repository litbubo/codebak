#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>

void my_daemond()
{
    pid_t pid, sid;
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid > 0)
    {
        exit(0);
    }

    sid = setsid();
    if (sid == -1)
    {
        perror("setsid");
        exit(1);
    }
    int ret = chdir("/home/xlp/Linux_c/system");
    if (ret == -1)
    {
        perror("chdir");
        exit(1);
    }
    umask(0002);
    close(STDIN_FILENO);
    open("/dev/null", O_RDWR);
    dup2(0, STDOUT_FILENO);
    dup2(0, STDERR_FILENO);
}

int main(int argc, char **argv)
{
    my_daemond();
    char buf[13] = "Hello world\n";
    while (1)
    {
        int fd = open("daemond.txt", O_CREAT | O_RDWR | O_APPEND, 0644);
        if(fd == -1)
        {
            exit(1);
        }
        write(fd, buf, sizeof(buf));
        close(fd);
        sleep(1);
    }
    return 0;
}