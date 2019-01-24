#include<bits/stdc++.h>
using namespace std;
///字符串匹配-----暴力搜索 && KMP算法

///暴力搜索
int Brute_Force(char text[],char pattern[],int text_len,int pattern_len){
    int i,j;
    for( i = 0 ; i <= text_len-pattern_len ; i++ ){
        for( j = 0 ; j < pattern_len && pattern[j] == text[i+j] ; j++);
        if(j >= pattern_len)return i;//找到
    }
    return -1;
}

///KMP算法
void Pre_for_KMP(char pattern[],int next[]){
    int pattern_len=strlen(pattern);
    int i = 0 , j = next[0] = -1;
    while( i < pattern_len ){
        while(-1 != j && pattern[i] != pattern[j]){
            j = next[j];
        }
        next[++i]  =  ++j;
    }

//    输出next数组
//   for(int i=0;i<pattern_len;i++){
//       cout<<next[i]<<" ";
//   }cout<<endl;
}

int KMP_Substr_Seach(char text[],char pattern[]){
    int next[1000];
    Pre_for_KMP(pattern,next);
    int i=0,j=0,m,n;
    m=strlen(text);
    n=strlen(pattern);
    //text[i]      len(text)=m;
    //pattern[j] len(pattern)=n;
    while( i < m ){
       if( j == n-1 && text[i]==pattern[j]){
           return i-j;
       }
        if( text[i] == pattern[j] ){
            i++; j++;
        }else{
            j = next[j];
            if( j == -1){
                i++;j++;
            }
        }
    }
}
int main(){
    //变量的定义
    char text[]="abababcabaa";
    char pattern[]="ababcabaa";
    int text_len=strlen(text),pattern_len=strlen(pattern);
    //暴力搜索输出
    cout<<Brute_Force(text,pattern,text_len,pattern_len)<<endl;

    //KMP算法
    cout<<KMP_Substr_Seach(text,pattern)<<endl;
}
