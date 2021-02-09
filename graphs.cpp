#include <bits/stdc++.h>
using namespace std;

vector<int>vect;
class Graph {
    int V;  
    list<int>* adj;
    void recDFS(int v, bool visited[],int limit,int t);
 
public:
    Graph(int V); 
    void addEdge(int v, int w);
    void DFS(int v, int limit);
    void BFS(int src,int dest,int paren[],int it);
    void printPath(int s,int dest);
    void display(int goal,int it);
    void IDS(int v, int limit);
    void IBS(int src,int it);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int src, int dest)
{
    adj[src].push_back(dest); 
}
 
void Graph::recDFS(int v, bool visited[],int limit,int t)
{
    //if(!limit)
    //vect.push_back(-1);
    if(!t){
    visited[v] = true;
    vect.push_back(v);
    limit=limit-1;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i] && limit>0)
            recDFS(*i, visited,limit,t);
    }
    else
    {
    visited[v] = true;
    vect.push_back(v);
    //limit=limit-1;
    list<int>::iterator i;
    int j;
    for (i = adj[v].begin(),j=1; i != adj[v].end(); ++i,++j)
        if (!visited[*i] && j<=t)
            recDFS(*i, visited,limit,t);
    }
    //if(!limit)
    //	vect.push_back(-1);
}
 
void Graph::DFS(int v, int limit)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    recDFS(v, visited,limit,0);
}

void Graph::IBS(int src,int it)
{
	for(int j=1;j<=it;j++)
	{
    	bool* visited = new bool[V];
    	for (int i = 0; i < V; i++)
        	visited[i] = false;
    	recDFS(src, visited,it,j);
    	vect.push_back(-1);
    	//cout<<"\nABCD\n";
    }	
} 

void Graph::IDS(int v, int limit)
{
	for(int i=1;i<limit;i++)
	{
    	bool* visited = new bool[V];
    	for (int i = 0; i < V; i++)
        	visited[i] = false;
    	recDFS(v, visited,i,0);
    	vect.push_back(-1);
    	//cout<<"\nABCD\n";
    }
}

void Graph::BFS(int src,int dest,int paren[],int it)
{

   
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        paren[i]=-1;
    }
 
    list<int> queue;
 
    
    visited[src] = true;
    queue.push_back(src);
 
    
    list<int>::iterator i;
    int j;
 	if(!it)
 	{
	    while(!queue.empty())
	    {

	        src = queue.front();
	       vect.push_back(src);
	        queue.pop_front();
	 
	        for (i = adj[src].begin(); i != adj[src].end(); ++i)
	        {
	            if (!visited[*i])
	            {
	                visited[*i] = true;
	                paren[*i]=src;
	                queue.push_back(*i);
	                //need check
	            }
	        }
	    }
	}
	/*else
	{
		while(!queue.empty())
	    {

	        src = queue.front();
	       vect.push_back(src);
	        queue.pop_front();
	 
	        for (i = adj[src].begin(),j=1; i != adj[src].end(); ++i,++j)
	        {
	        	if(j>it)
	        		break;
	            if (!visited[*i])
	            {
	                visited[*i] = true;
	                paren[*i]=src;
	                queue.push_back(*i);
	                //need check
	            }
	        }
	    }
	}*/
}

/*void Graph::IBS(int src,int dest,int paren[],int it)
{
		for(int i=1;i<=it;i++)
		{
			BFS(src,dest,paren,i);	
			vect.push_back(-1);
		}
}*/

void Graph::display(int goal,int it)
{
	if(!it)
	cout<<"Order : ";
	else
		cout<<"\nIteration "<<it++<<": ";
	    for(auto i=vect.begin();i!=vect.end();i++)
	    {
	    	if(*i==-1)
	        	cout<<"\nIteration "<<it++<<": ";
	        else
	        cout << *i << " ";
	        if(*i==goal)
	            break;
    	}
}


void Graph::printPath(int s,int dest)
{

    int paren[V];
 
    BFS(s,dest,paren,0);
 
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (paren[crawl] != -1) {
        path.push_back(paren[crawl]);
        crawl = paren[crawl];
    }
 
    cout << "\nPath : ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}



int main()
{
    int start,goal,n,u,v;
    cout<<"\nEnter the highest value node in the graph : ";
    cin>>n;
    n=n+1;
    int arr[n];
    Graph g(n);
    //Graph g(4);
    //int num[13]={1,2,3,4,5,6,7,8,9,10,11,14,15};
    while(u!=-1)
    {
    	cout<<"\nEnter the edge between two nodes(u,v), press -1 to denote all the edges have been inserted : ";
    	cin>>u>>v;
    	if(u==-1) break;
    	if(u<0 || v<0 || u>n || v>n)
    		cout<<"\nEnter a valid input\n";
    	else
    	g.addEdge(u,v);
    }
    /*g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);*/

  cout<<"\nEnter the start node"<<endl;
  cin>>start;
  cout<<"\nEnter the goal node"<<endl;
  cin>>goal;
  //if(start>=0 && start<=n && goal>=0 && goal<=n)
  int ch,limit,flag,flag2;
  while(ch!=6)
  {
  	  vect.clear();
  	  cout<<"\nEnter your choice 1. BFS 2. DFS 3. DLS 4. IDS 5. IBS 6. Exit\n-> ";
	  cin>>ch;
	  switch(ch)
	  {
	  	case 1:	
	  			g.BFS(start,goal,arr,0);
	  			g.display(goal,0);
	  			vect.clear();
	  			g.printPath(start, goal);
	  			break;
	  	case 2: vect.clear();
	  			g.DFS(start,n);
	  			g.display(goal,0);
	  			g.printPath(start, goal);
	  			break;
	  	case 3: vect.clear();
	  			flag=1;
	  			flag2=0;
	  			cout<<"\nEnter Depth limit : ";
	  			cin>>limit;
	  			limit=limit+1;
	  			g.DFS(start,limit);
	  			for(int i=0;i<vect.size();i++)
	  			{
					if(vect[i]==-1)
					{
						cout<<"\nPath not found in the given limit\n";
						flag=0;
						break;
					}
					if(vect[i]==goal)
						{
							flag2=1;
							break;
						}
				}
				if(!flag2)
					cout<<"\nPath not found within the given limit\n";
				else if(flag){
	  			g.display(goal,0);
	  			g.printPath(start,goal);
	  			}
	  			break;
	  	case 4: vect.clear();
	  			g.IDS(start,n);
	  			g.display(goal,1);
	  			g.printPath(start, goal);
	  			break;
	  	case 5: vect.clear();
	  			g.IBS(start,n);
	  			cout<<"\nIteration 1: "<<start;
	  			g.display(goal,2);
	  			g.printPath(start, goal);
	  			break;
	  }
  }
   
    return 0;
}