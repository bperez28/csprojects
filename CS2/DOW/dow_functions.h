#ifndef DOW_FUNCTIONS_H
#define DOW_FUNCTIONS_H




int m_d_ony_to_days(int m, int d, int y);

bool valid_d(int d,int m, int y);

bool valid_m(int m);

bool valid_y(int y);

bool valid_m_d_y(int m, int d, int y);

bool leap_y(int y);

bool valid_numbers(int n);

int add_date_n_days(int m, int d,int y,int n);

int days_to_years(int& d);

void y_rday_to_m(int y, int& n, int& m);

void m_rday_to_day(int m, int& d, int y);

char display_date(int m, int d, int y);

int display_padded_int(int number);

int m_d_y_to_days(int m, int d, int y );

int display_Dow(int n);

int dow(int m, int d, int y);


#endif // DOW_FUNCTIONS_H
