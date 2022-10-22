
#include <stdio.h>

int sum_product(int *num1, int *num2){
    int sum = *num1 + *num2;
    *num2 = (*num1)*(*num2);
      *num1 = sum;
    
} 

int main(){
    int num1 = 10, num2 = 5;
    sum_product(&num1, &num2);
    printf("sum: %d and product: %d", num1, num2);
    return 0;
}


