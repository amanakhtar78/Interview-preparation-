#include <bits/stdc++.h>
using namespace std;
//void dont return anything 
void pairNumbersVoid(){
    pair<int,int>a={1,4};
    cout<< a.first<<" void -->"<<a.second<<endl;
}
//single int export only 1 int number  
int  pairNumbersSingleExport(){
    pair<int,int>a={1,4};
    return  a.first;
}
//single char export only 1 char number  
char  pairCharacterSingleExport(){
    char a='a';
    return  a;
}

//pair export export both the pair  
pair<int,int> pairNumbersBothExpor(){
    pair<int,int>a={1,4};
    return a;
}
int main (){
    cout<<"aman"<<endl;

    //void dont return anything 
    pairNumbersVoid();



    //single int export only 1 int number  
    int onlySingleExport = pairNumbersSingleExport();
    cout<<"single function -->"<<onlySingleExport<<endl;


    //single char export only 1 char number  
    char pairCharacterSingle = pairCharacterSingleExport();
    cout<<"single charater -->"<<pairCharacterSingle<<endl;



    //pair export export both the pair  
    pair <int, int> outputBothExport = pairNumbersBothExpor();
    cout<<outputBothExport.first<<" pair -->"<<outputBothExport.second;


    return 0;
}