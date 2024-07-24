class Solution {
public:
    int nthUglyNumber(int n) {
        int f2=2;
        int f3=3;
        int f5=5;
        int i2=0;
        int i3=0;
        int i5=0;
        vector<int>arr(n+1);
        arr[0]=1;
        for(int i=1;i<n;i++){
            int mini=min(f2,min(f3,f5));
            arr[i]=mini;
            if(f2==mini){
                i2++;
                f2=2*arr[i2];
            }
            if(f3==mini){
                i3++;
                f3=3*arr[i3];
            }
            if(f5==mini){
                i5++;
                f5=5*arr[i5];
            }
        }
        return arr[n-1];
    }
};