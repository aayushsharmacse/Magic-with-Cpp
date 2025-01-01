#include<bits/stdc++.h>
using namespace std;
//found on gfg refer there
bool onSegment(pair<double,double> &p, pair<double,double> &q, pair<double,double> &r)
{
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
       return true;

    return false;
}
int orientation(pair<double,double> &p, pair<double,double> &q, pair<double,double> &r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    double val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;  // collinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(pair<double,double> &p1, pair<double,double> &q1, pair<double,double> &p2,pair<double,double> &q2)
{
    // Find the four orientations needed for general and
    // special cases
    double o1 = orientation(p1, q1, p2);
    double o2 = orientation(p1, q1, q2);
    double o3 = orientation(p2, q2, p1);
    double o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

//lets fly the flights
void fly(vector<pair<double,double>> v[],int ind,int n,double &ratio2){
    for(int i=ind-1;i>=0;i--){
        for(int j=0;j<v[i].size()-1;j++){
            for(int x=1;x<v[ind].size()-1;x++){
                if( doIntersect(v[i][j],v[i][j+1],v[ind][x],v[ind][x+1]) ){
                    cout<<"intersection found resolving..."<<
                    v[i][j].first<<v[i][j].second<<" "<<v[i][j+1].first<<v[i][j+1].second<<" "<<
                    v[ind][x].first<<v[ind][x].second<<" "<<v[ind][x+1].first<<v[ind][x+1].second<<endl;
                    double cx= (10*v[i][j+1].first-ratio2*(v[i][j].first))/(10-1) ;
                    double cy= (10*v[i][j+1].second-ratio2*(v[i][j].second))/(10-1) ;
                    ratio2=ratio2/0.9;
                    v[ind].insert(v[ind].begin()+x+1,{cx,cy});
                    cout<<"inserted"<<v[ind][x+1].first<<v[ind][x+1].second<<endl;
                    fly(v,ind,n,ratio2);
                }
            }
        }
    }
    return;
}
void printFinalVectorstoDrawLinesOnPlot(vector<pair<double,double>> v[],int n){
    cout<<"====================================================================\n\n";
    for(int i=0;i<n;i++){
        cout<<"coordinates to plot flight "<<i+1<<" line plot(flight path) :";
        for(int j=0;j<v[i].size();j++){
            cout<<" ("<<v[i][j].first<<","<<v[i][j].second<<") ";
        }
        cout<<"\n";
    }
}
int main(){
    int n;
    cout<<"Enter no of flights\n";
    cin>>n;
    vector<pair<double,double>> v[n];
    int i=1;
    while(i<=n){
        cout<<"Flight "<<i<<" : ";
        pair<double,double> stop1,stop2,stop3;
        cin>>stop1.first>>stop1.second>>stop2.first>>stop2.second>>stop3.first>>stop3.second;
        v[i-1].push_back(stop1);
        v[i-1].push_back(stop2);
        v[i-1].push_back(stop3);
        i++;
    }
    double ratio2=1;
    for(int i=1;i<n;i++){
     fly(v,i,n,ratio2);
    }
    printFinalVectorstoDrawLinesOnPlot(v,n);
    return 0;
}

/*
Output:
Enter no of flights
3
Flight 1 : 1 1 2 2 3 3
Flight 2 : 1 1 2 4 3 2
Flight 3 : 1 1 4 2 3 4
intersection found resolving...22 33 24 32
inserted3.111113.11111
====================================================================

coordinates to plot flight 1 line plot(flight path) : (1,1)  (2,2)  (3,3)
coordinates to plot flight 2 line plot(flight path) : (1,1)  (2,4)  (3.11111,3.11111)  (3,2)
coordinates to plot flight 3 line plot(flight path) : (1,1)  (4,2)  (3,4)

Process returned 0 (0x0)   execution time : 43.676 s
Press any key to continue.

*/
