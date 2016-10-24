#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<error.h>
#include<math.h>
#include<time.h>
/************************************
*	定义数据结构
*
************************************/
struct servant_inf
{
	char name[30];
	char rank[10];
	char strength[5];
	int str;
	char health[5];
	int hea;
	char agile[5];
	int agi;
	char magic[5];
	int mag;
	char lucky[5];
	int luc;
	char treasure[5];
	int tre;
	char weapon1[30];
	int wea1;
	char weapon2[30];
	int wea2;
	char weapon3[30];
int wea3;
}a[15]={
{"阿尔托莉亚·潘达拉贡","Saber","筋力",80,"耐久",70,"敏捷",70,"魔力",80,"幸运",80,"宝具",70,"风王结界",60,"誓约胜利之剑",99,"",0},
{"齐格菲里德","Saber","筋力",85,"耐久",90,"敏捷",80,"魔力",70,"幸运",50,"宝具",90,"",0,"",0,"",0},
{"库丘林","Lancer","筋力",80,"耐久",70,"敏捷",90,"魔力",70,"幸运",50,"宝具",80,"刺穿死棘之枪",80,"突穿死翔之枪",85,"",0},
{"迪鲁木多·奥迪那","Lancer","筋力",80,"耐久",70,"敏捷",95,"魔力",60,"幸运",50,"宝具",80,"破魔的红蔷薇",80,"必灭的黄蔷薇",80,"",0},
{"卫宫","Archer","筋力",60,"耐久",70,"敏捷",70,"魔力",80,"幸运",50,"宝具",90,"无限剑制",100,"",0,"",0},
{"吉尔伽美什","Archer","筋力",80,"耐久",70,"敏捷",70,"魔力",80,"幸运",90,"宝具",100,"王之财宝",95,"天之锁",50,"天地乖离开辟之星",100},
{"美杜莎","Rider","筋力",80,"耐久",60,"敏捷",80,"魔力",80,"幸运",50,"宝具",95,"骑英之缰绳",95,"他者封印·鲜血神殿",80,"",0},
{"伊斯坎达尔","Rider","筋力",80,"耐久",90,"敏捷",60,"魔力",70,"幸运",95,"宝具",98,"神威车轮",95,"王之军队",100,"",0},
{"美狄亚","Caster","筋力",50,"耐久",60,"敏捷",70,"魔力",95,"幸运",80,"宝具",70,"可破万法之符",70,"",0,"",0},
{"吉尔斯·德·莱斯","Caster","筋力",60,"耐久",60,"敏捷",60,"魔力",90,"幸运",50,"宝具",95,"螺湮城教本",95,"海魔",100,"",0},
{"哈桑·萨巴赫","Assassin","筋力",80,"耐久",70,"敏捷",90,"魔力",70,"幸运",50,"宝具",70,"妄想心音",70,"妄想幻想",85,"",0},
{"佐佐木小次郎","Assassin","筋力",70,"耐久",50,"敏捷",95,"魔力",50,"幸运",90,"宝具",50,"燕返",150,"",0,"",0},
{"赫拉克勒斯","Berserker","筋力",95,"耐久",90,"敏捷",90,"魔力",90,"幸运",80,"宝具",95,"十二试炼",80,"射杀百头",70,"",0},
{"兰斯洛特","Berserker","筋力",90,"耐久",90,"敏捷",95,"魔力",70,"幸运",80,"宝具",90,"无悔的湖光",98,"骑士不死于徒手",98,"为了自己的容光",80}
};
struct solder_attribute
{
	char name;			//骑兵=K，弓兵=A，步兵=F
	int price;			//价格
	int hp;			//血量
	int attack;			//攻击
	int defense;			//防御
	int move;			//速度
	int attack_distanse;		//攻击范围
	int enemy_friend;
}s[2500]={{'K',200,200,15,5,2,2,1},{'A',150,100,20,0,1,3,1},{'F',100,150,10,2,1,1,1}};

struct num_of_soldier
{					//各种士兵的数量	
	int nk1;			//蓝方骑兵的数量
	int nf1;			//蓝方步兵的数量
	int na1;			//蓝方弓箭兵的数量
	int nk2;			//红方骑兵的数量
	int nf2;			//红方步兵的数量
	int na2;			//红方弓箭兵的数量
}num;



