#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int search(char final_arthor[100][51], char author[], int count){
    for(int i=0;i<count;i++){
        if(strcmp(final_arthor[i], author) == 0)
            return i;
    }
    return 0;
}

int main(){
    int m;
    scanf("%d", &m);
    int book_to_arthor[100];
    char book[100][51], author[100][51], final_author[100][51];
    int count = 0;
    for(int i = 0;i<m;i++){
        scanf("%s%s", author[i], book[i]);
        if(search(final_author,author[i], count))
            continue;
        else{
            strcpy(final_author[count], author[i]);
            count++;
            // printf("%s\n", final_author[count]);
        }
    }
    for(int i=0;i<m;i++){
        int index = search(final_author, author[i], count);
        book_to_arthor[i] = index;
    }
    char book_name[51], sell_string[10];
    int sell[100] = {0}, sell_num;
    for(int i=0;i<m;i++){
        scanf("%s%d", book_name, &sell_num);
        int index = search(book, book_name, m);
        index = book_to_arthor[index];
        sell[index] += sell_num;
        // printf("%s %d\n", book_name, sell_num);
        // printf("%d\n", sell[index]);
    }
    int best = -1;
    int index;
    for(int i=0;i<count;i++){
        if(sell[i] > best || (sell[i]==best && strcmp(final_author[index], author[i])>0)){
            best = sell[i];
            index = i;
        }
    }
    printf("%s %d\n", final_author[index], sell[index]);
    return 0;
}