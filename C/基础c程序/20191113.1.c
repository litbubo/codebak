//��11��
#include <stdio.h>
main()
{
    int i=0,j;
    char str[100]= {"****abcd**ef***gh*****"};
    printf("%s\n",str);
    while(str[i]=='*')
        i++;
    for(j=0; str[i+j]!='\0'; j++)
        str[j]=str[i+j];
    str[j]='\0';
    printf("ɾ��*�ź���ַ���Ϊ\n");
    printf("%s\n", str);
}
