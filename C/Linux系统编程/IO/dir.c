#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char **argv)
{
    DIR *dir = opendir("/home/xlp/Linux_c");
    if (dir == NULL)
    {
        perror("opendir");
        return -1;
    }
    int count = 0;
    struct dirent *mydir = NULL;
    while (1)
    {
        mydir = readdir(dir);
        if (mydir == NULL)
        {
            printf("文件读完了\n");
            break;
        }
        if(mydir->d_type == DT_REG)
        {
            char *p = strstr(mydir->d_name,".c");
            if ( (p != NULL) && (*(p + 2) == '\0'))
            {
                count ++;
                printf("第%d个文件，%s\n", count, mydir->d_name);
            }
        }
    }
    printf("总计%d个文件", count);
    closedir(dir);
    free (mydir);
    return 0;
    
}
