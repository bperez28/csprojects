#ifndef MY_DATES_LIBRARY_H
#define MY_DATES_LIBRARY_H

//class date_l
//{
//public:
//    date_l date(int m, int d, int y);
//    date_l add(int n);
//    date_l


//};

int m_d_ony_to_days(int m, int d, int y);
int  c_diff_date_n_date(int m1, int d1, int y1, int m2, int d2, int y2);

void  c_add_date_n_days(int m, int d, int y, int &m1, int &d2, int &y3, int n);

int date_input(int& m, int& d, int& y);

int num_input();

bool valid_d(int d,int m, int y);

bool valid_m(int m);

bool valid_y(int y);

bool valid_m_d_y(int m, int d, int y, char c);

bool valid_colon(char c);

bool leap_y(int y);

bool valid_numbers(int n);

int add_date_n_days(int m, int d,int y, const int& n);

int add_days();

int  sub_date_n_days(int m, int d,int y,int n);

void  c_sub_date_n_days(int m, int d,int y,int& m1, int& d1,int& y1,int n);

int sub_days();

int  next_date_plus_1(int m, int d,int y);

//void  next_date_plus_1(int& m, int& d,int& y);

int next_day();

void n_output(int n);

void display_Dow(int n);

int dow(int m, int d, int y);

int c_dow(const int& m, const int& d, const int& y);

int DOW();

int  diff_date_n_date(int m1, int d1,int y1, int m2, int d2, int y2);

int date_diff();

int days_to_years(int& d);

void y_rday_to_m(int y, int& n, int& m);

void m_rday_to_day(int m, int& d, int y);

char display_date(int m, int d, int y);

int display_padded_int(int number);

int m_d_y_to_days(int m, int d, int y );


#endif // MY_DATES_LIBRARY_H
