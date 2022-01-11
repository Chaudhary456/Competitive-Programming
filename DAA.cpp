//***************************************************************** SOUMYA CHAUDHARY *************************************************//
//******************************************************************  1900520130053 **************************************************//
//**************************************************************  (Information Technology) **************************************************//

#include <bits/stdc++.h>
using namespace std;

int vis[10000];
vector<int> v[10000];

// 1->Insertion Sort
void insertionSort(int ar[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int val = ar[i], hole = i;

        while (hole >= 0 && ar[hole-1] > val)
        {
            ar[hole ] = ar[hole-1];
            hole--;
        }
        ar[hole] = val;
    }
}

// 2->Merge Sort
void merge(int ar[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;

    int left[n1+1];
    int rit[n2+1];

     left[n1]=INT_MAX;
     rit[n2]=INT_MAX;

    for(int i=0;i<n1;i++)
    left[i]=ar[p+i];

    for(int i=0;i<n2;i++)
    rit[i]=ar[q+i+1];

    int i=0,j=0;

    for(int k=p;k<=r;k++)
    {
        if(left[i]<rit[j])
        ar[k]=left[i],i++;
        else
        ar[k]=rit[j],j++;
    }
}
void mergeSort(int ar[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(ar,l,m);
        mergeSort(ar,m+1,r);
        merge(ar,l,m,r);
    }
}


// 3->Count Sort
void countingSort(int ar[],int n)
{
    int ma=0;
    int B[n];
    for(int i=0;i<n;i++)
    ma=max(ar[i],ma);

    int co[ma+1]={0};
    
    for(int i=0;i<n;i++)
    co[ar[i]]++;

    for(int i=1;i<=ma;i++)
    co[i]=co[i]+co[i-1];

    for(int i=n-1;i>=0;i--)
    {
        B[co[ar[i]]-1]=ar[i];
        co[ar[i]]--;
    }

    for(int i=0;i<n;i++)
    ar[i]=B[i];
}

// 4->Quicksort
int partition(int ar[],int l,int h)
{
    int j=l-1;
    int p=h;

    for(int i=l;i<=h-1;i++)
    {
        if(ar[i]<ar[p])
        {
            j++;
            swap(ar[j],ar[i]);
        }
    }
    swap(ar[j+1],ar[p]);
        return j+1;
}
void quickSort(int ar[],int l,int h)
{
    if(l<h)
    {
        int p=partition(ar,l,h);

        quickSort(ar,l,p-1);
        quickSort(ar,p+1,h);
    }
}


// 5->Heap sort
void heapify(int ar[],int n, int i)
{
    int larg=i;
    int l=i*2+1;
    int r=i*2+2;

    if(l<n&&ar[l]>ar[larg])
    larg=l;
    if(r<n&&ar[r]>ar[larg])
    larg=r;

    if(larg!=i)
    {
        swap(ar[i],ar[larg]);

        heapify(ar,n,larg);
    }
}
void heapSort(int ar[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
        heapify(ar,n,i);

    for(int i=n-1;i>0;i--)
    {
        swap(ar[0],ar[i]);

        heapify(ar,i,0);
    }
}


// 6-> Binary Search
int binarySearch(int ar[],int l,int r,int key)
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(ar[m]==key)
        return m;
        else{
            if(key<ar[m])
            return binarySearch(ar,l,m-1,key);
            else
            return binarySearch(ar,m+1,r,key);
        }
    }
    else
    return -1;

}

// 7->LCS
void lcs(string a,string b)
{
    int x=a.length();
    int y=b.length();

    int t[x+1][y+1]={};

    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(a[i-1]==b[j-1])
            t[i][j]=t[i-1][j-1]+1;
            else
            {
                t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
    }

    string ans="";

    int i=x,j=y;

    while(t[i][j]!=0)
    {
        if(a[i-1]==b[j-1])
        {
            ans=ans+a[i-1];
             i--,j--;
        }
        else
        {
            if(t[i][j]==t[i-1][j])
            i--;
            else
            j--;
        }
    }
    reverse(ans.begin(),ans.end());

    cout<<"\nLongest common subsequence is: "<<ans<<endl<<"With length equal to "<<t[x][y]<<endl;;
}

// 8 -DFS
void dfs(int n)
{
    cout<<n<< " ";
    vis[n]=1;
    for(int i=0;i<v[n].size();i++)
    {
        if(vis[v[n][i]]==0)
        dfs(v[n][i]);
    }
}

