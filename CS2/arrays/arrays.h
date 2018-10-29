#ifndef ARRAYS_H
#define ARRAYS_H


class arrays
{
public:
    arrays();
};

void _copy_array(int old[], int _new[], int &num_used);
void _shift_left(int a[], int &numused, int pos);
void _shift_right(int a[], int &numused, int pos);
int _search(int a[], int numused, int key);
void _rev(int a[], int numused);
int _search_rev(int a[], int numused,int key);
void _print_array(int a[], int numused);
void _print_array_rev(int a[], int numused);
void _append_array(int a[], int &numused, int iteam);
void _insert_on_pos(int a[], int &numused, int pos, int iteam);
void _insert_after_array(int a[],int &numused,int pos, int iteam);
void _insert_before_array(int a[], int &numused, int pos, int iteam);
void _asending_array(int a[], int &numused);
void _delete_array(int a[], int &numused, int pos);
void _ge(int a[], int &numused, int iteam);
void _swap_array(int a[], int &numused, int pos1, int pos2);
void _delete_duplicate(int a[], int &numused);
void _print_curser(int a[], int  &numused, int pos);
int _input_for_key(int pos);
void _choice_print_curser(int a[], int numused);
void _init_1d(int numused[],int m_row);
#endif // ARRAYS_H
