//��17��
#include <stdio.h>
main()
{
    int i=0,j=0;
    char str[100]= {"****abcd**ef***gh*****"};
    printf("%s\n",str);
    for(i=0; i<100; i++)
    {
        if(str[i]!='*')
            str[j++]=str[i];
    }
    printf("ɾ��*�ź���ַ���Ϊ\n");
    printf("%s\n", str);
}
