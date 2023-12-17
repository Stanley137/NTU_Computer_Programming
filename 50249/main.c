#include <stdio.h>
#include <stdint-gcc.h>
#include <stdbool.h>
#include <stdlib.h>
int min(int a,int b){
    return (a<b)? a:b;
}
void switch_channel(FILE *in, FILE *out, int data_num){
    fseek(in, 44, SEEK_SET); fseek(out, 44, SEEK_SET);
    uint16_t samples[4100], write_samples[4100];
    int sum = 0;
    while(1){
        
    }
}


int main(){
    char str_in[100], str_out[100];
    scanf("%s%s", str_in, str_out);
    int k;
    scanf("%d", &k);
    FILE *in, *out;
    in = fopen(str_in, "rb");
    out = fopen(str_out, "wb");
    uint8_t header[100];
    fread(header, sizeof(uint8_t), 44, in);
    fwrite(header, sizeof(uint8_t), 44, out);
    int data_rate = (header[28] + (header[29]<<8) + (header[30]<<16) + (header[31]<<24));
    printf("data_rate: %d\n", data_rate);
    int data_num = data_rate * k;
    switch_channel(in, out, data_num);
    return 0;
}