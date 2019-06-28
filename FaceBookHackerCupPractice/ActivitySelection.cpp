//More greedy Algorithms
#include <bits/stdc++.h>
using namespace std;

struct Activity{
    int start,finish;
};

bool activityCompare(Activity s1, Activity s2){
    return (s1.finish<s2.finish);
}

void printMaxActivities(Activity arr[],int n){
    sort(arr,arr+n,activityCompare);
    printf("Following activities are selected\n");
    int j = 0;
    printf("(%d,%d),",arr[j].start,arr[j].finish);
    for(int i=1;i<n;i++){
        if(arr[i].start>=arr[j].finish){
            printf("(%d,%d),",arr[i].start,arr[i].finish);
            j=i;
        }
    }
}

void printMaxActivities(int s[],int f[],int n){
    int j=0;
    printf("Following activities are selected\n");
    printf("%d ",j);
    for(int i=1;i<n;i++){
        if(s[i]>=f[j]){
            printf("%d ",i);
            j=i;
        }
    }
}

//using a priority queue
void SelectActivities(vector<int>s,vector<int>f){
    vector<pair<int,int>>ans;
    //supports removing the smallest pairt
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    for(unsigned int i=0;i<s.size();i++){
        //the key is f[i] so it has to be the first one
        p.push(make_pair(f[i],s[i]));
    }
    auto it = p.top();
    int start = it.second;
    int end = it.first;
    p.pop();
    ans.push_back(make_pair(start,end));
    while(!p.empty()){
        auto itr = p.top();
        p.pop();
        if(itr.second>=end){
            start = itr.second;
            end = itr.first;
            ans.push_back(make_pair(start,end));
        }
    }
    printf("Following activities are selected\n");
    for(auto itr=ans.begin();itr!=ans.end();itr++){
        printf("Activity started at: %d and ends at %d\n",(*itr).first,(*itr).second);
    }
}

int main(){
    FILE *fp=freopen("output.txt","w",stdout);

    //presorted
    int s[] = {1,3,0,5,8,5};
    int f[] = {2,4,6,7,9,9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s,f,n);
    printf("\n");

    //not presorted
    Activity arr[] = {{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
    n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivities(arr,n);
    printf("\n");
    
    /*priority queue*/
    vector<int> s1 = {1,3,0,5,8,5};
    vector<int> f1 = {2,4,6,7,9,9};
    SelectActivities(s1,f1);

    fclose(fp);
    return 0;
}
