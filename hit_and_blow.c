/*
 * ƒqƒbƒgƒAƒ“ƒhƒuƒ[
 * ”“–‚ÄƒQ[ƒ€
 * ‚RŒ…
 * ƒ‰ƒ“ƒ_ƒ€‚É‚RŒ…‚Ì”Žš‚ª—^‚¦‚ç‚ê‚é
 * ”Žš‚Ìd•¡‚Í‚È‚µ
 * ‚»‚Ì”Žš‚ð“–‚Ä‚½‚ç‚¨‚‹
 * ”Žš‚ÆˆÊ’u‚ª‡‚¦‚Îƒqƒbƒg
 * ”Žš‚¾‚¯‚ª‡‚¦‚Îƒuƒ[
 * 
 * example
 * —^‚¦‚ç‚ê‚é”Žš -> 237
 * ‚±‚±‚ÅA289‚Æ“š‚¦‚é‚Æ -> 1H0B
 * 325‚Æ“š‚¦‚é‚Æ -> 0H2B
 * ‚Æ‚¢‚¤‚©‚ñ‚¶‚É‚È‚é
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIZE 10
#define DIGITS 3

struct hit_blow
{
    int hit;
    int blow;
};

void array_erase(int num[], int pos)
{
    int i;
    for(i = pos + 1; i < NUM_SIZE; i++){
        num[i - 1] = num[i];
    }
}

void make_random_number(int res[])
{
    int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int num_range = NUM_SIZE;
    int i;
    int pos;
    int j;
    for(i = 0; i < 3; i++){
        srand((unsigned)time(NULL));
        pos = rand() % num_range;
        res[i] = num[pos];
        array_erase(num, pos);
        num_range--;
    }
}

struct hit_blow check(int x[], int in[])
{
    struct hit_blow res = { 0, 0 };
    int i, j;
    for(i = 0; i < DIGITS; i++){
        if(x[i] == in[i]) res.hit++;
    }
    for(i = 0; i < DIGITS; i++){
        for(j = 0; j < DIGITS; j++){
            if(i == j) continue;
            if(in[i] == x[j]) res.blow++;
        }
    }
    return res;
}

int is_end(struct hit_blow hb)
{
    if(hb.hit == 3){
        puts("********************************");
        puts("     Your answer is collect!    ");
        puts("     Congratulations! Bye!      ");
        puts("********************************");
        return 1;
    }else{
        puts("Your answer is wrong. Please try again!\n");
        return 0;
    }
}

int main()
{
    int x[3], in[3];
    struct hit_blow hb;
    
    puts("********************************");
    puts("      Hit and Blow starts!      ");
    puts("********************************");
    puts("");

    make_random_number(x);
    printf("%d%d%d\n", x[0], x[1], x[2]);

    do{
        puts("Please input three numbers.");
        scanf("%d %d %d", &in[0], &in[1], &in[2]);
        hb = check(x, in);
        printf("\nResult : %dH%dB\n\n", hb.hit, hb.blow);
    }while(!is_end(hb));

    return 0;
}
