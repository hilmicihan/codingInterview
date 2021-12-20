// link : https://www.interviewbit.com/problems/maximum-sum-combinations/
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.rbegin() , A.rend());
    sort(B.rbegin() , B.rend());
    int n = A.size();
    priority_queue<tuple<int,int,int>> pq;
    for(int i=0; i<n; i++)
    {
        pq.push({A[i] + B[0], i , 0});
    }
    vector<int> ans;
    while(C--)
    {
        auto [sum, i , j] = pq.top();
        //cout<<sum<<endl;
        pq.pop();
        ans.push_back(sum);
        pq.push({A[i] + B[j+1] ,i , j+1});
    }
    return ans;
}
