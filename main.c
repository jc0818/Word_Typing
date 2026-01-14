#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>



int realScore = 0;
int score = 0;
const char* target1 = "동해물과 백두산이 마르고 닳도록";
const char* target2 = "하느님이 보우하사 우리나라 만세";
const char* target3 = "무궁화 삼천리 화려강산";
const char* target4 = "대한사람 대한으로 길이 보전하세";

void result(double t)
{
    printf("\n====================================\n");
    printf("              RESULT                \n");
    printf("====================================\n");
    printf(" 걸린 시간 : %.2f 초\n", t);
    printf(" 타 수 율   : %.0lf 타/분\n", (realScore / t) * 60);
    printf(" 오 타 율   : %d %%\n", 100 - (score - 15));
    printf("====================================\n\n");


}

void acc(const char* target, char* input) {
    
    int ff = strlen(target);
    int all = ff;
    realScore += ff;
    for (int i = 0; i < ff; i++)
    {
        if (target[i] != input[i])
        {
            all -= 1;
        }
    }

    score += all;

}

void play(const char* target)
{
    char* input;


    printf("문장: %s\n", target);
    printf("type: ");

    input = (char*)malloc(strlen(target) + 2); // +1 for \0, +1 for \n 대비

    fgets(input, strlen(target) + 2, stdin); //엔터치면 

    // 개행 제거
    input[strcspn(input, "\n")] = '\0';

    acc(target,input);

    free(input);
    system("cls");
}

void timer()
{
    //for (int i = 5; i >= 1; i--)
    //{
    //    if (i != 1)
    //    {
    //    Sleep(1000); //1초 
    //    }
    //    else
    //    {
    //        Sleep(2000);
    //    }
    //    printf("%d초 (한영키를 눌러주세요.)\n", i);
    //}
    //

    //맛있는 버전.
    setbuf(stdout, NULL);

    int cd = 10;
    while (cd > 0) {
        Sleep(1000);
        printf("%d",cd);
        cd = cd - 1;
    }
    Sleep(1000);
    printf("%d\n", cd);
}

int main()
{
    printf(" __        __              _   _____           _             \n");
    printf(" \\ \\      / /__  _ __   __| | |_   _|   _ _ __ (_)_ __   __ _ \n");
    printf("  \\ \\ /\\ / / _ \\| '_ \\ / _` |   | || | | | '_ \\| | '_ \\ / _` |\n");
    printf("   \\ V  V / (_) | | | | (_| |   | || |_| | |_) | | | | | (_| |\n");
    printf("    \\_/\\_/ \\___/|_| |_|\\__,_|   |_| \\__, | .__/|_|_| |_|\\__, |\n");
    printf("                                     |___/|_|            |___/\n");
    printf("문장: %s\n", target1);
    timer();
    printf("\n\n");
    system("cls");
    
    
    clock_t start_time = clock();
    

    
    for (int i = 1; i <= 4; i++)
    {
        switch (i)
        {
        case 1:
            play(target1);
            break;
        case 2:
            play(target2);
            break;
        case 3:
            play(target3);
            break;
        case 4:
            play(target4);
            
            break;
        default:
            
            break;
        }
    }
    clock_t end_time = clock();

    
    double time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    result(time_elapsed);
    return 0;
}
