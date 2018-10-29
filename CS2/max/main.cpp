#include <iostream>

using namespace std;

int Max(int num1, int num2);//function for two variables
int  Max(int num1, int num2, int num3);//fuction for three variables

int main()
{
    cout<<endl<<"------------------------------------------"<<endl;//spacing

    int num1;//first number inputed by user
    int num2;//second number inputed by user
    int num3;//third number inputed by user
    char c;//comma

//output
    cout<<endl<<"numbers(ex:num,num,num): "<<endl;
    //input by user
    cin>>num1>>c>>num2>>c>>num3;

//output the end result
   cout<<"Max= "<<Max(num1,num2,num3)<<endl;

    return 0;
}

int Max(int num1, int num2){//function for two variable
    if(num1<num2){
        return num2;//if num2 is greater than num1
    }
    return num1;//if num1 is greater than num2
}
int Max(int num1, int num2, int num3){//fuction for three variables
    int set1;
    set1=Max(num1,num2);// the result of the function of two variables
    int set2;
    set2=(Max(set1,num3));//the result of the two variables compare to the third number

return set2;//the max of three variables

}
