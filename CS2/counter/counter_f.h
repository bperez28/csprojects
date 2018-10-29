#ifndef COUNTER_F_H
#define COUNTER_F_H


class counter_f
{
public:

    int input();
    int inc();
    int dec();
    char exist();
    int reset();
    void print();
    void negative();

private:

int r;
char i=' ';

};
char choice();
char negative_choice();

#endif // COUNTER_F_H
