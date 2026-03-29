struct DSU{
    int n;
    vector<int> par,size,sum;

    DSU(int x){
        n=x;
        size.assign(n,1);
        sum.assign(n,0);
        par.resize(n);
        for(int i=0;i<n;++i) par[i]=i;
    }

    int find(int x){
        
        if(par[x]==x) return x;

        int root = find(par[x]);

        sum[x]+=sum[par[x]];

        par[x]=root;
        return root;

    }

    void join(int u,int v,int w){
        int a=find(u);
        int b=find(v);

        if(a==b) return;
    
        if(size[b]>size[a]){
           swap(a,b);
           swap(u,v);
           w=-w;
        }

        par[b]=a;
        size[a]+=size[b];
        sum[b] = sum[u]-sum[v]+w;
    }

};
