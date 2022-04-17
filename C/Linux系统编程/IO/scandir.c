#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int Getc(const struct dirent *mydir)
{
    
    if (mydir->d_type == DT_REG)
    {
        char *p = strstr(mydir->d_name, ".c");
        if ((p != NULL) && (*(p + 2) == '\0'))
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    struct dirent** list = NULL;
    int count = scandir("/home/xlp/Linux_c", &list, Getc, alphasort);
    for (int i = 0; i < count; i++)
    {
        printf("文件：%s\n", list[i]->d_name);
        free(list[i]);
    }
    free(list);
    printf("总计%d个.c文件", count);
    return 0;
}
