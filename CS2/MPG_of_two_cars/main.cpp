#include <iostream>

using namespace std;
double gallon(double liters,double us_gallon);//function for liters to gallons
double mpg(double miles,double gallons);// function for miles per gallon
bool valid(double liters, double miles);// checking if inputs are valid



int main()
{
    double liters1;//first car liters
    double miles1;// first car miles
    double us_gallon;//how many gallons are in 1 liters
    double gallons1;// first car gallons
    double miles_per_g1;// first car miles per gallon
    double liters2;//second car liters
    double miles2;// second car miles
    double gallons2;// second car gallons
    double miles_per_g2;// second car miles per gallon
//inputs for first car
    cout<<"First car Liters: "<<endl;
    cin>>liters1;
    cout<<"First car miles: "<<endl;
    cin>>miles1;


    if(valid(liters1,miles1)){//if the valid fuction process
    gallons1=gallon(liters1,us_gallon);//the convertion liter to gallon

    miles_per_g1=mpg(miles1,gallons1);// the function of miles per gallon
    }
    else{// if the valid function doesnt process
        if(liters1<=0){//if liters is negative
            cout<<"invalid liters for first car"<<endl;
        }
        if(miles1<=0){// if miles is negative
           cout<<"invalid miles for first car"<<endl;
        }
        return 0;
    }
//inputs for second car
    cout<<"Second car Liters: "<<endl;
    cin>>liters2;
    cout<<"second car miles: "<<endl;
    cin>>miles2;
    if(valid(liters2,miles2)){//if the valid fuction process



    gallons2=gallon(liters2,us_gallon);//the convertion liter to gallon

    miles_per_g2=mpg(miles2,gallons2);// the function of miles per gallon
    }

    else{// if the valid function doesnt process
        if(liters2<=0){//if liters is negative
            cout<<"invalid liters for second car"<<endl;
        }
        if(miles2<=0){// if miles is negative
           cout<<"invalid miles for second car"<<endl;
        }
        return 0;
    }
    //output of first and second car mile per gallon
    cout<<"first car mpg: "<<miles_per_g1<<endl;
    cout<<"second car mpg: "<<miles_per_g2<<endl;



    cout.setf(ios::fixed);
     cout.setf(ios::showpoint);
     cout.precision(2);



    return 0;
}

double gallon(double liters, double us_gallon){//fuction for converting liters to gallons

      us_gallon=0.264172;

    return (liters*us_gallon);
}

double mpg(double miles, double gallons){//fuction for miles per gallon

    return (miles/gallons);
}
bool valid(double liters, double miles){// to check if the user input is valid
    if(liters<=0){
        return false;
    }
    if(miles<=0){
        return false;
    }
    return true;
}

