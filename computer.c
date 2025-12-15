#include <stdio.h>

void add(float *a, float *b, float *temp){
    *temp = *a + *b;
}

void sub(float *a, float *b,float *temp){
    *temp = *a - *b;
}

void mul(float *a,float *b,float *temp){
    *temp = *a * *b;
}

void div(float *a, float *b, float *temp){
    if(*b == 0){
        printf("錯誤：不能除以 0\n");
        *temp = 0; // 避免垃圾值
    } else {
        *temp = *a / *b;
    }
}

int main(){
    float x;
    float y;
    float ans;
    char op;

    puts("輸入兩個數值");
    scanf("%f",&x);
    scanf("%f",&y);// **注意 %c 前面有個空白，這是為了吃掉上一行的 Enter 鍵**
    puts("輸入要做的運算");
    scanf(" %c",&op);
    if (op == '+')
    {
        add(&x,&y,&ans);
        printf("答案是%.2f\n",ans);
    }
    else if (op == '-') 
    {
        sub(&x,&y,&ans);
        printf("答案是%.2f\n",ans);
    }
    else if (op == '*')
    {
        mul(&x,&y,&ans);
        printf("答案是%.2f\n",ans);
    }
    else if (op == '/')
    {
        div(&x,&y,&ans);
        printf("答案是%.2f\n",ans);
    }
    else
    {
        puts("無效的運算");
    }
}