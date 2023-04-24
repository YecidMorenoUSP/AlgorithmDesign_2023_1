#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct job
{
    int id;
    int time;
    int fine;
};

bool compareJobs(job &A , job &B){
    if(A.time*B.fine == B.time*A.fine) 
    return A.id < B.id;
    return (A.time*B.fine < B.time*A.fine);
}

int main(){

    int _N,_N_jobs;
    scanf("%d",&_N);
    
    for(int N = 0 ; N < _N ; N++){
        scanf("%d",&_N_jobs);
        
        vector<job> jobs(_N_jobs);

        for(int N_job = 0 ; N_job < _N_jobs ; N_job++){
            scanf("%d %d",&jobs[N_job].time,&jobs[N_job].fine);
            jobs[N_job].id = N_job+1;
        }

        sort(jobs.begin(),jobs.end(),compareJobs);

        for(int N_job = 0 ; N_job < _N_jobs ; N_job++){
            if(N_job == 0) printf("%d",jobs[N_job].id);
            else printf(" %d",jobs[N_job].id);
        }
        
        if(_N == 1) printf(" \n");
        else printf((_N-1)==(N)?"\n":"\n\n");

    }

    return 0;
}