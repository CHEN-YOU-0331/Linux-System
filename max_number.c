#include <stdio.h>
int main(){
    int num[5];
    puts("Enter 5 numbers:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        if (num[i] >= num[i+1])
        {
            int temp = num[i];
            num[i] = num[i+1];
            num[i+1] = temp;
        }
         
    }
    printf("最大數是%d\n" ,num[4]);
}