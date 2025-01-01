#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool gofunc(vector<int> &ram,int ramSum,vector<int> &sham,int shamSum,vector<int> &rahim,int rahimSum,vector<int> &v,int i,int n){
    if(i==n){
        if( ((ramSum/5)==(shamSum/3))  &&  ((shamSum/3)==(rahimSum/2))){
        cout<<"\nDistribution Result :\n";
                cout<<"Ram:";
                for(auto i:ram){
                    cout<<i<<" ";
                }
                cout<<"\nSham:";
                for(auto i:sham){
                    cout<<i<<" ";
                }
                cout<<"\nRahim:";
                for(auto i:rahim){
                    cout<<i<<" ";
                }
            return true;
        }
        else{
            return false;
        }
    }
    ram.push_back(v[i]);
    if(gofunc(ram,ramSum+v[i],sham,shamSum,rahim,rahimSum,v,i+1,n)){
        return true;
    }
    ram.pop_back();

    sham.push_back(v[i]);
    if(gofunc(ram,ramSum,sham,shamSum+v[i],rahim,rahimSum,v,i+1,n)){
        return true;
    }
    sham.pop_back();

    rahim.push_back(v[i]);
    if(gofunc(ram,ramSum,sham,shamSum,rahim,rahimSum+v[i],v,i+1,n)){
        return true;
    }
    rahim.pop_back();

    return false;
}

int main(){
    vector<int> v;
    cout<<"run distribute_apple\n";
    int appleWeight=1;
    while(appleWeight!=-1){
        cout<<"Enter apple weight in grams (-1 to stop ): ";
        cin>>appleWeight;
        v.push_back(appleWeight);
    }
    int n=v.size()-1;
    vector<int> ram;
    vector<int> sham;
    vector<int> rahim;
    if(!gofunc(ram,0,sham,0,rahim,0,v,0,n)){
        cout<<"---   No way exist ! ! !   ---";
    }
    return 0;
}

/*
Output:
run distribute_apple
Enter apple weight in grams (-1 to stop ): 400
Enter apple weight in grams (-1 to stop ): 100
Enter apple weight in grams (-1 to stop ): 400
Enter apple weight in grams (-1 to stop ): 300
Enter apple weight in grams (-1 to stop ): 200
Enter apple weight in grams (-1 to stop ): 300
Enter apple weight in grams (-1 to stop ): 100
Enter apple weight in grams (-1 to stop ): 200
Enter apple weight in grams (-1 to stop ): -1

Distribution Result :
Ram:400 100 400 100
Sham:300 300
Rahim:200 200
Process returned 0 (0x0)   execution time : 99.579 s
Press any key to continue.
*/
