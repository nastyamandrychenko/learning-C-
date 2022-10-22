
#include <stdio.h>

int search(int *a, int number)
{
   int i;
    for(i=0; i<10; i++)
    {
        if(a[i]==number)
        {
             return 1;		 
        }
    }
    
      
};

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,11};
    int number = 5;
    
    
    
    if (search(a,number) == 1)
    {
        
    printf("\nfound %d",number);
    }
    else
    {
       printf("\nnot found");
    }
    return 0;
}


