#include <stdio.h>
#include <stdlib.h>
#include "Mathematics.h"


int main()
{
    int m;
    float x,y,z;
    while(1){
            printf("1-x+y\n2-x-y\n3-x*y\n4-x/y\n5-Sin(x)\n6-Cos(x)\n7-Tan(x)\n8-x raised to the power of y\n9-The yth root of x\n10-ln(x)\n12-The log of x to the base y\n13-Factorial(x)\n11-Exit\n\nEnter the number of desired operation: ");
            scanf("%d",&m);
        if(m==11){
            return 0;
        }
        else{
            switch(m){

                case(1):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    printf("Enter y: ");
                    scanf("%f",&y);
                    z=Sum(x,y);
                    printf("x+y = %f\n\n",z);
                    break ;

                case(2):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    printf("Enter y: ");
                    scanf("%f",&y);
                    z=Sub(x,y);
                    printf("x-y = %f\n\n",z);
                    break;

                case(3):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    printf("Enter y: ");
                    scanf("%f",&y);
                    z=Mult(x,y);
                    printf("x*y = %f\n\n",z);
                    break;

                case(4):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    printf("Enter y: ");
                    scanf("%f",&y);
                    z=Div(x,y);
                    printf("x/y = %f\n\n",z);
                    break;

                case(5):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    z=Sin(x);
                    printf("Sin(x) = %f\n\n",z);
                    break;

                case(6):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    z=Cos(x);
                    printf("Cos(x) = %f\n\n",z);
                    break;

                case(7):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    z=Tan(x);
                    printf("Tan(x) = %f\n\n",z);
                    break;

                case(8):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    printf("Enter y: ");
                    scanf("%f",&y);
                    z=Exp(x,y);
                    printf("x raised to the power of y= %f\n\n",z);
                    break;

                case(9):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    printf("Enter y: ");
                    scanf("%f",&y);
                    z=Root(x,y);
                    printf("The yth root of x= %f\n\n",z);
                    break;

                case(10):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    z=Ln(x);
                    printf("ln(x) = %f\n\n",z);
                    break;

               case(12):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    float w = Ln(x);
                    printf("Enter y: ");
                    scanf("%f",&y);
                    float q = Ln(y) ;
                    printf("The log of x to the base y= %f\n\n",w/q);
                    break;

                case(13):
                    printf("\nEnter x: ");
                    scanf("%f",&x);
                    z=Fac(x);
                    printf("Factorial(x) = %f\n\n",z);
                    break;

                ;

            }
        }
    }
    return 0;
}
