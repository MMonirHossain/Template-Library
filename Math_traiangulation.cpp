#include<bits/stdc++.h>
using namespace std;

//input the all point(x,y) and give the area of the polygon
float area_of_a_polygon(int n){
    if(n<3){return 0;}

    int x1,y1,x2,y2,x,y;
    float area=0,now;

    cin>>x1>>y1;
    x=x1;y=y1;

    for(int i=1;i<n;i++){
        cin>>x2>>y2;

        area=area+((float)(x1*y2-x2*y1)/2);
        cout<<area<<"\n";
        x1=x2;y1=y2;
    }

    cin>>x2>>y2;
    area=area+ ( (float)(x2*y-x*y2)/2 );

    return abs(area);
}


class point{
public:
    int x,y;
    point(int a,int b){
        x=a;
        y=b;
    }
};


//Give three point (A,B,C) where C is the testing point
//if C in left side return 1
int isLeft(point A,point B,point C){
    //cout<<A.x<<A.y<<B.x<<B.y<<C.x<<C.y<<"\n";
    int area=A.x*(B.y-C.y) - A.y*(B.x-C.x) + (B.x*C.y - C.x* B.y);
    if(area<0)return area;
    else return area;
}

int isLeft_fromnet(point A,point B,point C){

    int area=(B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x);
    if(area<0)return -1;
    if(area>0)return 1;
    return 0;
}


int main(){

freopen("in.txt","r",stdin);

int x,y;
cin>>x>>y;

point A(x,y);


cin>>x>>y;

point B(x,y);


cin>>x>>y;

point C(x,y);

cout<<isLeft(A,B,C);

return 0;
}
