#include<stdio.h>
int main(){
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int n_a , n_b, n_c;
    n_a = a - 2 * e;
    n_b = b - 2 * e;
    n_c = c - 2 * e;
    int ori_surface = ((a * b) *2) + ((b * c) * 2) + ((a * c) * 2);
    int add_surface = (8 * (n_a * d)) + (8 * (n_b * d)) + (8 * n_c * d);
    int result_surface = ori_surface + add_surface;
    int ori_volu = a * b * c;
    int sub_volu = (n_a * n_b * d * 2) +  (n_b * n_c * d * 2) + (n_a * n_c * d * 2);
    int result_volu = ori_volu - sub_volu;
    printf("%d\n%d", result_surface, result_volu);
    return 0;
}