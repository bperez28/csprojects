#ifndef USER_INPUT_H
#define USER_INPUT_H


class user_input
{
public:
    user_input();

    char get_user_input();
    char switch_input();
    void print();
private:
    char c;
};

#endif // USER_INPUT_H