int print_menu();	   //游戏最初显示信息界面
void sleep(int x);
void print_story();
void print_story2();
void print_servant();
void print_bingzhong();
int buy_solder(int* m,int enymey_friend);
int init_solder(struct solder_attribute s[],const struct num_of_soldier num);
void print_scene(struct solder_attribute s[]);
int juli(struct solder_attribute s[],int n);
int yidong(struct solder_attribute* s);
int jiaohuan(struct solder_attribute* s,int a,int b);
int attack_enemy(struct solder_attribute s[],int n);
void damage(struct solder_attribute* s,int n,int m);
int tiaochu(struct solder_attribute s[]);
int chose_servant(struct servant_inf* a);
int jiemian();
//void chushihua(struct servant_inf servant,int mys,struct servant_inf* e);
/**********************************
*	主函数
*
***********************************/
int main()
{
	struct servant_inf servant;
	struct servant_inf enemy[6];
	struct servant_inf* e=enemy;
	int money=10000;	
	int* m=&money;
	int n=0,n2=0;
	int mod;
	int k,f;
	char space;
	int mys;
	int day=1;
	int step;
	mod=print_menu();
	if(mod==1)
{
	printf("load...\n");
	print_story2();	
	print_servant();
	mys=chose_servant(a);
//	chushihua(servant,mys,e);
	servant=a[mys];
	while(1)
	{
	sleep(2);
	printf("\n");
	printf("第%d天\n\n",day);sleep(1);
	printf("%s:",servant.name);
	step=jiemian();
/*	switch(step)
	{
	case 1:
//	ziliao();break;
	case 2:
//	jincheng();break;
	case 3:
//	suodi();break;
	case 4:
//	shangdian();break;
	}
	if(day==1)
//	{if(story1()){printf("GAME OVER");return 0;}}
	if(day==3)
//	{if(story2()){printf("GAME OVER");return 0;}}
	if(day==5)
//	{if(story3()){printf("GAME OVER");return 0;}}
	if(day==7)
//	{if(story4()){printf("GAME OVER");return 0;}else{printf("YOU WIN");return 0;}}
*/	day++;
	}












}
	if(mod==2)
{	
	printf("load...\n");
	print_story();
	print_bingzhong();
	printf("请为本阵配置单位：\n");
	while(buy_solder(m,1))
	{money=10000;}
	printf("本阵配置：\n骑士：%d,步兵：%d,弓箭手：%d\n",num.nk1,num.nf1,num.na1);
	printf("请为敌阵配置单位：\n");
	money=10000;
	while(buy_solder(m,2))
	{money=10000;}
	printf("敌阵配置：\n骑士：%d,步兵：%d,弓箭手：%d\n",num.nk2,num.nf2,num.na2);
	while(init_solder(s,num));
//	for(n=0;n<2500;n++)
//	printf("%c,%d\n",s[n].name,s[n].enemy_friend);
	print_scene(s);
	while(1)
	{
		yidong(s);
		sleep(1);
		printf("=======================================\n");
		print_scene(s);
		for(n2=0;n2<2500;n2++)	
		{
		if(s[n2].enemy_friend==0)
		continue;
		else
		attack_enemy(s,n2);
		}	
		printf("n:%d\n",n);
		n++;
		if(tiaochu(s)==0)
			break;
	}
	print_scene(s);
}
	return 0;
}
/***********************************
*
*
***********************************/
int tiaochu(struct solder_attribute s[])
{
	int i;
	int n1=0;
	int n2=0;
	for(i=0;i<2500;i++)
	{
		if(s[i].enemy_friend==1)
			n1=1;
		if(s[i].enemy_friend==2)
			n2=1;
		if(n1==1&&n2==1)
			return 1;
	}
	return 0;
}
/***********************************
*
*
***********************************/
int attack_enemy(struct solder_attribute* s,int n)
{
	int i,j;	//士兵坐标
	int x=0,y=0;	//范围内坐标
	int m;
	i=n/50;
	j=n%50;
//	printf("0000000000000000\n");
	
	for(x=0;x+y<=s[n].attack_distanse;x++)
	{
	for(y=0;x+y<=s[n].attack_distanse;y++)
	{
	if(i+x<50&&j+y<50)
	{
	m=n+(50*x)+y;
	if(m==n)
	continue;
	if(s[m].enemy_friend!=0&&s[m].enemy_friend!=s[n].enemy_friend)
	{damage(s,n,m);return 1;}
	}
	if(i+x<50&&j-y>0)
	{	
	m=n+(50*x)-y;
	if(s[m].enemy_friend!=0&&s[m].enemy_friend!=s[n].enemy_friend)
	{damage(s,n,m);return 1;}
	}
	if(i-x>0&&j+y<50)
	{
	m=n+(50*-x)+y;
	if(s[m].enemy_friend!=0&&s[m].enemy_friend!=s[n].enemy_friend)
	{damage(s,n,m);return 1;}
	}
	if(i-x>0&&j-y>0)
	{
	m=n+(50*-x)-y;
	if(s[m].enemy_friend!=0&&s[m].enemy_friend!=s[n].enemy_friend)
	{damage(s,n,m);return 1;}
	}
//	printf("i:%d,j:%d,x:%d,y:%d,",i,j,x,y);
//	printf("m:%d\n",m);
	}
	y=0;
	}
	return 0;
}

