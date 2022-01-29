#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Carrots{
    int weight;
    int length;
    char name[20];
    
public:
    Carrots();//建構函數
    Carrots(int w,int l);//建構函數
    Carrots(int w,int l, const char* new_name="carrots");
    ~Carrots();//解構函數
    void show();
};

Carrots::Carrots(){
    weight = 50; //defalut constructor
    length = 10;
}
Carrots::Carrots(int w,int l){
    weight = w; //defalut constructor
    length = l;
}

Carrots::Carrots(int w,int l,const char* new_name="carrots"){
    weight = w; 
    length = l;
    strcpy(name,new_name);
}

Carrots::~Carrots(){
    cout << "delete carrots" << endl;
}
void Carrots::show(){
    cout <<"weight : " << weight << endl;
    cout <<"length : " << length << endl;
}
int main(){
    
    Carrots obj;
    Carrots obj2(30,30);
    Carrots *obj3;
    obj3 = &obj2;
    Carrots obj4(30,30,"carrots");
    
    
    obj.show();
    obj2.show();
    
    obj3->show();
    return 0;
}