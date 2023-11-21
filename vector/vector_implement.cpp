#include<iostream>
#include<assert.h>
using namespace std;

// create a class of Vector with capital V
class Vector {
    private:
        int size {};
        int *array = nullptr ;
    
    public:
    // this fun calls (( constructor )) begin with name of the class without datatype
        Vector(int size): size(size){
            if(size < 0)
                size =1;
            array=new int [size] {};
        }
    //this fun is (( called deconstructor )) begin with ~ 
        ~Vector(){
            delete[] array;
            array = nullptr;
        }
    // let build a set & get functions
        int get(int idx){
            assert(0 <= idx && idx < size); // to check if the idx in range
            return array[idx];
        }

        void set(int idx, int val){
            assert( 0 <= idx && idx < size);
            array[idx] = val;
        }
    // to print all items of vector
        void print(){
            for(int i=0; i < size; ++i)
                cout<<array[i]<<" ";
            cout<<"\n";
            }
    // to find a value in vector and return its index
        int find(int val){
            for(int i=0; i < size; ++i)
                if(array[i] == val)
                    return i;
            return -1; // for not found value
        }

};


int main(){


    return 0;
}