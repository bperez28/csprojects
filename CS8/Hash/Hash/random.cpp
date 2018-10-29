#include "random.h"

Random::Random()
{

}
 int Random::GetNext(int from ,int to){
     return from+rand()%to;
 }
