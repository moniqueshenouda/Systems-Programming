#include "Utilities.h"
#include<string>
#include<iostream>
#include <algorithm>
#include <bits/stdc++.h>


using namespace std;
int labelch=0;
int labeleq=0;
string startlbl="";
vector<pair<string, int > >objectFile;
vector<int >objectFileFormat4;
string programName;
int startAdress;
string baseadd="";



Utilities::Utilities()
{
    //ctor
}
string Utilities::Comment(vector<string>a)
{
    string temp="";
    for(int i=0; i<a.size(); i++)
        temp+=a[i]+" ";
    return temp;
}
int Utilities::checkByte(string a)
{

    if(a.size()<4)
        return -1;

    if(a[0]=='x'&&a[1]=='\''&&a[a.size()-1]=='\'')
    {
        if((a.size()-3)%2==1)
            return -1;
        for(int i=2; i<a.size()-1; i++)
        {
            if((a[i]>='0'&&a[i]<='9')||(a[i]>='a'&&a[i]<='f'))
            {

            }
            else
                return -2;
        }
        return ((a.size()-3)/2);
    }
    else if(a[0]=='c'&&a[1]=='\''&&a[a.size()-1]=='\'')
    {

        return (a.size()-3);
    }
    else
        return -1;
}

bool Utilities::checkWord(string a)
{
    if(a.size()==1)
    {
        if((a[0]<'0'||a[0]>'9'))
            return false;
        return true;
    }
    if(a.size()==2&&a[1]=='-')
        return false;


    if(a[0]!='@'&&a[0]!='#'&&a[0]!='-'&&(a[0]<'0'||a[0]>'9'))
        return false;

    for(int i=1; i<a.size(); i++)
    {
        if(a[i]<'0'||a[i]>'9')
        {
            if(i==1)
            {
                if(a[1]=='-'&&(a[0]=='#'||a[0]=='@'))
                {

                }
                else
                    return false;
            }
            else
                return false;
        }
    }

    return true;
}

int Utilities::todecimal(string a)
{

    int ans=0;
    int t=a.size()-1;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]=='A'||a[i]=='a')
        {
            ans+=10*pow(16,t);

        }
        else if(a[i]=='B'||a[i]=='b')
        {
            ans+=11*pow(16,t);
        }
        else if(a[i]=='C'||a[i]=='c')
        {
            ans+=12*pow(16,t);
        }
        else if(a[i]=='D'||a[i]=='d')
        {
            ans+=13*pow(16,t);
        }
        else if(a[i]=='E'||a[i]=='e')
        {
            ans+=10*pow(14,t);
        }
        else if(a[i]=='F'||a[i]=='f')
        {
            ans+=10*pow(15,t);
        }
        else if(a[i]>='0'&&a[i]<='9')
        {
            ans+=(a[i]-'0')*pow(16,t);
        }
        else
            return -1;
        t--;
    }
    return ans;
}

int Utilities::Tointeger(string str)
{
    int res = 0 ;

    for(int i = 0 ; i < str.size() ; i++)
    {
        if(str[i]<'0'||str[i]>'9')
            return -1;
        res =  res*10 + (int)(str[i]-'0');
    }

    return res;
}
string Utilities::Tolower(string str)
{
    for(int i=0 ; i <str.size() ; i++)
        str[i]=tolower(str[i]);

    return str;
}
int Utilities:: check_operand(string opcode,string oper)
{
    int error;

    if(opcode.compare("tixr")==0)
    {

        if(oper.compare("a")==0||oper.compare("s")==0||oper.compare("t")==0||oper.compare("x")==0
                ||oper.compare("b")==0||oper.compare("l")==0)
        {
            error=0;
            return error;
        }
        else
        {
            if(oper.size()==1)
                error=1;
            else
                error=2;
            return error;
        }

    }

    else if(opcode.compare("addr")==0||opcode.compare("subr")==0||opcode.compare("compr")==0||opcode.compare("rmo")==0)
    {

        if(oper.size()==3)
        {
            if((oper[0]=='a'||oper[0]=='s'||oper[0]=='t'||oper[0]=='x'||oper[0]=='b'||oper[0]=='l')&&
                    oper[1]==','&&(oper[2]=='a'||oper[2]=='s'||oper[2]=='t'||oper[2]=='x'||oper[0]=='b'
                                   ||oper[0]=='l'))
            {

                error=0;
                return error;
            }
            else
            {

                error=1;
                return error;
            }
        }
        else
        {

            error=2;
            return error;
        }

    }
    else
    {


        if(oper[0]=='#'||oper[0]=='@')
        {


            if(oper.size()>=2&&oper[oper.size()-1]=='x'&&oper[oper.size()-2]==',')
            {
                error=2;
                return error;
            }
            else
            {
                if(oper[0]=='#')
                {
                    int countop=0;
                    oper.erase(std::remove(oper.begin(), oper.end(),'#'), oper.end());
                    for(int i=0; i<oper.size(); i++)
                    {
                        if(oper[i]>='0'&&oper[i]<='9')
                            countop++;
                    }

                    if(countop==oper.size())
                    {
                        error=0;
                        return error;
                    }
                }

                else if(oper[0]=='@')
                    oper.erase(std::remove(oper.begin(), oper.end(),'@'), oper.end());
                for(int i=0; i<label.size(); i++)
                {

                    if(oper.compare(label[i])==0)
                    {

                        error=0;
                        break;
                    }
                    else
                    {
                        error=3;

                    }

                }
                return error;
            }
        }
        else
        {
            if((opcode.compare("resw")!=0)&&(opcode.compare("resb")!=0)&&(opcode.compare("base")!=0)&&(opcode.compare("byte")!=0)&&(opcode.compare("word")!=0)&&(opcode.compare("equ")!=0)&&opcode.compare("org")!=0)
            {

                int comma;
                for(int i=0; i<oper.size(); i++)
                {
                    if(oper[i]==',')
                    {
                        comma=1;
                        break;
                    }
                    else
                        comma=0;
                }
                if(comma==1)
                {

                    if(oper[oper.size()-1]=='x'&&oper[oper.size()-2]==',')
                    {
                        oper.erase(std::remove(oper.begin(), oper.end(),'x'), oper.end());
                        oper.erase(std::remove(oper.begin(), oper.end(),','), oper.end());
                    }
                    else
                    {
                        error=2;
                        return error;
                    }
                }
                int countop2=0;
                for(int i=0; i<oper.size(); i++)
                {
                    if(oper[i]>='0'&&oper[i]<='9')
                        countop2++;
                }

                if(countop2==oper.size()&&oper[0]!='#')
                {
                    error=2;
                    return error;
                }
                else if((oper.find("+")!=-1)||(oper.find("/")!=-1)||(oper.find("*")!=-1)||(oper.find("-")!=-1))
                {

                    int cot=0;
                    int c=0;
                    string opr;
                    for( int n=0; n<oper.size(); n++)
                    {
                        if(oper[n]=='+'||oper[n]=='-'||oper[n]=='*'||oper[n]=='/')
                        {
                            opr+=oper[n];
                            oper[n]='.';
                            c++;
                        }
                    }

                    vector<string> s;
                    tokenize(oper, '.', s);
                    int j,m,i;
                    for(j=0; j<s.size(); j++)
                    {

                        for(i=0; i<label.size(); i++)
                        {

                            if(s[j].compare(label[i])==0||is_number(s[j]))
                            {

                                error=0;
                                break;
                            }
                            else
                            {
                                error=3;

                            }

                        }

                    }
                    return error;

                }

                else
                {
                    for(int i=0; i<label.size(); i++)
                    {

                        if(oper.compare(label[i])==0)
                        {

                            error=0;
                            break;
                        }
                        else
                        {
                            error=3;

                        }

                    }
                    return error;
                }

            }

        }


    }
}
int Utilities::validateOpcode(string a, int check)
{

    int found=0,i;
    int error0=1;
    int error1=2;
    int error2=3;
    int place=-1;

    for( i=0; i<opc.size(); i++)
    {
        if(a.compare(opc[i])==0)
        {
            found=1;
            place=i;
            break;

        }
    }
    if(found==1&&a!="org"&&a!="equ"&&a!="base")
    {
        if(check==1&&n2[i].compare("4")==0||check==0)

            return error0;
        else
            return error2;
    }
    else if(a=="org"||a=="equ"||a=="base")
        return 6;
    else
    {
        return error1;

    }


}