void damage(struct solder_attribute s[],int n,int m)
{
	int x;	
	int y=1;				
	if(s[n].name=='A'&&s[m].name=='F')
	y=2;
	if(s[n].name=='F'&&s[m].name=='K')
	y=2;
	if(s[n].name=='K'&&s[m].name=='A')
	y=2;
	x=(s[n].attack-s[m].defense)*y;				//伤害
	s[m].hp=s[m].hp-x;
//	printf("s[%d].hp:%d,s[%d].hp:%d\n",n,s[n].hp,m,s[m].hp);
	if(s[m].hp<=0)
	{
	s[m].name=' ';
	s[m].hp=0;				//血量
	s[m].attack=0;			//攻击
	s[m].defense=0;			//防御
	s[m].move=0;				//速度
	s[m].attack_distanse=0;		//攻击范围
	s[m].enemy_friend=0;
	}
}
/***********************************
*
*
************************************/
int jiaohuan(struct solder_attribute* s,int a,int b)
{
	struct solder_attribute mid;
	mid.name=s[a].name;
	mid.hp=s[a].hp;
	mid.attack=s[a].attack;
	mid.defense=s[a].defense;
	mid.attack_distanse=s[a].attack_distanse;
	mid.enemy_friend=s[a].enemy_friend;
	s[a].name=s[b].name;
	s[a].hp=s[b].hp;
	s[a].attack=s[b].attack;
	s[a].defense=s[b].defense;
	s[a].attack_distanse=s[b].attack_distanse;
	s[a].enemy_friend=s[b].enemy_friend;
	s[b].name=mid.name;
	s[b].hp=mid.hp;
	s[b].attack=mid.attack;
	s[b].defense=mid.defense;
	s[b].attack_distanse=mid.attack_distanse;
	s[b].enemy_friend=mid.enemy_friend;
}
int yidong(struct solder_attribute* s)
{
	int i,k,n1,n2;
	int dest[500]={};
	int src[500]={};
	int x=0;
	int y;
	for(i=0;i<2500;i++)
	{
		if(s[i].enemy_friend==1)
		{
			//printf("i=%d\n",i);
			k=juli(s,i);
			//printf("k=%d\n",k);
			if(k==1)//youxia
			{
				n1=i+50;
				n2=i+1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
					//jiaohuan(s,i,n1);
				}
				else if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;				
					//jiaohuan(s,i,n2);	
				}
			}
			if(k==2)//youshang
			{
				n1=i-50;
				n2=i+1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;				
				}
				else if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==3)//zuoxia
			{
				n1=i+50;
				n2=i-1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
				}
				else if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==4)//zuoshang
			{
				n1=i-50;
				n2=i-1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
				}
				else if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==5)//shang
			{
				n1=i-50;
				if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==6)//xia
			{
				n1=i+50;
				if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==7)//you
			{
				n2=i+1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
				}
			}
			if(k==8)//zuo
			{
				n2=i-1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
				}
			}
		}						    
	}
	for(y=0;y<x;y++)
	{
		jiaohuan(s,dest[y],src[y]);
	}
	x=0;
	for(i=0;i<2500;i++)
	{
		if(s[i].enemy_friend==2)
		{
			//printf("i=%d\n",i);
			k=juli(s,i);
			//printf("k=%d\n",k);
			if(k==1)//youxia
			{
				n1=i+50;
				n2=i+1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
					//jiaohuan(s,i,n1);
				}
				else if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;				
					//jiaohuan(s,i,n2);	
				}
			}
			if(k==2)//youshang
			{
				n1=i-50;
				n2=i+1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;				
				}
				else if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==3)//zuoxia
			{
				n1=i+50;
				n2=i-1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
				}
				else if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==4)//zuoshang
			{
				n1=i-50;
				n2=i-1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
				}
				else if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==5)//shang
			{
				n1=i-50;
				if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==6)//xia
			{
				n1=i+50;
				if(s[n1].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n1;
					x++;
				}
			}
			if(k==7)//you
			{
				n2=i+1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
				}
			}
			if(k==8)//zuo
			{
				n2=i-1;
				if(s[n2].enemy_friend==0)
				{
					dest[x]=i;
					src[x]=n2;
					x++;
				}
			}
		}						    
	}
	for(y=0;y<x;y++)
	{
		jiaohuan(s,dest[y],src[y]);
	}
}

