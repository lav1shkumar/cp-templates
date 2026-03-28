struct Node{
    int cnt;
    Node* arr[2];

    Node(){
        cnt=0;
        arr[0]=arr[1]=NULL;
    }


};

struct Trie{
    Node* root;
    Trie(){
        root=new Node();
    }



    void add(int x){
        Node* cur = root;
        for(int b=32;b>=0;--b){
            int bit = (x>>b)&1;

            if(cur->arr[bit]==NULL){
                cur->arr[bit]=new Node();
            }

            cur=cur->arr[bit];
            cur->cnt++;

        }
    }

    int query(int x){
        int ans=0;

        Node* cur = root;
        for(int b=32;b>=0;--b){
            int bit = (x>>b)&1;

            if(cur->arr[!bit]==NULL || cur->arr[!bit]->cnt<=0){
                cur=cur->arr[bit];
            }
            else{
                cur=cur->arr[!bit];
                ans|=(1<<b);
            }

        }

        return ans;
    }

    void remove(int x){
        Node* cur = root;
        for(int b=32;b>=0;--b){
            int bit = (x>>b)&1;
            cur=cur->arr[bit];
            cur->cnt--;
        }

    }

};
