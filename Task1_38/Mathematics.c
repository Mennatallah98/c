#include <stdio.h>
#include <stdlib.h>
#include "Mathematics.h"

long double pi = 3.14159265359;
long double rad = 3.14159265359/180;
double e = 2.71828;



float Sum(float a,float b){
    float result;
    result = a+b;
    return result;
}
float Sub(float a,float b){
    float result;
    result = a-b;
    return result;
}
float Mult(float a,float b){
    float result;
    result = a*b;
    return result;
}
float Div(float a,float b){
    float result;
    result = a/b;
    return result;
}
float Fac(float a){
    int n ;
    float result;
    n=a;
    if (n==a){
            if(a==0){
            result=1;}
    else{
        int i;
        result =1;
        for(i=a;i>0;i--){
            result=result*i;
        }
    }
    }
        else{
           /* long double fac2=0.5*Root(pi,2);
        if(a==0.5){
            result = fac2;
        }
        else{
            result=a;
        while(a > 0.5){
            result = result*a;
            a--;
        }
        result = result*fac2;
        }*/

       int i;
                result=0;
                for(i=0;i<5;i++){

                        result=result+((Exp(e,-i))*(Exp(i,a)));
                }

    return result;
    }
}

float Root(float a, float b){

    float result;
             float temp;
             result= a/b;
             temp = 0;
            int c= b-1;
            while(result != temp){
                    temp=result;
                    result=(a/(Exp(temp,c))+c*temp)/b;
                    }


    return result;
}
float Exp(float a, float b){
    int n;
    float result;
    n=b;
    if(n==b)
    {
        result=1;
        if(b>0)
        {
            int i;
            for(i=1;i<=b;i++){
            result = result*a;
            }
        }
        else if (b==0)
        {
            result=1;
        }
        else if(b<0)
        {
           b=abs(b);
           int i;
            for(i=1;i<=b;i++){
            result = result*a;
            }
            result=1/result;
        }
    }
    else
       {
           result=0;
        float temp = b*Ln(a);
        int i;
        for(i=0;i<20;i++){
            result=result+(Exp(temp,i)/Fac(i));
        }


       }
    return result;
}
float Ln(float a){
    float result;
    int i;
    float d = ((a-1)/(a+1));
    for(i=1;i<=100;i++)
    {
        int c= 2*i-1;
        result=result+(2*(Exp(d,c)/c));
    }
    return result;
}
float Sin(float a){
   float result=0;
   float angle = a* rad;
    int i;
    for(i=0;i<=6;i++)
    {
        int c= 2*i+1;
        result=result+(((Exp(-1,i))*(Exp(angle,c)))/(Fac(c)));
    }
    return result;
}
float Cos(float a){
    float result=0;
   float angle = a* rad;
    int i;
    for(i=0;i<=6;i++)
    {
        int c= 2*i;
        result=result+(((Exp(-1,i))*(Exp(angle,c)))/(Fac(c)));
    }
    return result;
}
float Tan(float a){
    while(a<0)
    {
        a=a+360;
    }
    float result;
    result = Sin(a)/Cos(a);
    return result;
}
