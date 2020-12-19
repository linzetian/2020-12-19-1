//学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
//设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组
//作为成员学生的成员有姓名、考试分数，1、创建数组存放3名老师，2、通过函数给每个老师及所带的
//学生赋值 3、最终打印出老师数据以及老师所带的学生数据。
#include<iostream>
#include<ctime>
#include<string>
using namespace std;

//学生结构体定义
struct student
{
	string sname = "student_";
	int score;
};
//老师结构体定义
struct teacher
{
	string tname = "teacher_";
	struct student stu[5];//结构体嵌套
};
void print(struct teacher tarry[3], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师名字：" << tarry[i].tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名：" << tarry[i].stu[j].sname << " 学生成绩 " << tarry[i].stu[j].score << endl;
		}
		cout << endl;
	}
}
void allocatespace(struct teacher tarry[], int len)
{
	int scoreseed = rand() % 61 + 40;
	string nameseed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tarry[i].tname += nameseed[i];
		for (int j = 0; j < 5; j++)
		{
			int scoreseed = rand() % 61 + 40;//每次循环产生一个随机数
			tarry[i].stu[j].sname+= nameseed[j];
			tarry[i].stu[j].score = scoreseed;
		}
	}
}
int main()
{
	//随机种子
	srand((unsigned int)time(NULL));
	struct teacher tarry[3];//创建三名老师数组
	int len = sizeof(tarry) / sizeof(tarry[0]);
	allocatespace(tarry, len);
	print(tarry,len);
	system("pause");
	return 0;
}