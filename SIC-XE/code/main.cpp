#include <fstream>
#include <string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include "Utilities.h"
#include<math.h>
#define INF 1000000000
#define MOD  1000000007
#define MAX 100000

using namespace std;
Utilities u;

int main()
{
    u.fillingMap();
    string inputFile;
    int choice;
    do
    {
        cout<<"For fixed assembly choose 0 for free assembly choose 1:"<<endl;
        cin>>choice;
    }
    while(choice!=0&&choice!=1);

    cout<<"Please enter the input file"<<endl;
    cin>>inputFile;
    freopen("output.txt","w",stdout);

    ifstream code;
    code.open(inputFile.c_str());

    string prev="" ;
    string next="";
    while(getline(code,next))
    {
        if(u.checkSpace(next))
        {
            if(prev!="")
                u.labtable(next);
            prev=next;
        }
    }
    code.close();
    code.open(inputFile.c_str());
    string prev2="" ;
    string next2="";

    while(getline(code,next2))
    {
        if(u.checkSpace(next2))
        {
            if(prev2!="")
                if(choice==0)
                    u.parse_sic(prev2);
                else
                    u.parse(prev2);
            prev2=next2;
        }
    }
    u.checkEndLine(prev2);
    u.objectCode();
    code.close();
   // if(u.error1)
    //{
       // u.objectCode();
        printf("%5s%20s%20s%20s%30s%30s%30s             ","LineNo","Address","Label","Op-code","Operand","Comment","ObjectCode");
        //printf("%s","ObjectCode");
        printf("\n");

        for(int i=0; i<u.table.size(); i++)
        {
            string location="";
            char buffer [33];
            if(u.table[i].loc!=-1)
            {
                itoa (u.table[i].loc,buffer,16);
                location=buffer;
            }

            printf("%5d%20s%20s%20s%30s%30s            ",i,location.c_str(),u.table[i].label.c_str(),u.table[i].op_code.c_str(),u.table[i].operand.c_str(),u.table[i].comment.c_str());
            if(u.table[i].ObjectCode!=""&&u.table[i].error=="")
             printf("%20s",u.table[i].ObjectCode.c_str());
                printf("\n");
            if(u.table[i].error!="")
                printf("                                            %s\n",u.table[i].error.c_str());
        }
   // }
    if(!u.error1)
    {
        //error of pass1
        printf("                     *********************pass1 errors********************\n\n");

        for(int i=0; i<u.table.size(); i++)
        {
            if(u.table[i].error!="")
                printf("line number : %d ,error: %s\n",i,u.table[i].error.c_str());
        }
    }
    else
    {
        //error of pass2
        printf("                     *********************pass2 errors********************\n\n");

        for(int i=0; i<u.table.size(); i++)
        {
            if(u.table[i].error!="")
                printf("line number : %d ,error: %s\n",i,u.table[i].error.c_str());
        }
    }

    if(u.error2)
    {
          //buildObjectFile();
         //generateObjectFile();
    }


    cout<<"\n\n\n\n\n"<<endl;
    cout<<"                     *********************Symbol Table********************"<<endl<<endl;
    printf("%20s             |         %20s\n","Symbol","Address");
    printf("     ****************************|*******************************\n");
    typedef map<string, int>::const_iterator MapIterator;
    for (MapIterator iter = u.symbolTable.begin(); iter !=u.symbolTable.end(); iter++)
    {
        char buffer [33];

        itoa (iter->second,buffer,16);

        printf("%20s             |         %20s\n",iter->first.c_str(),buffer);
    }


    u.buildObjectFile();
    u.generateObjectFile();


    return 0;
}

