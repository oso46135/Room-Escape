#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<cstring> 

void move();		//�̵�
void paper();		//����
void pot();			//ȭ��
void Photo();		//���� 
void door();		//Ż�⹮ 
void ending();		//������ 
void boos();		//å 

int chbo = 0;		//ó�� �ȳ����� ���۴ϴ�. 

int potskip = 0;		//ȭ�� �ʹ� �̺�Ʈ ��ŵ 
int pottoking = 0; 		//ȭ�� ��ȭ �̺�Ʈ 
int potfin = 0; 		//ȭ�� ���� ���� ��ŵ 

int paperskip = 0;		//���� �ʹ� �̺�Ʈ ��ŵ 
int paperfin = 0;		//������ ���� ���� �� �� 
int fay = 0;			//���� ����� �̺�Ʈ ��ŵ 
int titaw = 0;			//ƼŸ�� ���̶�� ���� �˾��� ��

int Photoskip = 0;		//���� �ʹ� �̺�Ʈ ��ŵ 
int Photosee = 0;		//���ڸ� ���� �̺�Ʈ ��ŵ 
int photdel = 0;		//���� �׸� ���� �̺�Ʈ ��ŵ 
int Photofin = 0;		//���� �׸��� �ı� �̺�Ʈ ��ŵ 

int jending = 2;			//�� ���� 
const char *paperch= "?";	//���� Īȣ 
const char *photoch= "?";	//���� Īȣ 
int main(){				//2P �÷��̾�

	system("mode con cols=53 lines=20 | title ��Ż�� 2P.Ver");

	printf(" ------------------------------------------------\n");
	printf(" |	   ���� ������ 2P ���� �Դϴ�.��	|\n | 	 ��1P�� ���� �÷����ؾ� �մϴ�.��	|\n");
	printf(" ------------------------------------------------\n\n");
	system("PAUSE");
	 
	system("cls");
	printf("\nõõ�� ���� ���� ���� �ƴ� ���� �ٸ� ���̿����ϴ�\n");
	Sleep(1500);
	printf("�ֺ��� ���� �����ϸ� ��ŭ�� ������ġ�� ���ҽ��ϴ�\n");
	Sleep(2000);
	printf("����� ��ٷ� �ڽ��� ��ġ�Ǿ��ٴ� ���� �˾����Ƚ��ϴ�\n");
	Sleep(2000);
	printf("\n'��...�߸� ������ ���� ����...�̶��� ����ؼ�'\n");
	Sleep(2500);
	printf("\n ����� ��Ÿ��� �������� ��Ż���� Ŭ���� �ϱ�� �߽��ϴ�\n");
	Sleep(2000);
	printf("�̷�! �ʹ� �ڸ��ؼ� �ൿ ������� �Ⱥ��ٰ� �ϴ±���\n");
	Sleep(2000);
	printf("(����� ���ֱ� �ٶ��ϴ�.)\n\n");		
	system("PAUSE");
	
	move(); 
	
}

