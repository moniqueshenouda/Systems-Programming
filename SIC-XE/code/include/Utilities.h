#ifndef UTILITIES_H
#define UTILITIES_H
#include <fstream>
#include <string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include <cctype>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include<math.h>
#include"Entry.h"
#define INF 1000000000
#define MOD  1000000007
#define MAX 100000
using namespace std;

class Utilities
{
public:
    map <string,int>symbolTable;
    vector <string> opc;
    vector <string> n1;
    vector <string> n2;
    vector <string> regmem;
    vector <string> objc;
    map<string,bool>absolute;
    bool firstEntering=true;
    vector<Entry>table;
    vector <string> label;
    int CURRENTADRESS=-1;

    map<string, string>mnemonicNumber;
    int base=0;
    bool error1;
    bool error2;
    int sizeall=0;
    Utilities();
    bool checkSpace(string a);
    void checkEndLine(string line);
    void fillingMap();
    void parse(string  line );
    void parse_sic(string  line );
    void labtable(string line);
    void threeWord ( vector<string> line,int typeByte,vector<string>comment);
    void twoWord ( vector<string> line,int typeByte,vector<string>comment);
    void oneWord ( vector<string> line,vector<string> comment,int byt);
    bool duplicateLable(string a);
    int validateOpcode(string a,int check);
    int check_operand(string opcode,string oper);
    string Tolower(string str);
    void buildObjectFile();
    void generateObjectFile();
    string modifyLocation(int loc , int len);
    int Tointeger(string str);
    int todecimal(string a);
    bool checkWord(string a);
    int checkByte(string a);
    int byte(string a);
    int stoi(string s);
    string Comment(vector<string>a);
    int checkOrg(string a);
    int checkEqu(string a,string label);
    void tokenize(std::string const &str, const char delim,
			std::vector<std::string> &out);
			bool is_number(const std::string& s);

   string binary_to_hexa(string a);
    string format1(string line);
    string format2(string opCode, string operand );
    string format3_4(int index,string instr,string operand,int current_address);
    vector <string>splitLine(string line);
    void initRegisters();
    int eval_address(string a,int index);
    void objectCode();



    virtual ~Utilities();
protected:
private:
};

#endif // UTILITIES_H