int Utilities::byte(string a)
{
    int p;
    if (a[0]=='+')
    {
        a.erase(std::remove(a.begin(), a.end(),'+'), a.end());

        for(int i=0; i<opc.size(); i++)
        {
            if(a.compare(opc[i])==0)
            {
                p=i;
                break;
            }

        }
        return stoi(n2[p]);
    }
    else
    {
        for(int i=0; i<opc.size(); i++)
        {
            if(a.compare(opc[i])==0)
            {
                p=i;
                break;
            }
        }
        return stoi(n1[p]);

    }
}
bool Utilities::duplicateLable(string a)
{
    if( symbolTable.find(a ) == symbolTable.end() )
        return false;
    return true;
}
void Utilities::oneWord ( vector<string> line,vector<string> comment,int byt)
{

    string temp=Comment(comment);


    table.push_back(Entry(CURRENTADRESS,"",line[0],"",temp,"",""));
    CURRENTADRESS+=byt;

}
void Utilities::twoWord ( vector<string> line,int typeByte,vector<string>comment)
{

    string temp=Comment(comment);

    table.push_back(Entry(CURRENTADRESS,"",line[0],line[1],temp,"",""));
    if(typeByte!=6)
        CURRENTADRESS+=typeByte;
    else if(typeByte==6)
    {
        if(line[0].compare("org")==0)
        {
            int org=checkOrg(line[1]);
            if(org==-1)
            {

                table[table.size()-1].error="****Error: Invalid Operand";

            }

            CURRENTADRESS=org;
        }
        else if(line[0].compare("base")==0)
        {
            int found =0;

            for(int i=0; i<label.size(); i++)
            {
                if(line[1].compare(label[i])==0)
                {
                    baseadd=line[1];
                    found=1;
                    break;
                }
            }
            if(found==0)
                table[table.size()-1].error="****Error: Symbol not found";
        }

    }

}

void Utilities::threeWord ( vector<string> line,int typeByte,vector<string>comment)
{
    string temp=Comment(comment);
    symbolTable[line[0]]=CURRENTADRESS;
    table.push_back(Entry(CURRENTADRESS,line[0],line[1],line[2],temp,"",""));


    if(typeByte!=5)
        CURRENTADRESS+=typeByte;
    else
    {
        if(line[1]=="equ")
        {
            int adress=checkEqu(line[2],line[0]);
            if(adress==-1)
            {

                table[table.size()-1].error="****Error: Invalid Operand";
            }
            else
            {
                symbolTable[line[0]]=adress;
            }

        }

        else if(line[1]=="byte")
        {
            int check=checkByte(line[2]);
            if(check!=-1&&check!=-2)
                CURRENTADRESS+=check;
            else if(check==-2)
                table[table.size()-1].error="****Error: not a hexadecimal string";
            else
                table[table.size()-1].error="****Error: Invalid Operand";
        }
        else if(line[1]=="word")
        {
            if(checkWord(line[2]))
                CURRENTADRESS+=3;
            else
                table[table.size()-1].error="****Error: Invalid Operand";
        }
        else if(line[1]=="resb")
        {
            int numOfByt=Tointeger(line[2]);
            if(numOfByt==-1)
            {
                table[table.size()-1].error="****Error: Invalid Operand";


            }

            else
                CURRENTADRESS+=numOfByt;
        }
        else
        {
            int numOfByt=Tointeger(line[2]);
            if(numOfByt==-1)
                table[table.size()-1].error="****Error: Invalid Operand";



            else
                CURRENTADRESS+=numOfByt*3;
        }

    }


}
int Utilities:: checkEqu(string a,string label)
{
    if(a.size()==1&&a[0]=='*')
        return CURRENTADRESS;
    int k=0;
    if(a[0]=='#'||a[0]=='@')
        k++;
    string one="";
    string two="";
    int sign=-1;
    bool flag1=true;
    bool flag2=true;
    for(int i=k; i<a.size(); i++)
    {
        if(a[i]=='-'||a[i]=='+')
        {
            if(a[i]=='+')
                sign=1;
            else
                sign=2;
        }
        else if(a[i]<'0'||a[i]>'9')
        {
            if(sign==-1)
            {
                one+=a[i];
                flag1=false;
            }
            else
            {
                flag2=false;
                two+=a[i];
            }
        }

        else
        {
            if(sign==-1)
                one+=a[i];
            else
                two+=a[i];

        }
    }
    if(one=="")
        return -1;
    if(sign!=-1&&two=="")
        return -1;

    if(flag1&&!flag2)
        return -1;
    //two integers
    if(flag1&&flag2)
    {
        if(sign==-1)
        {
            absolute[label]=true;
            return Tointeger(one);
        }
        else
            return -1;
    }
    // two words
    else
    {
        if(sign==-1)
        {
            if(symbolTable.find(one)!=symbolTable.end())
            {
                if(absolute.find(one)!=absolute.end())
                    absolute[label]=true;

                return symbolTable[one];
            }
            else
                return -1;
        }
        else
        {

            int addrs;
            if(symbolTable.find(one)!=symbolTable.end())
                addrs=symbolTable[one];
            else
                return -1;
            if(flag2==true)
            {
                if(absolute.find(one)!=absolute.end())
                    absolute[label]=true;
                if(sign==1)
                {

                    return addrs+Tointeger(two);
                }
                else
                {
                    return addrs-Tointeger(two);
                }
            }
            else
            {
                if(absolute.find(one)!=absolute.end()&&absolute.find(two)!=absolute.end())
                    absolute[label]=true;
                int addrs2;
                if(symbolTable.find(two)!=symbolTable.end())
                    addrs2=symbolTable[two];
                else
                    return -1;
                if(sign==1)
                {
                    if(absolute.find(one)==absolute.end()&&absolute.find(two)==absolute.end())
                        return -1;
                    return addrs+addrs2;
                }
                else
                {
                    return addrs-addrs2;
                }
            }
        }

    }


}

