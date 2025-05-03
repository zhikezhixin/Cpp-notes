#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5  // 定义学生数量

// 学生信息结构体
struct student 
{
    long num;          // 学号
    char name[10];    // 姓名
    float score[3];   // 三门课程成绩
} stu[SIZE]; // 定义一个学生数组

// 函数：将学生数据保存到文件
void save()
{
    FILE* fp;  // 文件指针
    int i;
    // 打开文件"stud"，以二进制写入模式
    if ((fp = fopen("stud", "wb")) == NULL)
    {
        printf("cannot open file\n");
        return;  // 如果打开失败，返回
    }
    // 循环写入每个学生的数据到文件
    for (i = 0; i < SIZE; i++)
        if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
            printf("file write error\n");  // 写入失败，打印错误信息
    fclose(fp);  // 关闭文件
}

// 函数：根据平均分对学生数据进行排序
void sortStudents(struct student* stu, int size) 
{
    // 使用冒泡排序算法
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            // 计算当前学生和下一个学生的平均分
            float avg1 = (stu[j].score[0] + stu[j].score[1] + stu[j].score[2]) / 3;
            float avg2 = (stu[j + 1].score[0] + stu[j + 1].score[1] + stu[j + 1].score[2]) / 3;
            // 如果当前学生的平均分小于下一个学生的平均分，则交换
            if (avg1 < avg2) 
            {
                struct student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}

// 函数：读取学生数据，计算平均分并排序
void readAndSort() 
{
    struct student stu[SIZE];  // 临时学生数组
    FILE* fp;  // 文件指针
    // 打开文件"stud"，以二进制读取模式
    if ((fp = fopen("stud", "rb")) == NULL) 
    {
        printf("cannot open file\n");
        return;  // 如果打开失败，返回
    }
    // 从文件中读取学生数据
    fread(stu, sizeof(struct student), SIZE, fp);
    fclose(fp);  // 关闭文件

    // 对读取的学生数据进行排序
    sortStudents(stu, SIZE);

    FILE* fp_sorted;  // 排序后文件指针
    // 打开文件"stu_sort"，以二进制写入模式
    if ((fp_sorted = fopen("stu_sort", "wb")) == NULL) 
    {
        printf("cannot open file\n");
        return;  // 如果打开失败，返回
    }
    // 将排序后的学生数据写入新文件
    fwrite(stu, sizeof(struct student), SIZE, fp_sorted);
    fclose(fp_sorted);  // 关闭文件
}

// 主函数
int main() 
{
    int i;
    // 输入学生信息
    for (i = 0; i < SIZE; i++)
        scanf("%ld%s%f%f%f", &stu[i].num, stu[i].name, &stu[i].score[0],
            &stu[i].score[1], &stu[i].score[2]);
    save();          // 保存学生数据到文件
    readAndSort();   // 读取数据并进行排序
    return 0;       // 返回0表示程序正常结束
}
