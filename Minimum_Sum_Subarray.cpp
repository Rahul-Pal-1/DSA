long maximumSumSubarray(int k, vector<int> &a , int n){

    long lastSum = 0 , ans = INT_MIN;
    int itr1 = 0, itr2 = k;
     for(int i = 0; i< k; i++){
         lastSum += a[i];
         ans = max(ans,lastSum);
     }
  // we distribute it in two half because we have to do a operation with one but not with other;
    //  lastSum = 0;
     for(int i = k; i<n; i++){
         lastSum -= a[i-k];
         
         lastSum += a[i];
         
         ans = max(ans,lastSum);
     }
    return ans;
    }

int main(){
  vector<int> v;
  for(auto i : v){
    cin>>v[i];
  }
  int n = v.size();
  int k = 3;
  cout<<maximumSumSubarray(k, a, n);
}
