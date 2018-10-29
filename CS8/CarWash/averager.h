#ifndef AVERAGER_H
#define AVERAGER_H

template<class t>
class averager
{

private:
    //keep track of all item
    t total_item;
public:
    //items that have been added
    int index=0;
    //adds and divided by index
  t avg(t item);
  //returns average
  t get_avg();
  //returns index
  int get_index();
};

//adds to total and divided by index
template<class t>
t averager<t>::avg(t item){
      total_item=item+total_item;
      index++;
      return total_item/index;
  }
//returns average
template<class t>
  t averager<t>::get_avg(){
      return total_item/index;
  }
   //returns index
template<class t>
    int averager<t>::get_index(){
        return index;
    }

#endif // AVERAGER_H
