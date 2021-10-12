#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10][10];
int find_total_paths(int n,int m,pair<int,int>x,pair<int,int>y){
    int r=y.first-x.first,c=abs(y.second-x.second);
    int path[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            path[i][j]=0;
        }
    }
    for(int i=1;i<c;i++){
        if(a[x.first][i]==0){
       path[0][i]=path[0][i-1];
        }
    }
    for(int i=1;i<r;i++){
        if(a[i][x.second]==0){
            path[i][0]=path[i-1][0];
        }
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
           if(!a[x.first+i][x.second+j]){
               path[i][j]=path[i-1][j]+path[i][j-1];
           }
        }
    }
    return path[r-1][c-1];
}
int diag_find_total_paths(int n,int m,pair<int,int>x,pair<int,int>y){
    int r=abs(x.first-y.first),c=abs(x.second-y.second);
    int path[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            path[i][j]=0;
        }
    }
    for(int i=c-2;i>=0;i--){
        if(a[x.first][i]==0 || a[x.first][i]<=m){
        path[0][i]=path[0][i+1];
        }
    }
    for(int i=1;i<r;i++){
        if(a[i][x.second+c-1]==0 || a[i][x.second+c-1]<=m){
           path[i][c-1]=path[i-1][c-1];
        }
    }
    for(int i=1;i<r;i++){
        for(int j=c-2;j>=0;j--){
            if(!a[i+x.first][j+x.second]){
            path[i][j]=path[i+1][j]+path[i][j+1];
            }
        }
    }
    return path[r-1][0];
}
int main() {
   int t;
   cin>>t;
   while(t--){
     cin>>n>>m;
     int a[n][n];
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             a[i][j]=0;
         }
     }
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             cin>>a[i][j];
         }
     }
     int ans=1;
     map<int,pair<int,int>>mp;
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             if(a[i][j]!=0 && a[i][j]!=9){
                 mp.insert({a[i][j],{i,j}});
             }
         }
     }
     /*for(auto x: mp){
         cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
     }*/
     for(int i=1;i<m;i++){
        pair<int,int>curr=mp[i];
        //cout<<p.first<<" "<<p.second<<"\n";
        pair<int,int>nex=mp[i+1];
        if(curr.first<=nex.first && curr.second<=nex.second){
        ans=ans*find_total_paths(n,m,curr,nex);
        }
        else{
            ans=ans*diag_find_total_paths(n,m,curr,nex);
        }
        cout<<ans<<"\n";
     }
     cout<<ans<<"\n";
   }
   return 0;
}
