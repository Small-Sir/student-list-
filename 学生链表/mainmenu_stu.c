#include <stdio.h>
#include  "mainmenu_stu.h"



//判断所输入的是否合法
void check_vlat(int id,char *name,int age,Score *score,Stu *pnew,Stu *head)
{
    while(1)///id
    {
        printf("please input id:");
        scanf("%d",&id);
        int flag=0;
        if(id<=0)
            {
                printf("你所输入的学号错误,请重新输入\n");
                continue;
            }
            else
            {
                while(head!=NULL)
                {
                    if(id==head->id)
                    {
                        printf("你所输入的id重复\n");
                        flag=1;
                        break;
                    }
                    head=head->next;
                }
            }
             if(flag==0)
                    break;
    }

    while(1)///name
    {
        printf("please input name:");
        scanf("%s",name);
        if(strlen(name)>19)
            {
                printf("你所输入的名字过长,请重新输入\n");
                continue;
            }
            else
                break;
    }


     while(1)///age
    {
            printf("please input age:");
            scanf("%d",&age);
            if(age<=0||age>=200)
            {
                printf("你输入的年龄不符合常理,请重新输入\n");
                continue;
            }
            else
                break;
    }

        while(1)///math score
        {
            printf("please input math score:");
            scanf("%f",&score->math);
            if(score->math<0||score->math>100)
                {
                    printf("你所输入的分数错误,请重新输入\n");
                    continue;
                }
                else
                    break;
        }

        while(1)///chinese score
        {
            printf("please input chinese score:");
            scanf("%f",&score->chinese);
            if(score->chinese<0||score->chinese>100)
                {
                    printf("你所输入的分数错误,请重新输入\n");
                    continue;
                }
                else
                    break;
        }

        while(1)///english score
        {
            printf("please input english score:");
            scanf("%f",&score->english);
            if(score->english<0||score->english>100)
                {
                    printf("你所输入的分数错误,请重新输入\n");
                    continue;
                }
                else
                    break;
        }


    pnew->age=age;
    pnew->id=id;
    pnew->score.chinese=score->chinese;
    pnew->score.math=score->math;
    pnew->score.english=score->english;
    strcpy(pnew->name,name);
    pnew->next=NULL;
}

Stu *creat_stu(Stu *head)//创建新的学生信息
{
    Stu *pnew=(Stu *)malloc(sizeof(Stu));//申请空间
    Score *score=(Score*)malloc(sizeof(Score));//申请空间
    int age;
    int id;
    char name[20];
    check_vlat(id,name,age,score,pnew,head);//检查和赋值
    return pnew;
}

Stu *find_tail_stu(Stu *head)//查找尾节点
{
        while(head!=NULL)
        {
            if(head->next==NULL)
            {
                    return head;
            }
            head=head->next;
        }
        return NULL;
}

//用尾插入法创建学生链表
/*
Stu *creat_stu_list_tail()
{
    Stu *head=NULL;//创建头指针
    Stu *new_stu=NULL;
        new_stu=creat_stu(head);
        if(head == NULL)
            head=new_stu;
        else
        {
            Stu *pstu=find_tail_stu(head);
            pstu->next=new_stu;
        }

    return head;
}
*/
Stu *creat_stu_list_head(Stu *head,Stu *pnew)//头插法
{
        ///Stu *pnew=NULL;
        pnew=creat_stu(head);
        pnew->next=head;
        head=pnew;
    return head;
}

Stu *creat_stu_list_head1(Stu *head,Stu *pnew)//头插法
{
        ///Stu *pnew=NULL;
        //pnew=creat_stu(head);
        pnew->next=head;
        head=pnew;
    return head;
}

Stu *add_stu_list(Stu*head,Stu *pnew)//增加学生
{
    head=creat_stu_list_head(head,pnew);
    return head;
}
void print_list(Stu *head)//显示所有学生
{
    printf("\t\t学号\t\t\t名字\t\t\t年龄\t\t\t数学成绩\t\t语文成绩\t\t英语成绩\n");
    while(head!=NULL)
    {
            printf("\t\t%-24d%-24s%-24d%-24.2f%-24.2f%-24.2f\n",head->id,head->name,head->age,head->score.math,head->score.chinese,head->score.english);
            head=head->next;
    }
    return;
}


Stu *find_node(Stu *head,int id)
{
    while(head!=NULL)
    {
        if(head->id==id)
            return head;
        head=head->next;
    }
    return NULL;
}

Stu *find_pre(Stu *head,Stu *node)///查询所要删除的节点的前一个节点
{
    while(head!=NULL)
    {
        if(head->next=node)
            return head;
        head=head->next;
    }
    return NULL;
}

Stu *take_off_node(Stu **head,Stu *node)///取出所要删除的节点
{
    Stu *temp=node;
    if(temp==*head)
        *head=(*head)->next;
    else
    {
        Stu *pre=find_pre(*head,node);
        pre->next=temp->next;
    }
    return temp;
}

Stu *del_node(Stu *head)///删除节点
{
    int id;
    printf("请输入你要删除的id\n");
    scanf("%d",&id);
    while(getchar()!='\n');
    Stu *node=find_node(head,id);
    if(node==NULL)
    {
        printf("查无此人\n");
        return head;
    }
    Stu *temp=take_off_node(&head,node);
    free(temp);
    return head;
}

//删除一个学生信息
Stu *del_stu_list(Stu *head)
{
        head=del_node(head);
        return head;
}

//修改一个学生信息
Stu *modify_stu(Stu *head)
{
    int id;
     printf("请输入你要修改的id\n");
    scanf("%d",&id);
    while(getchar()!='\n');
    Stu *node=find_node(head,id);
    if(node==NULL)
    {
        printf("查无此人\n");
        return head;
    }
    int age;
    char name[20];
    Score *score=(Score*)malloc(sizeof(Score));//申请空间
    check_vlat(id,name,age,score,node,head);
}

//查找一个学生信息
void  serach_stu(Stu *head)
{
    int id;
     printf("请输入你要查找的id\n");
    scanf("%d",&id);
    while(getchar()!='\n');
    Stu *node=find_node(head,id);
    if(node==NULL)
    {
        printf("查无此人\n");
        return;
    }
    printf("\t\t学号\t\t\t名字\t\t\t年龄\t\t\t数学成绩\t\t语文成绩\t\t英语成绩\n");
    printf("\t\t%-24d%-24s%-24d%-24.2f%-24.2f%-24.2f\n",node->id,node->name,node->age,node->score.math,node->score.chinese,node->score.english);
    return;
}

Stu *reserver(Stu *head)
{
    printf("翻转中！！......\n");
    Stu* head1=NULL;
    while(head!=NULL)
    {
        Stu* temp=take_off_node(&head,head);
        head1=creat_stu_list_head1(head1,temp);
    }
    printf("翻转成功！！...\n");
    return head1;
}

void  mainmenu_stu()
{
    Stu *head=NULL;
    Stu *pnew=NULL;
     int sel;
    while(1)
    {
        printf(MAINMENU_STU);
        scanf("%d",&sel);
        while(getchar()!='\n');
        switch(sel)
        {
        case 1:
            head=add_stu_list(head,pnew);
            break;
        case 2:
            head=del_stu_list(head);
            break;
        case 3:
            modify_stu(head);
            break;
        case 4:
            serach_stu(head);
            break;
        case 5:
            print_list(head);
            break;
        case 6:
            head=reserver(head);
            break;
        case 7:
            printf("谢谢你的使用\n");
            return;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    }
}