void move(){
	char movemove[20];
	while(1){
		system("cls"); 
		printf("[�߾�]\n");
		printf("Īȣ:%s,%s\n\n",paperch,photoch) ;
		printf("|ȭ��|����|����| �� | å |\n������ �ൿ�Ͻðڽ��ϱ�?\n\n");
		printf("(���� �ȵɼ� ������ �ǹ̴� ������ �ٸ� �ܾ�� �Է����ּ���)\n"); 
		if(chbo == 0){
			printf("(������ ���� �����ּ���)\n");
			printf("(���ư��� ������ '���Ʊ��'�� ���ּ���!)\n"); 
			printf("ex)ȭ��,����,����,���ư���(O)\nex)ȭ�а���,�� ��,����(����) (X)\n");
			printf("**������ �𸣰ڽ��ϴ� '����' ���ּ���! ����� ��� ���մϴ�!**\n");
			printf("(�ѱ��� �Է��Ҷ� �ѱ��� �з��� �� ���ð� �����̽��� �ѹ� �����ּ���!)\n"); 
			chbo=1;
		}
		printf("  >>");
		scanf("%s",movemove);
		if(strcmp(movemove,"ȭ��") == 0){
				pot();
		}
		else if(strcmp(movemove,"����") == 0){
				paper();
		}
		else if(strcmp(movemove,"����")==0){
				Photo();
		}
		else if(strcmp(movemove,"��")==0){
			door();
		}
		else{
			system("cls"); 
			printf("[�߾�]\n\n");
			printf("'�� �ൿ�� �� �� ���ڱ�..'\n\n");
			
			 system("PAUSE");
		} 
		
	}
}
void door(){	//Ż�⹮ 
	char a[20];
	while(1){
		system("cls"); 
		printf("[�߾�]-[��]\n\n");
		printf("����� ������ �ٰ������ϴ�.\n");
		Sleep(1500);
		printf("����� ������ ������ ����� �������� ���� ���̶� ���մϴ�!\n");
		printf(" >>");
		scanf("%s",a);
		if(strcmp(a,"���ư���") == 0 || strcmp(a,"���ư���") == 0 || strcmp(a,"�߾�") == 0){
			printf("\n����� �� ��Ʈ�� ������ �ٽ� ���⸦ ����մϴ�\n");
			 system("PAUSE");
			 move();
		}
		else if(strcmp(a,"����������")==0){
			system("cls"); 
			printf("[�߾�]-[��]\n\n");
			printf("���� ��鸮�鼭 ������ ������ �����߽��ϴ�\n");
			Sleep(1500);
			printf("�̰� �����ٴ� �Ϳ� ����� �� ������ �մϴ�. \n");
			system("PAUSE");
			ending();
			
		}
		else if(strcmp(a,"����") == 0 || strcmp(a,"����") == 0 || strcmp(a,"����") == 0 || strcmp(a,"���캻��") == 0 ){
			system("cls"); 
			printf("[�߾�]-[��]\n\n");
			printf("����� ���� �ڼ��� ���� ���ҽ��ϴ�.\n");
			Sleep(1500);
			printf("��! �ű��� ���̳׿�! ������ �����ϴ�! ������ �о ���� ���մϴ�!\n\n");
			
			system("PAUSE");
		}
		else{
			system("cls"); 
			printf("[�߾�]-[��]\n\n");
			printf("'�� �ൿ�� ���ϰڱ�.'\n");
			system("PAUSE");
			 
		}
	}
	
}

