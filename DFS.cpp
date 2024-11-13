#include<bits/stdc++.h>
using namespace std;
void DFS(int g[][5], int v,int vis[])
{
    
    stack<int> st;
    st.push(v);
    while(!st.empty())
    {
        int s= st.top();
        st.pop();
        if(vis[s]==0)
        {
            cout<<s<<"  ";
            vis[s]=1;
        }

        for(int j=0;j<=4;j++)
        {
            if(g[s][j]==1 && vis[j]==0)
            {
                st.push(j);
            }
        }
    }

}

int main()
{
    int g[][5]={{0,1,1,1,0},{1,0,0,0,0},{1,0,0,0,1},{1,0,0,0,0},{0,0,1,0,0}};
    int vis[5] = {0}; 
    cout<<"DFS:";
    DFS(g,0,vis);
    cout<<endl;
    cout<<"23CE058 prepared by dharmik";
}