#ifndef MYGOL_H
#define MYGOL_H

 const int max_col=100;
 const int max_row=10;

class mygol
{
public:

    void set(int row, int col);
    int check_around_8(int a[][max_col]);
    void print_2d_array(int a[][max_col]);
    void copy_new_gen(int a[][max_col]);
    void if_statements(int a[][max_col],int &c);
    void all();
    void load(int a[][max_col]);



private:
   int _r=0;
   int _c=0;
   int m_row=10;
   int m_col=10;



};

int next(int &row, int &col, int m_row, int m_col);
void _init_two_d(int two_d[][max_col], int m_row, int m_col);

#endif // MYGOL_H
