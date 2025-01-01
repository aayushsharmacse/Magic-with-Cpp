#include<bits/stdc++.h>
using namespace std;
void printchessboard(vector<vector<int>> &chessboard){
    cout<<"\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<chessboard[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void printset(unordered_set<int> &s){
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int moveFront(int direction,int coordinate){
    if(direction==2){
        return coordinate+9;
    }
    else if(direction==1){
        return coordinate-1;
    }
    else if(direction==3){
        return coordinate+1;
    }
    else if(direction==0){
        return coordinate-9;
    }
    cout<<"Entered in moveFront function, wrong direction given";
    return -1;
}
int changeDirection(int direction){
    return (direction+1)%4;
}
void goKillThem(int castle,int direction,vector<vector<int>> &chessboard,unordered_set<int> &s,int initial,vector<string> &moves,int &pathNo){
    if(castle==initial && moves.size()!=1){
        cout<<"\nPath "<<++pathNo;
        cout<<"\n======\n";
        for(auto i:moves){
            cout<<i<<endl;
        }
        cout<<"Arrive ("+to_string(initial%9 +1)+","+to_string(initial/9 +1)+")"<<endl;
        return;
    }
    if(castle<0 || castle>=(9*9) || (castle%9==8 && direction==3) || (castle%9==0 && direction==1) || (castle/9==0 && direction==0)
       || (castle/9==8 && direction==2) ){
        return;
    }

    castle=moveFront(direction,castle);

    //cout<<"castle="<<castle<<endl;
    if(s.find(castle)!=s.end()){
        int soldierInWay=castle;
        s.erase(soldierInWay);
        chessboard[soldierInWay/9][soldierInWay%9]=0;
        moves.push_back("Kill ("+to_string(soldierInWay%9 +1 )+","+to_string(soldierInWay/9 + 1)+"). Turn Left");
        //cout<<"going inside after killing castle="<<castle<<"with direction="<<direction<<endl;
        goKillThem(castle,(direction+1)%4,chessboard,s,initial,moves,pathNo);
        moves.pop_back();
        chessboard[soldierInWay/9][soldierInWay%9]=1;
        s.insert(soldierInWay);

        moves.push_back("Jump ("+to_string(soldierInWay%9 +1)+","+to_string(soldierInWay/9 +1)+")");
        goKillThem(castle,direction,chessboard,s,initial,moves,pathNo);
        moves.pop_back();
    }
    else{
        goKillThem(castle,direction,chessboard,s,initial,moves,pathNo);
    }
    return;
}

int main(){
    int noOfSoldiers;
    cout<<"find_my_home_castle - soldiers ";
    cin>>noOfSoldiers;
    int x,y;
    unordered_set<int> s;
    vector<vector<int>> chessboard(9,vector<int> (9,0));
    for(int i=1;i<=noOfSoldiers;i++){
        cout<<"Enter coordinates for soldier "<<i<<": ";
        cin>>y;
        cin>>x;
        chessboard[x-1][y-1]=1;
        s.insert( (x-1)*9+(y-1) );
    }
    printchessboard(chessboard);
    printset(s);
    cout<<"Enter the coordinates for your \"special\" castle: ";
    cin>>y;
    cin>>x;
    //int front;
    int start=(x-1)*9+(y-1);
    int initial=start;
    int direction=2;
    int pathNo=0;
    vector<string> moves;
    moves.push_back("Start ("+to_string(y)+","+to_string(x)+")");
    goKillThem(start,direction,chessboard,s,initial,moves,pathNo);
    cout<<"*********************************************";
    cout<<"\nTotal "<<pathNo<<" paths exist";
    cout<<"\nThank you!";
    return 0;
}

/*
Output:
find_my_home_castle - soldiers 11
Enter coordinates for soldier 1: 1 1
Enter coordinates for soldier 2: 8 9
Enter coordinates for soldier 3: 1 9
Enter coordinates for soldier 4: 4 1
Enter coordinates for soldier 5: 4 2
Enter coordinates for soldier 6: 4 8
Enter coordinates for soldier 7: 2 6
Enter coordinates for soldier 8: 5 6
Enter coordinates for soldier 9: 8 2
Enter coordinates for soldier 10: 5 9
Enter coordinates for soldier 11: 2 8

1 0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 1 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 0 1 0 0 0 0 0
1 0 0 0 1 0 0 1 0
76 49 64 12 16 3 46 72 66 79 0
Enter the coordinates for your "special" castle: 1 2

Path 1
======
Start (1,2)
Kill (1,9). Turn Left
Kill (5,9). Turn Left
Kill (5,6). Turn Left
Kill (2,6). Turn Left
Kill (2,8). Turn Left
Kill (4,8). Turn Left
Kill (4,2). Turn Left
Arrive (1,2)

Path 2
======
Start (1,2)
Kill (1,9). Turn Left
Kill (5,9). Turn Left
Kill (5,6). Turn Left
Kill (2,6). Turn Left
Kill (2,8). Turn Left
Kill (4,8). Turn Left
Jump (4,2)
Kill (4,1). Turn Left
Kill (1,1). Turn Left
Arrive (1,2)

Path 3
======
Start (1,2)
Kill (1,9). Turn Left
Jump (5,9)
Kill (8,9). Turn Left
Kill (8,2). Turn Left
Jump (4,2)
Arrive (1,2)
*********************************************
Total 3 paths exist
Thank you!
Process returned 0 (0x0)   execution time : 75.258 s
Press any key to continue.
*/