int Utilities::checkOrg(string a)
{
    cout<<a;
    if(a.size()==1&&a[0]=='*')
    {
        return CURRENTADRESS;
    }
    int k=0;
    string one="";
    string two="";
    int sign=-1;
    int c=0;
    bool flag1=true;
    bool flag2=true;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {

            one+=a[i];
            c++;
        }
    }
    if(c==a.size())
        return Tointeger(one);
    else
    {
        for(int i=0; i<label.size(); i++)
        {
            if(a.compare(label[i])==0)
                return symbolTable[a];

        }

    }

}
void Utilities::labtable(string line)
{

    string temp="";
    if(line!=""&&line[0]=='.')
    {

    }
    else
    {
        for(int i=0; i<line.length()&&i<8; i++)
        {

            if(line[i]!=' ')
            {
                temp+=line[i];
            }
        }
        if(temp!="")
        {

            if(line[0]!=' ')
            {
                label.push_back(Tolower(temp));
            }

        }
    }
}
void Utilities::parse_sic(string  line )
{
    if(line.size()>66)
    {
        table.push_back( Entry( CURRENTADRESS,"","","","","****Error: Invalid spaces in this line","") ) ;

    }

    vector<string>res;
    vector<string>comments;
    string temp="";
    bool com=false;
    bool check_spaces=false;
    bool check_spaces_l=false;
    bool check_spaces_opc=false;
    bool check_spaces_op=false;
    bool comment_field=false;
    if(line!=""&&line[0]=='.')
    {

    }
    else
    {
        for(int i=0; i<line.length()&&i<8; i++)
        {

            if(line[i]!=' ')
            {
                temp+=line[i];
            }
        }
        if(temp!="")
        {

            if(line[0]==' ')
            {
                check_spaces_l=true;
            }
            temp="";
        }
//................................

        for(int i=9; i<line.length()&&i<15; i++)
        {

            if(line[i]!=' ')
            {
                temp+=line[i];
            }
        }
        if(temp!="")
        {
            if(line[8]==' '||line[8]=='+')
            {

            }
            else
            {
                check_spaces=true;
            }

            if(line[9]==' ')
            {
                check_spaces_opc=true;
            }
            temp="";
        }
//................................

        for(int i=17; i<line.length()&&i<35; i++)
        {

            if(line[i]!=' ')
            {
                temp+=line[i];
            }
        }
        if(temp!="")
        {
            if(line[15]!=' '||line[16]!=' ')
            {
                check_spaces=true;
            }

            if(line[17]==' ')
            {
                check_spaces_op=true;
            }
            temp="";
        }

        //................................

        for(int i=35; i<line.length(); i++)
        {
            if(line[i]!=' ')
            {
                temp+=line[i];
            }
        }
        if(temp!="")
        {

            comment_field=true;
            temp="";
        }
        if(check_spaces)
        {
            table.push_back(Entry(CURRENTADRESS,"","","","","****Error: invalid spaces in this line",""));
        }
        if(check_spaces_l)
        {
            table.push_back(Entry(CURRENTADRESS,"","","","","****Error: misplaced label",""));
        }
        if(check_spaces_op)
        {
            table.push_back(Entry(CURRENTADRESS,"","","","","****Error: misplaced operand",""));
        }
        if(check_spaces_opc)
        {
            table.push_back(Entry(CURRENTADRESS,"","","","","****Error: misplaced opcode",""));
        }



    }
    temp="";

    for(int i = 0 ; i < line.size(); i++)
    {
        if(line[i]!=' ')
            temp+=line[i];

        else if(temp!="")
        {


            if(temp[0]=='.'||i>=35)
                com=true;

            if(!com)
            {
                temp=Tolower(temp);
                res.push_back(temp);
            }

            else
                comments.push_back(temp);
            temp="";



        }
    }

    if(temp!="")
    {


        if(temp[0]=='.'||comment_field)
            com=true;


        if(!com)
        {
            temp=Tolower(temp);
            res.push_back(temp);
        }

        else
            comments.push_back(temp);

    }




    if(res.size()>0&&firstEntering)
    {
        string start="";
        if(line.size()>13)
        {
            for(int i=9; i<14; i++)
            {
                start+=line[i];
            }
            start=Tolower(start);
        }

        if(res.size()==2)
            CURRENTADRESS=todecimal(res[1]);
        else if(res.size()==3)
        {
            CURRENTADRESS=todecimal(res[2]);
            startlbl=res[0];
        }
        firstEntering=false;
        if(res.size()==2&&res[0].compare("start")==0&&CURRENTADRESS!=-1&&start.compare("start")==0)
        {
            temp=Comment(comments);

            table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"",""));
        }
        else if(res.size()==3&&res[1].compare("start")==0&&CURRENTADRESS!=-1&&start.compare("start")==0)
        {
            temp=Comment(comments);

            table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"",""));
        }
        else
        {
            temp=Comment(comments);
            string lin=Comment(res);

            table.push_back(Entry(CURRENTADRESS,lin,"","",temp,"****Error: invalid start of the program",""));
        }

    }
    else if(res.size()==3)
    {

        int k,check=0;
        string p="";
        p=res[1];
        if(res[1][0]=='+')
        {
            check=1;
            p.erase(std::remove(p.begin(), p.end(),'+'), p.end());

        }
        k=validateOpcode(p,check);
        if(k==2)
        {
            temp=Comment(comments);
            if((res[1][0]>='a'&&res[1][0]<='z')||(res[1][0]>='A'&&res[1][0]<='Z'))
                table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Unrecognized OpCode",""));
            else
                table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: wrong operation prefix",""));


        }
        else if(k==3)
        {
            temp=Comment(comments);
            table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: can’t be format 4 instruction",""));
        }
        else
        {
            if(!duplicateLable(res[0]))
            {

                int r=check_operand(res[1],res[2]);
                if(r==1)
                {
                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Invalid Register address",""));

                }
                else if(r==2)
                {
                    temp=Comment(comments);
                    cout<<"here";
                    table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Invalid Operand",""));

                }
                else if(r==3)
                {
                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Symbol of operand not found",""));

                }
                else if(k==6)
                {
                    if(res[1]=="org"||res[1]=="base")
                    {
                        temp=Comment(comments);

                        table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: This instruction can't have a label",""));

                    }
                    else
                        threeWord(res,5,comments);
                }
                else
                {
                    threeWord(res,byte(res[1]),comments);
                }

            }
            else
            {
                temp=Comment(comments);
                table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Duplicate Symbol",""));

            }
        }
    }


    else if(res.size()==2)
    {

        int k,m,check=0;
        string p="",q="";
        p=res[0];
        q=res[1];
        m=validateOpcode(res[1],check);
        if(res[1][0]=='+')
        {
            check=1;
            q.erase(std::remove(q.begin(), q.end(),'+'), q.end());
            m=validateOpcode(q,check);
        }
        else
        {
            m=validateOpcode(res[1],check);
        }
        if(m==1||m==6)
        {
            temp=Comment(comments);
            table.push_back(Entry(CURRENTADRESS,res[0],res[1],"",temp,"****Error: missing operand",""));

        }
        else
        {
            if(res[0][0]=='+')
            {
                check=1;
                p.erase(std::remove(p.begin(), p.end(),'+'), p.end());

            }
            k=validateOpcode(p,check);

            if(k==2)
            {

                temp=Comment(comments);
                if((res[0][0]>='a'&&res[0][0]<='z')||(res[0][0]>='A'&&res[0][0]<='Z'))
                    table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: Unrecognized OpCode",""));
                else
                    table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: wrong operation prefix",""));

            }
            else if(k==3)
            {
                temp=Comment(comments);
                table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: can’t be format 4 instruction",""));
            }
            else
            {


                int r=check_operand(res[0],res[1]);
                if(r==1)
                {

                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: Invalid Register address",""));

                }
                else if(r==2)
                {
                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: Invalid Operand",""));

                }
                else if(r==3)
                {
                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: Symbol of operand not found",""));

                }
                else if(k==6)
                {
                    if(p=="equ")
                    {
                        temp=Comment(comments);

                        table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: This instruction must have a label",""));
                    }
                    else
                        twoWord(res,6,comments);
                }
                else
                {
                    twoWord(res,byte(res[0]),comments);
                }

            }

        }
    }

    else if(res.size()==1)
    {


        int k,check=0;
        string p="";
        p=res[0];
        if(res[0][0]=='+')
        {
            check=1;
            p.erase(std::remove(p.begin(), p.end(),'+'), p.end());

        }
        k=validateOpcode(p,check);
        if(k==2)
        {
            temp=Comment(comments);
            if((res[0][0]>='a'&&res[0][0]<='z')||(res[0][0]>='A'&&res[0][0]<='Z'))
                table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: Unrecognized OpCode",""));
            else
                table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: wrong operation prefix",""));


        }
        else if(k==3)
        {
            temp=Comment(comments);
            table.push_back(Entry(CURRENTADRESS,"",res[0],"",temp,"****Error: can’t be format 4 instruction",""));
        }
        else if(k==6)
        {

            temp=Comment(comments);
            table.push_back(Entry(CURRENTADRESS,"",res[0],"",temp,"****Error: missing operand",""));
        }
        else
        {
            oneWord(res,comments,byte(res[0]));

        }

    }



    else if(res.size()>3)
    {
        table.push_back( Entry( CURRENTADRESS, "",line,"","","****Error: Invalid Entry","") ) ;
    }
    else if(comments.size()>0)
    {
        temp=Comment(comments);
        if(!firstEntering)
            table.push_back( Entry( CURRENTADRESS,"","","",temp,"","") ) ;
        else
            table.push_back( Entry( -1,"","","",temp,"","") ) ;

    }


}

