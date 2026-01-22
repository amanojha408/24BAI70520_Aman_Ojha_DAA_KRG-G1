#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& time) 
{
    if (time[x] == x) return x;
    return time[x] = find(time[x], time);
}

pair<int, int> jobSeq(vector<pair<int, int>> jobs)
{
    int n = jobs.size(), count = 0, prof = 0;
    sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

    vector<int> time(n + 1);
    for(int i = 0; i <= n; i++)
    {
        time[i] = i;
    }
    for(int i = 0; i < n; i++)
    {
        int start = min(n, jobs[i].second);
        int empty = find(start, time);
        
        if(empty > 0)
        {
            count++;
            prof += jobs[i].first;
            time[empty] = find(empty - 1, time);
        }
    }
    return {count, prof};
}

int main()
{
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;

    vector<pair<int, int>> jobs(n);
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter the profit and deadline of job "<<i + 1<<": ";
        cin>>jobs[i].first>>jobs[i].second;
    }
    pair<int, int> ans;
    ans = jobSeq(jobs);
    cout<<"Number of jobs performed: "<<ans.first<<endl;
    cout<<"Total profit: "<<ans.second<<endl;
    
    return 0;
}
