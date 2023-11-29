#include <stdio.h>
struct Position
{
    int x;
    int y;
};
typedef struct Position P;

void fill_tiles(P center,P hole,int len){
    if(len < 1)
        return;
    // find the relative position
    int l = len / 2;
    P new_center;
    P new_hole;
    if((center.x-hole.x)>=0 && (center.y-hole.y)>=0){
        printf("1 %d %d\n",center.x,center.y);

    }
    else if((center.x-hole.x<0) && (center.y-hole.y)>=0){

    }
    else if((center.x-hole.x<0) && (center.y-hole.y)<0){

    }
    else if((center.x-hole.x>=0 && (center.y-hole.y)<0)){

    }
        
}

int main(){
    int l;
    int type_table[5] = {-1, 1, 2, 4, 3};
    P direction_table[4] = {};
    P hole;
    scanf("%d%d%d",&l,&hole.x,&hole.y);
    P center = {l/2,l/2};
    
    return 0;
}