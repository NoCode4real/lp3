#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int, int>p2){
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;

    return v1>v2;
}

int main(){

    int n;
    cout<<"Enter the no. of objects : ";
    cin>>n;
    vector<pair<int, int>> a(n);
    cout<<"Enter the value and weight : "<<endl;
    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    int w;
    cout<<"ENter the maximum capacity : "<<endl;
    cin>>w;
    sort(a.begin(), a.end(), compare);
    double ans= 0;
    for(int i=0; i<n; i++){
        if(w >= a[i].second){
            ans+= a[i].first;
            w-= a[i].second;
            continue;
        }
        double vw = (double) a[i].first/a[i].second;
        ans+= vw * w;
        w=0;
        break;
    }
    cout << "Total value is : " << ans <<endl;

}
