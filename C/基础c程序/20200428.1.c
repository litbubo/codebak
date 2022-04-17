#include <stdio.h>
struct index
{
    int key;
    int start;
    int end;
} index_table[4];
int storage[15];
int block_search(int key)
{
    int i = 0,startValue;
    while(i<=3&&key>index_table[i].key)
        i++;
    startValue=index_table[i].start;
    while(startValue<=index_table[i].end&&storage[startValue-1]!=key)
        startValue++;
    if(startValue>index_table[i].end)
        return 0;
    return startValue;
}
int main()
{
    int i,j=0,k,key,position;
    for (i=1; i<=15; i++)
        storage[i-1]=i;
    printf("初始数表为：\n");
    for (i=0; i<15; i++)
    {
        printf (" %d ",storage[i]);
        if ((i+1)%5==0&&i+1<15)
            printf ("|");
    }
    for(i=0; i<3; i++)
    {
        index_table[i].start=j+1;
        index_table[i].end=j+5;
        j+=4;
        index_table[i].key=storage[j++];
    }
    printf("\n\n");
    for(i=0; i<3; i++)
    {
        printf("index_table[%d].start = %d \n",i,index_table[i].start);
        printf("index_table[%d].end   = %d \n",i,index_table[i].end);
        printf("index_table[%d].key   = %d \n",i,index_table[i].key);
        printf("\n");
    }
    printf("输入需要查找的数字：");
    scanf("%d",&key);
    key=block_search(key);
    position=key-1;
    printf("\n");
    printf("已找到位置为%d的数字：%d\n",position,key);
    printf("\n");
    printf("将位置为%d的数修改为：",position);
    scanf("%d",&storage[position]);
    printf("\n");
    printf("修改后的数表为：\n");
    for (i=0; i<15; i++)
    {
        printf (" %d ",storage[i]);
        if ((i+1)%5==0&&i+1<15)
            printf ("|");
    }
}
