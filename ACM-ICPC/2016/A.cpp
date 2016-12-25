#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
bool split(string a,string b) {
    stringstream aa(a);
    stringstream bb(b);
    string itema,itemb;
    while (getline(aa, itema, ' '))
    {
        getline(bb, itemb, ' ');
        if(itema[0]!=itemb[0])
            return false;
    }
    return true;
}

int main()
{
    string a;
    string b;
    while(getline(cin,a))
    {
    	getline(cin,b);
       if(split(a,b))
            cout<<"yes"<<endl;
       else
            cout<<"no"<<endl;
    }

}
