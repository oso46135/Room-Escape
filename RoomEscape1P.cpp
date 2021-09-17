#include<stdio.h>						 
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h> 

void tutorial();		//튜토	
void move();			//메뉴
void desk();			//책상
void computer();		//컴퓨터
void opencomputer();	//켜진컴퓨터
void door();			//탈출문
void ending();			//엔딩분기점
void bar();				//막대기 
void Refrigerator(); 	//냉장고 
void bed();				//침대
void bedsp();			//침대에서 잔다. 
void card();			//카드 
void cardgame();		//카드게임 


int q = 0;	//철문 첫 이벤트 스킵 

int c = 0; //책상 첫 이벤트 스킵 
int noplz = 0; //책상 말거는 이벤트 스킵 
int DP = 0; //책상 암호 발견 이벤트 스킵 
int passwordeak = 0; ///책상 암호를 찾았을 경우 

int barskip = 0;	//막대기 이벤트 스킵 
int barhand = 0;	//막대기 던진 횟수 카운터 

int computerskip = 0;	//컴퓨터 이벤트 스킵 
int computerpassword = 0;	//컴퓨터 패스워드 알아냇을대 

int opencomputerskip = 0;		//켜진 컴퓨터 이벤트 스킵
int fillplz = 0;			//켜진 컴퓨터 파일 찾기 이벤트 

int Refskip = 0;	//냉장고 이벤트 스킵 
int soundgood = 0;	//냉장고 소리가 좋아집니다. 
int Refdef = 0; //냉장고가 고장이 나서 들어가는게 의미가 없습니다. 

int bedspfin = 0; //침대 이벤트 스킵 
 

int win = 0;	//카드게임 승점  
const char *Nickname;	//카드게임 칭호
int ss = 0;		//카드게임 연승인지 


int passwordsee = 0; //암호인걸 알았을때 달라지는 반응[이스터에그1] 

int Jending=0;		//칭호를 얻으면 올라가는 점수 진엔딩을 볼 수 있음  
const char *cardciho="?"; 	//카드게임 업적 
const char *Refciho="?";		//냉장고 업적
const char *barciho="?";	//막대기  업적 
const char *deskciho = "?";	//책상 업적 
const char *computerciho = "?"; 

//password=비밀번호 입력칸, ok=비밀번호 정답 

int main(){				//1P 플레이어

	system("mode con cols=53 lines=20 | title 방탈출 1P.Ver");

	printf(" ------------------------------------------------\n");
	printf(" |	   ※이 게임은 1P 버전 입니다.※	|\n | 	 ★2P랑 같이 플레이해야 합니다.★	|\n");
	printf(" ------------------------------------------------\n\n");
	system("PAUSE"); 
	


	system("cls");
	printf("\n'여..여긴 어디지?'\n\n");
	Sleep(1000);
	printf("어지러운 머리를 붙잡고 자리에서 서서히 일어났다.\n");
	Sleep(1500);
	printf("주변을 둘러보았지만 내 방과는 전혀 다른 모습이였다.\n");
	Sleep(2000);
	printf("그리고 짧게 시간이 흐른뒤 내가 납치되었다는 것을 짐작할 수  있게 되었다.\n");
	Sleep(2500);
	printf("\n '추워 뭐 걸칠거 없나?'\n\n");
	system("PAUSE");
	 
	move();
		
}

void move(){		//이동 
	
	int a;
	
	while(1){
		system("cls");
		printf("[중앙]\n");										//지도 
		printf("획득 업적:%s,%s,%s,%s,%s \n\n",barciho,cardciho,deskciho,Refciho,computerciho) ;		//칭호 목록 
		printf("1.철문		2.책상		3.컴퓨터\n");			//이동 반경 
		if(barhand==11){
			printf("4.(故)막대기	5.냉장고	6.침대\n");
		} 
		else{
			printf("4.막대기	5.냉장고	6.침대\n");
		}
		printf(" >>");
		scanf("%d",&a);
		switch(a){
			case 1:
				door();		//탈출문 
				break;
			case 2:
				desk();		//책 상 
				break;
			case 3:			//컴퓨터,잠금 풀린 컴퓨터 
				if(computerpassword == 0){
					computer();
				}
				else{
					opencomputer();
				}
				break;	
			case 4: 	//막대기 
				bar();
				break;
			case 5:		//냉장고 
				if(Refdef == 0){
					Refrigerator();
				}
				else{
					printf("냉장고가 고장이 나서 못들어갑니다.\n\n");
					system("PAUSE"); 
					break; 
				}
				break; 
			case 6:		//침대 
				if(bedspfin == 0){
					bed();
				} 
				printf("당신은 이제 피곤하지 않습니다.\n");
				Sleep(1000);
				printf("꿈 내용이 떠올랐습니다. 으으...침대에서 멀어집니다..\n\n");
				system("PAUSE"); 
				break;
			case 99:
				printf("쉿! 조용하세요! 당신은 지금 진엔딩을 바로 볼수 있는 조건이 완료 되엇습니다!\n");
				system("PAUSE");
				Jending=5;
				q = 99;
				break;
			default:
				system("cls");
				printf("[중앙]\n");	
				printf("\n 1~6까지를 입력하시오.");
				system("PAUSE"); 
		}
		
	}
}

