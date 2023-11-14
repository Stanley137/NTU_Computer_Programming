#include <stdio.h>
int compose_material(int a,int b,int c,int da,int db,int dc,int ea,int eb,int ec,int fa,int fb,int fc){
    //printf("a:%d,b:%d,c:%d\n",a,b,c);
    if(a<0 || b<0 || c<0)
        return 0;
    if(a==0 && b==0 && c==0)
        return 1;
    if(compose_material(a-da,b-db,c-dc,da,db,dc,ea,eb,ec,fa,fb,fc))
        return 1;
    if(compose_material(a-ea,b-eb,c-ec,da,db,dc,ea,eb,ec,fa,fb,fc))
        return 1;
    if(compose_material(a-fa,b-fb,c-fc,da,db,dc,ea,eb,ec,fa,fb,fc))
        return 1;
    return 0;
}
void write_msg(int n,int da,int db,int dc,int ea,int eb,int ec,int fa,int fb,int fc){
    if(n==0)
        return;
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    //printf("%d\n", n);
    if(compose_material(a,b,c,da,db,dc,ea,eb,ec,fa,fb,fc))
        printf("yes\n");
    else
        printf("no\n");
    write_msg(n-1,da,db,dc,ea,eb,ec,fa,fb,fc);
}
int main(){
    int da,db,dc;
    int ea,eb,ec;
    int fa,fb,fc;
    int n,a,b,c;
    scanf("%d%d%d",&da,&db,&dc);
    scanf("%d%d%d",&ea,&eb,&ec);
    scanf("%d%d%d",&fa,&fb,&fc);
    scanf("%d", &n);
    write_msg(n,da,db,dc,ea,eb,ec,fa,fb,fc);
    return 0;
}