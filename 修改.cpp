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
	printf("�밴���������");
	getch();
	//clrscr();
	//gotoxy(1,1);
	printf("----------��ӭʹ�û�����Ʊϵͳ----------\n");
	printf("��ϵͳ�����¹��ܣ���ѡ������Ҫ�ķ���:\n");
	printf("             0.���뺽����Ϣ\n");
	printf("             1.��ʾ������Ϣ\n");
	printf("             2.������Ų�ѯ������Ϣ\n");
	printf("             3.�����в�ѯ������Ϣ\n");
	printf("             4.��    Ʊ\n");
	printf("             5.��    Ʊ\n");
	printf("             6.�޸ĺ�����Ϣ\n");
	printf("             7.�� �� �� ��\n");
	printf("             8.�� ȡ �� ��\n");
	printf("             9.�� �� ϵ ͳ\n");
	printf("----------��ӭʹ�û�����Ʊϵͳ----------\n");
	do{
		printf("��ѡ������Ҫ�ķ���");
		scanf("%d",&c);
	}
	while(c<0||c>9);
	return c;
}
int enter(FLIGHT t[]){
	int i,n;
	//clrscr();
	printf("�����뺽������(����������)");
	scanf("%d",&n);
	while(n>6||n<0){
		//clrscr();
		printf("�����������������뺽������(����������)");
		scanf("%d",&n);
	}
	printf("�����뺽����ϸ��Ϣ:");
	printf("�����\t��ɳ���\t�������\t���ʱ��\t����ʱ��\t��λ��\t�۸�\t�ۿ�\n");
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
	printf("�����\t��ɳ���\t�������\t���ʱ��\t����ʱ��\t��λ��\t�۸�\t�ۿ�\n");
	for(i=0;i<n;i++)
	printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
	printf("��ʾ����");
}
void search1(FLIGHT t[],int n){
	char s[20];
	int i;
	//clrscr();
	printf("����������Ҫ��ѯ�ĺ����:");
	scanf("%s",s);
	for(i=0;i<n;i++){
		if(strcmp(s,t[i].plane_num)==0) break;
	}
	if(i>n-1) printf("���޴˺�����Ϣ\n");
	else{
		printf("�����\t��ɳ���\t�������\t���ʱ��\t����ʱ��\t��λ��\t�۸�\t�ۿ�\n");
		printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
		printf("��ʾ����");
	}
}
void search2(FLIGHT t[],int n){
	char s1[20];
	char s2[20];
	int i;
	//clrscr();
	printf("��������ɳ���:");
	scanf("%s",s1);
	printf("�����뽵�����:");
	scanf("%s",s2);
	for(i=0;i<n;i++){
		if((strcmp(s1,t[i].city1)==0)&&(strcmp(s2,t[i].city2)==0)) break;
	}
	if(i>n-1) printf("���޴˺�����Ϣ\n");
	else{
		printf("�����\t��ɳ���\t�������\t���ʱ��\t����ʱ��\t��λ��\t�۸�\t�ۿ�\n");
		printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
		printf("��ʾ����");
	}
}
void book(FLIGHT t[],int n){
	char number1[10],name1[10],id1[20],flight_num1[10];
	int i,j=0,m,k,count1;
	//clrscr();
	printf("����Ҫ������Ʊ");
	scanf("%d",&m);
	printf("���\t����\t֤����\t��Ʊ��\t�����\n");
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
			printf("���޴˺���");
			m=m+2;
			k++;
		}
	}
}
void refund(FLIGHT t[],int n){
	char s1[20],s2[20];
	int i,k,j,h,l,ch;
	//clrscr();
	printf("������������Ʊ�ĺ���ĺ����:");
	scanf("%s",s1);
	printf("����������֤����:");
	scanf("%s",s2);
	printf("���\t����\t֤����\t��Ʊ��\t�����\n");
	for(i=0;i<n;i++){
		for(j=0;j<t[i].sit;j++)
		if((strcmp(s1,t[i].guest[j].flight_num)==0)&&(strcmp(s2,t[i].guest[j].id)==0)){
			printf("%s\t%s\t%s\t%d\t%s\n",t[i].guest[j].number,t[i].guest[j].name,t[i].guest[j].id,t[i].guest[j].count,t[i].guest[j].flight_num);
			l=j;
			h=i;break;
		}
	}
	i=h;
	if(i>n-1) printf("���޴˺�����Ϣ\n");
	else{
		printf("��ȷ����Ʊ��(ȷ�ϰ�1��ȡ����0)\n");
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
		printf("��Ʊ�ɹ�\n");
	}
}
void change(FLIGHT t[],int n){
	char s[20];
	int i;
	//clrscr();
	printf("�����������޸ĺ�����Ϣ�ĺ����:");
	scanf("%s",s);
	for(i=0;i<n;i++){
		if(strcmp(s,t[i].plane_num)==0) break;
	}
	if(i>n-1) printf("���޴˺�����Ϣ\n");
	else{
		printf("�����\t��ɳ���\t�������\t���ʱ��\t����ʱ��\t��λ��\t�۸�\t�ۿ�\n");
		printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\t%s\n",t[i].plane_num,t[i].city1,t[i].city2,t[i].time1,t[i].time2,t[i].seat,t[i].price,t[i].discount);
		printf("�������µ���Ϣ\n");
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
		printf("�ļ��޷���\n");
		exit(1);
	}
	printf("��ʼ�����ļ�\n");
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
	printf("�ļ�����ɹ�\n");
}
int load(FLIGHT t[]){
	int i,j,n;
	FILE *fp;
	if((fp=fopen("flight.txt","rb"))==NULL){
		printf("�ļ��޷���\n");
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
	printf("�ѳɹ���ȡ�ļ�\n\n");
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