void pot(){		//ȭ�� 
	char potpot[20];

	while(1){
		if(potskip ==  0){		//ó���̺�Ʈ ��ŵ 
			system("cls"); 
			printf("[�߾�]-[ȭ��]\n\n");
			printf("����� ȭ�п��� ������ ����.\n");
			Sleep(1000);
			printf("ȭ���� ���� �Ƹ��ٿ� �� �Ѽ��̰� �Ǿ��ִ�\n");
			Sleep(1000);
			potskip=1;	
		}
		else{
			system("cls"); 
			printf("[�߾�]-[ȭ��]\n\n");
			printf("�Ʊ�� ���� �� �Ʊ�� ���� ��ġ\n");
			printf("���� ���� Ư���� ���� ��\n");
		}
		printf("\n���� �ൿ�� �ұ�?\n");
		printf("  >>");
		scanf("%s",potpot);
		//�̺�Ʈ Ÿ���� 
		if(strcmp(potpot,"����") == 0 || strcmp(potpot,"����") == 0 || strcmp(potpot,"��������") == 0 || strcmp(potpot,"����") == 0 || strcmp(potpot,"ȭ������") == 0 || strcmp(potpot,"������") == 0 || strcmp(potpot,"���캻��") == 0 ){
			system("cls"); 
			printf("[�߾�]-[ȭ��]-[%s]\n\n",potpot);
			printf("����� ȭ���� �ڼ��� ���ҽ��ϴ�.\n");
			Sleep(1000);
			printf("�ٸ��� �𸣰ڰ�, ���� �ſ� �̻޴ϴ�.\n\n");
			
			system("PAUSE");
			
		}
		else if(strcmp(potpot,"���´�") == 0 || strcmp(potpot,"�������´�") == 0 || strcmp(potpot,"���δ�") == 0 || strcmp(potpot,"�׿�") == 0 || strcmp(potpot,"óġ") == 0 || strcmp(potpot,"�̴´�") == 0 || strcmp(potpot,"�����̴´�") == 0 || strcmp(potpot,"�̴�") == 0 || strcmp(potpot,"����") == 0){
			system("cls"); 
			printf("[�߾�]-[ȭ��]-[%s]\n\n",potpot);
			printf("����� ���� ����� ����߽��ϴ�.\n\n");
		
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".\n\n");
			Sleep(1000);
			
			printf("���� �̻��� ������ ���� �� �����ϴ�..\n\n");
			system("PAUSE");
				
		}
		else if(strcmp(potpot,"���ư���") == 0 || strcmp(potpot,"���ư���") == 0 || strcmp(potpot,"�߾�") == 0){		//�߾����� ���� Ŀ�ǵ� 
			system("cls"); 
			printf("[�߾�]-[ȭ��]\n\n");
			printf("����� �ٽ� ó������ ���Ʊ�� �߽��ϴ�.\n\n"); 
			system("PAUSE");
			move(); 
		}
		else if(strcmp(potpot,"��������") == 0){
			system("cls"); 
			printf("[�߾�]-[ȭ��]-[%s]\n\n",potpot);
			if(potfin == 0){
				printf("����� ȭ���� ��� ���� ���ҽ��ϴ�\n");
				Sleep(1500);
				printf("��! ȭ�йؿ� ������ �ֽ��ϴ�!\n");
				Sleep(1500);
				printf("����� ���� �Ӹ��� �̰��� ������ ���� �˾����Ƚ��ϴ�!\n\n");
				system("PAUSE");
				
				system("cls"); 
				printf("[�߾�]-[ȭ��]-[%s]\n\n",potpot);
				printf("'0���� 9���� 10���� ���ڸ� ��� ����� ��Ģ�� �´� ���� ������.'\n\n") ;		//3816547290
				printf("'ù ��° ���ڱ��� 1�� ����������.\n");
				printf(" �� ��° ���ڱ��� 2�� ����������. \n ");
				printf(" �� ��° ���ڱ��� 3���� ����������.\n");
				printf(" �� ��° ���ڱ��� 4�� ����������.\n") ;	
				printf(" �ټ� ��° ���ڱ��� 5�� ����������.\n") ;
				printf(" ���� ��° ���ڱ��� 6�� ����������.\n") ;
				printf(" �ϰ� ��° ���ڱ��� 7�� ����������.\n") ;
				printf(" ���� ��° ���ڱ��� 8�� ����������.\n") ;
				printf(" ��ȩ ��° ���ڱ��� 9�� ����������.\n") ;
				printf(" �� ��° ���ڱ��� 10�� ����������.'\n\n") ;
				Sleep(1500);
				printf("����� �� ������ ���������� 10���ڶ�� ���� �˾����ȴ�\n");
				printf("��...");
				Sleep(1500);
				printf("���� ���̵��� ��ƴٴ� ���� ���޾Ҵ�!\n");
				Sleep(1500);
				printf("����� �� ������ Ǫ�µ� ��û �����ɸ� �� ���� ������ �����.\n"); 
				potfin = 1;
			}
			else{
				printf("����� Ǯ���� ���ϰ� �������� Ŭ���ع����� Ȳ���ϰ� �ٽ� ���̸� ���� �����߽��ϴ�\n\n"); 
				system("PAUSE");
				system("cls"); 
				printf("[�߾�]-[ȭ��]-[%s]\n\n",potpot);
				printf("'0���� 9���� 10���� ���ڸ� ��� ����� ��Ģ�� �´� ���� ������.'\n\n") ;		//3816547290
				printf("'ù ��° ���ڱ��� 1�� ����������.\n");
				printf(" �� ��° ���ڱ��� 2�� ����������. \n ");
				printf(" �� ��° ���ڱ��� 3���� ����������.\n");
				printf(" �� ��° ���ڱ��� 4�� ����������.\n") ;	
				printf(" �ټ� ��° ���ڱ��� 5�� ����������.\n") ;
				printf(" ���� ��° ���ڱ��� 6�� ����������.\n") ;
				printf(" �ϰ� ��° ���ڱ��� 7�� ����������.\n") ;
				printf(" ���� ��° ���ڱ��� 8�� ����������.\n") ;
				printf(" ��ȩ ��° ���ڱ��� 9�� ����������.\n") ;
				printf(" �� ��° ���ڱ��� 10�� ����������.'\n\n") ;
				
				printf("��Ʈ�� ���ڸ� ù��°�� 3�̸�, ����°�� 1�̴�, ��ȩ��°�� ���� ���ڵ� �� ���� �ִ�.\n\n");
				
			}
			system("PAUSE");
		}
		else if(strcmp(potpot,"�����Ǵ�") == 0 || strcmp(potpot,"��ȭ") == 0 || strcmp(potpot,"�ȳ�") == 0 ){
			system("cls"); 
			printf("[�߾�]-[ȭ��]-[%s]\n\n",potpot);
			printf("����� ��û�� �γ��� �ɿ��� �λ縦 �߽��ϴ�.\n\n");
			Sleep(1500);
			printf("������� ���� ����Ի��̿����ϴ�.\n\n");
			system("PAUSE");
			pottoking = 1;
		}
		else if(pottoking == 1 && strcmp(potpot,"�����Ǵ�") == 0 || pottoking == 1 && strcmp(potpot,"��ȭ") == 0 || pottoking == 1 && strcmp(potpot,"�ȳ�") == 0 ) {
			system("cls"); 
			printf("[�߾�]-[ȭ��]-[%s]\n\n",potpot);
			printf("�� �̻� ����� ��û�� ���� �ϱ� �Ƚ��ϴ�\n");
			Sleep(1500);
			printf("���� ���� �ְ��� �ϰ� �ϴ� ����� ������?\n\n");
			system("PAUSE");
		}
		else{
			system("cls"); 
			printf("[�߾�]-[ȭ��]\n\n");
			printf("'�� �ൿ�� �� �� ���ڱ�..'\n\n");
			system("PAUSE");
		}
	}
 
}

