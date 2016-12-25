#include <iostream>

using namespace std;

int main()
{
    int c, p;
    int G = 0, B = 0, R = 0;
    char m, s;

    cin >> c;
    while(c--){
        cin >> p;
        while (p--){
            cin >> m >> s;

            if(m == 'R'){
                if(s == 'G'){
                    R += 2;
                }else{
                    R += 1;
                }
            }else if(m == 'G'){
                if(s == 'B'){
                    G += 2;
                }else{
                    G += 1;
                }
            }else{
                if(s == 'R'){
                    B += 2;
                }else{
                    B += 1;
                }
            }
        }
        if(G == R && R == B){
            cout<<"trempate"<<endl;
        }else if((R == G && G > B) || (R == B && B > G) || (B == G && G > R)){
            cout<<"empate"<<endl;
        }else{
            if(R > G && R > B){
                cout <<"red"<< endl;
            }else if(G > R && G > B){
                cout <<"green"<< endl;
            }else if(B > R && B > G){
                cout <<"blue"<< endl;
            }
        }
        G = B = R = 0;
    }

    return 0;
}
