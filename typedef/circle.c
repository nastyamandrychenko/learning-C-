
#include <stdio.h>
#include <math.h>

typedef struct {

    float x, y, r;

}centerOfCircle;

centerOfCircle circle(centerOfCircle first,centerOfCircle second){

    float pythagorean =  sqrt(pow((first.x - second.x),2) + pow((first.y - second.y),2));

    if(pythagorean < first.r + second.r){

        printf("overlap");

    }else{

        printf("don't overlap");
        
    };

}
int main()
{
       centerOfCircle firstCircle;
       centerOfCircle secondCircle;

    printf("Enter coordinates for first circle  ");

    scanf("%f  %f %f",&firstCircle.x,&firstCircle.y,&firstCircle.r);

    printf("Enter coordinates for second circle  ");

    scanf("%f  %f %f",&secondCircle.x,&secondCircle.y,&secondCircle.r);

    circle(firstCircle,secondCircle);


    return 0;
}
