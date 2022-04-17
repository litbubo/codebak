#include <stdio.h>
#include <string.h>
void compare(char **p);
int main()
{
    char *a[5], b[5][1000], **p;
    int i;
    for (i = 0; i < 5; i++)
        a[i] = b[i];
    printf("请依次输入五个字符串：每按回车输入下一个。\n");
    for (i = 0; i < 5; i++)
        scanf("%s", a[i]);
    p = a;
    compare(p);
    printf("排序后输出为：\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s\n", a[i]);
    }
}
void compare(char **p)
{
    char **q, **s, *t;
    for (q = p; q < p + 4; q++)
    {
        for (s = q + 1; s < p + 5; s++)
        {
            if (strcmp(*q, *s) > 0)
            {
                t = *q;
                *q = *s;
                *s = t;
            }
        }
    }
}
