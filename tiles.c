#include <stdio.h>
struct tile
{
    int x;
    int y;
};
typedef struct tile Tile;
int check(int x,int y,int l,int m){
    if(x==l-m && y==l-m){
        //printf("%d %d\n", x, y);
        return 1;
    }
    else if(x<=0 || y<=0 || x>=l || y>=l || (x==l-m || y==l-m))
        return 0;
    else 
        return 1;
}

void put_tile(int type,Tile tiles[],int x, int y,int l,int m){
    if(check(x,y,l,m)){
        printf("%d %d %d\n", type+1,x,y);
        if(type == 0){ 
            put_tile(3, tiles, x+tiles[3].x, y+tiles[3].y,l,m);
            put_tile(0, tiles, x+tiles[0].x, y+tiles[0].y,l,m);
            put_tile(1, tiles, x+tiles[1].x, y+tiles[1].y,l,m);
        }
        else if(type == 1){
            put_tile(0, tiles, x+tiles[0].x, y+tiles[0].y, l, m);
            put_tile(1, tiles, x+tiles[1].x, y+tiles[1].y, l, m);
            put_tile(2, tiles, x+tiles[2].x, y+tiles[2].y, l, m);
        }
        else if(type == 2){
            put_tile(1, tiles, x+tiles[1].x, y+tiles[1].y, l, m);
            put_tile(2, tiles, x+tiles[2].x, y+tiles[2].y, l, m);
            put_tile(3, tiles, x+tiles[3].x, y+tiles[3].y, l, m);
        }
        else if(type == 3){
            put_tile(2, tiles, x+tiles[2].x, y+tiles[2].y, l, m);
            put_tile(3, tiles, x+tiles[3].x, y+tiles[3].y, l, m);
            put_tile(0, tiles, x+tiles[0].x, y+tiles[0].y, l, m);
        }
    }
    else
        return;
}
int main(){
    int l, m;
    scanf("%d%d", &l,&m);
    Tile tiles[4] = {{-1,-1}, {1,-1}, {1,1}, {-1,1}};
    put_tile(0,tiles,l-m,l-m,l,m);
    return 0;
}