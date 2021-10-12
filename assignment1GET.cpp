#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
double fun(double k){
    double ret, val;
    ret = atan(k);
    val = (ret * 180) / PI;
    return val;
}
int main() {
int t,r=1;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int x,y;
    vector<pair<int,int>>v;
    v.clear();
    for(int i=0;i<n;i++){
      cin>>x>>y;
      v.push_back({x,y});
    }
    set<double>st;
    st.clear();
    for(int i=0;i<n;i++){
        //cout<<fixed<<setprecision(5)<<d<<" "<<"\n";
       // cout<<v[i].first<<" "<<v[i].second<<"\n";
        if(v[i].second>50000){
            //cout<<"y: "<<v[i].second<<"\n";
            int h=v[i].second-50000;
            //cout<<"h: "<<h<<"\n";
            double hh=double(double(h)/double(2));
            //cout<<"hh: "<<hh<<"\n";
            st.insert(v[i].first-hh);
           // cout<<v[i].first-hh<<"\n";
        }
        else{
            //cout<<"y: "<<v[i].second<<"\n";
            int h=50000-v[i].second;
            //cout<<"h: "<<h<<"\n";
            int hh=2*h;
            //cout<<"hh: "<<hh<<"\n";
            st.insert(v[i].first-hh);
            //cout<<v[i].first-hh<<"\n";
        }
    }
    cout<<"#"<<r<<" "<<st.size()<<"\n";r++;
}
return 0;
}