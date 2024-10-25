// For all pair shortest path
int add(int &a, int &b)
{
    if(a==INT_MAX || b==INT_MAX || (a>0 && b>INT_MAX-a))
        return INT_MAX;
    return a+b;
}
void perform(vector<vector<int>> &matrix, int &n, int &k)
{
    for(int i=0;i<n;i++)
    {
        if(i==k)
            continue;
        for(int j=0;j<n;j++)
        {
            if(j==k || i==j)
                continue;
            matrix[i][j]=min(matrix[i][j],add(matrix[i][k],matrix[k][j]));
        }
    }
}
// Requires directed adjacency matrix
void floydWarshall(vector<vector<int>> &adjacencyMatrix){
    int n = adjacencyMatrix.size();
    if(adjacencyMatrix[0].size() != n){
        cout<<"This is not perfect adjacency matrix. Please try again!"<<endl;
        return;
    }
    for(int i=0; i<n; i++)
        adjacencyMatrix[i][i]=0;
    
    for(int i=0; i<n; i++)
        perform(adjacencyMatrix, n, i);
}