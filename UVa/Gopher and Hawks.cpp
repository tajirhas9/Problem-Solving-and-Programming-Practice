#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define MAX 100000
struct points
{
    double x,y,level;
};
points source,d;
vector <points> graph;
queue <points> q;
int velocity,minuites;
int main()
{
    char s[100];
    double u,v,dis;
    int i=0,j,l,flag=0;
    points top;
    while(1)
    {
        i=0;
        cin >> velocity >> minuites;
        if(velocity == 0 && minuites == 0)    return 0;
        cin >> source.x >> source.y;
        graph.push_back(points());
        graph[i].x = source.x;
        graph[i].y = source.y;
        graph[i].level = 0;
        i++;
        q.push(source);
        cin >> d.x >> d.y;
        graph.push_back(points());
        graph[i].x = d.x;
        graph[i].y = d.y;
        graph[i].level = MAX;
        i++;
        getchar();
        while(gets(s))
        {
            if(strlen(s) == 0) break;
            sscanf(s,"%lf %lf",&u,&v);
            graph.push_back(points());
            graph[i].x = u;
            graph[i].y = v;
            graph[i].level = MAX;
            i++;
            while(strlen(s))
            {
                s[strlen(s)-1] = '\0';
            }
        }
        while(!q.empty())
        {
            top = q.front();
            q.pop();
            for(j=0;j<graph.size();j++)
            {
                dis = ((top.x-graph[j].x)*(top.x-graph[j].x))+((top.y-graph[j].y)*(top.y-graph[j].y));
                dis = sqrt(dis);
                if(dis <= (velocity*minuites*60) && graph[j].level == MAX)
                {
                    points it;
                    it.x = graph[j].x;
                    it.y = graph[j].y;
                    it.level = top.level + 1;
                    graph[j].level = it.level;
                    q.push(it);
                    if(graph[j].x == d.x && graph[j].y == d.y)
                    {
                        flag = 1;
                        l = it.level;
                    }
                }
            }
        }
        if(flag == 1)
            cout << "Yes, visiting " << l-1 << " other holes." << endl;
        else
            cout << "No." << endl;
        flag = 0;
        graph.clear();
    }
}
