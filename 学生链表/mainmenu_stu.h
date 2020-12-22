#ifndef _MAINMENU_STU_H_
#define  _MAINMENU_STU_H_

#define  MAINMENU_STU  "\t\t\t1.����ѧ����Ϣ\n"\
                                                    "\t\t\t2.ɾ��һ��ѧ����Ϣ\n"\
                                                    "\t\t\t3.�޸�һ��ѧ����Ϣ\n"\
                                                    "\t\t\t4.����һ��ѧ����Ϣ\n"\
                                                    "\t\t\t5.��ʾ����ѧ����Ϣ\n"\
                                                    "\t\t\t6.��ת\n"\
                                                    "\t\t\t7.�˳�\n"\
                                                    "\t\t\t���������ѡ�"

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

//����ѧ���б�
Stu *creat_stu(Stu *head);

//����ѧ����Ϣ
Stu *add_stu_list(Stu*head,Stu *pnew);

//ɾ��һ��ѧ����Ϣ
Stu *del_stu_list(Stu *head);

//�޸�һ��ѧ����Ϣ
Stu *modify_stu(Stu *head);

//����һ��ѧ����Ϣ
void  serach_stu(Stu *head);

//��ת
Stu *reserver(Stu *head);

//��ʾ����ѧ����Ϣ
void  print_list(Stu *head);


void  mainmenu_stu();

#endif
