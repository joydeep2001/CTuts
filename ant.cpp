#include<bits/stdc++.h>
using namespace std;

double dist[20][20];
double T[10][10];//PHEROMONE MATRIX
 


class node
{
    int x;
    int y;
public:
    vector<pair<double,double>>co_ord;
    void get_node(int n);
    void calculate_dist(int n);
    
};




void node::get_node(int n)
{

    int a,b;
    for(int i=0 ;i<n; i++){
        cout<<"Enter "<<i+1<<" node"<<endl ;
        cin>>a>>b;
        co_ord.push_back(make_pair(a,b));
    }
    
  cout<<" Calculating Distance : "<<endl ;
    
    calculate_dist(n);
}
void node::calculate_dist(int n)
{
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
            {

    dist[i][j] = pow((pow((co_ord[i].first - co_ord[j].first),2))+(pow((co_ord[i].second - co_ord[j].second),2)),0.5);
            }
        }
      
    }
    
    cout<<endl ;
}


class ACO 
{
    int ants;
    int cities;
    double L[10][10] ;
    int path[10][10] ;
   int  vis[20] ;
    
public:
 
  
    ACO(int ant , int city)
    {
      
         ants=ant;
         cities=city;
       
       //pheromone matrix update
      
       for(int i=0 ;i<cities; i++){
           
         for(int j=0 ;j<cities ;j++){
           
             if(i==j) T[i][j]=0 ;
             
             else T[i][j]=1 ;
         }
       }
       
    cout<<" ACO object creation Successful "<<endl ;
    }
    
    int find_path();
    
    int next_probable_node(int curr);
    
    void show_details() ;


};//END OF ACO class




int ACO::next_probable_node(int curr)
{
 
    double max_probability=0;
    double s=0;
    double probab ;
    int k;
    float alpha=0.5 , beta=0.5 ;
    
    for(int next =0;next<cities;next++)
    {
       if(curr != next) 
       {
         
    s += pow((T[curr][next]),alpha) * pow((1/dist[curr][next]),beta) ;
       } 

    }
    for(int next =0;next<cities ; next++)
    {
       
       if(curr == next)
       {
         continue;
        }
    
        
    if(!vis[next])
   {
         double t ;
      
     t = pow((T[curr][next]),alpha) * pow((1/dist[curr][next]),beta) ;
     
     
     probab = t/s ;
     
    
    if(probab>max_probability)
    {
        max_probability=probab;
        k=next;
   
    }
    
    
    }
    
   }
   
   
   vis[k]=1;
    return k;
}





int ACO::find_path()
{
  
int curr , next , from,to;
float evapr ;


//initialise Length Matrix

   for(int x=0 ;x<cities;x++){
     for(int q=0;q<cities;q++)
         L[x][q]=0 ;
     }
     
     
     for(int x=0 ;x<cities;x++){
     for(int q=0;q<cities;q++)
         path[x][q]=0 ;
     }     
     
     
         
    

    for(int i=0;i<ants;i++) //no of iterations
    {
     
        for(int p=0 ; p<cities ; p++)
        {
             
          for(int x=0 ;x< sizeof(vis);x++)
                vis[x]=0 ;
             
            int temp=cities-1;
            
             curr=p; 
             vis[curr]=1 ;
             
             int k=0 ;
             
            while(temp--)
            {  
               next = next_probable_node(curr);
  
                 L[i][p]+=dist[curr][next];
                 
              
               path[p][k++]=next ;
                    
                curr=next;
      
            }
     
            L[i][p]+=dist[curr][p];
            
             path[p][k++]= p;
    
    cout<<endl ;
            

//display path matrix         
   cout<<"starting from "<<p<<" node of  "<<i<<" iteration "<<endl ;
    cout<<"path Matrix  "<<endl ;
    for(int x=0; x < cities ;x++){
     
      for (int it = 0; it<cities ; it++)
          cout<<path[x][it]<<" " ;

           cout << endl ;
         }
    
    
       
    }
    
   cout<<i<<" th iteration comlt "<<endl ;
   
   
   
  cout<<"pheromone  matrix "<<endl ;
  
  for(int x=0 ;x<cities;x++){
     for(int q=0;q<cities;q++)
         cout<<  T[x][q] <<" ";
    cout<<endl ;     
     }
     
     
   cout<<endl;
   
  
  //impact of evaporation rate

for(int i=0;i<cities;i++)
{
    for(int j=0;j<cities;j++)
        T[i][j]=((1-evapr)*(T[i][j]));
}


 //pheromone update due to ants movement
 
  for(int itr=0;itr<cities;itr++)
     {
        from=itr ;
        
        for(int j=0;j<cities;j++)
        {

            to=path[from][j] ;
            T[from][to]+=(1/L[i][from]);
            
        }
    }
  
 
 }
 return 0;
 }
 
 
      
 
 
void ACO::show_details() 
{  
    double min=999 ;
    int start ;
    
for(int i=0; i< cities ;i++)
  {
    if(L[cities-1][i] < min)
    {
        min=L[cities-1][i] ; start=i ;
    }
  }
    
  cout<<" Length of shortest path : "<< min <<endl;
  
  cout<<" shortest Path is : "<<start<<"->";
  
  for(int i=0; i< cities ;i++)
  {
    cout<<path[start][i]<<"->" ;
  }
  
  cout<<"Reached"<< endl;
  
  cout<<"length matrix "<<endl ;
  
  for(int x=0 ;x<cities;x++){
     for(int q=0;q<cities;q++)
         cout<<  L[x][q] <<" ";
    cout<<endl ;     
     }
  

  
}    
        
        
   int main()
   {
              int n ;
               cout<<"Enter no of cities "<<endl ;
                cin>>n;
                
                node data;
                
                data.get_node(n);
                
                ACO shortest_path(n,n);
                
                shortest_path.find_path();
                
                shortest_path.show_details() ;
                     
                
              return 1 ;
    }