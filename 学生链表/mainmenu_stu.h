#ifndef _MAINMENU_STU_H_
#define  _MAINMENU_STU_H_

#define  MAINMENU_STU  "\t\t\t1.增加学生信息\n"\
                                                    "\t\t\t2.删除一个学生信息\n"\
                                                    "\t\t\t3.修改一个学生信息\n"\
                                                    "\t\t\t4.查找一个学生信息\n"\
                                                    "\t\t\t5.显示所有学生信息\n"\
                                                    "\t\t\t6.翻转\n"\
                                                    "\t\t\t7.退出\n"\
                                                    "\t\t\t请输入你的选项："

typedef struct Score
{
    float math;
    float chinese;
    float english;
}Score;

typedef struct Stu
{
    int id;
    char name[20];
    int age;
    Score score;
    struct Stu *next;
}Stu;

//创建学生列表
Stu *creat_stu(Stu *head);

//增加学生信息
Stu *add_stu_list(Stu*head,Stu *pnew);

//删除一个学生信息
Stu *del_stu_list(Stu *head);

//修改一个学生信息
Stu *modify_stu(Stu *head);

//查找一个学生信息
void  serach_stu(Stu *head);

//翻转
Stu *reserver(Stu *head);

//显示所有学生信息
void  print_list(Stu *head);


void  mainmenu_stu();

#endif
