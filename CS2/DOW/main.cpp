#include <iostream>
#include "dow_functions.h"

using namespace std;

int main()
{
    int m;
    int d;
    int y;
    char s;

    cout<<endl<<"Date(mm/dd/yyyy): ";
    cin>>m>>s>>d>>s>>y;

    if(valid_m_d_y(m,d,y)){

    }
    else{
        return 0;
    }

    int day_of_week=dow(m,d,y);
    display_Dow(day_of_week);

}
