// 3408. Design Task Manager



using int2=pair<int , int>; 
int2 mp[100001];
class TaskManager {
    int maxI=-1;
    priority_queue<int2> pq;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& t: tasks){
            int  u=t[0], i=t[1], p=t[2];
            maxI=max(maxI, i);
            mp[i]={p, u};
            pq.emplace(p, i);
        }
    }
    ~TaskManager(){
        memset(mp, -1, 8*(maxI+1));
    }
    void add(int userId, int taskId, int priority) {
        mp[taskId]={priority, userId};
        pq.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].first=newPriority;
        pq.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) {
        mp[taskId].first=-1;
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [p, i] = pq.top();
            if (mp[i].first==p) {
                pq.pop();
                int u=mp[i].second;
                mp[i]={-1, -1};
                return u;
            }
            pq.pop();
        }
        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