// 9->BFS
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        cout<<f<<" ";

        for(int i=0;i<v[f].size();i++)
        {
            if(vis[v[f][i]]==0)
            {
                vis[v[f][i]]=1;
                q.push(v[f][i]);
            }
        }
    }
}

//10 -> Selectuon Sort
void selectionSort(int ar[],int n)
{
    for(int i=0;i<n-1;i++)
    {   int minn=i;
        
        for(int j=i+1;j<n;j++)
        if(ar[j]<ar[minn])
            minn=j;
        
        swap(ar[i],ar[minn]);
    }
}


void printArray(int ar[],int n)
{
    for(int i=0;i<n;i++)
    cout<<ar[i]<<" ";

    cout<<endl;
}

int main()
{
    int ch ,flag=0;
    while (1)
    {

        cout << "\n1 => Insertion Sort\n"
             << "2 => Merge Sort\n"
             << "3 => Counting Sort\n"
             << "4 => Quick Sort\n"
             << "5 => Heap Sort\n"
             << "6 => Binary Search\n"
             << "7 => LCS\n"
             << "8 => DFS\n"
             << "9 => BFS\n"
             << "10 => Selection Sort\n"
             << "0 => EXIT\n"
             << "Enter your choice\n\n";
        cin >> ch;

        if ((ch >= 1 && ch <= 6) || ch == 10)
        {
            int n;
            cout << "Enter array size\n";
            cin >> n;
            int ar[n];
            cout << "Enter array elements\n";
            for (int i = 0; i < n; i++)
            cin >> ar[i];

            if(ch==1)
            {
                insertionSort(ar,n);
                cout<<"Array after Insertion Sort\n";
                printArray(ar,n);
            }
            else if(ch==2)
            {
                mergeSort(ar,0,n-1);
                cout<<"Array after Merge Sort\n";
                printArray(ar,n);
            }
            else if(ch==3)
            {
                countingSort(ar,n);
                cout<<"Array after Counting Sort\n";
                printArray(ar,n);
            }
            else if(ch==4)
            {
                quickSort(ar,0,n-1);
                cout<<"Array after Quick Sort\n";
                printArray(ar,n);
            }
            else if(ch==5)
            {
                heapSort(ar,n);
                cout<<"Array after Heap Sort\n";
                printArray(ar,n);
            }
            else if(ch==10)
            {
                selectionSort(ar,n);
                cout<<"Array after Selection Sort\n";
                printArray(ar,n);
            }
            else if(ch==6)
            {
                int key;
                mergeSort(ar,0,n-1);
                cout<<"Enter element to be serached\n";
                cin>>key;
                int p=binarySearch(ar,0,n,key);

                if(p>=0)
                cout<<"Element is present at position "<<p+1<<endl;
                else
                cout<<"Element is not present"<<endl;
            }
        }
        else
        {
            if(ch==7)
            {
                string s1,s2;
                cout<<"Enter first string - "<<endl;
                cin>>s1;
                cout<<"\nEnter second string - "<<endl;
                cin>>s2;

                lcs(s1,s2);
            }
            else if(ch==8||ch==9)
            {
                int n,e,x,y;
                cout<<"Enter number of vertices\n";
                cin>>n;
                cout<<"Enter number of Edges\n";
                cin>>e;

                if(e>n*(n-1))
                {
                    cout<<"Too many edges for "<<n<<" vertices\n";
                    break;
                }

                

                cout<<"Enter edges\n";

                while(e--)
                {
                    cin>>x>>y;
                    
                        v[x].push_back(y);
                        v[y].push_back(x);
                }

                if(ch==8)
                {
                    cout<<"DFS traversal of graph - ";
                    for(int i=1;i<=n;i++)
                    {
                        if(vis[i]==0)
                        {
                            dfs(i);
                        }
                    }
                }
                else if(ch==9)
                {
                    cout<<"BFS traversal of graph - ";
                    for(int i=1;i<=n;i++)
                    {
                        if(vis[i]==0)
                        {
                            bfs(i);
                        }
                    }
                }
                memset(vis,0,sizeof(vis));
                for(int i=0;i<n;i++)
                v[i].clear();
            }
            else if(ch==0)
            break;
        }
    }
    return 0;
}