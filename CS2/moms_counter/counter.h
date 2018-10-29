#ifndef COUNTER_H
#define COUNTER_H


class counter
{
public:
    counter();
    double  ones();
    double five();
    double ten();
    double f();
    double  th();
     double cent();
     double fivecent();
     double tcent();
     double fcent();
    void  print();

private:
    double n;
};

char get_choice();

#endif // COUNTER_H