int juli(struct solder_attribute s[],int n)
{
	int i,j,x,y,k,m,l;
	int i1,j1;
	int o,p;
	int lo=2500;
	y=n/50;
	x=n%50;
	for(k=0;k<2500;k++)
	{
		if(s[k].enemy_friend!=0&&s[k].enemy_friend!=s[n].enemy_friend)
		{
			j=k/50;
			i=k%50;		
			l=(x-i)*(x-i)+(y-j)*(y-j);
			//printf("l=%d\n",l);
			if(l<lo)
			{
				lo=l;
				i1=i;
				j1=j;
			}
		}
	}
	if(lo==1)
		return 0;
	if(i1>x&&j1>y)
		return 1;//youxia
	if(i1>x&&j1<y)	
		return 2;//youshang
	if(i1<x&&j1>y)
		return 3;//zuoxia
	if(i1<x&&j1<y)
		return 4;//zuoshang
	if(i1==x&&j1<y)
		return 5;//shang
	if(i1==x&&j1>y)
		return 6;//xia
	if(i1>x&&j1==y)
		return 7;//you
	if(i1<x&&j1==y)
		return 8;//zuo
		
}
/************************************
*	显示游戏信息
*	无返回值，输入回车后跳出
*************************************/
int print_menu()
{
	int a;
	printf("\n");
	printf("\n");
		printf("*********#*********#*********#*********#*********#*********#*********#**********\n");
	printf("*********#    \033[;33m                                               \033[0m        #**********\n");
	printf("*********#       \033[;31m圣            杯            战           争 \033[0m        #**********\n");
	printf("*********#    \033[;33m                                               \033[0m        #**********\n");
	printf("*********#    \033[;33m            作者  ：  史佳俊&顾筑强            \033[0m        #**********\n");
	printf("*********#    \033[;33m                                               \033[0m        #**********\n");
	printf("*********#*********#*********#*********#*********#*********#*********#**********\n");printf("\n");
	printf("press enter to continue,1=hero mod,2=soldier mod\n");
	scanf("%d",&a);
	return a;
	
}
/************************************
*	显示故事背景
*	
*************************************/
void print_story2()
{
	char playername[20];
	printf("约每60年一次");sleep(2);
	printf("\n积累了巨大来自地脉之魔力的“圣杯”会出现于冬木市");sleep(2);
	printf("\n它有着无论何等愿望都能立即实现的力量");sleep(2);
	printf("\n然而能得到这一权利的只有一组魔术师与英灵从者");sleep(2);
	printf("\n为了争夺这一权利");sleep(2);
	printf("\n各组势力相互厮杀");sleep(2);
	printf("\n最终只剩下一组......");sleep(2);
	printf("\n");sleep(2);
	printf("\n");sleep(2);
	printf("请输入你的姓名:");
	scanf("%s",playername);sleep(2);
	printf("是叫%s吗？\n",playername);sleep(2);
	printf("%s,你要做的就是选择你的英灵从者打败你的对手\n",playername);sleep(2);
	printf("现在让我们来挑选从者吧！！\n");sleep(2);
}
void print_story()
{
	char playername[20];
	printf("约每60年一次");sleep(2);
	printf("\n积累了巨大来自地脉之魔力的“圣杯”会出现于冬木市");sleep(2);
	printf("\n它有着无论何等愿望都能立即实现的力量");sleep(2);
	printf("\n然而能得到这一权利的只有一个人");sleep(2);
	printf("\n为了争夺这一权利");sleep(2);
	printf("\n各路人马捉对厮杀");sleep(2);
	printf("\n最终只剩下两队精英......");sleep(2);
	printf("\n");sleep(2);
	printf("\n");sleep(2);
	printf("请输入你的姓名:");
	scanf("%s",playername);sleep(2);
	printf("是叫%s吗？\n",playername);sleep(2);
	printf("%s,你要做的就是率领你的军队打败你的对手\n",playername);sleep(2);
	printf("现在让我们来配置部队吧！！\n");sleep(2);
}
/************************************
*	兵种信息
*
************************************/
void print_bingzhong()
{
	printf("*********#*********#*********#*********#*********#*********#*********#**********\n");
	printf("*********#       \033[;31m骑士(K)           步兵(F)             弓箭兵(A)\033[0m     #**********\n");
	printf("*********#    \033[;33m血量---300       血量---150          血量---100\033[0m        #**********\n");
	printf("*********#    \033[;33m护甲---5         护甲---2            护甲---0\033[0m          #**********\n");
	printf("*********#    \033[;33m攻击---15        攻击---10           攻击---20\033[0m         #**********\n");
	printf("*********#    \033[;33m速度------2      速度------1         速度------1\033[0m       #**********\n");
	printf("*********#    \033[;33m攻击范围------2  攻击范围------1     攻击范围------3\033[0m   #**********\n");
	printf("*********#    \033[;33m价格---200       价格---100          价格---150\033[0m        #**********\n");
	printf("*********#*********#*********#*********#*********#*********#*********#**********\n");sleep(1);
	printf("顺便一提 骑士对战弓箭兵会有优势，弓箭兵对战步兵会有优势，步兵对战骑士会有优势\n");sleep(1);
	printf("总之尽量选择有利的配置来战胜对方吧！\n");
}

