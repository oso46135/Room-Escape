#include<stdio.h>						 
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h> 

void tutorial();		//Ʃ��	
void move();			//�޴�
void desk();			//å��
void computer();		//��ǻ��
void opencomputer();	//������ǻ��
void door();			//Ż�⹮
void ending();			//�����б���
void bar();				//����� 
void Refrigerator(); 	//����� 
void bed();				//ħ��
void bedsp();			//ħ�뿡�� �ܴ�. 
void card();			//ī�� 
void cardgame();		//ī����� 


int q = 0;	//ö�� ù �̺�Ʈ ��ŵ 

int c = 0; //å�� ù �̺�Ʈ ��ŵ 
int noplz = 0; //å�� ���Ŵ� �̺�Ʈ ��ŵ 
int DP = 0; //å�� ��ȣ �߰� �̺�Ʈ ��ŵ 
int passwordeak = 0; ///å�� ��ȣ�� ã���� ��� 

int barskip = 0;	//����� �̺�Ʈ ��ŵ 
int barhand = 0;	//����� ���� Ƚ�� ī���� 

int computerskip = 0;	//��ǻ�� �̺�Ʈ ��ŵ 
int computerpassword = 0;	//��ǻ�� �н����� �˾Ƴ����� 

int opencomputerskip = 0;		//���� ��ǻ�� �̺�Ʈ ��ŵ
int fillplz = 0;			//���� ��ǻ�� ���� ã�� �̺�Ʈ 

int Refskip = 0;	//����� �̺�Ʈ ��ŵ 
int soundgood = 0;	//����� �Ҹ��� �������ϴ�. 
int Refdef = 0; //����� ������ ���� ���°� �ǹ̰� �����ϴ�. 

int bedspfin = 0; //ħ�� �̺�Ʈ ��ŵ 
 

int win = 0;	//ī����� ����  
const char *Nickname;	//ī����� Īȣ
int ss = 0;		//ī����� �������� 


int passwordsee = 0; //��ȣ�ΰ� �˾����� �޶����� ����[�̽��Ϳ���1] 

int Jending=0;		//Īȣ�� ������ �ö󰡴� ���� �������� �� �� ����  
const char *cardciho="?"; 	//ī����� ���� 
const char *Refciho="?";		//����� ����
const char *barciho="?";	//�����  ���� 
const char *deskciho = "?";	//å�� ���� 
const char *computerciho = "?"; 

//password=��й�ȣ �Է�ĭ, ok=��й�ȣ ���� 

int main(){				//1P �÷��̾�

	system("mode con cols=53 lines=20 | title ��Ż�� 1P.Ver");

	printf(" ------------------------------------------------\n");
	printf(" |	   ���� ������ 1P ���� �Դϴ�.��	|\n | 	 ��2P�� ���� �÷����ؾ� �մϴ�.��	|\n");
	printf(" ------------------------------------------------\n\n");
	system("PAUSE"); 
	


	system("cls");
	printf("\n'��..���� �����?'\n\n");
	Sleep(1000);
	printf("�������� �Ӹ��� ����� �ڸ����� ������ �Ͼ��.\n");
	Sleep(1500);
	printf("�ֺ��� �ѷ��������� �� ����� ���� �ٸ� ����̿���.\n");
	Sleep(2000);
	printf("�׸��� ª�� �ð��� �帥�� ���� ��ġ�Ǿ��ٴ� ���� ������ ��  �ְ� �Ǿ���.\n");
	Sleep(2500);
	printf("\n '�߿� �� ��ĥ�� ����?'\n\n");
	system("PAUSE");
	 
	move();
		
}

void move(){		//�̵� 
	
	int a;
	
	while(1){
		system("cls");
		printf("[�߾�]\n");										//���� 
		printf("ȹ�� ����:%s,%s,%s,%s,%s \n\n",barciho,cardciho,deskciho,Refciho,computerciho) ;		//Īȣ ��� 
		printf("1.ö��		2.å��		3.��ǻ��\n");			//�̵� �ݰ� 
		if(barhand==11){
			printf("4.(ͺ)�����	5.�����	6.ħ��\n");
		} 
		else{
			printf("4.�����	5.�����	6.ħ��\n");
		}
		printf(" >>");
		scanf("%d",&a);
		switch(a){
			case 1:
				door();		//Ż�⹮ 
				break;
			case 2:
				desk();		//å �� 
				break;
			case 3:			//��ǻ��,��� Ǯ�� ��ǻ�� 
				if(computerpassword == 0){
					computer();
				}
				else{
					opencomputer();
				}
				break;	
			case 4: 	//����� 
				bar();
				break;
			case 5:		//����� 
				if(Refdef == 0){
					Refrigerator();
				}
				else{
					printf("����� ������ ���� �����ϴ�.\n\n");
					system("PAUSE"); 
					break; 
				}
				break; 
			case 6:		//ħ�� 
				if(bedspfin == 0){
					bed();
				} 
				printf("����� ���� �ǰ����� �ʽ��ϴ�.\n");
				Sleep(1000);
				printf("�� ������ ���ö����ϴ�. ����...ħ�뿡�� �־����ϴ�..\n\n");
				system("PAUSE"); 
				break;
			case 99:
				printf("��! �����ϼ���! ����� ���� �������� �ٷ� ���� �ִ� ������ �Ϸ� �Ǿ����ϴ�!\n");
				system("PAUSE");
				Jending=5;
				q = 99;
				break;
			default:
				system("cls");
				printf("[�߾�]\n");	
				printf("\n 1~6������ �Է��Ͻÿ�.");
				system("PAUSE"); 
		}
		
	}
}

