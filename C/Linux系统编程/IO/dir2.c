#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int GetNum(const char *path)
{
    DIR *dir = opendir(path);
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
            //printf("文件读完了\n");
            break;
        }
        if (strcmp(mydir->d_name,".") == 0 || strcmp(mydir->d_name,"..") == 0)
            continue;

        if (mydir->d_type == DT_DIR)
        {
            char newpath[500];
            sprintf(newpath, "%s/%s", path, mydir->d_name);
            count += GetNum(newpath);
        }
        else if (mydir->d_type == DT_REG)
        {
            char *p = strstr(mydir->d_name, ".c");
            if ((p != NULL) && (*(p + 2) == '\0'))
            {
                count++;
                printf("第%d个文件，%s/%s\n", count, path, mydir->d_name);
            }
        }
    }
    closedir(dir);
    free(mydir);
    return count;
}

int main(int argc, char **argv)
{
    int count = GetNum("/home/xlp/Linux_code");
    printf("总计%d个.c文件", count);
    return 0;
}
