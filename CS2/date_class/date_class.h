#ifndef DATE_CLASS_H
#define DATE_CLASS_H


class date_class
{
public:
  void set(const int& m,const int& d,const int& y);
  //holds the three variables
    date_class();
    //empty
    date_class add_date(const int &n) const;
    //adds the dates
    int diff_date(const date_class &d2) const;
    //subtacts both dates to get difference
    date_class sub_date(const int& n) const;
    //subtracts days from dates
    void dow() const;
    //date of the week
    date_class d_input();
    //user input when chosen to change
    void d_output() const;
    //out put for date
    void num_output();
    //out put for number (date difference)
    friend date_class operator -(const date_class & date, const int &n );
    //operator to subtract days to date
    friend int operator -(const date_class & date, const date_class &n );
    //operator to subtract a date to another date
    friend date_class operator +(const date_class &date,const int & n );
    //operator to add days to date


private:
int _m;
//month
int _d;
//days
int _y;
//year
};
int n_input();
//number input
char get_choice();
//ask user which date to change or number to change (input)
void report(const date_class &d1, const date_class &d2, const int &);
//does the math and prints out result

#endif // DATE_CLASS_H
