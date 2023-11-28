#include <stdio.h>
struct tile
{
    int x;
    int y;
};
typedef struct tile Tile;
// int check(int type,int x,int y,int last_x,int last_y){
//     if(type==0){
//         if(x<last_x && y<last_y)
//             return 1;
//         else
//             return 0;
//     }
//     else if(type==1){
//         if(x>last_x && y<last_y)
//             return 1;
//         else
//             return 0;
//     }
//     else if(type==2){
//         if(x>last_x && y>last_y)
//             return 1;
//         else
//             return 0;

//     }
//     else if(type==3){
//         if(x<last_x && y>last_y)
//             return 1;
//         else 
//             return 0;
//     }
// }

void put_tile(int type,Tile tiles[],int x,int y,int length,int l,int m){ // length represent sliced length
    if(x>l-m && y>l-m)
        return;
    if(length>=1){
        printf("%d %d %d\n",type+1,x,y);
        length /= 2;
        if(type==0){
            put_tile(0,tiles,x-length,y-length,length,l,m);
            put_tile(3,tiles,x-length,y+length,length,l,m);
            put_tile(1,tiles,x+length,y-length,length,l,m);
            put_tile(0,tiles,x+length,y+length,length,l,m);
        }
        else if(type ==1){
            put_tile(1,tiles,x+length,y-length,length,l,m);
            put_tile(2,tiles,x+length,y+length,length,l,m);
            put_tile(0,tiles,x-length,y-length,length,l,m);
            put_tile(1,tiles,x-length,y+length,length,l,m);
        }
        else if(type==2){
            put_tile(2,tiles,x+length,y+length,length,l,m);
            put_tile(3,tiles,x-length,y+length,length,l,m);
            put_tile(1,tiles,x+length,y-length,length,l,m);
            put_tile(2,tiles,x-length,y-length,length,l,m);
        }
        else if(type==3){
            put_tile(3,tiles,x-length,y+length,length,l,m);
            put_tile(2,tiles,x+length,y+length,length,l,m);
            put_tile(0,tiles,x-length,y-length,length,l,m);
            put_tile(3,tiles,x+length,y-length,length,l,m);
        }
    }
    return;
}
int main(){
    int l, m;
    scanf("%d%d", &l,&m);
    Tile tiles[4] = {{-1,-1}, {1,-1}, {1,1}, {-1,1}};
    int x = l/2,y=l/2;
    printf("%d %d %d\n",1,x,y);
    put_tile(2,tiles,x+l/4,y+l/4,l/4,l,m);
    put_tile(0,tiles,x-l/4,y-l/4,l/4,l,m);
    put_tile(3,tiles,x-l/4,y+l/4,l/4,l,m);
    put_tile(1,tiles,x+l/4,y-l/4,l/4,l,m);
    return 0;
}