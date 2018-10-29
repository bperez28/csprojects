#include <iostream>
#include "date_diff.h"

using namespace std;

int main()
{

    int m1;
    int d1;
    int y1;
    char c1=' ';

    cout<<"start date(mm/dd/yyyy): ";
    cin>>m1>>c1>>d1>>c1>>y1;
    cout<<endl;

    if(valid_m_d_y(m1,d1,y1,c1)){

    }
    else{
        return 0;
    }

    int m2;
    int d2;
    int y2;
    char c2=' ';

    cout<<"end date(mm/dd/yyyy): ";
    cin>>m2>>c2>>d2>>c2>>y2;
    cout<<endl;


    if(valid_m_d_y(m1,d1,y1,c1)){

    }
    else{
        return 0;
    }

    int total_date_diff;

    total_date_diff=diff_date_n_date(m1,d1,y1,m2,d2,y2);

  cout<<"date difference: "<<total_date_diff<<endl;

}