void print_servant()
{
	printf("*********#*********#*********#*********#*********#*********#*********#**********\n");
	printf("*********#       \033[;31m阿尔托莉亚       齐格菲里德          库丘林\033[0m         #**********\n");
	printf("*********#       \033[;33m职阶---Saber     职阶---Saber       职阶---Lancer\033[0m   #**********\n");
	printf("*********#       \033[;33m筋力---B         筋力---B+          筋力---B\033[0m        #**********\n");
	printf("*********#       \033[;33m耐久---C         耐久---A           耐久---C\033[0m        #**********\n");
	printf("*********#       \033[;33m敏捷---C         敏捷---B           敏捷---A\033[0m        #**********\n");
	printf("*********#       \033[;33m魔力---B         魔力---C           魔力---C\033[0m        #**********\n");
	printf("*********#       \033[;33m幸运---B         幸运---E           幸运---E\033[0m        #**********\n");
	printf("*********#       \033[;33m宝具---C         宝具---？          宝具---B\033[0m        #**********\n");
	printf("*********#                                                           #**********\n");
	printf("*********#       \033[;31m迪鲁木多           卫宫              吉尔伽美什\033[0m     #**********\n");
	printf("*********#       \033[;33m职阶---Lancer    职阶---Archer      职阶---Archer\033[0m   #**********\n");
	printf("*********#       \033[;33m筋力---B         筋力---D           筋力---B\033[0m        #**********\n");
	printf("*********#       \033[;33m耐久---C         耐久---C           耐久---C\033[0m        #**********\n");
	printf("*********#       \033[;33m敏捷---A+        敏捷---C           敏捷---C\033[0m        #**********\n");
	printf("*********#       \033[;33m魔力---D         魔力---B           魔力---B\033[0m        #**********\n");
	printf("*********#       \033[;33m幸运---E         幸运---E           幸运---A\033[0m        #**********\n");
	printf("*********#       \033[;33m宝具---B         宝具---A           宝具---EX\033[0m       #**********\n");
	printf("*********#                                                           #**********\n");
	printf("*********#       \033[;31m 美杜莎           伊斯坎达尔          美狄亚\033[0m        #**********\n");
	printf("*********#       \033[;33m职阶---Rider     职阶---Rider       职阶---Caster\033[0m   #**********\n");
	printf("*********#       \033[;33m筋力---B         筋力---B           筋力---E\033[0m        #**********\n");
	printf("*********#       \033[;33m耐久---D         耐久---A           耐久---D\033[0m        #**********\n");
	printf("*********#       \033[;33m敏捷---B         敏捷---D           敏捷---C\033[0m        #**********\n");
	printf("*********#       \033[;33m魔力---B         魔力---C           魔力---A+\033[0m       #**********\n");
	printf("*********#       \033[;33m幸运---E         幸运---A+          幸运---B\033[0m        #**********\n");
	printf("*********#       \033[;33m宝具---A+        宝具---A++         宝具---C\033[0m        #**********\n");
	printf("*********#                                                           #**********\n");
	printf("*********#       \033[;31m吉尔斯·德·莱斯    哈桑·萨巴赫       佐佐木小次郎\033[0m    #**********\n");
	printf("*********#       \033[;33m职阶---Caster    职阶---Assassin    职阶---Assassin\033[0m #**********\n");
	printf("*********#       \033[;33m筋力---C         筋力---B           筋力---C\033[0m        #**********\n");
	printf("*********#       \033[;33m耐久---E         耐久---C           耐久---E\033[0m        #**********\n");
	printf("*********#       \033[;33m敏捷---D         敏捷---A           敏捷---A+\033[0m       #**********\n");
	printf("*********#       \033[;33m魔力---A         魔力---C           魔力---E\033[0m        #**********\n");
	printf("*********#       \033[;33m幸运---E         幸运---E           幸运---A\033[0m        #**********\n");
	printf("*********#       \033[;33m宝具---A+        宝具---C           宝具---E\033[0m        #**********\n");
	printf("*********#                                                           #**********\n");
	printf("*********#       \033[;31m赫拉克勒斯(狂)                     兰斯洛特(狂)\033[0m     #**********\n");
	printf("*********#       \033[;33m职阶---Berserker                   职阶---Berserker\033[0m #**********\n");
	printf("*********#       \033[;33m筋力---A+                          筋力---A\033[0m         #**********\n");
	printf("*********#       \033[;33m耐久---A                           耐久---A\033[0m         #**********\n");
	printf("*********#       \033[;33m敏捷---A                           敏捷---A+\033[0m        #**********\n");
	printf("*********#       \033[;33m魔力---A                           魔力---C\033[0m         #**********\n");
	printf("*********#       \033[;33m幸运---B                           幸运---B\033[0m         #**********\n");
	printf("*********#       \033[;33m宝具---A+                          宝具---A\033[0m         #**********\n");
	printf("*********#*********#*********#*********#*********#*********#*********#**********\n");sleep(1);



}

