#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"

int main(int argc, char **argv)
{
    struct stat st;
    int ret = stat("copy.txt", &st);
    if(ret == -1) 
    {
        perror("copy.txt");
        return -1;
    }
    printf("文件大小%d\n", (int)st.st_size);
    
    if(S_ISDIR(st.st_mode))
    {
        printf("copy.txt是个目录\n");
    }
    if(S_ISREG(st.st_mode))
    {
        printf("copy.txt是个文件\n");
    }
    if(S_ISLNK(st.st_mode))
    {
        printf("copy.txt是个软连接\n");
    }
   

    if (st.st_mode & S_IRUSR)
    {
        printf("r");
    }
    if (st.st_mode & S_IWUSR)
    {
        printf("w");
    }if (st.st_mode & S_IXUSR)
    {
        printf("x");
    }
    printf("\n");
    return 0;
}