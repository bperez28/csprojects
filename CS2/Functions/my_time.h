#ifndef MY_TIME_H
#define MY_TIME_H

int time(int hr, int min);//fuction to convert time to min after 12am

bool valid_ampm(char ap);//fuction to check if user didnt put any other charater for a p

bool ampm(char ap);//fuction to check if its a if not than its p

int time_diff(int time1, int time2);//the difference in min fuction

bool hour(int hr);//fuction to check if hours are valid

bool minutes(int min);//fuction to check if min are valid

bool valid_colon(char colon);//fuction to only manage :

char time_display(int hr, int min, char ap);//print function

int display_padded_int(int min);//spaces in printed fuction

int time_after_12(int hr, int min);// convert time to min after 12 pm

int time_add(int hr,int min, char ap,int min2);//add time to a min

int valid_time(int hr, char colon, int min, char ap); // all time validation

#endif // MY_TIME_H