void paper(){ 	//���� 




	char paperpaper[20];
	while(1){
		system("cls"); 
		printf("[�߾�]-[����]\n\n");
		if(paperskip == 0){
			printf("����� ���� ������ �ִ� ���̸� �־����ϴ�.\n");
			Sleep(1000);
			printf("��");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf("�׻��Դϴ�\n");

		}
		else if(paperfin == 1){
			printf("��...");
			Sleep(1000);
			printf("å�� �׸��� 3326�� ����...");
			Sleep(1000);
			printf("�׳�");
			Sleep(1000);
		} 
		else{
			printf("��...");
			Sleep(1000);
			printf("�׳�");
			Sleep(1000); 
		}
		if(titaw == 1 && paperskip == 1){
			printf(" ƼŸ�������Դϴ�!\n");
		} 
		else if(paperskip == 1){
			printf(" �����Դϴ�!\n");
		}
		else{
			printf("");
			paperskip = 1;
		}
		printf("  >>");
		scanf("%s",paperpaper);
		//�̺�Ʈ Ÿ����
		 
		if(paperfin == 0 && strcmp(paperpaper,"����") == 0 || strcmp(paperpaper,"����") == 0 ||  strcmp(paperpaper,"���캸��") == 0 ||  strcmp(paperpaper,"����") == 0 ||  strcmp(paperpaper,"����") == 0) {
			system("cls"); 
			printf("[�߾�]-[����]-[%s]\n\n",paperpaper);
			printf("����� ���̸� �ڼ��� ���캸�ҽ��ϴ�\n");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n");
			Sleep(1500);
			
			printf("����� �ڼ������� ���ڿ� �׸��� �׷����ֽ��ϴ�!\n");
			Sleep(1000);
			printf("��");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			
			printf("å�� �׸��̶� 3326�̶�� ���ڰ� ���� �����ִ�.\n");
			printf("�� Ư���Ѱ� ����.\n");
			paperfin = 1;
			system("PAUSE");
			
		}
		else if(strcmp(paperpaper,"���´�")==0 || strcmp(paperpaper,"����")==0 || strcmp(paperpaper,"����")==0 || strcmp(paperpaper,"������")==0){
			system("cls"); 
			printf("[�߾�]-[����]-[%s]\n\n",paperpaper);
			printf("����� ���ȷ� ���̸� ��� ���� �ֱ� �����߽��ϴ�\n");
			Sleep(1500);
			printf("�̷�! �ڼ��� ���� ƼŸ�� ���̿�����!\n\n");
			titaw = 1;
			 
			system("PAUSE"); 
		}
		else if(fay == 0 && strcmp(paperpaper,"���´�") == 0 || fay == 0 && strcmp(paperpaper,"��������") == 0 || fay == 0 && strcmp(paperpaper,"����") == 0){
			system("cls"); 
			printf("[�߾�]-[����]-[%s]\n\n",paperpaper);
			printf("����� ������ �������� ���̸� �����ϴ�.\n\n"); 
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n\n");
			Sleep(2000);
			
			printf("����� ����� ���� ���� ����⸦ ���Ƚ��ϴ�!\n\n");
			Sleep(1000);
			
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n\n");
			Sleep(2000);
			
			printf("�̷�! ����� ������ ������ �� ���� ���� �߶��߽��ϴ�\n");
			Sleep(1000);
			printf("�ٽ� ������ �ִ� ���̰� ����ϴ�.\n\n");
			system("PAUSE");
			
			fay = 1;
			move();
			 
		} 
		else if(fay == 1 && strcmp(paperpaper,"���´�") == 0 || fay == 1 && strcmp(paperpaper,"��������") == 0 || fay == 1 && strcmp(paperpaper,"����") == 0 ){
			system("mode con cols=53 lines=20 | title �������� ��Ƴ�");
			system("cls"); 
			printf("[�߾�]-[����]-[%s]\n\n",paperpaper);
		
			printf("����� �ٽ� ���̸� ���� �����߽��ϴ�\n\n");
			
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n\n");
			Sleep(2000);
			
			printf("�̹����� ���� ������ ���߽��ϴ�!\n ����� �ָ��� ���� �����մϴ�.\n\n");
		
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n\n");
			Sleep(2000);
			
			printf("�̷�! ����� ������ ���� ���������ϴ�! �ٽ� ���̰� ����ϴ�.\n\n");
			printf("����� ��¦ �Ǿ�ö��� ������ ���������ϴ�..\n");
			paperch = "�λ�����"; 
			system("PAUSE");
			jending--;
			fay = 2; 
			move();
		}
		else if(fay == 2 && strcmp(paperpaper,"���´�") == 0 || fay == 2 && strcmp(paperpaper,"��������") == 0 || fay == 2 && strcmp(paperpaper,"����") == 0 ){
			system("cls"); 
			printf("[�߾�]-[����]-[%s]\n\n",paperpaper);
			printf("����� ���̻� ������ ������ �𸨴ϴ�.\n\n");
			system("PAUSE"); 
		}
		else if(strcmp(paperpaper,"���ư���") == 0 || strcmp(paperpaper,"���ư���") == 0 || strcmp(paperpaper,"�߾�") == 0){		//�߾����� ���� Ŀ�ǵ� 
			system("cls"); 
			printf("[�߾�]-[����]\n\n");
			printf("����� �ٽ� ó������ ���Ʊ�� �߽��ϴ�.\n\n"); 
			system("PAUSE");
			move(); 
		}
		else{
			system("cls"); 
			printf("[�߾�]-[����]\n\n");
			printf("'�� �ൿ�� �� �� ���ڱ�..'\n\n");
			system("PAUSE");
		}
	}
}

 void Photo(){	//���� 
	char PhotoPhoto[20];
	while(1){
		if(Photoskip == 0){
			system("cls"); 
			printf("[�߾�]-[����]\n\n");
			printf("����� ���� �ɷ��ִ� ���ڷ� �ٰ������ϴ�\n");
			Sleep(1500);
			printf("��");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf("������ ������ ������ ���� ������!\n");
			Photoskip = 1;
		}
		else{
			system("cls"); 
			printf("[�߾�]-[����]\n\n");
			printf("��...");
			Sleep(1000);
			printf("����� ������ ���� �����߽��ϴ�.\n");
			printf("��...");
			Sleep(2500);
			printf("�ƹ����� �ƴ� �� �����ϴ�.\n");
		}
		
		printf(" >>");
		scanf("%s",PhotoPhoto);
		
		if(strcmp(PhotoPhoto,"**") == 0 ){
			
		}
		else if(strcmp(PhotoPhoto,"����") == 0 || strcmp(PhotoPhoto,"����") == 0 ||  strcmp(PhotoPhoto,"���캸��") == 0 ||  strcmp(PhotoPhoto,"����") == 0 ||  strcmp(PhotoPhoto,"����") == 0 ){
				system("cls"); 
				printf("[�߾�]-[����]-[%s]\n\n",PhotoPhoto);
				if(Photosee == 0){
					printf("����� �׸��� �ڼ��� ���� �����߽��ϴ�.\n");
					Sleep(1000);
					printf("�������� ���� ���?");
					Sleep(1500);
					printf("...�ƴ� ���� �������� ���?\n");
					Sleep(2000);
					printf("�ƹ�ư �̻��� �׸��� ���� Ȯ���մϴ�.\n");
					Photosee = 1;
				}
				else if(Photosee == 1){
					printf("��");
					Sleep(1500);
					printf(".");
					Sleep(1500);
					printf(".");
					Sleep(1500);
					printf("����� �� �׸��� ���� ���� �����մϴ�.\n");
					Sleep(1500);
					
					Sleep(1500);
					printf(".");
					Sleep(1500);
					printf(".");
					Sleep(1500);
					
					printf("���� ������ �����ϴ� ���� �ƴմϴ�\n");
					
					Photosee = 2;
				} 
				else{
					
					printf("����� �׸��� ���� ���� �������� �ʱ�� �߽��ϴ�.\n");
					Sleep(1000);
					printf("�� ���� �����̶�� �����մϴ�.\n");
					Sleep(1000);
				}
				
				printf("\n");
				system("PAUSE");
		}
		else if(strcmp(PhotoPhoto,"����")==0 ||strcmp(PhotoPhoto,"������")==0 ||strcmp(PhotoPhoto,"����Ʈ����")==0 ||strcmp(PhotoPhoto,"���")==0){
			system("mode con cols=53 lines=20 | title ��ġ������ȭ!");
			system("cls"); 
			printf("[�߾�]-[����]-[%s]\n\n",PhotoPhoto);
			if(Photofin == 0){
				
				printf("����� �� �ǹ̾��� �׸��� ȸ���ҷ��� �߽��ϴ�.\n");
				Sleep(2500);
				printf("...��𼱰� ���԰� �鸮�±���...�ǵ��� �ʱ�� �߽��ϴ�.\n"); 
				Sleep(2500);
				photoch ="�����Ǹ�";
				Photofin ++;
				jending--;
				system("PAUSE");
			}
			else{
				printf("����� �׸��� ���游 �Ͽ����ϴ�..");
				system("PAUSE");
				
			}
		}
		else if(strcmp(PhotoPhoto,"�׸�������")==0){
			system("cls"); 
			printf("[�߾�]-[����]-[%s]\n\n",PhotoPhoto);
			if(photdel == 0){
				printf("����� ������ �𸣰����� �׸��� �ѹ� �����ҽ��ϴ�.\n");
				printf("�ȿ��� �� �������� ���̰� ����ֽ��ϴ�!\n"); 
			}
			else{
				printf("����� ���� ������ ������ �־ �ٽ� ������ ���� �����߽��ϴ�.\n");
			}
			printf("'������ �� ������ 52���� ī�尡 �ִ�.\n�׷��� Ȯ���غ��� ������ ��������.\n������ ä�� 9���� �Ȱ��� ī�带 ������������ 2���� ���Ҵ�.\n�̹����� 4���� ������µ� 3���� ����, 7���� ��������� 5���� ���Ҵ�.\n�׷� ������ ī��� �����ϱ�?\n'");
			printf("����� �̹����� �������ϰŶ�� ������ ���.\n");
			printf("(������ 0���� �־��ּ���)\n");
			photdel = 1;
			system("PAUSE");
		}
		else if(strcmp(PhotoPhoto,"���ư���") == 0 || strcmp(PhotoPhoto,"���ư���") == 0 || strcmp(PhotoPhoto,"�߾�") == 0){		//�߾����� ���� Ŀ�ǵ� 
				system("cls"); 
				printf("[�߾�]-[����]\n\n");
				printf("����� �ٽ� ó������ ���Ʊ�� �߽��ϴ�.\n\n"); 
				system("PAUSE");
				move(); 
			}
		else{
				system("cls"); 	
				printf("[�߾�]-[����]\n\n");
				printf("'�� �ൿ�� �� �� ���ڱ�..'\n\n");
			
				 system("PAUSE");
			} 
	
	}
}

