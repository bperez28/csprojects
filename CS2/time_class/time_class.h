#ifndef TIME_CLASS_H
#define TIME_CLASS_H


class time_class
{
public:
    time_class();
    time_class(min,hr,ap);
    time_class(hr,min);
    int time_diff();
    int add_time();
    int sub_time();

private:
    int min;
    int hr;
    char ap;


};

#endif // TIME_CLASS_H