int chose_servant(struct servant_inf* a)
{
	char anykey;
	int i=0;
	printf("首先，我们要了解一下英灵从者的职阶\n");sleep(2);
	printf("职阶代表着从者的职任，分为Saber、Lancer、Archer、Rider、Caster、Assassin、Berserker七种\n");sleep(2);
	printf("剑之骑士——Saber：以剑为主要武器，除魔力以外的属性要求为最上等\n");sleep(2);
	printf("枪之骑士——Lancer：以枪为主要武器，要求全能力值必须优秀，以敏捷和擅长格斗战著称\n");sleep(2);
	printf("弓之骑士——Archer：以宝具的强大为特长的阶位，以强力的射击武器著称\n");sleep(2);
	printf("骑    兵——Rider：英灵要求与某些乘坐物有渊源，能力值虽然不高却有坐骑的性能补救\n");sleep(2);
	printf("魔 术 师——Caster：以强大的魔力著称的阶位，英灵要求魔力值为最上级\n");sleep(2);
	printf("暗 杀 者——Assassin：使用以突袭为代表的暗杀术，并有独特的气息遮断能力\n");sleep(2);
	printf("狂 战 士——Berserker：曾在战斗中疯狂的英灵符合此职阶，可以通过狂化舍弃理智换取能力值的提升\n");sleep(2);
	printf("\n");sleep(2);
	printf("接下来，我们来了解一下英灵的六大能力值\n");sleep(2);
	printf("筋力:英灵的身体力量，筋力的数值能直接反映到物理攻击上\n");sleep(2);
	printf("耐久:英灵的身体承受能力，耐久值高的英灵具有很强的持续作战能力\n");sleep(2);
	printf("敏捷:英灵的灵活程度，敏捷值高的英灵在闪避和命中方面显得很出色\n");sleep(2);
	printf("魔力:英灵的神秘力量，魔力值高的英灵通常会施展出强力的技能从而改变战况\n");sleep(2);
	printf("幸运:一种神奇的力量，有很微妙的作用\n");sleep(2);		
	printf("宝具:宝具是英灵在传说中所使用的道具，宝具可以是武器、防具、首饰、甚至技能本身\n");sleep(2);
	printf("\n下面请做出选择:\n");
	printf("1.阿尔托莉亚\t\t2.齐格菲里德\t\t3.库丘林\t\t4.迪鲁木多\n5.卫宫\t\t\t6.吉尔伽美什\t\t7.美杜莎\t\t8.伊斯坎达尔\n9.美狄亚\t\t10.吉尔斯·德·莱斯\t11.哈桑·萨巴赫\t\t12.佐佐木小次郎\n13.赫拉克勒斯\t\t14.兰斯洛特\n");
	while(1)
	{
	scanf("%d",&i);
	if(i>14||i<1)
	{
	printf("警告：你不能选择这个选项\n");
	continue;
	}
	break;
	}
	i--;
	printf("祝贺你获得自己的英灵从者『%s』,他将效忠于你并助你获得胜利，祝你好运\n\n",a[i].name);sleep(2);
	return i;
}
/*************************************
*	买兵函数
*@参数  int* m——初始金钱数
*	int enmey_friend——敌友判断
*
*************************************/


