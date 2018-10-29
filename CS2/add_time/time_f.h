#ifndef TIME_F_H
#define TIME_F_H



//time validation fuction
bool valid_ampm(char ap);//fuction to check if user didnt put any other charater for a p

bool valid_hour(int hr);//fuction to check if hours are valid

bool valid_minutes(int min);//fuction to check if min are valid

bool valid_colon(char colon);//fuction to only manage :

 bool valid_military_hour(int n);

 bool valid_std_time(int hr, char colon, int min, char ap); // all time validation

 bool valid_military_time(int hr1, char colon1, int min1);


//time displays
char time_display(int hr, int min, char ap);//print function

int display_padded_int(int min);//spaces in printed fuction

char military_time_display(int hr, int min);


//military/std time conversion to time
 int military_time_to_min(int hr,int min);

  int time_to_min(int hr, int min, char ap);//fuction to convert time to min after 12am


// std time to miltary conversion
 void std_time_to_military(int &hr, int min, char ap );

  bool ampm(char ap);


//military time add/sub
 int add_military_time(int hr1, int min1, int hr2, int min2);

 int military_time_diff(int hr1, int min1, int hr2, int min2, int day);



//min to time conversion

void min_to_military_time(int& hr, int& min);

int min_to_hr(int n);

int min_to_min(int n);

char add_ampm(int n);

 int hr_respect_to_std(int n);

 void min_to_time(int& new_hr, int& new_min,char &new_ap);




 // to std times conversion add/sub to min
 int time_diff(int hr1, int min1, char ap1, int hr2, int min2, char ap2);//the difference in min fuctionz

 int time_add(int hr1,int min1, char ap1,int hr2,int min2, char ap2);//add time to a min(not used in program)



 // days/week fuctions (not used in program)
 void min_to_day(int& n, int& i);

 void days_week(int& day, int& week );

 int only_days_from_mins( int m);






#endif // TIME_F_H
