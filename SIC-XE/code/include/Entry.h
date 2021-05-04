#ifndef ENTRY_H
#define ENTRY_H
#include <string>
#include<cstring>

using namespace std;



class Entry
{
    public:
    int loc ;
    string label , op_code , operand ,comment,error,ObjectCode;
        Entry();
        Entry(int x , string a , string b , string c , string d,string e, string o);
        virtual ~Entry();
    protected:
    private:
};

#endif // ENTRY_H
