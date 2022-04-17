#include <QCoreApplication>
#include "stdio.h"
#include "math.h"
int main()
{
    int num;
    int i = 0;
    int a[10];
    int count = 0;
    scanf("%d", &num);
    while (num != 0)
    {
        count++;
        a[i] = num % 10;
        num /= 10;
        i++;
    }
    double  i3 = sin(56);
    for (int temp = 0; temp < count; temp++)
    {
        printf("%d,", a[temp]);
    }

    return 0;

}
