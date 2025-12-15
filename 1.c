#include <stdio.h>

// 這是定義一個函式，接收兩個整數的「地址」
void swap(int a, int b) {
    int temp = a; // 把 a 指向的值先存起來
    a = b;       // 把 b 指向的值塞給 a
    b = temp;     // 把暫存的值塞給 b
}

int main() {
    int x = 10, y = 20;
    printf("交換前: x=%d, y=%d\n", x, y);
    
    swap(x, y); // 傳入 x 和 y 的地址
    
    printf("交換後: x=%d, y=%d\n", x, y);
    return 0;
}