void door(){	//Ż�⹮ 
	int a, password=0, ok=0005;
	char passworddoor[20];
	while(1){
		system("cls");
		printf("[�߾�]-[ö��]\n\n");
		
		printf("�� �ܴ��� ���̴� ö���� �ֽ��ϴ�.\n");
		Sleep(1000);
		if(q == 0){ 
			printf("1.ö���� �����Ѵ�	2.���ư���\n");
			printf(" >>");
			scanf("%d",&a);
			switch(a){
				case 1:
					system("cls");
					printf("[�߾�]-[ö��]\n\n");
					printf("ö���� �ڼ��� ���ҽ��ϴ�.\n");
					Sleep(500);
					
					printf("..");
					Sleep(1500);
					
					printf("..");
					Sleep(1500);
					
					printf(".!");
					Sleep(1000);
					
					system("cls");
					printf("[�߾�]-[ö��]\n\n");
					if(passwordsee == 0){			//�̽��Ϳ��� 1
						printf("ö�� �߾ӿ� ���� �Է��� �� ���� �� �����ϴ�\n\n");
						passwordsee++;
					}
					else if(passwordsee == 1){
						printf("ö�� �߾ӿ� ��ȣ�� �Է��� �� �ִ� �� �����ϴ�\n\n");
						passwordsee++;
						}
					else{
						printf("���⵵...��ȣ�� ����� �Ѵ�..(�Ѽ�)\n\n");
					}
					system("PAUSE"); 
					q++;
					break;
				case 2:
					move();
				default:
					printf("�Է¿���");
					system("PAUSE"); 
			}
		
		}
		else if(q == 99){
			printf("��...�� �̻��� ������ �ʿ� �Ѱ���? �ٷ� ���� ȭ������ ������.\n");
			system("PAUSE");
			ending();
		}
		else{
			printf("1.��ȣ�� �Է��Ѵ�		2.���ư���\n");
			printf(" >>");
			scanf("%d",&a);
			switch(a){
				case 1:
					system("cls");
					printf("[�߾�]-[ö��]-[��ȣ�Է�]\n\n");
					
					printf("���� 4�ڸ��� �Է� �� �� �ִ� �� �����ϴ�\n");
					printf(" >>");
					scanf("%s",passworddoor);	//���� ������ �Լ�
					if(strcmp(passworddoor,"0005")==0){
						printf("����� �ű��ϰ� �ƹ� ��Ʈ�� ���� ���� �̲��� ��� �Է��Ͽ����ϴ�\n");
						Sleep(2000);
						printf("Ʋ�ȴٰ� ������ ����� �ڸ� ���� ����..\n");
						
						printf("\n'�츮��'\n\n");
						
						printf("������� ���� �����ڸ���..\n\n");
						Sleep(2000);
						printf("**'����������!'**\n\n");
						Sleep(1500);
						printf("�� ���鿡�� �̻��� �Ҹ��� ��Ƚ��ϴ�.\n"); 
						printf("..��¦ ������ ������ �װ� ���� ����Դϱ�! ���̿��Ƚ��ϴ�!\n");
						 
						system("PAUSE");
						ending();
					}
					else{
						printf("��ȣ�� Ʋ�� �� �մϴ�.\n");
					}
					break;
				case 2:
					 move(); 
			}
		}
	}
}
void desk(){	// å�� 
	int a, b, password, ok=3326;
	while(1){
		system("cls");
		printf("[�߾�]-[å��]\n\n");
		if(c==0){
			printf("��޽����� å���Դϴ�.\n");
			Sleep(1000);
			printf("å�� ������ �������� �Ƹ���� ĥ�����ֽ��ϴ�\n\n");
			Sleep(2500);
			printf("'�� ������ �ƴ� ��;'.\n\n");
			Sleep(1000);
			c++;
		}
		else{
			printf("�� ������ �ƴ� å���� �ֽ��ϴ�.\n\n");
		}
		if(DP == 0){
			printf("1.å���� ���캸��	2.å�󼭶��� ���캸��	 	 3.å�󿡰� ���ɾ��	4.���ư���\n");
		}
		else if(passwordeak == 1){
			printf("1.å���� ���캸��	2.å�󼭶� ��ȣ �ٽú���	 3.å�󿡰� ���ɾ��	4.���ư���\n");
		} 
		else{
			printf("1.å���� ���캸��	2.å�󼭶� ��ȣ �Է��ϱ�	 3.å�󿡰� ���ɾ��	4.���ư���\n");
		}
		printf(" >>");
		scanf("%d",&a);
		if(a == 1){
			system("cls");
			printf("[�߾�]-[å��]-[ī�����]\n\n");
			printf("����� å�� �ִ� ī�带 �߰��߽��ϴ�.\n\n");
			Sleep(2000);
			printf("'�ճ⿡ ���� ī����� �� �غ���!'\n\n");
			Sleep(1000);
			printf("����� ī������� 10�� �ϰ� ���� ������ �����帨�ϴ�.\n\n");
			printf("1.ī������� ����	2.���ư���\n");
			printf(" >>");
			scanf("%d",&a);
			if(a == 1)	card(); 
			else desk();

		}
		else if(a == 2 && DP == 0){
			system("cls");
			printf("[�߾�]-[å��]\n\n");
			DP++;
			if(passwordsee == 0){			//�̽��Ϳ��� 1 
				printf("�ȿ�����...\n");
				Sleep(2000);
				printf("�ƹ����� ���� �Է��ؾ� �ϴ� �� �����ϴ�.\n\n");
				system("PAUSE");
				passwordsee++;
			} 
			else if(passwordsee == 1){
				printf("�ȿ�����...�ƹ����� ��ȣ�� �Է��ؾ� �ϴ� ���ϴ�.\n\n");
				system("PAUSE");
				passwordsee++;
			}
			else{
				printf("����..�̰͵� ��ȣ�� �Է��ؾ� �ϴ� ���̴�.\n\n");
				system("PAUSE");
			}
		}
		else if (a == 2	&& passwordeak == 0){		//���� 1�� ���� 
			system("cls");
			printf("[�߾�]-[å��]\n\n");
			
			printf("���� 4�ڸ��� �Է� �� �� �ִ� �� �����ϴ�\n");
			printf(" >>");
			scanf("%d",&password);
			if(password == ok){
				system("cls");
				printf("[�߾�]-[å��]\n\n");
				printf("����� �˼� ���� ������� 3326�� �Է��߽��ϴ�\n\n");
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf("!\n\n"); 
				
				 
				printf("å�� ���� �ȿ��� ���� �ϳ��� �־����ϴ�.\n");
				Sleep(1500);
				printf("����� ���� ���� ���� �̻��� �׸��� '��������' ��� ���� �����ֽ��ϴ�.\n");
				Sleep(1500);
				printf("�� �ڼ��� ���� ��? ");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(" ���⵵ �մϴ�.\n");
				system("PAUSE");
				passwordeak=1; 
			}
		
			else{
				printf("�ƹ����� �ƴ� �� ����.\n");
				system("PAUSE");
			}
		}
		else if (a == 2 && passwordeak == 1){
			system("cls");
			printf("[�߾�]-[å��]\n\n");
			printf("����� ���� ������ ������ ���̸� �ѹ��� ���ϴ�.\n");
			Sleep(1500);
			printf("'��������'��� �۾��� ��? ");
			Sleep(1500);
			printf(" ���� ������ ���Դϴ�..\n");
			system("PAUSE");
		}
		
		else if(a == 3){
			system("cls");
			printf("[�߾�]-[å��]\n\n");
			if(noplz == 0){
				printf("����� �Ӹ��� ���� ���ƴ��� å�󿡰� ���� �ɾ�ҽ��ϴ�.\n\n");
				Sleep(1000);
				printf("'��..��...�ȳ�?'\n\n");
				
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				
				printf("������ ����ߴ°�? ����� �ڽ��� ������� ���ݱ� �����߽��ϴ�.\n\n");
				noplz++;
				system("PAUSE"); 
				
			}
			else if(noplz == 1){
				printf("�ڽ��� �λ簡 ������� ���� �����ϰ� ȯ�ϰ� �λ��Ͽ����ϴ�.\n\n");
				
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				
				printf("�ƹ����� ����� �Ӹ��� ��ģ�� �����ϴ�.\n\n");
				noplz++; 
				system("PAUSE");
			}
			else if(noplz == 2){
				printf("����� å���� �������� ����ΰ� ĳġ�ϰ� ���ɽ����� �λ��Ͽ����ϴ�.\n\n");
				
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				
				printf("���� �߸� �Ȱ��� ������ ���ϴ� �� ���Դϴ�.\n\n");
				noplz++;
				system("PAUSE");
			}
			else if(noplz == 3){
				printf("����� ���������� ģ�� ģ��ó�� �λ縦 �Ͽ����ϴ�.\n\n");
				
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf("!");
								
				system("mode con cols=53 lines=20 | title ��û���Ǳ�ġ!"); 
				deskciho="å����ģ"; 
				printf("[�߾�]-[å��]\n\n");
				printf("����� ���������� ģ�� ģ��ó�� �λ縦 �Ͽ����ϴ�.\n\n");
				printf("..!");
				printf("����� �̰� ��Ų ����� �����ϱ� �����߽��ϴ�.");
				printf("\n(��������)\n");		
				system("PAUSE");
				Jending++;
				noplz++; 				
			}
			else{
				printf("����� å�� ���� �Ŵ� ���� ��û�� ���̶�� ���� ���޾Ҵ�.\n");
				system("PAUSE");
			}
		}
		else{
			move();
		}
	}
	
	
}
void computer(){	//��ǻ�� 
	int a;
	char passwordcom[20];
	while(1){
		system("cls");
		printf("[�߾�]-[��ǻ��]\n");
		if(computerskip == 0) {
			printf("����� ��ǻ�͸� Ű�� �����߽��ϴ�.\n");
				Sleep(1500);
			printf("��...�ƹ����� ���¸� ���� �� ������ ���� ���� ��ǻ�� �Դϴ�.\n");
				Sleep(2500);
			if(passwordsee == 0){			//�̽��Ϳ��� 1
					printf("������ ��ȣ?�� Ǯ��� �ϴ� �� ���Դϴ�.\n\n");
					passwordsee++;
			}
			else if(passwordsee == 1){
					printf("������ ��ȣ�� Ǯ��� �ϴ� �� ���Դϴ�.\n\n");
					passwordsee++;
			}
			else{
					printf("�� ������ �ͼ��ϰ� ��ȣ�� Ǯ��� �� �� ���Դϴ�.\n\n");
			}
			computerskip = 1;
		}
		else if(computerskip == 1){
			printf("����� �ƹ� �ǽɾ��� ��ǻ�͸� �׽��ϴ�.\n");
			Sleep(1500);
			printf("��ǻ�Ͱ� �����ϱ� �����մϴ�.\n");
			Sleep(1500);
			printf("��...�������� ����?\n\n");
		}
		
		printf("1.��ȣǮ��	2.���ư���\n");
		printf(" >>");
		scanf("%d",&a);
		
		if(a == 1){
			system("cls");
			printf("[�߾�]-[��ǻ��]\n");
			printf("��...�ƹ����� 10���� ��ȣ �����ϴ�.\n");			//3816547290
			printf(" >>"); 
			scanf("%s",passwordcom);
			
			if(strcmp(passwordcom,"3816547290") == 0){
				system("cls");
				printf("[�߾�]-[��ǻ��]\n");
				printf("��!");
				Sleep(1500);
				printf("�����");
				Sleep(1500);
				printf("10���ڸ�");
				Sleep(1500);
				printf("�� �����ٺ��� ���Ƚ��ϴ�!\n");
				printf("��ǻ�Ͱ� ������ �����߽��ϴ�!\n"); 
				system("PAUSE");
				computerpassword = 1;
				opencomputer(); 
			}
			 
			
		}
		else if(a == 2){
			system("cls");
			printf("[�߾�]-[��ǻ��]\n");
			printf("����� �Ӹ��� ��½�̸� �ٽ� ���ư��ϴ�\n\n");
			system("PAUSE"); 
			move(); 
			
		}
		else{
			system("cls");
			printf("[�߾�]-[��ǻ��]\n");
			printf("���ڸ� �߸� �Է��� �� ���δ�.");
		}
	}
	
}
void opencomputer(){	//��� Ǯ�� ��ǻ�� 
	int a;
	while(1){
		system("cls");
		printf("[�߾�]-[��ǻ��]\n");
		if(opencomputerskip == 0){
			printf("����� ��ǻ�͸� Ű�� ���� ��ٷȽ��ϴ�.\n");
			Sleep(1500);
			printf("������ �ӵ��� ���� ���ͳ��� �����ؾ� �ҵ� ���Դϴ�.\n");
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			Sleep(1500);
			printf("���� �������ϴ�..\n");
			opencomputerskip = 1;
		}
		else if(opencomputerskip == 1){
			printf("����� ��ǻ�͸� ų������ �ű����� �����ϴ�.\n\n");
			Sleep(1500);
			printf("'��� ��ǻ�Ϳ��� ��� ���ư��� �Ҹ��� �鸮��?'\n\n");
			Sleep(1500);
			printf("�̹����� �ٷ� �������ϴ�. �� ���� ��ǻ�͵� ������ ��豺��.\n");
			opencomputerskip = 2;
		}
		else if(opencomputerskip == 2){
			printf("����� ��ǻ�͸� ų�� ���� ���ҽ��ϴ�.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			printf("������..�ѽð����� �ڹ��Ƚ��ϴ�...����������! ��ǻ�ʹ� ���� ���������ϴ�.\n");
		}
		else{
			printf("��ǻ�Ϳ� �� �Ҹ��� ����� �͸� �ڱ� �ϱ� ����߽��ϴ�.\n");
			Sleep(1500);
			printf("������ �׻� ���� �� �����ϴ�!\n");
		}
		printf("1.������ Ž���ϱ�	2.���ư���\n");
		
		printf(" >>");
		scanf("%d",&a);
		
		if(a == 1){
			system("cls");
			printf("[�߾�]-[��ǻ��]\n");
			printf("����� ������ Ž���ϱ� �����߽��ϴ�.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			printf("��! '�׸�������'��� �޸��� ���� �� ���� �����ϴ�. �� ���뵵 �ƹ��͵� �����ϴ�.\n");
				system("PAUSE"); 
			fillplz = 1;
		} 
		else if(a == 1 || fillplz == 1){
			system("cls");
			printf("[�߾�]-[��ǻ��]\n");
			Sleep(1500);
			printf("����� '�׸����A��'�� ������ �ٸ� ������ ã���ϴ�.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			
			printf("��...��! 8��Ʈ ���ͽ� BGM�� ã�ҽ��ϴ�. ����� ������ �����ϱ� �����߽��ϴ�\n");
				system("PAUSE"); 
			fillplz = 2; 
		}
		else if (a == 1 || fillplz == 2){
			system("cls");
			printf("[�߾�]-[��ǻ��]\n");
			Sleep(1500);
			printf("����� '�׸�������','��¼�� ���'�� ������ �ٸ� ������ ã���ϴ�.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			
			printf("��...��! ����� �Ϳ��� ����̸� ã�ҽ��ϴ�! ������ �����ϱ� �����߽��ϴ�\n");
				system("PAUSE"); 
			fillplz = 3;
		}
		else if (a == 1 || fillplz == 3){
			system("mode con cols=53 lines=20 | title ������!"); 
			system("cls");
			printf("[�߾�]-[��ǻ��]\n");
			Sleep(1500);
			printf("����� '�׸�������','��¼�� ���','�Ϳ�������'�� ������ �ٸ� ������ ã���ϴ�.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			printf("����� Īȣ�� �߰��߽��ϴ�! �̰� ���Ѱ� ����?\n");
			
			system("PAUSE"); 
			fillplz = 4;
			computerciho = "���� ������";
			Jending ++;
	}
		else if (a == 1 || fillplz == 4){
			system("cls");
			printf("[�߾�]-[��ǻ��]\n");
			Sleep(1500);
			printf("����� '�׸�������','��¼�� ���','�Ϳ�������'�� ������ �ٸ� ������ ���� �� ���Դϴ�!\n");
				system("PAUSE"); 
		}
		else{
			system("cls");
			printf("[�߾�]-[��ǻ��]\n");
			printf("����� ��ǻ�͸� ���� �ٽ� �߾����� ���ư��ϴ�.\n");
			system("PAUSE"); 
			move(); 
		}
		system("cls");
		printf("[�߾�]-[��ǻ��]\n");
		printf("\n\n���� ������! ��ǻ�Ͱ� �����Ǿ����ϴ�!\n");
		system("PAUSE"); 
		move();
		
	} 
}
void bar(){		//���� 
	int a;
	while(1){
		system("cls");
		printf("[�߾�]-[�����]\n\n");
		if(barskip == 0){			//����� ������ �̺�Ʈ 1 
			printf("����� �ٴڿ� ����Ⱑ �ִ� ���� �Ǿ��� �մϴ�.\n");
			Sleep(3000);
			printf("�׷���...");
			Sleep(800);
			printf("������ ����� �Դϴ�.");
			barskip = 1;
		} 
		else if(barskip == 1){		//����� ������ �̺�Ʈ 2 
			printf("����� ����⸦ �ٽ� ���� ������ ����� ���ϴ�.\n");
			Sleep(3500);
			printf("������ �׻� ���� ������ ����� �Դϴ�.\n");
			Sleep(1500);
			barskip = 2;
		}
		else if(barskip == 2){		//����� ������ �̺�Ʈ 3 
			printf("����� ����⿡�� ������� �̸��� �������ϴ�.\n");
			Sleep(2500);
			printf("ª�� ������ ��ģ ����� �׳� ������ �θ���� �߽��ϴ�.\n"); 
			Sleep(1500);
			barskip = 3;
		}
		else if(barskip == 3){		//����� ������ �̺�Ʈ 4
			printf("������ ���ο��� �ϱ� �����߽��ϴ�!\n");
			Sleep(3500);
			printf("������ ���� ���ٴ� ���� ���޾ҽ��ϴ�...\n"); 
			barskip = 4;
			
		}
		else if (barskip == 4){		//����� ������ �̺�Ʈ 5 
			printf("����� ����⿡�� ȭ�� �½��ϴ�.\n");
			Sleep(2500);
			printf("����� ����⿡�� ��� �߽��ϴ�.\n");
			Sleep(1000);
			barskip = 5;
		}
		else if(barskip == 5){		//����� ������ �̺�Ʈ 6 
			printf("����Ⱑ ���߽��ϴ�.\n");
			Sleep(1000);
			printf("'...'\n");
			Sleep(1000);
			printf("�̷�! ���� ������!\n") ;
			barskip = 6;
		}
		else if(barhand == 11){		//����� �μ����� �̽��Ϳ��� 
			printf("������ �μ����� ���ҽ��ϴ�...\n"); 
			Sleep(2000);
			printf("����� ����⸦ �����ϴ� ������ ���� �����ϴ�.\n");
			system("PAUSE"); 
			system("mode con cols=53 lines=20 | title �����...����Ұ�..."); 
			barciho="�������ι�";
			move(); 
		}
		else{						//����� ������ �̺�Ʈ 
			printf("����� %d�� ����⸦ �������ϴ�!\n ������ �� �� �ϸ� ����Ⱑ �μ��� �� �����ϴ�.\n",barhand);
		}
		printf("\n1.������ 2.���ư���\n");
		printf(" >>");
		scanf("%d",&a);
		
		if(a == 1){
			system("cls");
			printf("[�߾�]-[�����]-[����]\n\n");
			printf("����� ����⸦ �������ϴ�.\n");
			Sleep(500);
			printf(".");			
			Sleep(2000);
			
			printf(".");			
			Sleep(2000);
			
			printf(".\n");
			Sleep(2000);
			if(barhand==8){			//����� �μ����� �̺�Ʈ 
				printf("�̷�! ����Ⱑ �μ��� ���Ƚ��ϴ�!\n");
				Sleep(1500);
				printf("����� ����� ���� �ð��� ������ �˴ϴ�.\n");
				printf("\n(���� ȹ��)\n");		
				barhand=11;
				Jending++;
				system("PAUSE"); 
				bar();
			}
			system("cls");
			printf("[�߾�]-[�����]\n\n");
			printf("����� ����⸦ �������ϴ�.\n");
			printf("...\n"); 
			printf("�ٽ� �ֿ����ϴ�.\n");
			barhand++;
			system("PAUSE");
			
		}
		else{
			move();
		}
	}
}
void Refrigerator(){	//�����
		int a=0; 
		while(1){
			system("cls");
			printf("[�߾�]-[�����]\n\n");	
			if(Refskip == 0){
				printf("����� ����� ������ ����� �������ϴ�.\n");
				Sleep(1500);
				printf("������ ���ʿ��� ���� ���� �� �������ϴ�.\n"); 
				Refskip++; 
			}
			else if(Refskip == 1){
				printf("����� �������� ����� ���� �������ϴ�.\n");
				Refskip++;
			}
			else{
				printf("����� ����� �� ���� �Ҹ��� ���������ϴ�.\n");
				soundgood=1;
			}
			printf("\n");
			if(soundgood==1){
				printf("1.�����Ѵ� 2.������ �峭ģ�� 3.���ư���\n");
				printf(" >>");
				scanf("%d",&a);
				if(a == 1){
					system("cls");
					printf("[�߾�]-[�����]\n\n");	
					printf("����� ������ �ѷ���������, �ƹ��͵� �߰��� ���� �������ϴ�.\n");
					system("PAUSE"); 
					move(); 
				} 
				else if(a == 2){
					for(int i=0; i<=10; i++){
						system("cls");
						printf("[�߾�]-[�����]-[����]\n\n");	
						printf("����\n");
						Sleep(500);
						
						system("cls");
						printf("[�߾�]-[�����]-[����]\n\n");
						printf("����\n");
						Sleep(500);
					}
					system("cls");
					printf("[�߾�]-[�����]-[����]\n\n");
					printf("�۾�!\n");
					Sleep(2000);
					 
					printf("����� ���峵��.\n");
					printf("(��������)\n");
					system("PAUSE"); 
					system("mode con cols=53 lines=20 | title ����� ���� �����ֳ�.."); 
					Refciho="����� �� �r�r";
					Jending++;
					Refdef=1;
				 	move();
				 	
				}
				else{
					move();
				}
			}
			else{
				printf("1.�����Ѵ�  2.���ư���\n");
				printf(" >>");
				scanf("%d",&a);
				if(a == 1){
					system("cls");
					printf("[�߾�]-[�����]\n\n");	
					printf("����� ������ �ѷ���������, �ƹ��͵� �߰��� ���� �������ϴ�.\n");
					system("PAUSE"); 
					move(); 
				} 
				else{
					move();
				}
				
			} 
	}
}		
void bed(){		//ħ��  
	int a;
	
	while(1){
		system("cls");
		printf("[�߾�]-[ħ��]\n\n");
		printf("���� ħ�븦 �ٶ󺸾Ҵ�.\n");
		Sleep(1000);
		printf("��û �ǰ��� ����� ħ�뿡 ���� �;������ϴ�.\n\n");
		printf("1.���´�	2.�����Ҹ� ������ ��ƾ��.\n");
		printf(" >>");
		scanf("%d",&a);
		if(a == 1){
			printf("����� ħ�뿡 ������ �����ϴ�.\n");
			system("PAUSE"); 
			bedsp();
		}
		else{
			system("cls");
			printf("[�߾�]-[ħ��]\n\n");
			printf ("����� ħ�뿡�� �ڰ� ������ ��Ƽ��� �߽��ϴ�.\n");
			Sleep(1000);
			printf("������ ����� ��Ƽ�⿡�� �ʹ� ����ϴ�.\n\n");
			
			printf("1.�ȵǰھ� ���̳� ����	2.����������!\n");
			printf(" >>");
			scanf("%d",&a);
			
			if(a == 1){
				
				printf("����� ħ�뿡 ������ ����ϴ�.");
				system("PAUSE"); 
				bedsp();
			}
			else{
				system("cls");
				printf("[�߾�]-[ħ��]\n\n");
				printf("����� ");
				Sleep(500);
				printf("����"); 
				Sleep(500);
				printf("����"); 
				Sleep(500);
				printf("����"); 
				Sleep(500);
				printf("��������,");
				Sleep(1000);
				
				printf("�׷��� ����� �߽��ϴ�.\n");
				Sleep(1000);
				printf("��!");
				Sleep(2000);
				printf(" �׷��� ħ�뿡 ���� �̻��Ѱ� �ִ� �� �����ϴ�!.\n\n");
				printf("1. ħ�뿡 ���´�	2.ħ�븦 �����Ѵ�.\n"); 
				printf(" >>");
				scanf("%d",&a);
				if(a == 1){
					system("cls");
					printf("[�߾�]-[ħ��]\n\n");
					printf("����� ��.�� ħ�뿡�� �ڷ��� ���� ���縦 ��������,\nħ�뿡 �������ϴ�.\n");
					system("PAUSE"); 
					bedsp();
				}
				else{
					system("cls");
					printf("[�߾�]-[ħ��]\n\n");	
					printf("����� ħ�밡 ������ ���� �����մϴ�.\n ");
					system("PAUSE"); 
					bedsp();
				}
			}
			
			
		}
		 
	}
}
void bedsp(){		//ħ�뿡�� �ܴ�.
	int a;
	
	system("cls");
	printf("[�߾�]-[ħ��]\n\n");
	printf("����� ħ�뿡 ���� ���ڸ��� ������ �K�������ϴ�.\n");
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".\n");
	Sleep(1000);
	
	printf("'!!!'\n\n");
	printf("����� ������ ���� �پ����ϴ�. �ٷ� �Ͼ ħ�뿡�� �־����ϴ�.\n");
	system("PAUSE"); 
	bedspfin++;
	
	move();
		 
}
 void card(){				//ī�� 
 		int a,s,c,h,d; 
 		srand(time(NULL));
 		if(win == 0)	Nickname="�ʺ���"; 
 	
	 	while(1){
	 			s,c,h,d=0;
 				system("cls");
				printf("[�߾�]-[å��]-[ī�����]-�¸�:%d\n",win);
				printf("�г���:%s\n\n",Nickname);
			 	printf(".����� ī�带 �����ϴ�.\n");
			 	Sleep(1000);
		 	
			 	system("cls");
				printf("[�߾�]-[å��]-[ī�����]-�¸�:%d\n",win);
				printf("�г���:%s\n\n",Nickname);
			 	printf("..����� ī�带 �����ϴ�..\n");
			 	Sleep(1000);
		 	
		 		system("cls");
				printf("[�߾�]-[å��]-[ī�����]-�¸�:%d\n",win);
				printf("�г���:%s\n\n",Nickname);
		 		printf("...����� ī�带 �����ϴ�...\n");
		 		Sleep(1000);
		 	
		 		system("cls");
				printf("[�߾�]-[å��]-[ī�����]-�¸�:%d\n",win);
				printf("�г���:%s\n\n",Nickname);
		 		printf(".����� ī�带 �����ϴ�.\n");
		 		Sleep(1000);
		 	
		 		system("cls");
				printf("[�߾�]-[å��]-[ī�����]-�¸�:%d\n",win);
				printf("�г���:%s\n\n",Nickname);
		 		printf("..����� ī�带 �����ϴ�..\n");
		 		Sleep(1000);
		 	
		 		system("cls");
				printf("[�߾�]-[å��]-[ī�����]-�¸�:%d\n",win);
				printf("�г���:%s\n\n",Nickname);
		 		printf("...����� ī�带 �����ϴ�...\n");
		 		Sleep(1000);
		 	
				cardgame();	            
		 }
 } 
 
void cardgame(){		//ī�� ����  
	int a,b;
		while(1){
			srand(time(NULL)); 
			system("cls");
			printf("[�߾�]-[å��]-[ī�����]-�¸�:%d\n",win);
			printf("�г���:%s\n\n",Nickname);
		 	Sleep(500);
		 	printf("����� ������?\n");
		 	Sleep(500);
			printf("1.�����̵�  2.Ŭ�ι�  3.���̾�  4.��Ʈ  5.��Ŀ\n"); 
		 	printf(" >>");
		 	scanf("%d",&a);
		 	
		 	system("cls");
			printf("[�߾�]-[å��]-[ī�����]-�¸�:%d\n",win);
			printf("�г���:%s\n\n",Nickname);
		 	if(a == 1){
			    printf("����� �����̵带 �����߽��ϴ�.\n");
			    
			}
			else if(a == 2){
				printf("����� Ŭ�ι��� �����߽��ϴ�.\n");
				
			}
			else if(a == 3){
				printf("����� ���̾Ƹ� �����߽��ϴ�.\n");
			
			}
			else if(a == 4){	
				printf("����� ��Ʈ�� �����߽��ϴ�.\n");
			
			}
			else if(a == 5){
				printf("����� ��Ŀ�� �����߽��ϴ�.\n");
			} 
			else if(a == 10){
				printf("����� 10���� �����߽��ϴ�.\n");
			}
			else{
				printf("�Է� ����"); 
				cardgame(); 
			}

			Sleep(1500);
			printf("����� ī�� �� ���� ���ɽ����� �̽��ϴ�.\n");
			Sleep(2000);
			if(rand()%4+1 == 1){
				printf("���� ī��� �����̵��Դϴ�!\n\n"); 
				b=1;
				Sleep(1000);
			}
			else if(rand()%4+1 == 2){
				printf("���� ī��� Ŭ�ι��Դϴ�!\n\n");
				b=2;
				Sleep(1000);
			}
			else if(rand()%4+1 == 3){
				printf("���� ī��� ���̾��Դϴ�!\n\n");
				b=3;
				Sleep(1000);
			}
			else if(rand()%4+1 == 4){
				printf("���� ī��� ��Ʈ�Դϴ�!\n\n");
				b=4;
				Sleep(1000);
			} 
			else{
				printf("��! ��Ŀ�� ���Ա���!\n\n");
				b=5;
				Sleep(1000);
			} 
			
			if(a == b){
				printf("����� �̰���ϴ�!\n\n");
				system("PAUSE"); 
				win++;
				ss++;
			}
			else if (a==10){
				printf("����� ������, 10�� ���� ì��ϴ�!\n");
				system("PAUSE");
				win=10;
				ss=10; 
			}
			else{
				printf("����� �����ϴ�\n\n");
				ss=0;
				system("PAUSE"); 		 
			}
			if(win == 1)	Nickname="���� �̰ܺ���"; 
			else if(win == 2)	Nickname="���� �̰ܺ���";
			else if(win == 3)	Nickname="�＼��!";
			else if(win == 4)	Nickname="���!!";
			else if(win == 8) 	Nickname="����� ����!";
			else if(win == 10){		//ī�� 10�½� Īȣ, Ÿ��Ʋ �ٲ� 
				Nickname="��Ŀ �ְ�!";
				system("mode con cols=53 lines=20 | title ��Ŀ�� �ְ�!"); 
				cardciho="��Ŀ�� �ְ�!"; 
				printf("\n (����ȹ��) \n"); 
				Jending++;
				system("PAUSE");
			} 
			

			
			system("cls");
			printf("[�߾�]-[å��]-[ī�����]-�¸�:%d\n",win);
			printf("�г���:%s\n\n",Nickname);
			
			printf("����ϰڽ��ϱ�?");
			if(ss > 1){
				printf("%d����!!!\n",ss);
			}
			else{
				printf("\n");
			}
			
			printf("1.��	2.�ƴϿ�\n");
			
			printf(" >>");
			scanf("%d",&a);
			if(a == 1)	card();
			else if(a == 2) desk();
			else{
				printf("�Է¿����� ���� �κ�� ���ư�\n");
				system("PAUSE"); 
				move(); 
			}
		}
		 
}

void ending(){		//���� 
	int a;
	system("cls");
	printf("[�߾�]-[����]\n\n");		//	system("PAUSE");  Sleep(2000);
	printf("����� �ڵ� ���ƺ��� �ʰ� ������ �ո��� ���� �޷����ϴ�.\n");
	Sleep(1500);
	if(Jending == 5 )	
		printf("����� ���� ���� �� ���� ������ ������ �׷��� ������ �ٱ� �����߽��ϴ�. \n"); 
	else
		printf("����� �� ���������� ������ ������ ���������� ���� ���̿����ϴ�.\n");
	
	Sleep(1500);
	printf("����� ���� ��¦ ���� �����߽��ϴ�\n\n");
	Sleep(1500);
	printf("'...��...��'\n\n");
	Sleep(1500);
	printf("����� ���ٴڿ� ���� �ִٴ� ���� �˾����Ƚ��ϴ�.\n ���� �� ������� ������ ª�� �ϰ� �ٷ� ���� ���� �ٽ� �޸��� �����߽��ϴ�.\n");
	system("PAUSE");
	
	system("cls");
	printf("[�߾�]-[����]\n\n");		//	system("PAUSE");  Sleep(2000);
	
	printf("������� �������� ���ʿ� ����� �Һ��� ���̱� �����߽��ϴ�.\n");
	Sleep(1500);
	printf("����� ���������� �������ַ� �޸��� �����߽��ϴ�.\n\n");
	Sleep(1500);
	printf("�͹�.\n'...���..���..'\n\n");
	Sleep(1500);
	printf("���ÿ� ���� ���ڱ��Ҹ��� ���� ���� �����⸦ �ϴ� ����..\n");
	Sleep(1500);
	printf("�� ���������� �ָӴϿ� �ִ� ���� ������  ������ �����ϱ� �����ߴ�.\n");
	Sleep(1500);
	printf("�װ� ���� ��뵵 ��Ȳ�ϵ��� ���� ������ �ܴ�����.\n");
	Sleep(1500);
	
	printf("���� ��� �� �ʰ� �������� ������� �츮 ���� �ƴ϶�� ���� �ƴ޾ҽ��ϴ�.\n");
	
	if(Jending == 5){
		printf("����� ������ ����̷� ������ ����� ���� ���� ���� �˾����Ƚ��ϴ�..\n");
		Sleep(1500);
	}
	else{
		printf("������ �� ��¼�ڽ��ϱ�? �̹� ����� ���� �÷Ƚ��ϴ�. ����� �ƴϸ�  ��밡 ����� ���� �� �Դϴ�.\n");
	} 
	
	if(Jending == 5){
		printf("1.�������	2.��ٸ���\n");
	}
	else{
		printf("1.�������	2.��ٸ���(���)\n");
	}
	
	printf(" >>");
	scanf("%d",&a);
	
	if(Jending == 5 && a == 2){		//	system("PAUSE");  Sleep(2000);
		printf("����� ������ ���� ���� ������ �������ϴ�. �׷��ٰ� ���� �߸� �������ٰ� ������ ��� ���ҽ��ϴ�.\n");
		Sleep(2000);
		printf("�ᱹ ����� ��� ������ ����ϸ鼭 ��ٸ���� �߽��ϴ�.\n");
		system("PAUSE");
		
		system("cls");
		printf("[�߾�]-[����]\n\n");
		
		printf("����� ������ �ð��� �������� ������ ����� �� ���ڰ� ���ٴ� ���� �˾����ȴ��� ���� ���� �����ߴ�.\n");
		Sleep(2000);
		printf("��밡 ���� ���� ���ΰ� ���ذ� �ִٴ� ���� �˾Ұ� ���� õõ�� �ŵα� �����ߴ�\n");
		Sleep(2000);
		printf("���ΰ� ���ο� �濡�� ������ ã�Ҵ��� �̾߱��Ͽ���..���� �̾߱Ⱑ �������� �� �̾߱⵵ �� �ߴ�.\n");
		Sleep(2000);
		printf("����� ���⼭ ������ �������� �ƹ��� ��������, �׷��� ��Ű� ����� ó���� �ִ� ����� ���� �������� �ķ��߽��ϴ�\n");
		Sleep(2000);
		printf("\n'...'\n\n");
			Sleep(2000);
		printf("�� ���� �����ؼ� Ż��.....Ż���� ���� ģ��ģ��...��..���� ���ǿ����̳׿�..\n");
		Sleep(2000);
		printf("...�� �߉�׿�..���ϼ̽��ϴ�!\n");
		
		exit(1); 
 
	}
	else if(a == 2){
		printf("����� ��ٸ��� �;�����,,,����� �Ҿ����� ����� ��Ƽ踦 ���� ���ҽ��ϴ�.");
		
	} 
	else if(a == 1){
		printf("����� ������ ������ �����ڸ��� ��Ƽ踦 ������.");
	}
	else{
		printf("����� 1,2�� �߿� ������ ���Ͽ� ��Ȳ�� ƴŸ ��Ƽ踦 ���� ���Ҵ�..");
	} 
	printf("\n");
	system("PAUSE");
	
	system("cls");
	printf("[�߾�]-[����]\n\n");
	printf("'Ÿ��!'\n\n");
	Sleep(1500);
	printf("�� ��տ� ���Ⱑ ������� ����� �� �ϰ� ��������..\n\n");
	Sleep(3500);
	printf("'Ÿ��!'\n");
	Sleep(500);
	printf("'Ÿ��!'\n");
	Sleep(500);
	printf("'Ÿ��!'\n\n");
	Sleep(500);
	printf("����� �̹� ���� ���� �˾�����..�׷��� Ȯ���ϰ� �ϰ� �;���.\n\n");
	Sleep(1500);
	printf("'ŻĬ!ŻĬ!!'\n\n");
	Sleep(1500); 
	printf("�Ѿ��� �������� ������ ���ƿ��� �����ߴ�...");
	Sleep(3500);
	printf("��å��? �׷��� ���ٴ� ���ǰ��� �ȵ����...\n");
	Sleep(1500);
	printf("��ݱ��� �ι߷� ���ִ� �����...�̷��� �� ���� �������ٴ�..\n");
	Sleep(2000);
	printf("����������.");
	Sleep(1000);
	printf("�����ϱ� �������.\n");
	Sleep(1000);
	printf("���� �Ž�������.");
	Sleep(1000);
	printf("����� �״� ����� ó������.\n");
	Sleep(1300);
	printf("\n '���..'\n\n");
	Sleep(1500);
	printf("���̶�� ���ǵ����ϴ� ������ �İ��� �ƴ϶�� ������ �ϱ� �����ߴ�.\n");
	Sleep(2500);
	printf("�� �ð��� ������ ������ ����������, ���������� �������� �����ߴ�.\n\n");
	Sleep(2500);
	printf("'��¼��..���� �Ƚ�� ���� �״� �ſ���..'\n\n");
	Sleep(1500);
 	printf("���� �̷� ������ �ص� �޶����� ���� ������. �������� �Ӹ��� ��������,���� �Ž����� ���̿���.\n");
	Sleep(3500);
 	printf("���� ��å�� ����⿴��.\n");
	Sleep(1500);
 	printf("����� ��� �� ����� �Դ� ���� ��������ߴ�.\n\n");
	Sleep(2500);
 	printf("'�и�...��ġ���� ����...�и�..���Ⱑ ���ϰž�..'\n\n");
	Sleep(2000);
 	printf("���...������ �����ϸ� ����� ���� �ɾ��.\n");
	Sleep(2000);
 	printf("�� ��¼�ڽ��ϱ�? ����� ����� ���� ���θ���� ���� ������ �ʽ��ϴ�.\n");
	Sleep(2000);
 	printf("�ڱ��ո�ȭ �Ѵٰ� ���� ���ұ��?..�� ��¼�� ��ŵ� �󸶾Ȱ� ������ ����������...\n");
	Sleep(2500);
 	printf("��..��ø��̶� �׿� ſ�� �ƴ϶�� �����ϰڽ��ϴ�..\n��忣���Դϴ�..\n");

 	 	
 	exit(1);
	
}
