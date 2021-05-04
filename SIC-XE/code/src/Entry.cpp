#include "Entry.h"


Entry::Entry()
{
    //ctor
    loc=0;
    label=op_code=operand=comment=error=ObjectCode="";
}

Entry::Entry(int x , string a , string b , string c , string d,string e, string o)
{
    loc = x;
    label=a, op_code=b, operand=c ,comment=d,error=e, ObjectCode =o;
}

Entry::~Entry()
{
    //dtor
}

