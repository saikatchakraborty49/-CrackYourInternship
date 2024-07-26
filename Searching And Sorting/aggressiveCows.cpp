#include<bits/stdc++.h>
#define int long long
using namespace std;

bool isPossbile(vector<int>&v,int n,int c,int minDist){
    int cowCnt=1;
    int prevAllocated=v[0];
    for(int i=1;i<n;i++){
        if(v[i]-prevAllocated>=minDist){
            cowCnt++;
            prevAllocated=v[i];
        }
    }
    if(cowCnt>=c) return true;
    else return false;
}

int aggressivecows(vector<int>&v,int n,int c){
    int maxPossible=v.back()-v[0];
    int ans=0;
    int i=1;
    int j=maxPossible;
    int mid=i+(j-i)/2;
    while(i<=j){
        if(isPossbile(v,n,c,mid)){
            ans=mid;
            i=mid+1;
        }
        else{
            j=mid-1;
        }        
        mid=i+(j-i)/2;
    }
    // return j;
    return ans;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        if(c>n) return -1;
        vector<int>v;
        for(int i=0;i<n;i++){
            int ele;
            cin>>ele;
            v.push_back(ele);
        }
        sort(v.begin(),v.end());
        cout<<aggressivecows(v,n,c)<<endl;
    }
    return 0;
}