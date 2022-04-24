#include <bits/stdc++.h>
using namespace std;

///Implemented using min heap
class PriorityQueue
{
    vector<int> pq;
    public:
    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()) return 0;
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);  ///CBT Property satisfied, Heap not satisfied
        int cI = pq.size() - 1;
        while(cI > 0){
            int pI = (cI-1)/2;
            if(pq[cI] < pq[pI]){
                swap(pq[cI], pq[pI]);
                cI = pI;
            }else{
                break;
            }
        }
    }

    int removeMin(){
        if(isEmpty()) return 0;
        int lastIndex = pq.size() - 1;
        swap(pq[0], pq[lastIndex]);
        int ans = pq[lastIndex];
        pq.pop_back();

        int pI = 0;
        while(true){
            int lcI = 2*pI+1;
            int rcI = 2*pI+2;
            int minIndex = pI;

            if(pq[lcI] < pq[minIndex] && lcI < pq.size()){
                minIndex = lcI;
            }
            if(pq[rcI] < pq[minIndex] && rcI < pq.size()){
                minIndex = rcI;
            }
            if(minIndex == pI){
                break;
            }
            swap(pq[pI], pq[minIndex]);
            pI = minIndex;
        }
        return ans;
    }
};

int main()
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(45);
    p.insert(58);
    p.insert(25);
    p.insert(65);
    p.insert(21);
    cout<<p.getSize()<<endl;
    cout<<p.removeMin()<<endl;

    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";
    }