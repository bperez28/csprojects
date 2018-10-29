#ifndef GOL_H
#define GOL_H
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <gol.h>
#include <iostream>
using namespace std;
using namespace sf;



class gol
{
public:

   void set(int row, int col);
   void check_around_8(int a[][max_col]);
   void print_2d_array(int a[][max_col]);
   void copy_new_gen(int a[][max_col]);
   void if_statements(int a[][max_col],int &c);
   void all();
   void get(int &mrow, int &mcol);
   void Events();
   void pattern(int a[][max_col]);
   bool _load(int a[][max_col]);
   bool _save(int a[][max_col]);
   void _random_(int a[][max_col]);


private:
  int _r;
  int _c;

};

void next(int &row, int &col, int m_row, int m_col);
void _init_two_d(int two_d[][max_col], int m_row, int m_col);
char getchoice();
void _copy_2d(int a[][max_col], int b[][max_col]);
int _count_n(int a[][max_col],int _r, int _c);



#endif // GOL_H
