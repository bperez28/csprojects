#include <iostream>

using namespace std;

int Abs(int num);//the fuction if number is a int
double Abs(double num);//the fuction if number is a double
float Abs(float num);//the fuction if number is a float
long Abs(long num);//the fuction if number is a long



int main()
{
    int num(-2);
    double d_num(2.2);
    float f_num(-2.222);
    long l_num(-22222222);
    int abs_num;


//output of result of function

    cout<<"int Abs(int num)= "<<Abs(num)<<endl;//int fuction result

    cout<<"double Abs(double num)= "<<Abs(d_num)<<endl;//double fuction result

    cout<<"float Abs(float num)= "<<Abs(f_num)<<endl;//float fuction result

    cout<<"long Abs(long num)= "<<Abs(l_num)<<endl;//long fuction result




    return 0;
}

int Abs(int num){//the fuction if Abs is a int
       if(num>0){
           return num;
        }
       else{
           return (num*-1);
       }
   }

double Abs(double d_num){//the fuction if Abs is a double
       if(d_num>0){
           return d_num;
        }
       else{
           return (d_num*-1);
       }
   }
float Abs(float f_num){//the fuction if Abs is a float
       if(f_num>0){
           return f_num;
        }
       else{
           return (f_num*-1);
       }
   }
long Abs(long l_num){//the fuction if Abs is a long
       if(l_num>0){
           return l_num;
        }
       else{
           return (l_num*-1);
       }
   }


