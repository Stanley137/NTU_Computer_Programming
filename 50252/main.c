#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void filter(FILE *in,FILE *vocal,FILE *out){
    fseek(in, 44, SEEK_SET);
    fseek(vocal, 44, SEEK_SET);
    fseek(out, 44, SEEK_SET);
    // in - vocal = out(persample)
    uint16_t data[4100], human[4100]; // samples
    while(1){
        int samples_n = fread(data, sizeof(uint16_t), 4096, in);
        fread(human, sizeof(uint16_t), 4096, vocal);
        if(samples_n == 0) break;
        for(int i=0;i<samples_n;i++){ // minus every single sample
            data[i] -= human[i];
        }
        fwrite(data, sizeof(uint16_t), samples_n, out);
    }
    
}

int main(){
    FILE *out, *in, *vocal;
    char in_s[100], vocal_s[100], out_s[100];
    scanf("%s", in_s);
    scanf("%s", vocal_s);
    scanf("%s", out_s);
    in = fopen(in_s, "rb");
    vocal = fopen(vocal_s, "rb");
    out = fopen(out_s, "wb");
    // copy the header
    uint8_t header[100];
    fseek(in, 0, SEEK_SET); fseek(out, 0, SEEK_SET);
    fread(header, sizeof(uint8_t), 44, in);
    fwrite(header, sizeof(uint8_t), 44, out);

    filter(in, vocal, out);
    fclose(in);
    fclose(out);
    fclose(vocal);
    return 0;
}