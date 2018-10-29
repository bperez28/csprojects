#ifndef MY_NUM_BASE_H
#define MY_NUM_BASE_H


class My_num_base
{
public:
    My_num_base();
};

void add(char a[], char b[], char result[], int base);
void _add_pad_rev(char a[],int i);
void convert_base(char a, int &n, int &r, int base);
void strlength(char a[], int i);
int convert_base16(char a);
void convert_base2(char a, int& n, int & r, int base);
void convert_base10(char a, int& n, int & r, int base);
void convert_base16(char a, int& n, int & r, int base);

#endif // MY_NUM_BASE_H
