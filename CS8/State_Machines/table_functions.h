#ifndef TABLE_FUNCTIONS_H
#define TABLE_FUNCTIONS_H
#include <iostream>
#include <cstdlib>

using namespace std;
const int MAX_COLUMNS=70;//count from 0
const int MAX_ROWS=20;//count from 0

class table_functions
{
public:


//    int state_array[MAX_ROWS];
    int Number_starts=0;
    int Dot_starts=2;
    int Space_starts=6;
    int Alpha_starts=4;
    int Alpha_end=27;
    int Unknown=-1;

    table_functions();
    //doubles:
    //Fill all cells of the array with -1
    void init_table(int _table[][MAX_COLUMNS]);

    //Mark this state (row) with a 1 (success)
    void mark_success(int _table[][MAX_COLUMNS], int state_row);

    //Mark this state (row) with a 0 (fail)
    void mark_fail(int _table[][MAX_COLUMNS], int state_row);

    //true if state is a success state
    bool is_success(int _table[][MAX_COLUMNS], int state_row);

    int check_table(int _table[][MAX_COLUMNS], int& start_state, string& token, string buffer, int& pos);

    int check_num_table(string& token, string _buffer, int pos, int _table[][MAX_COLUMNS]);


    int check_dot_table(string& token,string buffer,int pos,int _table[][MAX_COLUMNS]);

    int check_alpha_table(string& token, string _buffer,int pos,int _table[][MAX_COLUMNS]);

    int check_alpha_table(string& token, string _buffer,int pos,int _table[][MAX_COLUMNS],int& state,int& start, int& end);

    int check_space_table(string& token,string _buffer,int pos,int _table[][MAX_COLUMNS]);

    //Mark a range of cells in the array.
    void mark_cells(int current_row, int _table[][MAX_COLUMNS], int from, int to, int next_row);

    //Mark columns represented by the string columns[] for this row
    void mark_cells(int row, int _table[][MAX_COLUMNS], char c_s, char c_e, int state);

    //Mark this row and column
    void mark_cell(int row, int table[][MAX_COLUMNS], int column, int state);

    //This can realistically be used on a small table
    void print_table(int _table[][MAX_COLUMNS]);


    //show string s and mark this position on the string:
    //hello world   pos: 7
    //      ^
    void show_string(string s, int _pos);
};

#endif // TABLE_FUNCTIONS_H