void door(){	//탈출문 
	int a, password=0, ok=0005;
	char passworddoor[20];
	while(1){
		system("cls");
		printf("[중앙]-[철문]\n\n");
		
		printf("꽤 단단해 보이는 철문이 있습니다.\n");
		Sleep(1000);
		if(q == 0){ 
			printf("1.철문을 조사한다	2.돌아간다\n");
			printf(" >>");
			scanf("%d",&a);
			switch(a){
				case 1:
					system("cls");
					printf("[중앙]-[철문]\n\n");
					printf("철문을 자세히 보았습니다.\n");
					Sleep(500);
					
					printf("..");
					Sleep(1500);
					
					printf("..");
					Sleep(1500);
					
					printf(".!");
					Sleep(1000);
					
					system("cls");
					printf("[중앙]-[철문]\n\n");
					if(passwordsee == 0){			//이스터에그 1
						printf("철문 중앙에 무언가 입력할 수 있을 것 같습니다\n\n");
						passwordsee++;
					}
					else if(passwordsee == 1){
						printf("철문 중앙에 암호를 입력할 수 있는 것 같습니다\n\n");
						passwordsee++;
						}
					else{
						printf("여기도...암호로 열어야 한다..(한숨)\n\n");
					}
					system("PAUSE"); 
					q++;
					break;
				case 2:
					move();
				default:
					printf("입력오류");
					system("PAUSE"); 
			}
		
		}
		else if(q == 99){
			printf("음...더 이상의 설명이 필요 한가요? 바로 엔딩 화면으로 가시죠.\n");
			system("PAUSE");
			ending();
		}
		else{
			printf("1.암호를 입력한다		2.돌아간다\n");
			printf(" >>");
			scanf("%d",&a);
			switch(a){
				case 1:
					system("cls");
					printf("[중앙]-[철문]-[암호입력]\n\n");
					
					printf("숫자 4자리만 입력 할 수 있는 것 같습니다\n");
					printf(" >>");
					scanf("%s",passworddoor);	//이후 나가는 함수
					if(strcmp(passworddoor,"0005")==0){
						printf("당신은 신기하게 아무 힌트도 없이 손이 이끌린 대로 입력하였습니다\n");
						Sleep(2000);
						printf("틀렸다고 생각한 당신은 뒤를 도는 순간..\n");
						
						printf("\n'띠리릭'\n\n");
						
						printf("도어락에 문이 열리자마자..\n\n");
						Sleep(2000);
						printf("**'열려라참께!'**\n\n");
						Sleep(1500);
						printf("옆 벽면에서 이상한 소리가 들렸습니다.\n"); 
						printf("..살짝 진동이 났지만 그게 무슨 상관입니까! 문이열렸습니다!\n");
						 
						system("PAUSE");
						ending();
					}
					else{
						printf("암호가 틀린 듯 합니다.\n");
					}
					break;
				case 2:
					 move(); 
			}
		}
	}
}
void desk(){	// 책상 
	int a, b, password, ok=3326;
	while(1){
		system("cls");
		printf("[중앙]-[책상]\n\n");
		if(c==0){
			printf("고급스러운 책상입니다.\n");
			Sleep(1000);
			printf("책상 색깔이 무지개가 아름답게 칠해져있습니다\n\n");
			Sleep(2500);
			printf("'내 취향은 아닌 듯;'.\n\n");
			Sleep(1000);
			c++;
		}
		else{
			printf("내 취향은 아닌 책상이 있습니다.\n\n");
		}
		if(DP == 0){
			printf("1.책상을 살펴보기	2.책상서랍을 살펴보기	 	 3.책상에게 말걸어보기	4.돌아가기\n");
		}
		else if(passwordeak == 1){
			printf("1.책상을 살펴보기	2.책상서랍 암호 다시보기	 3.책상에게 말걸어보기	4.돌아가기\n");
		} 
		else{
			printf("1.책상을 살펴보기	2.책상서랍 암호 입력하기	 3.책상에게 말걸어보기	4.돌아가기\n");
		}
		printf(" >>");
		scanf("%d",&a);
		if(a == 1){
			system("cls");
			printf("[중앙]-[책상]-[카드게임]\n\n");
			printf("당신은 책상에 있는 카드를 발견했습니다.\n\n");
			Sleep(2000);
			printf("'왕년에 내가 카드게임 좀 해봤지!'\n\n");
			Sleep(1000);
			printf("당신은 카드게임을 10승 하고 싶은 의지가 넘쳐흐릅니다.\n\n");
			printf("1.카드게임을 하자	2.돌아가기\n");
			printf(" >>");
			scanf("%d",&a);
			if(a == 1)	card(); 
			else desk();

		}
		else if(a == 2 && DP == 0){
			system("cls");
			printf("[중앙]-[책상]\n\n");
			DP++;
			if(passwordsee == 0){			//이스터에그 1 
				printf("안열린다...\n");
				Sleep(2000);
				printf("아무래도 무언가 입력해야 하는 것 같습니다.\n\n");
				system("PAUSE");
				passwordsee++;
			} 
			else if(passwordsee == 1){
				printf("안열린다...아무래도 암호를 입력해야 하는 듯하다.\n\n");
				system("PAUSE");
				passwordsee++;
			}
			else{
				printf("역시..이것도 암호를 입력해야 하는 것이다.\n\n");
				system("PAUSE");
			}
		}
		else if (a == 2	&& passwordeak == 0){		//쪽지 1개 등장 
			system("cls");
			printf("[중앙]-[책상]\n\n");
			
			printf("숫자 4자리만 입력 할 수 있는 것 같습니다\n");
			printf(" >>");
			scanf("%d",&password);
			if(password == ok){
				system("cls");
				printf("[중앙]-[책상]\n\n");
				printf("당신은 알수 없는 기운으로 3326을 입력했습니다\n\n");
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf("!\n\n"); 
				
				 
				printf("책상 서랍 안에는 쪽지 하나가 있었습니다.\n");
				Sleep(1500);
				printf("당신은 쪽지 안을 보니 이상한 그림과 '밑을본다' 라는 것이 적혀있습니다.\n");
				Sleep(1500);
				printf("아 자세히 보니 꽃? ");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(" 같기도 합니다.\n");
				system("PAUSE");
				passwordeak=1; 
			}
		
			else{
				printf("아무래도 아닌 것 같다.\n");
				system("PAUSE");
			}
		}
		else if (a == 2 && passwordeak == 1){
			system("cls");
			printf("[중앙]-[책상]\n\n");
			printf("당신은 나쁜 기억력을 가져서 종이를 한번더 봅니다.\n");
			Sleep(1500);
			printf("'밑을본다'라는 글씨와 꽃? ");
			Sleep(1500);
			printf(" 같은 사진이 보입니다..\n");
			system("PAUSE");
		}
		
		else if(a == 3){
			system("cls");
			printf("[중앙]-[책상]\n\n");
			if(noplz == 0){
				printf("당신은 머리가 조금 다쳤는지 책상에게 말을 걸어보았습니다.\n\n");
				Sleep(1000);
				printf("'아..안...안녕?'\n\n");
				
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				
				printf("무엇을 기대했는가? 당신은 자신의 어리석음을 깨닫기 시작했습니다.\n\n");
				noplz++;
				system("PAUSE"); 
				
			}
			else if(noplz == 1){
				printf("자신의 인사가 문제라는 것을 생각하고 환하게 인사하였습니다.\n\n");
				
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				
				printf("아무래도 당신은 머리를 다친것 같습니다.\n\n");
				noplz++; 
				system("PAUSE");
			}
			else if(noplz == 2){
				printf("당신은 책상이 쑥스러운 사람인걸 캐치하고 조심스럽게 인사하였습니다.\n\n");
				
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				
				printf("뭐가 잘못 된건지 인지를 못하는 듯 보입니다.\n\n");
				noplz++;
				system("PAUSE");
			}
			else if(noplz == 3){
				printf("당신은 마지막으로 친한 친구처럼 인사를 하였습니다.\n\n");
				
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf(".");
				Sleep(1500);
				printf("!");
								
				system("mode con cols=53 lines=20 | title 멍청함의극치!"); 
				deskciho="책상절친"; 
				printf("[중앙]-[책상]\n\n");
				printf("당신은 마지막으로 친한 친구처럼 인사를 하였습니다.\n\n");
				printf("..!");
				printf("당신은 이걸 시킨 사람을 원망하기 시작했습니다.");
				printf("\n(업적성공)\n");		
				system("PAUSE");
				Jending++;
				noplz++; 				
			}
			else{
				printf("당신은 책상에 말을 거는 것은 멍청한 짓이라는 것을 깨달았다.\n");
				system("PAUSE");
			}
		}
		else{
			move();
		}
	}
	
	
}
void computer(){	//컴퓨터 
	int a;
	char passwordcom[20];
	while(1){
		system("cls");
		printf("[중앙]-[컴퓨터]\n");
		if(computerskip == 0) {
			printf("당신은 컴퓨터를 키기 시작했습니다.\n");
				Sleep(1500);
			printf("음...아무래도 상태를 보니 좀 있으면 터질 듯한 컴퓨터 입니다.\n");
				Sleep(2500);
			if(passwordsee == 0){			//이스터에그 1
					printf("그전에 암호?를 풀어야 하는 듯 보입니다.\n\n");
					passwordsee++;
			}
			else if(passwordsee == 1){
					printf("그전에 암호를 풀어야 하는 듯 보입니다.\n\n");
					passwordsee++;
			}
			else{
					printf("뭐 이제는 익숙하게 암호를 풀어야 할 듯 보입니다.\n\n");
			}
			computerskip = 1;
		}
		else if(computerskip == 1){
			printf("당신은 아무 의심없이 컴퓨터를 켰습니다.\n");
			Sleep(1500);
			printf("컴퓨터가 과열하기 시작합니다.\n");
			Sleep(1500);
			printf("음...괜찮은거 맞죠?\n\n");
		}
		
		printf("1.암호풀기	2.돌아가기\n");
		printf(" >>");
		scanf("%d",&a);
		
		if(a == 1){
			system("cls");
			printf("[중앙]-[컴퓨터]\n");
			printf("음...아무래도 10글자 암호 같습니다.\n");			//3816547290
			printf(" >>"); 
			scanf("%s",passwordcom);
			
			if(strcmp(passwordcom,"3816547290") == 0){
				system("cls");
				printf("[중앙]-[컴퓨터]\n");
				printf("오!");
				Sleep(1500);
				printf("당신은");
				Sleep(1500);
				printf("10글자를");
				Sleep(1500);
				printf("막 눌르다보니 열렸습니다!\n");
				printf("컴퓨터가 켜지기 시작했습니다!\n"); 
				system("PAUSE");
				computerpassword = 1;
				opencomputer(); 
			}
			 
			
		}
		else if(a == 2){
			system("cls");
			printf("[중앙]-[컴퓨터]\n");
			printf("당신은 머리를 글쩍이며 다시 돌아갑니다\n\n");
			system("PAUSE"); 
			move(); 
			
		}
		else{
			system("cls");
			printf("[중앙]-[컴퓨터]\n");
			printf("숫자를 잘못 입력한 듯 보인다.");
		}
	}
	
}
void opencomputer(){	//잠금 풀린 컴퓨터 
	int a;
	while(1){
		system("cls");
		printf("[중앙]-[컴퓨터]\n");
		if(opencomputerskip == 0){
			printf("당신은 컴퓨터를 키는 것을 기다렸습니다.\n");
			Sleep(1500);
			printf("켜지는 속도를 보아 인터넷은 포기해야 할듯 보입니다.\n");
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			Sleep(1500);
			printf("드디어 켜졌습니다..\n");
			opencomputerskip = 1;
		}
		else if(opencomputerskip == 1){
			printf("당신은 컴퓨터를 킬때마다 신기함을 느낍니다.\n\n");
			Sleep(1500);
			printf("'어떻게 컴퓨터에서 기계 돌아가는 소리가 들리지?'\n\n");
			Sleep(1500);
			printf("이번에는 바로 켜졌습니다. 뭐 역시 컴퓨터도 적응에 기계군요.\n");
			opencomputerskip = 2;
		}
		else if(opencomputerskip == 2){
			printf("당신은 컴퓨터를 킬때 눈을 감았습니다.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			printf("어이쿠..한시간동안 자버렸습니다...걱정마세요! 컴퓨터는 아직 안켜졌습니다.\n");
		}
		else{
			printf("컴퓨터에 쿨러 소리는 당신의 귀를 자극 하기 충분했습니다.\n");
			Sleep(1500);
			printf("하지만 그뿐 이제 잘 켜집니다!\n");
		}
		printf("1.파일을 탐색하기	2.돌아가기\n");
		
		printf(" >>");
		scanf("%d",&a);
		
		if(a == 1){
			system("cls");
			printf("[중앙]-[컴퓨터]\n");
			printf("당신은 파일을 탐색하기 시작했습니다.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			printf("음! '그림을뺀다'라는 메모장 말고 딴 것은 없습니다. 뭐 내용도 아무것도 없습니다.\n");
				system("PAUSE"); 
			fillplz = 1;
		} 
		else if(a == 1 || fillplz == 1){
			system("cls");
			printf("[중앙]-[컴퓨터]\n");
			Sleep(1500);
			printf("당신은 '그림을뺸다'을 제외한 다른 파일을 찾습니다.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			
			printf("음...오! 8비트 리믹스 BGM을 찾았습니다. 당신은 조용히 소장하기 시작했습니다\n");
				system("PAUSE"); 
			fillplz = 2; 
		}
		else if (a == 1 || fillplz == 2){
			system("cls");
			printf("[중앙]-[컴퓨터]\n");
			Sleep(1500);
			printf("당신은 '그림을뺀다','개쩌는 브금'을 제외한 다른 파일을 찾습니다.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			
			printf("음...오! 당신은 귀여운 고양이를 찾았습니다! 조용히 소장하기 시작했습니다\n");
				system("PAUSE"); 
			fillplz = 3;
		}
		else if (a == 1 || fillplz == 3){
			system("mode con cols=53 lines=20 | title 수집가!"); 
			system("cls");
			printf("[중앙]-[컴퓨터]\n");
			Sleep(1500);
			printf("당신은 '그림을뺀다','개쩌는 브금','귀여운고양이'을 제외한 다른 파일을 찾습니다.\n");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".\n");
			printf("당신은 칭호를 발견했습니다! 이걸 원한거 맞죠?\n");
			
			system("PAUSE"); 
			fillplz = 4;
			computerciho = "수집 전문가";
			Jending ++;
	}
		else if (a == 1 || fillplz == 4){
			system("cls");
			printf("[중앙]-[컴퓨터]\n");
			Sleep(1500);
			printf("당신은 '그림을뺀다','개쩌는 브금','귀여운고양이'을 제외한 다른 파일은 없는 듯 보입니다!\n");
				system("PAUSE"); 
		}
		else{
			system("cls");
			printf("[중앙]-[컴퓨터]\n");
			printf("당신은 컴퓨터를 끄고 다시 중앙으로 돌아갑니다.\n");
			system("PAUSE"); 
			move(); 
		}
		system("cls");
		printf("[중앙]-[컴퓨터]\n");
		printf("\n\n똥컴 같으니! 컴퓨터가 방전되었습니다!\n");
		system("PAUSE"); 
		move();
		
	} 
}
void bar(){		//막대 
	int a;
	while(1){
		system("cls");
		printf("[중앙]-[막대기]\n\n");
		if(barskip == 0){			//막대기 들어오는 이벤트 1 
			printf("당신은 바닥에 막대기가 있는 것을 의아해 합니다.\n");
			Sleep(3000);
			printf("그래도...");
			Sleep(800);
			printf("막대기는 막대기 입니다.");
			barskip = 1;
		} 
		else if(barskip == 1){		//막대기 들어오는 이벤트 2 
			printf("당신은 막대기를 다시 보자 마음이 편안해 집니다.\n");
			Sleep(3500);
			printf("하지만 그뿐 역시 막대기는 막대기 입니다.\n");
			Sleep(1500);
			barskip = 2;
		}
		else if(barskip == 2){		//막대기 들어오는 이벤트 3 
			printf("당신은 막대기에게 찰스라는 이름을 붙혔습니다.\n");
			Sleep(2500);
			printf("짧게 생각을 마친 당신은 그냥 막대기로 부르기로 했습니다.\n"); 
			Sleep(1500);
			barskip = 3;
		}
		else if(barskip == 3){		//막대기 들어오는 이벤트 4
			printf("막대기랑 눈싸움을 하기 시작했습니다!\n");
			Sleep(3500);
			printf("막대기는 눈이 없다는 것을 깨달았습니다...\n"); 
			barskip = 4;
			
		}
		else if (barskip == 4){		//막대기 들어오는 이벤트 5 
			printf("당신은 막대기에게 화를 냈습니다.\n");
			Sleep(2500);
			printf("당신은 막대기에게 사과 했습니다.\n");
			Sleep(1000);
			barskip = 5;
		}
		else if(barskip == 5){		//막대기 들어오는 이벤트 6 
			printf("막대기가 말했습니다.\n");
			Sleep(1000);
			printf("'...'\n");
			Sleep(1000);
			printf("이런! 입이 없군요!\n") ;
			barskip = 6;
		}
		else if(barhand == 11){		//막대기 부셔지는 이스터에그 
			printf("막대기는 부셔지고 말았습니다...\n"); 
			Sleep(2000);
			printf("당신은 막대기를 생각하니 눈물이 앞을 가립니다.\n");
			system("PAUSE"); 
			system("mode con cols=53 lines=20 | title 막대기...기억할게..."); 
			barciho="막대기살인범";
			move(); 
		}
		else{						//막대기 던지는 이벤트 
			printf("당신은 %d번 막대기를 던졌습니다!\n 하지만 좀 더 하면 막대기가 부셔질 것 같습니다.\n",barhand);
		}
		printf("\n1.던지기 2.돌아가기\n");
		printf(" >>");
		scanf("%d",&a);
		
		if(a == 1){
			system("cls");
			printf("[중앙]-[막대기]-[던짐]\n\n");
			printf("당신은 막대기를 던졌습니다.\n");
			Sleep(500);
			printf(".");			
			Sleep(2000);
			
			printf(".");			
			Sleep(2000);
			
			printf(".\n");
			Sleep(2000);
			if(barhand==8){			//막대기 부셔지는 이벤트 
				printf("이런! 막대기가 부셔져 버렸습니다!\n");
				Sleep(1500);
				printf("당신은 잠깐의 슬픈 시간을 가지게 됩니다.\n");
				printf("\n(업적 획득)\n");		
				barhand=11;
				Jending++;
				system("PAUSE"); 
				bar();
			}
			system("cls");
			printf("[중앙]-[막대기]\n\n");
			printf("당신은 막대기를 던졌습니다.\n");
			printf("...\n"); 
			printf("다시 주웠습니다.\n");
			barhand++;
			system("PAUSE");
			
		}
		else{
			move();
		}
	}
}
void Refrigerator(){	//냉장고
		int a=0; 
		while(1){
			system("cls");
			printf("[중앙]-[냉장고]\n\n");	
			if(Refskip == 0){
				printf("당신은 배고픈 마음에 냉장고를 열었습니다.\n");
				Sleep(1500);
				printf("하지만 안쪽에는 먹을 만한 게 없었습니다.\n"); 
				Refskip++; 
			}
			else if(Refskip == 1){
				printf("당신은 생각없이 냉장고 문을 열었습니다.\n");
				Refskip++;
			}
			else{
				printf("당신은 냉장고 문 여는 소리가 좋아졌습니다.\n");
				soundgood=1;
			}
			printf("\n");
			if(soundgood==1){
				printf("1.조사한다 2.문으로 장난친다 3.돌아간다\n");
				printf(" >>");
				scanf("%d",&a);
				if(a == 1){
					system("cls");
					printf("[중앙]-[냉장고]\n\n");	
					printf("냉장고를 유심히 둘러보았지만, 아무것도 발견할 수가 없었습니다.\n");
					system("PAUSE"); 
					move(); 
				} 
				else if(a == 2){
					for(int i=0; i<=10; i++){
						system("cls");
						printf("[중앙]-[냉장고]-[열음]\n\n");	
						printf("덜컥\n");
						Sleep(500);
						
						system("cls");
						printf("[중앙]-[냉장고]-[닫음]\n\n");
						printf("끼익\n");
						Sleep(500);
					}
					system("cls");
					printf("[중앙]-[냉장고]-[고장]\n\n");
					printf("퍼엉!\n");
					Sleep(2000);
					 
					printf("냉장고가 고장났다.\n");
					printf("(업적성공)\n");
					system("PAUSE"); 
					system("mode con cols=53 lines=20 | title 냉장고 누가 물어주냐.."); 
					Refciho="냉장고 문 촵촵";
					Jending++;
					Refdef=1;
				 	move();
				 	
				}
				else{
					move();
				}
			}
			else{
				printf("1.조사한다  2.돌아간다\n");
				printf(" >>");
				scanf("%d",&a);
				if(a == 1){
					system("cls");
					printf("[중앙]-[냉장고]\n\n");	
					printf("냉장고를 유심히 둘러보았지만, 아무것도 발견할 수가 없었습니다.\n");
					system("PAUSE"); 
					move(); 
				} 
				else{
					move();
				}
				
			} 
	}
}		
void bed(){		//침대  
	int a;
	
	while(1){
		system("cls");
		printf("[중앙]-[침대]\n\n");
		printf("나는 침대를 바라보았다.\n");
		Sleep(1000);
		printf("엄청 피곤한 당신은 침대에 눕고 싶어졌습니다.\n\n");
		printf("1.눕는다	2.무슨소리 의지로 버틴다.\n");
		printf(" >>");
		scanf("%d",&a);
		if(a == 1){
			printf("당신은 침대에 살포시 눕습니다.\n");
			system("PAUSE"); 
			bedsp();
		}
		else{
			system("cls");
			printf("[중앙]-[침대]\n\n");
			printf ("당신은 침대에서 자고 싶지만 버티기로 했습니다.\n");
			Sleep(1000);
			printf("하지만 당신은 버티기에는 너무 힘듭니다.\n\n");
			
			printf("1.안되겠어 잠이나 자자	2.정신차리자!\n");
			printf(" >>");
			scanf("%d",&a);
			
			if(a == 1){
				
				printf("당신은 침대에 살포시 누웁니다.");
				system("PAUSE"); 
				bedsp();
			}
			else{
				system("cls");
				printf("[중앙]-[침대]\n\n");
				printf("당신은 ");
				Sleep(500);
				printf("무지"); 
				Sleep(500);
				printf("무지"); 
				Sleep(500);
				printf("무지"); 
				Sleep(500);
				printf("졸리지만,");
				Sleep(1000);
				
				printf("그래도 참기로 했습니다.\n");
				Sleep(1000);
				printf("아!");
				Sleep(2000);
				printf(" 그런데 침대에 무언가 이상한게 있는 것 같습니다!.\n\n");
				printf("1. 침대에 눕는다	2.침대를 조사한다.\n"); 
				printf(" >>");
				scanf("%d",&a);
				if(a == 1){
					system("cls");
					printf("[중앙]-[침대]\n\n");
					printf("당신은 절.때 침대에서 자려는 것이 조사를 목적으로,\n침대에 누웠습니다.\n");
					system("PAUSE"); 
					bedsp();
				}
				else{
					system("cls");
					printf("[중앙]-[침대]\n\n");	
					printf("당신은 침대가 수상해 직접 조사합니다.\n ");
					system("PAUSE"); 
					bedsp();
				}
			}
			
			
		}
		 
	}
}
void bedsp(){		//침대에서 잔다.
	int a;
	
	system("cls");
	printf("[중앙]-[침대]\n\n");
	printf("당신은 침대에 살이 닿자마자 졸음이 쏫아졌습니다.\n");
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".\n");
	Sleep(1000);
	
	printf("'!!!'\n\n");
	printf("당신은 무서운 꿈을 꾸었습니다. 바로 일어나 침대에서 멀어집니다.\n");
	system("PAUSE"); 
	bedspfin++;
	
	move();
		 
}
 void card(){				//카드 
 		int a,s,c,h,d; 
 		srand(time(NULL));
 		if(win == 0)	Nickname="초보자"; 
 	
	 	while(1){
	 			s,c,h,d=0;
 				system("cls");
				printf("[중앙]-[책상]-[카드게임]-승리:%d\n",win);
				printf("닉네임:%s\n\n",Nickname);
			 	printf(".당신은 카드를 섞습니다.\n");
			 	Sleep(1000);
		 	
			 	system("cls");
				printf("[중앙]-[책상]-[카드게임]-승리:%d\n",win);
				printf("닉네임:%s\n\n",Nickname);
			 	printf("..당신은 카드를 섞습니다..\n");
			 	Sleep(1000);
		 	
		 		system("cls");
				printf("[중앙]-[책상]-[카드게임]-승리:%d\n",win);
				printf("닉네임:%s\n\n",Nickname);
		 		printf("...당신은 카드를 섞습니다...\n");
		 		Sleep(1000);
		 	
		 		system("cls");
				printf("[중앙]-[책상]-[카드게임]-승리:%d\n",win);
				printf("닉네임:%s\n\n",Nickname);
		 		printf(".당신은 카드를 섞습니다.\n");
		 		Sleep(1000);
		 	
		 		system("cls");
				printf("[중앙]-[책상]-[카드게임]-승리:%d\n",win);
				printf("닉네임:%s\n\n",Nickname);
		 		printf("..당신은 카드를 섞습니다..\n");
		 		Sleep(1000);
		 	
		 		system("cls");
				printf("[중앙]-[책상]-[카드게임]-승리:%d\n",win);
				printf("닉네임:%s\n\n",Nickname);
		 		printf("...당신은 카드를 섞습니다...\n");
		 		Sleep(1000);
		 	
				cardgame();	            
		 }
 } 
 
void cardgame(){		//카드 게임  
	int a,b;
		while(1){
			srand(time(NULL)); 
			system("cls");
			printf("[중앙]-[책상]-[카드게임]-승리:%d\n",win);
			printf("닉네임:%s\n\n",Nickname);
		 	Sleep(500);
		 	printf("당신의 선택은?\n");
		 	Sleep(500);
			printf("1.스페이드  2.클로버  3.다이아  4.하트  5.조커\n"); 
		 	printf(" >>");
		 	scanf("%d",&a);
		 	
		 	system("cls");
			printf("[중앙]-[책상]-[카드게임]-승리:%d\n",win);
			printf("닉네임:%s\n\n",Nickname);
		 	if(a == 1){
			    printf("당신은 스페이드를 선택했습니다.\n");
			    
			}
			else if(a == 2){
				printf("당신은 클로버를 선택했습니다.\n");
				
			}
			else if(a == 3){
				printf("당신은 다이아를 선택했습니다.\n");
			
			}
			else if(a == 4){	
				printf("당신은 하트를 선택했습니다.\n");
			
			}
			else if(a == 5){
				printf("당신은 조커를 선택했습니다.\n");
			} 
			else if(a == 10){
				printf("당신은 10승을 선택했습니다.\n");
			}
			else{
				printf("입력 오류"); 
				cardgame(); 
			}

			Sleep(1500);
			printf("당신은 카드 한 장을 조심스럽게 뽑습니다.\n");
			Sleep(2000);
			if(rand()%4+1 == 1){
				printf("뽑은 카드는 스페이드입니다!\n\n"); 
				b=1;
				Sleep(1000);
			}
			else if(rand()%4+1 == 2){
				printf("뽑은 카드는 클로버입니다!\n\n");
				b=2;
				Sleep(1000);
			}
			else if(rand()%4+1 == 3){
				printf("뽑은 카드는 다이아입니다!\n\n");
				b=3;
				Sleep(1000);
			}
			else if(rand()%4+1 == 4){
				printf("뽑은 카드는 하트입니다!\n\n");
				b=4;
				Sleep(1000);
			} 
			else{
				printf("오! 조커가 나왔군요!\n\n");
				b=5;
				Sleep(1000);
			} 
			
			if(a == b){
				printf("당신이 이겼습니다!\n\n");
				system("PAUSE"); 
				win++;
				ss++;
			}
			else if (a==10){
				printf("당신은 졌지만, 10연 승을 챙깁니다!\n");
				system("PAUSE");
				win=10;
				ss=10; 
			}
			else{
				printf("당신이 졌습니다\n\n");
				ss=0;
				system("PAUSE"); 		 
			}
			if(win == 1)	Nickname="한판 이겨본자"; 
			else if(win == 2)	Nickname="두판 이겨본자";
			else if(win == 3)	Nickname="삼세판!";
			else if(win == 4)	Nickname="찍신!!";
			else if(win == 8) 	Nickname="행운의 여신!";
			else if(win == 10){		//카드 10승시 칭호, 타이틀 바뀜 
				Nickname="포커 최강!";
				system("mode con cols=53 lines=20 | title 포커의 최강!"); 
				cardciho="포커의 최강!"; 
				printf("\n (업적획득) \n"); 
				Jending++;
				system("PAUSE");
			} 
			

			
			system("cls");
			printf("[중앙]-[책상]-[카드게임]-승리:%d\n",win);
			printf("닉네임:%s\n\n",Nickname);
			
			printf("계속하겠습니까?");
			if(ss > 1){
				printf("%d연승!!!\n",ss);
			}
			else{
				printf("\n");
			}
			
			printf("1.네	2.아니요\n");
			
			printf(" >>");
			scanf("%d",&a);
			if(a == 1)	card();
			else if(a == 2) desk();
			else{
				printf("입력오류로 인한 로비로 돌아감\n");
				system("PAUSE"); 
				move(); 
			}
		}
		 
}

void ending(){		//엔딩 
	int a;
	system("cls");
	printf("[중앙]-[엔딩]\n\n");		//	system("PAUSE");  Sleep(2000);
	printf("당신은 뒤도 돌아보지 않고 빠르게 앞만을 향해 달려갑니다.\n");
	Sleep(1500);
	if(Jending == 5 )	
		printf("당신은 숨이 차는 것 같은 느낌이 들지만 그래도 열심히 뛰기 시작했습니다. \n"); 
	else
		printf("당신은 이 지긋지긋한 곳에서 빠르게 빠저나오고 싶을 뿐이였습니다.\n");
	
	Sleep(1500);
	printf("당신은 숨을 살짝 고르기 시작했습니다\n\n");
	Sleep(1500);
	printf("'...앗...총'\n\n");
	Sleep(1500);
	printf("당신은 땅바닥에 총이 있다는 것을 알아차렸습니다.\n 총이 왜 있지라는 생각을 짧게 하고 바로 총을 집어 다시 달리기 시작했습니다.\n");
	system("PAUSE");
	
	system("cls");
	printf("[중앙]-[엔딩]\n\n");		//	system("PAUSE");  Sleep(2000);
	
	printf("희망인지 불행인지 앞쪽에 희미한 불빛이 보이기 시작했습니다.\n");
	Sleep(1500);
	printf("당신은 마지막까지 전력질주로 달리기 시작했습니다.\n\n");
	Sleep(1500);
	printf("터벅.\n'...허억..허억..'\n\n");
	Sleep(1500);
	printf("동시에 나는 발자국소리와 나와 같이 숨고르기를 하는 상대방..\n");
	Sleep(1500);
	printf("난 본능적으로 주머니에 있던 총을 꺼내어  상대방을 조준하기 시작했다.\n");
	Sleep(1500);
	printf("그걸 보자 상대도 당황하듯이 총을 나에게 겨누었다.\n");
	Sleep(1500);
	
	printf("총을 들고 몇 초가 지나고서야 저사람은 우리 적이 아니라는 것을 꺠달았습니다.\n");
	
	if(Jending == 5){
		printf("당신은 예리한 눈썰미로 상대방이 당신을 쏘지 않을 것을 알아차렸습니다..\n");
		Sleep(1500);
	}
	else{
		printf("하지만 뭐 어쩌겠습니까? 이미 당신은 총을 올렸습니다. 당신이 아니면  상대가 당신을 죽일 것 입니다.\n");
	} 
	
	if(Jending == 5){
		printf("1.총을쏜다	2.기다린다\n");
	}
	else{
		printf("1.총을쏜다	2.기다린다(잠김)\n");
	}
	
	printf(" >>");
	scanf("%d",&a);
	
	if(Jending == 5 && a == 2){		//	system("PAUSE");  Sleep(2000);
		printf("당신은 상대방을 전혀 죽일 마음은 없었습니다. 그렇다고 총을 잘못 움직였다간 상대방이 쏠것 같았습니다.\n");
		Sleep(2000);
		printf("결국 당신은 잠시 상대방을 경계하면서 기다리기로 했습니다.\n");
		system("PAUSE");
		
		system("cls");
		printf("[중앙]-[엔딩]\n\n");
		
		printf("당신은 한참의 시간이 지났을까 상대방은 당신이 쏠 의자가 없다는 것을 알아차렸는지 입을 열기 시작했다.\n");
		Sleep(2000);
		printf("상대가 입을 열자 서로가 오해가 있다는 것을 알았고 총을 천천히 거두기 시작했다\n");
		Sleep(2000);
		printf("서로가 서로에 방에서 무엇을 찾았는지 이야기하였다..물론 이야기가 새버려서 딴 이야기도 좀 했다.\n");
		Sleep(2000);
		printf("당신은 여기서 나갈지 못나갈지 아무도 몰랐지만, 그래도 당신과 비슷한 처지에 있던 사람을 만나 한편으로 후련했습니다\n");
		Sleep(2000);
		printf("\n'...'\n\n");
			Sleep(2000);
		printf("뭐 둘이 협력해서 탈출.....탈출후 서로 친구친구...뭐..뻔한 해피엔딩이네요..\n");
		Sleep(2000);
		printf("...참 잘됬네요..잘하셨습니다!\n");
		
		exit(1); 
 
	}
	else if(a == 2){
		printf("당신은 기다리고 싶었지만,,,당신의 불안함은 어느덧 방아쇠를 당기고 말았습니다.");
		
	} 
	else if(a == 1){
		printf("당신은 생각에 정리가 끝나자마자 방아쇠를 당기었다.");
	}
	else{
		printf("당신은 1,2번 중에 선택을 안하여 당황을 틈타 방아쇠를 당기고 말았다..");
	} 
	printf("\n");
	system("PAUSE");
	
	system("cls");
	printf("[중앙]-[엔딩]\n\n");
	printf("'타앙!'\n\n");
	Sleep(1500);
	printf("내 양손에 무기가 쥐어지자 사람은 뚝 하고 쓰러졌다..\n\n");
	Sleep(3500);
	printf("'타앙!'\n");
	Sleep(500);
	printf("'타앙!'\n");
	Sleep(500);
	printf("'타앙!'\n\n");
	Sleep(500);
	printf("당신은 이미 죽은 것을 알았지만..그래도 확실하게 하고 싶었다.\n\n");
	Sleep(1500);
	printf("'탈칵!탈칵!!'\n\n");
	Sleep(1500); 
	printf("총알이 떨어지자 정신이 돌아오기 시작했다...");
	Sleep(3500);
	printf("죄책감? 그런것 보다는 현실감이 안들었다...\n");
	Sleep(1500);
	printf("방금까지 두발로 서있던 사람이...이렇게 힘 없이 쓰러지다니..\n");
	Sleep(2000);
	printf("어지러웠다.");
	Sleep(1000);
	printf("생각하기 어려웠다.\n");
	Sleep(1000);
	printf("속이 매스꺼웠다.");
	Sleep(1000);
	printf("사람이 죽는 모습은 처음본다.\n");
	Sleep(1300);
	printf("\n '우욱..'\n\n");
	Sleep(1500);
	printf("꿈이라고 현실도피하는 나에게 후각이 아니라고 부정을 하기 시작했다.\n");
	Sleep(2500);
	printf("좀 시간이 지나자 정신은 온전해지고, 어지러움은 끝나가기 시작했다.\n\n");
	Sleep(2500);
	printf("'어쩌피..내가 안쏘면 내가 죽는 거였어..'\n\n");
	Sleep(1500);
 	printf("물론 이런 생각을 해도 달라지는 것은 없었다. 어지러운 머리는 어지럽고,속은 매스꺼울 뿐이였다.\n");
	Sleep(3500);
 	printf("그저 죄책감 덜어내기였다.\n");
	Sleep(1500);
 	printf("당신은 방금 그 사람이 왔던 길을 가기시작했다.\n\n");
	Sleep(2500);
 	printf("'분명...납치범일 꺼야...분명..여기가 길일거야..'\n\n");
	Sleep(2000);
 	printf("라고...속으로 생각하면 당신은 길을 걸어갔다.\n");
	Sleep(2000);
 	printf("뭐 어쩌겠습니까? 당신은 사람을 죽인 살인마라는 것은 변하지 않습니다.\n");
	Sleep(2000);
 	printf("자기합리화 한다고 뭐가 변할까요?..뭐 어쩌피 당신도 얼마안가 죽을것 같긴하지만...\n");
	Sleep(2500);
 	printf("뭐..잠시만이라도 그에 탓이 아니라고 생각하겠습니다..\n배드엔딩입니다..\n");

 	 	
 	exit(1);
	
}
