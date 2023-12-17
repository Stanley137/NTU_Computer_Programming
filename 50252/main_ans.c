#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
void copy_header(FILE* audio, FILE* res){
    uint8_t arr[44];
    fseek(audio, 0, SEEK_SET); fseek(res, 0, SEEK_SET);
    fread(arr, sizeof(uint8_t), 44, audio);
    fwrite(arr, sizeof(uint8_t), 44, res);
}
 
void solve(FILE *audio, FILE *vocal, FILE *res){
    copy_header(audio, res);
 
    fseek(audio, 44, SEEK_SET);
    fseek(vocal, 44, SEEK_SET);
    fseek(res, 44, SEEK_SET);
    uint16_t a[4096], v[4096];
    while(1){
        int n = fread(a, sizeof(uint16_t), 4096, audio);
        fread(v, sizeof(uint16_t), 4096, vocal);
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            a[i] -= v[i];
        }
 
        fwrite(a, sizeof(uint16_t), n, res);
    }
}
 
int main(){
    char in_name_1[128], in_name_2[128], out_name[128];
    scanf("%s %s %s", in_name_1, in_name_2, out_name);
    FILE* audio = fopen(in_name_1, "rb");
    FILE* vocal = fopen(in_name_2, "rb");
    FILE* res = fopen(out_name, "wb");
 
    solve(audio, vocal, res);
 
    fclose(audio);
    fclose(vocal);
    fclose(res);
}