#include <iostream>

using namespace std;

int main()
{
    int n, t1 = 0, t2 = 0, pts_1 = 0, pts_2 = 0, goals_1 = 0, goals_2 = 0, goalsv_1 = 0, goalsv_2 = 0;
    char x;

    cin >> n;
    n *= 2;

    int vuelta = 1;

    while(n--){

    if( vuelta == 1){
        cin >> t1 >> x >> t2;

        if(t1 > t2){
            pts_1 += 3;
            goals_1 += t1;
            goals_2 += t2;
            goalsv_2 = t2;
        }

        else if (t1 == t2){
            pts_1 += 1;
            pts_2 += 1;
            goals_1 += t1;
            goals_2 += t2;
            goalsv_2 = t2;
        }

        else{
            pts_2 += 3;
            goals_1 += t1;
            goals_2 += t2;
            goalsv_2 = t2;
        }
        vuelta += 1;
    }
    else{
        cin >> t2 >> x >> t1;

        if(t1 > t2){
            pts_1 += 3;
            goals_1 += t1;
            goals_2 += t2;
            goalsv_1 = t1;
        }

        else if (t1 == t2){
            pts_1 += 1;
            pts_2 += 1;
            goals_1 += t1;
            goals_2 += t2;
            goalsv_1 = t1;
        }

        else{
            pts_2 += 3;
            goals_1 += t1;
            goals_2 += t2;
            goalsv_1 = t1;
        }

        if(pts_1 > pts_2){
            cout <<"Time 1"<<endl;
        }
        else if(pts_1 == pts_2){
            if((goals_1 - goals_2) > (goals_2 - goals_1)){
                cout <<"Time 1"<<endl;
            }
            else if((goals_1 - goals_2) == (goals_2 - goals_1)){
                if(goalsv_1 > goalsv_2){
                    cout <<"Time 1"<<endl;
                }
                else if(goalsv_1 == goalsv_2){
                    cout <<"Penaltis"<<endl;
                }
                else{
                    cout<<"Time 2"<<endl;
                }
            }
            else{
                cout <<"Time 2"<< endl;
            }
        }
        else{
            cout<<"Time 2"<< endl;
        }
        pts_1 = pts_2 = goals_1 = goals_2 = goalsv_1 = goalsv_2 = 0;
        vuelta = 1;
    }
    }
    return 0;
}