void Utilities::parse(string  line )
{

    labelch=1;
    vector<string>res;
    vector<string>comments;
    string temp="";
    bool com=false;

    for(int i = 0 ; i < line.size(); i++)
    {
        if(line[i]!=' ')
            temp+=line[i];

        else if(temp!="")
        {


            if(temp[0]=='.')
                com=true;

            if(!com)
            {
                temp=Tolower(temp);
                res.push_back(temp);
            }

            else
                comments.push_back(temp);
            temp="";



        }
    }

    if(temp!="")
    {


        if(temp[0]=='.')
            com=true;


        if(!com)
        {
            temp=Tolower(temp);
            res.push_back(temp);
        }

        else
            comments.push_back(temp);

    }




    if(res.size()>0&&firstEntering)
    {
        if(res.size()==2)
            CURRENTADRESS=todecimal(res[1]);
        else if(res.size()==3)
        {
            CURRENTADRESS=todecimal(res[2]);
            startlbl=res[0];
        }
        firstEntering=false;
        if(res.size()==2&&res[0].compare("start")==0&&CURRENTADRESS!=-1)
        {
            temp=Comment(comments);

            table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"",""));
        }
        else if(res.size()==3&&res[1].compare("start")==0&&CURRENTADRESS!=-1)
        {
            temp=Comment(comments);

            table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"",""));
        }
        else
        {
            temp=Comment(comments);
            string lin=Comment(res);

            table.push_back(Entry(CURRENTADRESS,lin,"","",temp,"****Error: invalid start of the program",""));
        }



    }
    else if(res.size()==3)
    {

        int k,check=0;
        string p="";
        p=res[1];
        if(res[1][0]=='+')
        {
            check=1;
            p.erase(std::remove(p.begin(), p.end(),'+'), p.end());

        }
        k=validateOpcode(p,check);
        if(k==2)
        {
            temp=Comment(comments);
            if((res[1][0]>='a'&&res[1][0]<='z')||(res[1][0]>='A'&&res[1][0]<='Z'))
                table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Unrecognized OpCode",""));
            else
                table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: wrong operation prefix",""));


        }
        else if(k==3)
        {
            temp=Comment(comments);
            table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: can’t be format 4 instruction",""));
        }
        else
        {
            if(!duplicateLable(res[0]))
            {

                int r=check_operand(res[1],res[2]);
                if(r==1)
                {
                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Invalid Register address",""));

                }
                else if(r==2)
                {
                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Invalid Operand",""));

                }
                else if(r==3)
                {
                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Symbol of operand not found",""));

                }
                else if(k==6)
                {
                    if(res[1]=="org"||res[1]=="base")
                    {
                        temp=Comment(comments);

                        table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: This instruction can't have a label",""));

                    }
                    else
                        threeWord(res,5,comments);
                }
                else
                {
                    threeWord(res,byte(res[1]),comments);
                }

            }
            else
            {
                temp=Comment(comments);
                table.push_back(Entry(CURRENTADRESS,res[0],res[1],res[2],temp,"****Error: Duplicate Symbol",""));

            }
        }
    }


    else if(res.size()==2)
    {

        int k,m,check=0;
        string p="",q="";
        p=res[0];
        q=res[1];
        m=validateOpcode(res[1],check);
        if(res[1][0]=='+')
        {
            check=1;
            q.erase(std::remove(q.begin(), q.end(),'+'), q.end());
            m=validateOpcode(q,check);
        }
        else
        {
            m=validateOpcode(res[1],check);
        }
        if(m==1)
        {
            temp=Comment(comments);
            table.push_back(Entry(CURRENTADRESS,res[0],res[1],"",temp,"****Error: missing operand",""));

        }
        else
        {
            if(res[0][0]=='+')
            {
                check=1;
                p.erase(std::remove(p.begin(), p.end(),'+'), p.end());

            }
            k=validateOpcode(p,check);

            if(k==2)
            {


                temp=Comment(comments);
                if((res[0][0]>='a'&&res[0][0]<='z')||(res[0][0]>='A'&&res[0][0]<='Z'))
                    table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: Unrecognized OpCode",""));
                else
                    table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: wrong operation prefix",""));
            }
            else if(k==3)
            {
                temp=Comment(comments);
                table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: can’t be format 4 instruction",""));
            }
            else
            {


                int r=check_operand(res[0],res[1]);
                if(r==1)
                {
                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: Invalid Register address",""));

                }
                else if(r==2)
                {
                    temp=Comment(comments);

                    table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: Invalid Operand",""));

                }
                else if(k==6)
                {
                    if(p=="equ")
                    {
                        temp=Comment(comments);

                        table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: This instruction must have a label",""));
                    }
                    else
                        twoWord(res,6,comments);
                }
                else
                {
                    twoWord(res,byte(res[0]),comments);
                }

            }

        }
    }

    else if(res.size()==1)
    {


        int k,check=0;
        string p="";
        p=res[0];
        if(res[0][0]=='+')
        {
            check=1;
            p.erase(std::remove(p.begin(), p.end(),'+'), p.end());

        }
        k=validateOpcode(p,check);
        if(k==2)
        {

            temp=Comment(comments);
            if((res[0][0]>='a'&&res[0][0]<='z')||(res[0][0]>='A'&&res[0][0]<='Z'))
                table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: Unrecognized OpCode",""));
            else
                table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"****Error: wrong operation prefix",""));


        }
        else if(k==3)
        {
            temp=Comment(comments);
            table.push_back(Entry(CURRENTADRESS,"",res[0],"",temp,"****Error: can’t be format 4 instruction",""));
        }
        else if(k==6)
        {

            temp=Comment(comments);
            table.push_back(Entry(CURRENTADRESS,"",res[0],"",temp,"****Error: missing operand",""));
        }
        else
        {
            oneWord(res,comments,byte(res[0]));

        }

    }



    else if(res.size()>3)
    {
        table.push_back( Entry( CURRENTADRESS, "",line,"","","****Error: Invalid Entry","" ) ) ;
    }
    else if(comments.size()>0)
    {
        temp=Comment(comments);
        if(!firstEntering)
            table.push_back( Entry( CURRENTADRESS,"","","",temp,"","") ) ;
        else
            table.push_back( Entry( -1,"","","",temp,"","" ) ) ;

    }




}
void Utilities::fillingMap()
{
    ifstream infile( "format.txt" );
    vector <string> record;
    while (infile)
    {
        string s;
        if (!getline( infile, s ))
            break;

        istringstream ss( s );


        while (ss)
        {
            string s;
            if (!getline( ss, s, ',' ))
                break;
            record.push_back( s );
        }

    }
    infile.close();
    for(int i=0; i<record.size(); i++)
    {
        if(i%5==0)
            opc.push_back(record[i]);
        else if(i%5==1)
            n1.push_back(record[i]);
        else if(i%5==2)
            n2.push_back(record[i]);
        else if(i%5==3)
            regmem.push_back(record[i]);
        else if(i%5==4)
            objc.push_back(record[i]);
    }
}
void Utilities::checkEndLine(string line)
{
    vector<string>res;
    vector<string>comments;
    string temp="";
    bool com=false;

    for(int i = 0 ; i < line.size(); i++)
    {
        if(line[i]!=' ')
            temp+=line[i];

        else if(temp!="")
        {


            if(temp[0]=='.')
                com=true;

            if(!com)
            {
                temp=Tolower(temp);
                res.push_back(temp);
            }

            else
                comments.push_back(temp);
            temp="";



        }
    }

    if(temp!="")
    {


        if(temp[0]=='.')
            com=true;


        if(!com)
        {
            temp=Tolower(temp);
            res.push_back(temp);
        }

        else
            comments.push_back(temp);

    }

    temp=Comment(comments);
    if(res.size()==1&&res[0]=="end"||res.size()==2&&res[0]=="end"&&res[1].compare(startlbl)==0)
    {
        if(res.size()==1)

            table.push_back(Entry(CURRENTADRESS,"",res[0],"",temp,"",""));
        else
            table.push_back(Entry(CURRENTADRESS,"",res[0],res[1],temp,"",""));
    }
    else
    {
        if(res[0]!="end"&&res[1]!="end")
        {
            string lin=Comment(res);
            table.push_back(Entry(CURRENTADRESS,lin,"","",temp,"****Error: invalid end of program",""));
        }
        else if(res[0]!="end")
        {
            string lin=Comment(res);
            table.push_back(Entry(CURRENTADRESS,lin,"","",temp,"****Error: This instruction can't have a label",""));
        }
        else if(startlbl=="")
        {
            string lin=Comment(res);
            table.push_back(Entry(CURRENTADRESS,lin,"","",temp,"****Error: Start instruction doesn't have a label so this instruction can't have an operand ",""));
        }

        else
        {
            string lin=Comment(res);
            table.push_back(Entry(CURRENTADRESS,lin,"","",temp,"****Error: The operand must be the label of the start instruction",""));
        }
    }

}

