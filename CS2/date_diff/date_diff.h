#ifndef DATE_DIFF_H
#define DATE_DIFF_H

int m_d_Lswitch(int m, int d);

int m_d_switch(int m, int d);

int m_d_ony_to_days(int m, int d, int y);

bool valid_d(int d,int m, int y);

bool valid_m(int m);

bool valid_y(int y);

bool valid_colon(char c);

bool valid_m_d_y(int m, int d, int y, char c);

bool leap_y(int y);

//bool valid_numbers(int n);

int  diff_date_n_date(int m1, int d1,int y1,int m2, int d2, int y2);

int days_to_m_d_y(int& m,int& d,int& y);

int days_to_years(int& d);

void y_rday_to_m(int y, int& n, int& m);

void m_rday_to_day(int m, int& d, int y);

char display_date(int m, int d, int y);

int display_padded_int(int number);

int m_d_y_to_days(int m, int d, int y );


#endif // DATE_DIFF_H
