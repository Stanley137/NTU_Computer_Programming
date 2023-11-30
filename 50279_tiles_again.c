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
    // printf("center: %d %d\n",center.x,center.y);
    // printf("hole: %d %d\n",hole.x,hole.y);
    // printf("len: %d\n", len);
    // printf("center: %p\n", &new_center);
    // printf("hole: %p\n", &new_hole);
    if((hole.x - center.x)>=0 && (hole.y- center.y)>=0){
        printf("1 %d %d\n",center.x,center.y);
        // 1
        new_center.x = center.x + l; new_center.y = center.y + l;
        fill_tiles(new_center,hole,l);
        // 2
        new_center.x = center.x - l; new_center.y = center.y + l;
        new_hole.x = center.x - 1; new_hole.y = center.y;
        fill_tiles(new_center,new_hole,l);
        // 3
        new_center.x = center.x - l; new_center.y = center.y - l;
        new_hole.x = center.x - 1; new_hole.y = center.y - 1;
        fill_tiles(new_center,new_hole,l);
        // 4
        new_center.x = center.x + l; new_center.y = center.y - l;
        new_hole.x = center.x; new_hole.y = center.y - 1;
        fill_tiles(new_center,new_hole,l);
    }
    else if(((hole.x - center.x)<0) && (hole.y- center.y)>=0){
        printf("2 %d %d\n", center.x, center.y);
        // 2
        new_center.x = center.x - l; new_center.y = center.y + l;
        fill_tiles(new_center,hole,l);
        // 3
        new_center.x = center.x - l; new_center.y = center.y - l;
        new_hole.x = center.x - 1; new_hole.y = center.y - 1;
        fill_tiles(new_center,new_hole,l);
        // 4
        new_center.x = center.x + l; new_center.y = center.y - l;
        new_hole.x = center.x; new_hole.y = center.y - 1;
        fill_tiles(new_center,new_hole,l);
         // 1
        new_center.x = center.x + l; new_center.y = center.y + l;
        new_hole.x = center.x; new_hole.y = center.y;
        fill_tiles(new_center,new_hole,l);
    }
    else if((hole.x - center.x>=0) && (hole.y- center.y)<0){
        printf("3 %d %d\n", center.x, center.y);
        // 4
        new_center.x = center.x + l; new_center.y = center.y - l;
        fill_tiles(new_center,hole,l);
        // 1
        new_center.x = center.x + l; new_center.y = center.y + l;
        new_hole.x = center.x; new_hole.y = center.y;
        fill_tiles(new_center,new_hole,l);
        // 2
        new_center.x = center.x - l; new_center.y = center.y + l;
        new_hole.x = center.x - 1; new_hole.y = center.y;
        fill_tiles(new_center,new_hole,l);
        // 3
        new_center.x = center.x - l; new_center.y = center.y - l;
        new_hole.x = center.x - 1; new_hole.y = center.y - 1;
        fill_tiles(new_center,new_hole,l);

    }
    else if(((hole.x - center.x)<0 && (hole.y- center.y)<0)){
        printf("4 %d %d\n", center.x, center.y);
        // 3
        new_center.x = center.x - l; new_center.y = center.y - l;
        fill_tiles(new_center,hole,l);
        // 4
        new_center.x = center.x + l; new_center.y = center.y - l;
        new_hole.x = center.x; new_hole.y = center.y-1;
        fill_tiles(new_center,new_hole,l);
        // 1
        new_center.x = center.x + l; new_center.y = center.y + l;
        new_hole.x = center.x; new_hole.y = center.y;
        fill_tiles(new_center,new_hole,l);
        // 2
        new_center.x = center.x - l; new_center.y = center.y + l;
        new_hole.x = center.x-1; new_hole.y = center.y;
        fill_tiles(new_center,new_hole,l);
    }
    return;
}

int main(){
    int l;
    int type_table[5] = {-1, 1, 2, 4, 3};
    P direction_table[4] = {};
    P hole;
    scanf("%d%d%d",&l,&hole.x,&hole.y);
    P center = {l/2,l/2};
    fill_tiles(center,hole,l/2);
    return 0;
}