bool Utilities::checkSpace(string a)
{
    for(int i=0; i<a.size(); i++)
        if(a[i]!=' ')
            return true;
    return false;
}

int Utilities::stoi(string s)
{

    int i;
    i =(s[0] -'0');

    return i;

}

string Utilities::binary_to_hexa(string a)
{
    int dec=0;
    for(int i=0; i<a.size(); i++)
    {
        dec+=(a[i]-'0')*pow(2,a.size()-i-1);
    }
    char buffer [33];
    itoa(dec,buffer,16);
    return buffer;
}
void Utilities::initRegisters()
{
    mnemonicNumber["a"]="0";
    mnemonicNumber["x"]="1";
    mnemonicNumber["l"]="2";
    mnemonicNumber["b"]="3";
    mnemonicNumber["s"]="4";
    mnemonicNumber["t"]="5";
    mnemonicNumber["f"]="6";
    mnemonicNumber["pc"]="8";
    mnemonicNumber["sw"]="9";
}
vector <string>Utilities::splitLine(string line)
{
    vector<string>res;
    string temp="";
    for(  int i = 0; i < line.size() ; i++)
    {
        if(line[i]==',')
        {
            res.push_back(temp);
            temp="";
        }
        else
            temp+=line[i];
    }
    res.push_back(temp);

    return res;

}
int Utilities::eval_address(string a,int index)
{


    if(a!=""&&(a.find("+")==-1)&&(a.find("/")==-1)&&(a.find("*")==-1)&&(a.find("-")==-1))
    {

        if(a.size()==1&&a[0]=='*')
            return CURRENTADRESS;
        int k=0;
        if(a[0]=='#'||a[0]=='@')
            k++;
        string one="";
        string two="";
        int sign=-1;
        bool flag1=true;
        bool flag2=true;
        for(int i=k; i<a.size(); i++)
        {
            if(a[i]=='-'||a[i]=='+')
            {
                if(a[i]=='+')
                    sign=1;
                else
                    sign=2;
            }
            else if(a[i]<'0'||a[i]>'9')
            {
                if(sign==-1)
                {
                    one+=a[i];
                    flag1=false;
                }
                else
                {
                    flag2=false;
                    two+=a[i];
                }
            }
            else
            {
                if(sign==-1)
                    one+=a[i];
                else
                    two+=a[i];
            }
        }

        if((a[0]=='#'||a[0]=='@')&&flag1&&two=="")
        {
            if(sign==-1)
            {
                return -2;
            }
            else
            {
                table[index].error="****Error: invalid expression";
                return -1;
            }
        }
        if(one=="")
        {
            table[index].error="****Error: invalid expression";
            return -1;
        }
        if(sign!=-1&&two=="")
        {
            table[index].error="****Error: invalid expression";
            return -1;
        }
        if(flag1&&!flag2)
        {
            table[index].error="****Error: invalid expression";
            return -1;
        }

        //two integers
        if(flag1&&flag2)
        {
            table[index].error="****Error: invalid expression";
            return -1;
        }

        // two words
        else
        {
            if(sign==-1)
            {
                if(symbolTable.find(one)!=symbolTable.end())
                {

                    return symbolTable[one];

                }
                else
                {

                    table[index].error="****Error: undefined symbol";

                    return -1;
                }
            }
            else
            {
                if(flag1&&!flag2)
                {
                    table[index].error="****Error: invalid expression";
                    return -1;
                }
                else if(!flag1&&flag2)
                {
                    if(symbolTable.find(one)!=symbolTable.end())
                    {
                        if(sign==1)
                        {
                            return symbolTable[one]+Tointeger(two);
                        }
                        else
                        {
                            return symbolTable[one]-Tointeger(two);
                        }
                    }
                    else
                    {

                        table[index].error="****Error: undefined symbol";
                        return -1;
                    }
                }
                else if(!flag1&&!flag2)
                {
                    if(sign==1&&((symbolTable.find(one)!=symbolTable.end()&&absolute.find(two)!=absolute.end())||
                                 (symbolTable.find(two)!=symbolTable.end()&&absolute.find(one)!=absolute.end())))
                    {
                        return symbolTable[one]+symbolTable[two];
                    }
                    else if(sign==2&&((symbolTable.find(one)!=symbolTable.end()&&absolute.find(two)!=absolute.end())||
                                      (symbolTable.find(two)!=symbolTable.end()&&absolute.find(one)!=absolute.end())))
                    {
                        return -1;

                    }
                    else if(sign==2&&((symbolTable.find(one)!=symbolTable.end()&&symbolTable.find(two)!=symbolTable.end())||
                                      (symbolTable.find(two)!=symbolTable.end()&&symbolTable.find(one)!=symbolTable.end())))
                    {
                        int add=symbolTable[one]-symbolTable[two];
                        if(add<0)
                        {
                            table[index].error="****Error: negative address";
                            return -1;
                        }
                        else
                        {
                            return add;
                        }
                    }
                    else
                    {
                        table[index].error="****Error: invalid expression";
                        return -1;
                    }
                }
            }
        }
    }
    else if(a!=""&&((a.find("+")!=-1)||(a.find("/")!=-1)||(a.find("*")!=-1)||(a.find("-")!=-1)))
    {

        int cot=0;
        int c=0;
        string opr;
        vector<string> str;
        vector<int> str2;
        if((a.find("+")!=-1)||(a.find("/")!=-1)||(a.find("*")!=-1)||(a.find("-")!=-1))
        {


            for( int n=0; n<a.size(); n++)
            {
                if(a[n]=='+'||a[n]=='-'||a[n]=='*'||a[n]=='/')
                {
                    opr+=a[n];
                    a[n]='.';
                    c++;
                }
            }


            tokenize(a, '.', str);




            int res=0;
            for(int j=0; j<opr.size(); j++)
            {
                if(j==0)
                {
                    if(opr[j]=='+')
                    {
                        int cp=0;
                        for(int k=0; k<str[j+1].size(); k++)
                        {
                            if(str[j+1][k]>='0'&&str[j+1][k]<='9')
                                cp++;
                        }
                        if(cp==str[j+1].size())
                            res=symbolTable[str[j]]+atoi(str[j+1].c_str());
                        else
                            res=symbolTable[str[j]]+symbolTable[str[j+1]];
                    }
                    else if(opr[j]=='-')
                    {
                        int cp=0;
                        for(int k=0; k<str[j+1].size(); k++)
                        {
                            if(str[j+1][k]>='0'&&str[j+1][k]<='9')
                                cp++;
                        }
                        if(cp==str[j+1].size())
                            res=symbolTable[str[j]]-atoi(str[j+1].c_str());
                        else
                            res=symbolTable[str[j]]-symbolTable[str[j+1]];
                    }
                    else if(opr[j]=='/')
                    {
                        int cp=0;
                        for(int k=0; k<str[j+1].size(); k++)
                        {
                            if(str[j+1][k]>='0'&&str[j+1][k]<='9')
                                cp++;
                        }
                        if(cp==str[j+1].size())
                            res=symbolTable[str[j]]/atoi(str[j+1].c_str());
                        else
                            res=symbolTable[str[j]]/symbolTable[str[j+1]];
                    }
                    else if(opr[j]=='*')
                    {
                        int cp=0;
                        for(int k=0; k<str[j+1].size(); k++)
                        {
                            if(str[j+1][k]>='0'&&str[j+1][k]<='9')
                                cp++;
                        }
                        if(cp==str[j+1].size())
                            res=symbolTable[str[j]]*atoi(str[j+1].c_str());
                        else
                            res=symbolTable[str[j]]*symbolTable[str[j+1]];
                    }

                }
                else
                {
                    if(opr[j]=='+')
                    {
                        int cp=0;
                        for(int k=0; k<str[j+1].size(); k++)
                        {
                            if(str[j+1][k]>='0'&&str[j+1][k]<='9')
                                cp++;
                        }
                        if(cp==str[j+1].size())
                            res=res+atoi(str[j+1].c_str());
                        else
                            res=res+symbolTable[str[j+1]];
                    }
                    else if(opr[j]=='-')
                    {
                        int cp=0;
                        for(int k=0; k<str[j+1].size(); k++)
                        {
                            if(str[j+1][k]>='0'&&str[j+1][k]<='9')
                                cp++;
                        }
                        if(cp==str[j+1].size())
                            res=res-atoi(str[j+1].c_str());
                        else
                            res=res-symbolTable[str[j+1]];
                    }
                    else if(opr[j]=='/')
                    {
                        int cp=0;
                        for(int k=0; k<str[j+1].size(); k++)
                        {
                            if(str[j+1][k]>='0'&&str[j+1][k]<='9')
                                cp++;
                        }
                        if(cp==str[j+1].size())
                            res=res/atoi(str[j+1].c_str());
                        else
                            res=res/symbolTable[str[j+1]];
                    }
                    else if(opr[j]=='*')
                    {
                        int cp=0;
                        for(int k=0; k<str[j+1].size(); k++)
                        {
                            if(str[j+1][k]>='0'&&str[j+1][k]<='9')
                                cp++;
                        }
                        if(cp==str[j+1].size())
                            res=res*atoi(str[j+1].c_str());
                        else
                            res=res*symbolTable[str[j+1]];
                    }
                }
            }

            return res;
        }
    }
    return -1;
}

