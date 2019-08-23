#include <bits/stdc++.h>

// FIXME ????
// 如果时刻t同时有m个staff和n个job，题目所述规则是否会冲突？

using namespace std;

struct Job{
    int id;
    int num, start, busy, idle;
};

struct Staff{
    int id;
    int busy_until;
    int last_job_start;
    int working_job_id;
    vector<int> capable;
};

map<int, Job> job_map;
vector<Staff> staffs;

vector<pair<int,int>> arrive_time;  // time, job_id
queue<pair<int,int>> waiting_job;  // time, job_id

void arrange_proper_staff(int cur_time){
    // map<int, vector<int>> cand_staff_per_job;  // {job_id : [staff]}

    int qsize = waiting_job.size();
    for(int i=0; i<qsize; i++){
        pair<int, int> p = waiting_job.front(); waiting_job.pop();
        int arrive_time = p.first, job_id = p.second;

        for(int si=0; si<staffs.size(); si++){
            if(cur_time < staffs[si].busy_until) continue;
            for(int j=0; j<staffs[si].capable.size(); j++){
                int cap_job_id = staffs[si].capable[j];
                // if(cap_job_id == )

            }
        }
    }
    return ;
}

void analysis_execute_time(){
    for(int i=0; i<arrive_time.size(); i++){
        int cur_time = arrive_time[i].first;
        int job_id = arrive_time[i].second;

        // update waiting_job/staffs
        waiting_job.push(make_pair(cur_time, job_id));
        arrange_proper_staff(cur_time);
    }

    // arrange remain jobs

}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, staff_id, n_cover, t;
    while(cin>>n && n != 0){
        for(int i=0; i<n; i++){
            Job job;
            cin>>job.id>>job.num>>job.start>>job.busy>>job.idle;
            job_map[job.id] = job;
            
            for(int j=0; j<job.num; j++){
                arrive_time.push_back(
                    make_pair(job.id, job.start + j*(job.busy+job.idle)));
            }
        }

        cin>>n;
        for(int i=0; i<n; i++){
            Staff staff;
            cin>>staff.id>>n_cover;
            for(int j=0; j<n_cover; j++){
                cin>>t;
                staff.capable.push_back(t);
            }
            staff.busy_until = 0;
            staff.last_job_start = 0;
            staff.working_job_id = -1;
            staffs.push_back(staff);
        }

        sort(arrive_time.begin(), arrive_time.end(), [](
            pair<int,int>&left, pair<int,int>&right){
            return left.first < right.first;
        });

        analysis_execute_time();
    }
}