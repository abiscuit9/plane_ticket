#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define N 20
#define q 40
typedef struct {
	char number[10];
	char id[20];
	char name[20];
	int count;
	char flight_num[10]; 
}GUEST;
typedef struct {
	char plane_num[10];
	char city1[20];
	char city2[20];
	char time1[20];
	char time2[20];
	int seat;
	char price[5];
	char discount[5];
	GUEST guest[20];
	int sit;
}FLIGHT;
manu(){
	int c;
	//gotoxy(1,25);
	printf("请按任意键继续");
	getch();
	//clrscr();
	//gotoxy(1,1);
	printf("----------欢迎使用机场售票系统----------\n");
	printf("该系统有以下功能，请选择您需要的服务:\n");
	printf("             0.输入航班信息\n");
	printf("             1.显示航班信息\n");
	printf("             2.按航班号查询航班信息\n");
	printf("             3.按城市查询航班信息\n");
	printf("             4.订    票\n");
	printf("             5.退    票\n");
	printf("             6.修改航班信息\n");
	printf("             7.保 存 文 件\n");
	printf("             8.读 取 文 件\n");
	printf("             9.退 出 系 统\n");
	printf("----------欢迎使用机场售票系统----------\n");
	do{
		printf("请选择您需要的服务：");
		scanf("%d",&c);
	}
	while(c<0||c>9);
	return c;
}
int enter(FLIGHT t[]){
	int i,n;
	//clrscr();
	printf("请输入航线总数(不超过六条)");
	scanf("%d",&n);
	while(n>6||n<0){
		//clrscr();
		printf("输入有误，请重新输入航线总数(不超过六条)");
		scanf("%d",&n);
	}
	printf("请输入航线详细信息:");
	printf("航班号\t起飞城市\t降落城市\t起飞时间\t降落时间\t座位数\t价格\t折扣\n");
	for(i=0;i<n;i++){
		scanf("%s",t[i].plane_num);
		//gotoxy(13,6+i);
		scanf("%s",t[i].city1);
		//gotoxy(25,6+i);
		scanf("%s",t[i].city2);
		//gotoxy(36,6+i);
		scanf("%s",t[i].time1);
		//gotoxy(47,6+i);
		scanf("%s",t[i].time2);
		//gotoxy(57,6+i);
		scanf("%d",&t[i].seat);
		//gotoxy(64,6+i);
		scanf("%s",t[i].price);
		//gotoxy(73,6+i);
		scanf("%s",t[i].discount);
	}
	for(i=0;i<n;i++)t[i].sit=0;
	return n;
}
void list(FLIGHT t[],int n){
	int i;
	//clrscr();
	printf("航班号\t起飞城市\t降落城市\t起飞时间\t降落时间\t座位数\t价格\t折扣\n");
	for(i=0;i<n;i++)
	printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
	printf("显示结束");
}
void search1(FLIGHT t[],int n){
	char s[20];
	int i;
	//clrscr();
	printf("请输入您想要查询的航班号:");
	scanf("%s",s);
	for(i=0;i<n;i++){
		if(strcmp(s,t[i].plane_num)==0) break;
	}
	if(i>n-1) printf("查无此航线信息\n");
	else{
		printf("航班号\t起飞城市\t降落城市\t起飞时间\t降落时间\t座位数\t价格\t折扣\n");
		printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
		printf("显示结束");
	}
}
void search2(FLIGHT t[],int n){
	char s1[20];
	char s2[20];
	int i;
	//clrscr();
	printf("请输入起飞城市:");
	scanf("%s",s1);
	printf("请输入降落城市:");
	scanf("%s",s2);
	for(i=0;i<n;i++){
		if((strcmp(s1,t[i].city1)==0)&&(strcmp(s2,t[i].city2)==0)) break;
	}
	if(i>n-1) printf("查无此航线信息\n");
	else{
		printf("航班号\t起飞城市\t降落城市\t起飞时间\t降落时间\t座位数\t价格\t折扣\n");
		printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
		printf("显示结束");
	}
}
void book(FLIGHT t[],int n){
	char number1[10],name1[10],id1[20],flight_num1[10];
	int i,j=0,m,k,count1;
	//clrscr();
	printf("您想要订几张票");
	scanf("%d",&m);
	printf("编号\t姓名\t证件号\t订票数\t航班号\n");
	for(k=0;k<m;k++){
		scanf("%s",number1);
		//gotoxy(13,4+k);
		scanf("%s",name1);
		//gotoxy(25,4+k);
		scanf("%s",id1);
		//gotoxy(43,4+k);
		scanf("%d",&count1);
		//gotoxy(53,4+k);
		scanf("%s",flight_num1);
		for(i=0;i<n;i++){
			if(strcmp(flight_num1,t[i].plane_num)==0){
				j=t[i].sit;
				strcpy(t[i].guest[j].number,number1);
				strcpy(t[i].guest[j].name,name1);
				strcpy(t[i].guest[j].id,id1);
				t[i].guest[j].count=count1;
				strcpy(t[i].guest[j].flight_num,flight_num1);
				t[i].seat=t[i].seat-count1;
				t[i].sit++;
				break;
			}
		}
		if(i>n-1){
			printf("查无此航班");
			m=m+2;
			k++;
		}
	}
}
void refund(FLIGHT t[],int n){
	char s1[20],s2[20];
	int i,k,j,h,l,ch;
	//clrscr();
	printf("请输入您想退票的航班的航班号:");
	scanf("%s",s1);
	printf("请输入您的证件号:");
	scanf("%s",s2);
	printf("编号\t姓名\t证件号\t订票数\t航班号\n");
	for(i=0;i<n;i++){
		for(j=0;j<t[i].sit;j++)
		if((strcmp(s1,t[i].guest[j].flight_num)==0)&&(strcmp(s2,t[i].guest[j].id)==0)){
			printf("%s\t%s\t%s\t%d\t%s\n",t[i].guest[j].number,t[i].guest[j].name,t[i].guest[j].id,t[i].guest[j].count,t[i].guest[j].flight_num);
			l=j;
			h=i;break;
		}
	}
	i=h;
	if(i>n-1) printf("查无此航班信息\n");
	else{
		printf("您确认退票吗(确认按1，取消按0)\n");
		scanf("%d",&ch);
		if(ch==1){
			for(k=l+1;k<t[i].sit;k++){
				strcpy(t[i].guest[k-1].number,t[i].guest[k].number);
				strcpy(t[i].guest[k-1].name,t[i].guest[k].name);
				strcpy(t[i].guest[k-1].id,t[i].guest[k].id);
				t[i].guest[k-1].count=t[i].guest[k].count;
				strcpy(t[i].guest[k-1].flight_num,t[i].guest[k].flight_num);
			}
			t[i].sit--;
		}
		printf("退票成功\n");
	}
}
void change(FLIGHT t[],int n){
	char s[20];
	int i;
	//clrscr();
	printf("请输入您想修改航班信息的航班号:");
	scanf("%s",s);
	for(i=0;i<n;i++){
		if(strcmp(s,t[i].plane_num)==0) break;
	}
	if(i>n-1) printf("查无此航线信息\n");
	else{
		printf("航班号\t起飞城市\t降落城市\t起飞时间\t降落时间\t座位数\t价格\t折扣\n");
		printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
		printf("请输入新的信息\n");
		scanf("%s",t[i].plane_num);
		//gotoxy(13,6+i);
		scanf("%s",t[i].city1);
		//gotoxy(25,6+i);
		scanf("%s",t[i].city2);
		//gotoxy(35,6+i);
		scanf("%s",t[i].time1);
		//gotoxy(47,6+i);
		scanf("%s",t[i].time2);
		//gotoxy(57,6+i);
		scanf("%d",&t[i].seat);
		//gotoxy(64,6+i);
		scanf("%s",t[i].price);
		//gotoxy(71,6+i);
		scanf("%s",t[i].discount);
	}
}
void save(FLIGHT t[],int n){
	int i,j;
	FILE *fp;
	if((fp=fopen("flight.txt","wb"))==NULL){
		printf("文件无法打开\n");
		exit(1);
	}
	printf("开始保存文件\n");
	fprintf(fp,"%d",n);
	fprintf(fp,"\r\n");
	for(i=0;i<n;i++){
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
		fprintf(fp,"\r\n");
		fprintf(fp,"%d",t[i].sit);
		fprintf(fp,"\r\n");
		for(j=0;j<t[i].sit;j++){
			fprintf(fp,"%s\t%s\t%s\t%d\t%s\n",t[i].guest[j].number,t[i].guest[j].name,t[i].guest[j].id,t[i].guest[j].count,t[i].guest[j].flight_num);
			fprintf(fp,"\r\n");
		}
	}
	fclose(fp);
	printf("文件保存成功\n");
}
int load(FLIGHT t[]){
	int i,j,n;
	FILE *fp;
	if((fp=fopen("flight.txt","rb"))==NULL){
		printf("文件无法打开\n");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++){
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
		fscanf(fp,"%d",&t[i].sit);
		for(j=0;j<t[i].sit;j++)
		fscanf(fp,"%s\t%s\t%s\t%d\t%s\n",t[i].guest[j].number,t[i].guest[j].name,t[i].guest[j].id,t[i].guest[j].count,t[i].guest[j].flight_num);
	}
	fclose(fp);
	printf("已成功读取文件\n\n");
	return n;
}
main(){
	FLIGHT flight[q];
	int length;
	for(;;){
		switch(manu()){
			case 0:length=enter(flight);break;
			case 1:list(flight,length);break;
			case 2:search1(flight,length);break;
			case 3:search2(flight,length);break;
			case 4:book(flight,length);break;
			case 5:refund(flight,length);break;
			case 6:change(flight,length);break;
			case 7:save(flight,length);break;
			case 8:length=load(flight);break;
			case 9:exit(0);
		}
	}
	return 0;
}