string Utilities::format1(string line)
{
    int found = 0;
    int place = -1;
    for( int i=0; i<objc.size(); i++)
    {
        if(line.compare(objc[i])==0)
        {
            found=1;
            place=i;
            break;

        }
    }
    return binary_to_hexa( objc[place] );
}
string Utilities::format2(string opCode, string operand )
{
    // op_code r1,r2
    initRegisters();
    string res="";
    vector<string>registers = splitLine(operand);

    int found = 0;
    int place = -1;
    for( int i=0; i<objc.size(); i++)
    {
        if(opCode.compare(opc[i])==0)
        {
            found=1;
            place=i;
            break;

        }
    }
    res += binary_to_hexa(objc[place]);
    res+=mnemonicNumber[registers[0]];

    if(registers.size()>1)
        res+=mnemonicNumber[registers[1]];
    else
        res+="0";


    return res;
}
string Utilities::format3_4(int index,string instr,string operand,int current_address)
{

    string res="";
    string nixbpe="000000";
    string temp="";
    if(instr[0]=='+')
    {
        for(int i=1; i<instr.size(); i++)
            temp+=instr[i];
        instr=temp;
        nixbpe[5]='1';
    }
    if(operand[0]=='#')
    {
        nixbpe[1]='1';
    }
    else if(operand[0]=='@')
    {
        nixbpe[0]='1';
    }
    else
    {
        nixbpe[0]='1';
        nixbpe[1]='1';
        //check ni==00
    }
    int found1 = 0;
    int place1 = -1;
    for( int i=0; i<opc.size(); i++)
    {
        if(instr.compare(opc[i])==0)
        {
            found1=1;
            place1=i;
            break;

        }
    }

    string opValue= objc[place1];


    temp=opValue;


    if(temp.size()==1)
    {
        string temp2="";
        temp2='0';
        temp2+=temp[0];
        temp=temp2;
    }
    for(int i=0; i<temp.size(); i++)
        res+=temp[i];


    if(operand[operand.size()-1]=='x'&&operand[operand.size()-2]==',')
    {
        nixbpe[2]='1';
        temp="";
        for(int i=0; i<operand.size()-2; i++)
        {
            temp+=operand[i];
        }
        operand=temp;

    }

    string dis="";
    if(nixbpe[5]=='0')
    {


        int TA=eval_address(operand,index);

        if(TA!=-1)
        {
            int dis=TA-(current_address+3);

            if(TA!=-2)
            {
                if(dis>=-2048&&dis<=2047)
                {
                    nixbpe[4]='1';
                }
                else if(dis>=0&&dis<=4095)
                {
                    //dis will change here=TA-B
                    //lsa man3rfsh lw mandash 3la LDB 7n3ml 2eh



                    dis=TA-base;
                    nixbpe[3]='1';

                }
            }
            else
            {
                temp="";
                for(int i=1; i<operand.size(); i++)
                    temp+=operand[i];

                dis=Tointeger(temp);
            }

            char buffer [33];

            for(int i=0; i<nixbpe.size(); i++)
            {
                res+=nixbpe[i];
            }
            res=binary_to_hexa(res);

            temp=itoa (dis,buffer,16);

            if(temp.size()>3)
            {
                string temp2="";
                temp2=temp[temp.size()-3];
                temp2+=temp[temp.size()-2];
                temp2+=temp[temp.size()-1];
                temp=temp2;
            }
            else
            {
                string temp2="";
                for(int i=0; i<(3-temp.size()); i++)
                {
                    temp2+='0';
                }
                for(int i=0; i<temp.size(); i++)
                {
                    temp2+=temp[i];
                }
                temp=temp2;
            }

            for(int i=0; i<temp.size(); i++)
            {
                res+=temp[i];
            }

            return res;
        }
        else
        {
            //error
            if(operand=="")
            {
                temp="0000";
                for(int i=0; i<temp.size(); i++)
                {
                    res+=temp[i];
                }
                return res;
            }
            else
            {
                // table[index].error="invalid expression or symbol";
                error2=false;
            }
        }
    }
    else
    {
        for(int i=0; i<nixbpe.size(); i++)
        {
            res+=nixbpe[i];
        }
        res=binary_to_hexa(res);
        char buffer [33];

        //lsa mat3mltsh
        int TA=eval_address(operand,index);
        if(TA!=-1)
        {
            if(TA!=-2)
            {
                temp= itoa (TA,buffer,16);
            }
            else
            {
                temp="";
                for(int i=1; i<operand.size(); i++)
                    temp+=operand[i];
                TA  = atoi(temp.c_str());

            }
            temp= itoa (TA,buffer,16);
            if(temp.size()>5)
            {
                string temp2="";
                temp2=temp[temp.size()-5];
                temp2+=temp[temp.size()-4];
                temp2+=temp[temp.size()-3];
                temp2+=temp[temp.size()-2];
                temp2+=temp[temp.size()-1];
                temp=temp2;
            }
            else
            {
                string temp2="";
                for(int i=0; i<(5-temp.size()); i++)
                {
                    temp2+='0';
                }
                for(int i=0; i<temp.size(); i++)
                {
                    temp2+=temp[i];
                }
                temp=temp2;
            }

            for(int i=0; i<temp.size(); i++)
                res+=temp[i];

            return res;
        }
        else
        {
            //error
            if(operand=="")
            {
                temp="000000";
                for(int i=0; i<temp.size(); i++)
                {
                    res+=temp[i];
                }
                return res;
            }
            else
            {
                // table[index].error="invalid expression or symbol";
                error2=false;
            }
        }
    }
    return res;
}
void Utilities::objectCode()
{
    for(int i=0; i<table.size(); i++)
    {
        string q=table[i].op_code;
        if(table[i].op_code[0]=='+')
        {

            q.erase(std::remove(q.begin(),q.end(),'+'),q.end());

        }
        if(q=="start"||q=="end"||q==""||q=="org"||q=="base")
            continue;
         if(q=="resw"){

            sizeall=sizeall+atoi(table[i].operand.c_str())*3;
            cout<<sizeall;
             }
             if(q=="resb"){

            sizeall=sizeall+atoi(table[i].operand.c_str());

             }
        if(table[i].op_code=="byte")
        {

            if(table[i].operand[0]=='x')
            {
                for(int j=2; j<table[i].operand.size()-1; j++)
                    table[i].ObjectCode+=table[i].operand[j];

            }
            else
            {
                for(int j=2; j<table[i].operand.size()-1; j++)
                {
                    int ascii=table[i].operand[j];
                    char buffer [33];
                    itoa (ascii,buffer,16);
                    table[i].ObjectCode+=buffer;
                }
            }
        }
        else if(table[i].op_code=="word")
        {
            int dec=0;

            for(int k=0 ; k<table[i].operand.size(); k++)
            {
                dec=dec*10+(table[i].operand[k]-48);


            }

            char buffer [33];
            itoa (dec,buffer,16);
            string b2;
            b2=buffer;
            while(b2.size()<6)
                b2="0"+b2;
            table[i].ObjectCode=b2;
        }
        else
        {
            int found = 0;
            int place = -1;
            int j;

            for( j=0; j<opc.size(); j++)
            {

                if(q.compare(opc[j])==0)
                {
                    found=1;
                    place=j;
                    break;
                }
            }
            //bydrb hna

            int byt=stoi(n1[place]);


            string res="";

            if(byt==1)
            {
                res=format1(q);
                while(res.size()<2)
                    res="0"+res;
            }
            else if(byt==2)
            {
                res=format2(q,table[i].operand);
                while(res.size()<4)
                    res="0"+res;
            }
            else if(byt==3||byt==4)
            {
                res=format3_4(i,table[i].op_code,table[i].operand,table[i].loc);
                if(byt==3)
                {
                    while(res.size()<6)
                        res="0"+res;
                }
                else
                {
                    while(res.size()<8)
                        res="0"+res;
                }

            }
            table[i].ObjectCode=res;
            string s=table[i].operand;
            if(table[i].op_code=="ldb")
            {
                s.erase(std::remove(s.begin(),s.end(),'#'),s.end());

                if(s.compare(baseadd)==0)
                {
                    base=eval_address(table[i].operand,i);

                    if(base==-1)
                    {
                        error2=false;
                        table[i].error="invalid expression or symbol";

                    }
                }
                else
                    table[i].error="invalid symbol or base directive not found";
            }
        }

    }
}
void Utilities::buildObjectFile()
{

    programName="";
    for(int i =  0 ; i < table.size() ; i++)
    {

        if(table[i].op_code=="start")
        {
            if(table[i].label!="")
            {
                programName=table[i].label;
            }
            startAdress=table[i].loc;

        }
        if(table[i].ObjectCode !="")
        {


            if(table[i].op_code[0]=='+'&&table[i].operand[0]!='#')
                objectFileFormat4.push_back(table[i].loc);
            objectFile.push_back(make_pair(table[i].ObjectCode,table[i].loc));




        }

    }
}
string Utilities::modifyLocation(int loc, int len)
{

    string lenght="";
    char buffer [33];
    itoa (loc,buffer,16);
    lenght=buffer;
    while(lenght.size()<len)
        lenght="0"+lenght;

    return lenght;
}