void ending(){
	char a[20];
	system("cls");
	printf("[�߾�]-[����]\n\n");		//	system("PAUSE");  Sleep(2000);
	printf("����� õõ�� �ȱ� �����߽��ϴ�. Ȥ�� �𸣴� ���������ϼ��� �ֽ��ϴ�.\n");
	Sleep(1500);
	printf("����� �� ���� ���� �ٴڿ� ������ �ִٴ� ���� �˾����Ƚ��ϴ�.\n\n");
	Sleep(1500);	
	printf("'...Ȥ�� �𸣴ϱ� �������?'\n\n");
	Sleep(1500);	
	printf("����� õõ�� �ɾ���ϴ�. ���� ������ ������ϴ�.\n");
	Sleep(1500);
	printf("�� ���� �տ� ���� ��¦�ϰ� �������ϴ�. ����� �װ��� ���� �������ַ� �޷Ƚ��ϴ�.\n");
	
	system("PAUSE");
	
	system("cls");
	printf("[�߾�]-[����]\n\n");
	printf("�͹�.\n'...���..���..'\n\n");
	Sleep(1500);
	printf("���ÿ� ���� ���ڱ��Ҹ��� ���� ���� �����⸦ �ϴ� ����..\n");
	Sleep(1500);
	printf("���� �ָӴϿ� �ִ� ������ ������, ��¦��� ���� ���� ����� �߽��ϴ�.\n");
	Sleep(1500);
	printf("����� ��Ȳ�� �о�� ��뵵 ��ġ�� ���� Ʋ�������ϴ�..������...�� �Ҽ� �������?\n"); 
	printf(" >>");
	scanf("%s",a);
	if(strcmp(a,"��ȭ") == 0 || strcmp(a,"����") == 0 || strcmp(a,"��") == 0 || strcmp(a,"����") == 0 || strcmp(a,"ħ��") == 0){
		printf("����� �ڽ��� ��ġ���� �ƴϴٶ�� ���� ���ϱ� �����߽��ϴ�\n");
		Sleep(1500);
		printf("���� ��������� �ڲ� ������ ��Ǯ� �̷ȱ�������,�׷����� ħ���ϰ� �ൿ�Ͽ����ϴ�.\n");
		Sleep(1500);
		printf("���� ������ Ǯ���� ���� ���� ���ο��� ��ȭ�� �ϱ� �����߽��ϴ�.\n"); 
		printf("���� �̾߱Ⱑ �������� �� �̾߱⵵ �� �߱� �߽��ϴ�. .\n");
		Sleep(2000);
		printf("����� ���⼭ ������ �������� �ƹ��� ��������, �׷��� ��Ű� ����� ó���� �ִ� ����� ���� �������� �ķ��߽��ϴ�\n");
		Sleep(2000);
		printf("�� �ᱹ ���� ���� Ż��! ���� ģ��!...�� ���� ���ǿ����̳׿�..");
		exit(1); 
	}
	else{
		printf("����� �Ӹ��ӿ� ������ ���� ���߽��ϴ�.\n");
		Sleep(1500);
		printf("�Ӹ��ӿ� �������� �ʰ� ��Ȯ�ߴ�����!\n");
		Sleep(1500);
		printf("����� �ϴ� �ൿ�� �������� ���� ���·� �����̱� �����߽��ϴ�...�� ���� ���� �ٸ��� �����߳����ϴ�.\n");
		system("PAUSE");
	} 
	system("cls");
	printf("[�߾�]-[����]\n\n");
	printf("'Ÿ��!'\n\n");
	printf("����� ���� �´��� �������� �����߽��ϴ�.\n");
	Sleep(1500);
	printf("�ƴ� �ѿ� ������ �������?...�״� �������� �ʾҽ��ϴ�..\n");
	Sleep(1500);
	printf("����...������ ���� ��������...");
	Sleep(1500);
	printf("...������...���Դϴ�! ���žƴϱ���!");
	Sleep(1500);
	printf("..�� ����� õõ�� ���� ���� �����߽��ϴ�.\n");
	Sleep(1500);
	printf("���� õõ�� ���� ������ ������ ���� ���������ϴ�.\n");
	Sleep(1500);
	printf("���� ���� ���� �߰ſ����� �����ϰ�..�������� �����մϴ�.\n");
	Sleep(1500);
	printf("����� �ڴʰ� ���� �ܴ��� ��ƺ�������..�� źâ�� �����׿� ����..\n");
	Sleep(1500);
	printf("�� ����� �и� ���� 'ħ��'�ϰ� '��ȭ'�ϰų� ��븦 '����'�ҷ��� �߾ �̻�Ȳ�� ����Ҽ� �־�����.\n");
	Sleep(1500);
	printf("��¼�ڽ��ϱ�?..����� �̹� �Ѹ°� �������ִµ�..\n");
	Sleep(1500);
	printf("�����ϰ� ���� ���� ������ ſ�Ҽ� �ۿ�..\n");
	Sleep(1500);
	printf("�׸��� ��� �ڿ� �鸮��..\n"); 
	system("PAUSE");
	printf("'Ÿ��!'\n");
	Sleep(500);
	printf("'Ÿ��!'\n");
	Sleep(500);
	printf("'Ÿ��!'\n\n");
	Sleep(500);
	printf("'ŻĬ! ŻĬ! '\n\n"); 
	Sleep(500);
	printf("��...������ ��¥ �׾��׿�\n");
	printf("�󱼿� ���� ������ ���� ����� ���� ���� �ʳ׿�....\n ��忣���Դϴ�!");
	
	exit(1); 
}
