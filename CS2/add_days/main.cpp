#include <iostream>
#include "my_dates.h"

using namespace std;

int main()
{
    int m;
    int d;
    int y;
    char s;

    cout<<"Date(mm/dd/yyyy): ";
    cin>>m>>s>>d>>s>>y;

    if(valid_m_d_y(m,d,y)){

    }
    else{
        return 0;
    }


    int n;

    cout<<"days to add: ";
    cin>>n;

    if(valid_numbers(n)){

    }
    else{
        return 0;
    }


    int new_y;
    int new_m;
    int t_days;

    t_days=add_date_n_days(m,d,y,n);

    new_y=days_to_years(t_days);

    y_rday_to_m(new_y,t_days,new_m);

    display_date(new_m,t_days,new_y);


}