void Utilities::generateObjectFile()
{
    FILE * file = fopen( "objectfile.txt", "w" );
    string res ="";

    string header="H";
    int len;
    if(programName!="")
    {
        header+=programName;
    }
    while(header.size()<7)
                header=header+"0";

    string lenght=modifyLocation(CURRENTADRESS-startAdress,6);


    string start=modifyLocation(startAdress,6);

    fprintf(file,"%s%s%s\n",header.c_str(),start.c_str(),lenght.c_str());


    int sizeobj=0;
    int sizetot=0;
    int numberOfFormat4=0,numberOfotherForamt=0;
    for(int i =0; i <objectFile.size(); i+=9)
    {

        numberOfFormat4=numberOfotherForamt=0;
        res="T";
        res+=modifyLocation(objectFile[i].second,6);
        string  temp="";

        for(int j = i ; j < i+9 && j<objectFile.size() ; j++){

            temp+=objectFile[j].first;
        sizeobj+=objectFile[j].first.size();
        }
        sizetot=sizeall+sizeobj/2;
        res+=modifyLocation(sizetot,2)+temp;

        fprintf(file,"%s\n",res.c_str());

    }

    for(int i = 0 ; i < objectFileFormat4.size(); i++)
        fprintf(file,"M%s05\n",modifyLocation(objectFileFormat4[i]+1,6).c_str());

    fprintf(file,"E%s\n",start.c_str());
}
void Utilities:: tokenize(std::string const &str, const char delim,
                          std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}
bool Utilities::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}
Utilities::~Utilities()
{
    //dtor
}
