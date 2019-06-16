// vote.c --投票系统,用结构体实现
#include <stdio.h>
#include <string.h>
#define N 3             // 候选人
#define M 6             // 学生
struct stduent{
        char name[20];  // 姓名
        int num;        // 票数
} stu[N - 1];

int main(void)
{
        int i, j;
        char temp[10];

        for (i = 0; i < N; i++)
        {
                printf("请输入第%d个候选人姓名:", i + 1);
                scanf("%s", stu[i].name);
        }
        
        for (i = 0; i < M; i++)
        {
                printf("请第%d个学生输入投票结果:", i+1);
                scanf("%s", temp);

                for (j = 0; j < N; j++)
                        if (strcmp(stu[j].name, temp) == 0)
                        {
                                stu[j].num++;
                                break;
                        }
        }

        // 插入排序
        // 创建中间结构变量
        struct stduent t;
        for (i = 1; i < N; ++i)
        {
                t = stu[i];
                j = i - 1;
                while (t.num > stu[j].num && j >= 0)
                {
                        stu[j + 1] = stu[j];
                        --j;
                }
                stu[j + 1] = t;
        }

        printf("\n投票排名:\n");
        for (i = 0; i < N; i++)
                printf("%s的票数是%d\n", stu[i].name, stu[i].num);

        return 0;
}
