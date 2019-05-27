#include <vector>
namespace Sort{
//快排,取第一个为参考值，每次排序目的是保证参考值左侧为小于等于参考值，右侧大于等于参考值
template<typename T>
void quickSort(std::vector<T>&data){
    QuickSort(data,0,data.size()-1);
}
template<typename T>
int SplitVec(std::vector<T>& data,int left,int right){
    //填坑分割，从右侧开始查找，找到小的，填到左坑，留下坑位，然后从左侧坑右移一个开始查，大的填到坑位，如此循环，知道相遇，将参考值填到最后那个坑位即可
    int i=left,j=right,stand=data[left];
    while(i<j){
        while(i<j && data[j]>stand) --j;
        if (i<j){
            data[i++]=data[j];
        }
        while(i<j && data[i]<stand) ++i;
        if(i<j){
            data[j--]=data[i];
        }
    }
    data[i]=stand;
    return i;
}
template<typename T>
void QuickSort(std::vector<T>& data,int left,int right){
    if (left>=right) return;
    int mid=SplitVec(data,left,right);
    QuickSort(data,left,mid-1);
    QuickSort(data,mid+1,right);
}
//归并排序，递归对称分割，然后合并，合并时排好序就行
template<typename T>
void mergeSort(std::vector<T> &data){
    MergeSort(data,0,data.size()-1);
}
#include<iostream>
template<typename T>
void MergeSort(std::vector<T> &data,int left,int right){
    if (left>=right) return;
    int mid=(left+right)/2;
    MergeSort(data,left,mid);
    MergeSort(data,mid+1,right);
    merge(data,left,mid,right);
}
template<typename T>
void merge(std::vector<T>&data,int left,int mid,int right){
    std::vector<T> temp;
    int i=left,j=mid+1;
    while(i<=mid && j<=right){
        if (data[i]<data[j]){
            temp.push_back(data[i++]);
        }else{
            temp.push_back(data[j++]);
        }
    }
    while(i<=mid) temp.push_back(data[i++]);
    while(j<=right) temp.push_back(data[j++]);
    for(size_t i=0;i<temp.size();++i)
    {
        data[left+i]=temp[i];
    }
}
//堆排序
template<typename T>
void heapSort(std::vector<T> &data){
    //先构建节点最大的树
    for (int i=data.size()/2-1; i>=0; --i){
        build(data,i,data.size());
    }
    for (int i=data.size()-1; i>0; --i){
        T temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        build(data,0,i);
    }
}

template<typename T>
void build(std::vector<T> &data,int node,int len){
    T temp=data[node];
    for (int i=node*2+1; i<len;i=i*2+1){
        if (i+1<len && data[i+1]>data[i]) ++i;
        if (data[i] > temp){
            data[node]=data[i];
            node=i;
        }
    }
    data[node]=temp;
}
};