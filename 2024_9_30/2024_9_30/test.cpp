#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5  // ����ѧ������

// ѧ����Ϣ�ṹ��
struct student 
{
    long num;          // ѧ��
    char name[10];    // ����
    float score[3];   // ���ſγ̳ɼ�
} stu[SIZE]; // ����һ��ѧ������

// ��������ѧ�����ݱ��浽�ļ�
void save()
{
    FILE* fp;  // �ļ�ָ��
    int i;
    // ���ļ�"stud"���Զ�����д��ģʽ
    if ((fp = fopen("stud", "wb")) == NULL)
    {
        printf("cannot open file\n");
        return;  // �����ʧ�ܣ�����
    }
    // ѭ��д��ÿ��ѧ�������ݵ��ļ�
    for (i = 0; i < SIZE; i++)
        if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
            printf("file write error\n");  // д��ʧ�ܣ���ӡ������Ϣ
    fclose(fp);  // �ر��ļ�
}

// ����������ƽ���ֶ�ѧ�����ݽ�������
void sortStudents(struct student* stu, int size) 
{
    // ʹ��ð�������㷨
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            // ���㵱ǰѧ������һ��ѧ����ƽ����
            float avg1 = (stu[j].score[0] + stu[j].score[1] + stu[j].score[2]) / 3;
            float avg2 = (stu[j + 1].score[0] + stu[j + 1].score[1] + stu[j + 1].score[2]) / 3;
            // �����ǰѧ����ƽ����С����һ��ѧ����ƽ���֣��򽻻�
            if (avg1 < avg2) 
            {
                struct student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}

// ��������ȡѧ�����ݣ�����ƽ���ֲ�����
void readAndSort() 
{
    struct student stu[SIZE];  // ��ʱѧ������
    FILE* fp;  // �ļ�ָ��
    // ���ļ�"stud"���Զ����ƶ�ȡģʽ
    if ((fp = fopen("stud", "rb")) == NULL) 
    {
        printf("cannot open file\n");
        return;  // �����ʧ�ܣ�����
    }
    // ���ļ��ж�ȡѧ������
    fread(stu, sizeof(struct student), SIZE, fp);
    fclose(fp);  // �ر��ļ�

    // �Զ�ȡ��ѧ�����ݽ�������
    sortStudents(stu, SIZE);

    FILE* fp_sorted;  // ������ļ�ָ��
    // ���ļ�"stu_sort"���Զ�����д��ģʽ
    if ((fp_sorted = fopen("stu_sort", "wb")) == NULL) 
    {
        printf("cannot open file\n");
        return;  // �����ʧ�ܣ�����
    }
    // ��������ѧ������д�����ļ�
    fwrite(stu, sizeof(struct student), SIZE, fp_sorted);
    fclose(fp_sorted);  // �ر��ļ�
}

// ������
int main() 
{
    int i;
    // ����ѧ����Ϣ
    for (i = 0; i < SIZE; i++)
        scanf("%ld%s%f%f%f", &stu[i].num, stu[i].name, &stu[i].score[0],
            &stu[i].score[1], &stu[i].score[2]);
    save();          // ����ѧ�����ݵ��ļ�
    readAndSort();   // ��ȡ���ݲ���������
    return 0;       // ����0��ʾ������������
}
