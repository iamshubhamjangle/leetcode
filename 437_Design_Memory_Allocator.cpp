/*
Design_Memory_Allocator.cpp

https://discord.com/channels/981595631636316200/981595632181604378
*/


class Allocator {
public:
    vector<int> array;
    unordered_map<int, int> mpp;
    int n;

    Allocator(int n) {
        this->n=n;
        array.resize(n);
    }
    
    int allocate(int size, int mID) {
        for(int i=0; i<n; i++){
            if(array[i]==0){
                int k=i, b=0;
                while(i<n and array[i]==0){
                    i++, b++;
                    if(b==size) break;
                }
                if(b>=size){
                    for(int j=k; j<k+size; j++)
                        array[j]=mID;
                    mpp[mID]=k;
                    
                    return k;
                }
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int i=mpp[mID], b=0;
        for(int i=0; i<n; i++){
            if(array[i]==mID)
                b++, array[i]=0;
        }
        mpp.erase(mID);
        return b;
    }
};