int buy_solder(int* m,int enymey_friend)
{
	int n=0;
	if(enymey_friend==1)
	{
	printf("请输入购买骑士($200)的数量\t\t现有金钱：%d\n",*m);
	scanf("%d",&n);
	*m=(*m)-200*n;
	if(*m<0)
	{printf("超额\n");
	return 1;}
	num.nk1=n;
	printf("请输入购买步兵($100)的数量\t\t现有金钱：%d\n",*m);
	scanf("%d",&n);
	*m=(*m)-100*n;
	if(*m<0)
	{printf("超额\n");
	return 1;}
	num.nf1=n;
	printf("请输入购买弓箭手($150)的数量\t\t现有金钱：%d\n",*m);
	scanf("%d",&n);
	*m=(*m)-150*n;
	if(*m<0)
	{printf("超额\n");
	return 1;}
	num.na1=n;
	return 0;
	}
	if(enymey_friend==2)
	{
	printf("请输入购买骑士($200)的数量\t\t现有金钱：%d\n",*m);
	scanf("%d",&n);
	*m=(*m)-200*n;
	if(*m<0)
	{printf("超额\n");
	return 1;}
	num.nk2=n;
	printf("请输入购买步兵($100)的数量\t\t现有金钱：%d\n",*m);
	scanf("%d",&n);
	*m=(*m)-100*n;
	if(*m<0)
	{printf("超额\n");
	return 1;}
	num.nf2=n;
	printf("请输入购买弓箭手($150)的数量\t\t现有金钱：%d\n",*m);
	scanf("%d",&n);
	*m=(*m)-150*n;
	if(*m<0)
	{printf("超额\n");
	return 1;}
	num.na2=n;
	return 0;
	}
}
/************************************
*	初始化战场
*@参数	num=兵种数量
*	hp判断是否是士兵
*	enymey_friend判断敌友
************************************/
int init_solder(struct solder_attribute s[],const struct num_of_soldier num)
{
	int n;
	for(n=0;n<num.na1;n++)
	{
	s[n].name='A';			//兵种 骑兵=K，弓兵=A，步兵=F
	s[n].hp=100;				//血量
	s[n].attack=20;			//攻击
	s[n].defense=0;			//防御
	s[n].move=1;				//速度
	s[n].attack_distanse=3;		//攻击范围
	s[n].enemy_friend=1;			//敌友判断 1=友军，2=敌军，0=空地
	}
	for(n;n<num.na1+num.nf1;n++)
	{
	s[n].name='F';			//兵种 骑兵=K，弓兵=A，步兵=F
	s[n].hp=150;				//血量
	s[n].attack=10;			//攻击
	s[n].defense=2;			//防御
	s[n].move=1;				//速度
	s[n].attack_distanse=1;		//攻击范围
	s[n].enemy_friend=1;			//敌友判断 1=友军，2=敌军，0=空地
	}
	for(n;n<num.na1+num.nf1+num.nk1;n++)
	{
	s[n].name='K';			//兵种 骑兵=K，弓兵=A，步兵=F
	s[n].hp=200;				//血量
	s[n].attack=15;			//攻击
	s[n].defense=5;			//防御
	s[n].move=2;				//速度
	s[n].attack_distanse=2;		//攻击范围
	s[n].enemy_friend=1;			//敌友判断 1=友军，2=敌军，0=空地
	}
	for(n;n<2500-num.nk2-num.nf2-num.na2;n++)
	{
	s[n].name=' ';
	s[n].hp=0;				//血量
	s[n].attack=0;			//攻击
	s[n].defense=0;			//防御
	s[n].move=0;				//速度
	s[n].attack_distanse=0;		//攻击范围
	s[n].enemy_friend=0;			//敌友判断 1=友军，2=敌军，0=空地
	}
	for(n;n<2500-num.na2-num.nf2;n++)
	{
	s[n].name='K';			//兵种 骑兵=K，弓兵=A，步兵=F
	s[n].hp=200;				//血量
	s[n].attack=15;			//攻击
	s[n].defense=5;			//防御
	s[n].move=2;				//速度
	s[n].attack_distanse=2;		//攻击范围
	s[n].enemy_friend=2;			//敌友判断 1=友军，2=敌军，0=空地
	}
	for(n;n<2500-num.na2;n++)
	{
	s[n].name='F';			//兵种 骑兵=K，弓兵=A，步兵=F
	s[n].hp=150;				//血量
	s[n].attack=10;			//攻击
	s[n].defense=2;			//防御
	s[n].move=1;				//速度
	s[n].attack_distanse=1;		//攻击范围
	s[n].enemy_friend=2;			//敌友判断 1=友军，2=敌军，0=空地
	}
	for(n;n<2500;n++)
	{
	s[n].name='A';			//兵种 骑兵=K，弓兵=A，步兵=F
	s[n].hp=100;				//血量
	s[n].attack=20;			//攻击
	s[n].defense=0;			//防御
	s[n].move=1;				//速度
	s[n].attack_distanse=3;		//攻击范围
	s[n].enemy_friend=2;			//敌友判断 1=友军，2=敌军，0=空地
	}
	return 0;
}
/**********************************
*	打印战场
*
************************************/

void print_scene(struct solder_attribute s[])
{
	int n;
	for(n=0;n<2500;n++)
	{
		if(s[n].enemy_friend==1)
			printf("\033[;31m%c\033[0m",s[n].name);
		if(s[n].enemy_friend==2)
			printf("\033[;34m%c\033[0m",s[n].name);
		if(s[n].enemy_friend==0)
			printf(" ");
		if((n+1)%50==0)
			printf("\n");
	}
	//printf("ok\n");
}
/*******************************
*	MOD1界面
*
*
*******************************/
int jiemian()
{
	int n;
	printf("Master，请选择日程\n");sleep(1);
	printf("1.状态\n");
	printf("2.进度\n");
	printf("3.索敌\n");
	printf("4.商店\n");
	scanf("%d",&n);
	return n;


}
