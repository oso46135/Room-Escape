#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<cstring> 

void move();		//이동
void paper();		//종이
void pot();			//화분
void Photo();		//액자 
void door();		//탈출문 
void ending();		//엔딩문 
void boos();		//책 

int chbo = 0;		//처음 안내문을 없앱니다. 

int potskip = 0;		//화분 초반 이벤트 스킵 
int pottoking = 0; 		//화분 대화 이벤트 
int potfin = 0; 		//화분 답지 보기 스킵 

int paperskip = 0;		//종이 초반 이벤트 스킵 
int paperfin = 0;		//종이의 적힌 것을 본 후 
int fay = 0;			//종이 비행기 이벤트 스킵 
int titaw = 0;			//티타늄 종이라는 것을 알았을 때

int Photoskip = 0;		//액자 초반 이벤트 스킵 
int Photosee = 0;		//액자를 보고 이벤트 스킵 
int photdel = 0;		//액자 그림 빼는 이벤트 스킵 
int Photofin = 0;		//액자 그림을 파괴 이벤트 스킵 

int jending = 2;			//진 엔딩 
const char *paperch= "?";	//종이 칭호 
const char *photoch= "?";	//액자 칭호 
int main(){				//2P 플레이어

	system("mode con cols=53 lines=20 | title 방탈출 2P.Ver");

	printf(" ------------------------------------------------\n");
	printf(" |	   ※이 게임은 2P 버전 입니다.※	|\n | 	 ★1P랑 같이 플레이해야 합니다.★	|\n");
	printf(" ------------------------------------------------\n\n");
	system("PAUSE");
	 
	system("cls");
	printf("\n천천히 눈을 뜨자 내가 아는 곳과 다른 곳이였습니다\n");
	Sleep(1500);
	printf("주변을 보다 수상하리 만큼의 가구배치를 보았습니다\n");
	Sleep(2000);
	printf("당신은 곧바로 자신이 납치되었다는 것을 알아차렸습니다\n");
	Sleep(2000);
	printf("\n'후...추리 게임을 많이 봤지...이때를 대비해서'\n");
	Sleep(2500);
	printf("\n 당신은 당신만의 성격으로 방탈출을 클리어 하기로 했습니다\n");
	Sleep(2000);
	printf("이런! 너무 자만해서 행동 보기까지 안본다고 하는군요\n");
	Sleep(2000);
	printf("(띄어쓰기는 빼주기 바랍니다.)\n\n");		
	system("PAUSE");
	
	move(); 
	
}

void move(){
	char movemove[20];
	while(1){
		system("cls"); 
		printf("[중앙]\n");
		printf("칭호:%s,%s\n\n",paperch,photoch) ;
		printf("|화분|종이|액자| 문 | 책 |\n무엇을 행동하시겠습니까?\n\n");
		printf("(가끔 안될수 있으니 의미는 같지만 다른 단어로 입력해주세요)\n"); 
		if(chbo == 0){
			printf("(공백은 쓰지 말아주세요)\n");
			printf("(돌아가고 싶으면 '돌아기기'를 써주세요!)\n"); 
			printf("ex)화분,종이,액자,돌아가기(O)\nex)화분가기,종 이,액자(공백) (X)\n");
			printf("**뭐할지 모르겠습니다 '조사' 해주세요! 조사는 모두 통합니다!**\n");
			printf("(한글은 입력할때 한글자 밀려서 다 쓰시고 스페이스바 한번 눌러주세요!)\n"); 
			chbo=1;
		}
		printf("  >>");
		scanf("%s",movemove);
		if(strcmp(movemove,"화분") == 0){
				pot();
		}
		else if(strcmp(movemove,"종이") == 0){
				paper();
		}
		else if(strcmp(movemove,"액자")==0){
				Photo();
		}
		else if(strcmp(movemove,"문")==0){
			door();
		}
		else{
			system("cls"); 
			printf("[중앙]\n\n");
			printf("'그 행동은 할 수 없겠군..'\n\n");
			
			 system("PAUSE");
		} 
		
	}
}
void door(){	//탈출문 
	char a[20];
	while(1){
		system("cls"); 
		printf("[중앙]-[문]\n\n");
		printf("당신은 문으로 다가갔습니다.\n");
		Sleep(1500);
		printf("당신의 예리한 직감은 여기는 마지막에 오는 것이라 말합니다!\n");
		printf(" >>");
		scanf("%s",a);
		if(strcmp(a,"돌아가기") == 0 || strcmp(a,"돌아간다") == 0 || strcmp(a,"중앙") == 0){
			printf("\n당신은 더 힌트를 모으고 다시 오기를 기약합니다\n");
			 system("PAUSE");
			 move();
		}
		else if(strcmp(a,"열려라참께")==0){
			system("cls"); 
			printf("[중앙]-[문]\n\n");
			printf("문이 흔들리면서 서서히 열리기 시작했습니다\n");
			Sleep(1500);
			printf("이게 먹힌다는 것에 당신은 헛 웃음만 합니다. \n");
			system("PAUSE");
			ending();
			
		}
		else if(strcmp(a,"보기") == 0 || strcmp(a,"본다") == 0 || strcmp(a,"조사") == 0 || strcmp(a,"살펴본다") == 0 ){
			system("cls"); 
			printf("[중앙]-[문]\n\n");
			printf("당신은 문을 자세히 살펴 보았습니다.\n");
			Sleep(1500);
			printf("음! 신기한 문이네요! 문고리가 없습니다! 힘으로 밀어도 꿈적 안합니다!\n\n");
			
			system("PAUSE");
		}
		else{
			system("cls"); 
			printf("[중앙]-[문]\n\n");
			printf("'그 행동은 못하겠군.'\n");
			system("PAUSE");
			 
		}
	}
	
}

void pot(){		//화분 
	char potpot[20];

	while(1){
		if(potskip ==  0){		//처음이벤트 스킵 
			system("cls"); 
			printf("[중앙]-[화분]\n\n");
			printf("당신은 화분에게 가까이 갔다.\n");
			Sleep(1000);
			printf("화분을 보니 아름다운 꽃 한송이가 피어있다\n");
			Sleep(1000);
			potskip=1;	
		}
		else{
			system("cls"); 
			printf("[중앙]-[화분]\n\n");
			printf("아까와 같은 꽃 아까와 같은 위치\n");
			printf("변함 없고 특별함 없는 꽃\n");
		}
		printf("\n무슨 행동을 할까?\n");
		printf("  >>");
		scanf("%s",potpot);
		//이벤트 타이핑 
		if(strcmp(potpot,"보기") == 0 || strcmp(potpot,"본다") == 0 || strcmp(potpot,"꽃을본다") == 0 || strcmp(potpot,"조사") == 0 || strcmp(potpot,"화분조사") == 0 || strcmp(potpot,"꽃조사") == 0 || strcmp(potpot,"살펴본다") == 0 ){
			system("cls"); 
			printf("[중앙]-[화분]-[%s]\n\n",potpot);
			printf("당신은 화분을 자세히 보았습니다.\n");
			Sleep(1000);
			printf("다른건 모르겠고, 꽃이 매우 이쁩니다.\n\n");
			
			system("PAUSE");
			
		}
		else if(strcmp(potpot,"꺽는다") == 0 || strcmp(potpot,"꽃을꺽는다") == 0 || strcmp(potpot,"죽인다") == 0 || strcmp(potpot,"죽여") == 0 || strcmp(potpot,"처치") == 0 || strcmp(potpot,"뽑는다") == 0 || strcmp(potpot,"꽃을뽑는다") == 0 || strcmp(potpot,"뽑다") == 0 || strcmp(potpot,"꺽기") == 0){
			system("cls"); 
			printf("[중앙]-[화분]-[%s]\n\n",potpot);
			printf("당신은 꽃을 꺽기로 결심했습니다.\n\n");
		
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".\n\n");
			Sleep(1000);
			
			printf("꽃이 이뻐서 도저히 못할 것 같습니다..\n\n");
			system("PAUSE");
				
		}
		else if(strcmp(potpot,"돌아가기") == 0 || strcmp(potpot,"돌아간다") == 0 || strcmp(potpot,"중앙") == 0){		//중앙으로 가는 커맨드 
			system("cls"); 
			printf("[중앙]-[화분]\n\n");
			printf("당신은 다시 처음으로 돌아기로 했습니다.\n\n"); 
			system("PAUSE");
			move(); 
		}
		else if(strcmp(potpot,"밑을본다") == 0){
			system("cls"); 
			printf("[중앙]-[화분]-[%s]\n\n",potpot);
			if(potfin == 0){
				printf("당신은 화분을 들어 밑을 보았습니다\n");
				Sleep(1500);
				printf("오! 화분밑에 쪽지가 있습니다!\n");
				Sleep(1500);
				printf("당신은 명석한 머리로 이것이 퀴즈라는 것을 알아차렸습니다!\n\n");
				system("PAUSE");
				
				system("cls"); 
				printf("[중앙]-[화분]-[%s]\n\n",potpot);
				printf("'0부터 9까지 10개의 숫자를 모두 사용해 규칙에 맞는 수를 만들어라.'\n\n") ;		//3816547290
				printf("'첫 번째 숫자까지 1로 나누어진다.\n");
				printf(" 두 번째 숫자까지 2로 나누어진다. \n ");
				printf(" 세 번째 숫자까지 3으로 나누어진다.\n");
				printf(" 네 번째 숫자까지 4로 나누어진다.\n") ;	
				printf(" 다섯 번째 숫자까지 5로 나누어진다.\n") ;
				printf(" 여섯 번째 숫자까지 6로 나누어진다.\n") ;
				printf(" 일곱 번째 숫자까지 7로 나누어진다.\n") ;
				printf(" 여덟 번째 숫자까지 8로 나누어진다.\n") ;
				printf(" 아홉 번째 숫자까지 9로 나누어진다.\n") ;
				printf(" 열 번째 숫자까지 10로 나누어진다.'\n\n") ;
				Sleep(1500);
				printf("당신은 이 문제가 직감적으로 10글자라는 것을 알아차렸다\n");
				printf("음...");
				Sleep(1500);
				printf("문제 난이도도 어렵다는 것을 깨달았다!\n");
				Sleep(1500);
				printf("당신은 이 문제를 푸는데 엄청 오래걸릴 것 같은 예감이 들었다.\n"); 
				potfin = 1;
			}
			else{
				printf("당신은 풀지도 못하고 다음으로 클릭해버려서 황금하게 다시 종이를 보기 시작했습니다\n\n"); 
				system("PAUSE");
				system("cls"); 
				printf("[중앙]-[화분]-[%s]\n\n",potpot);
				printf("'0부터 9까지 10개의 숫자를 모두 사용해 규칙에 맞는 수를 만들어라.'\n\n") ;		//3816547290
				printf("'첫 번째 숫자까지 1로 나누어진다.\n");
				printf(" 두 번째 숫자까지 2로 나누어진다. \n ");
				printf(" 세 번째 숫자까지 3으로 나누어진다.\n");
				printf(" 네 번째 숫자까지 4로 나누어진다.\n") ;	
				printf(" 다섯 번째 숫자까지 5로 나누어진다.\n") ;
				printf(" 여섯 번째 숫자까지 6로 나누어진다.\n") ;
				printf(" 일곱 번째 숫자까지 7로 나누어진다.\n") ;
				printf(" 여덟 번째 숫자까지 8로 나누어진다.\n") ;
				printf(" 아홉 번째 숫자까지 9로 나누어진다.\n") ;
				printf(" 열 번째 숫자까지 10로 나누어진다.'\n\n") ;
				
				printf("힌트를 주자면 첫번째는 3이며, 세번째는 1이다, 아홉번째는 무슨 숫자든 다 들어갈수 있다.\n\n");
				
			}
			system("PAUSE");
		}
		else if(strcmp(potpot,"말을건다") == 0 || strcmp(potpot,"대화") == 0 || strcmp(potpot,"안녕") == 0 ){
			system("cls"); 
			printf("[중앙]-[화분]-[%s]\n\n",potpot);
			printf("당신은 멍청한 두뇌로 꽃에게 인사를 했습니다.\n\n");
			Sleep(1500);
			printf("들려오는 것은 고요함뿐이였습니다.\n\n");
			system("PAUSE");
			pottoking = 1;
		}
		else if(pottoking == 1 && strcmp(potpot,"말을건다") == 0 || pottoking == 1 && strcmp(potpot,"대화") == 0 || pottoking == 1 && strcmp(potpot,"안녕") == 0 ) {
			system("cls"); 
			printf("[중앙]-[화분]-[%s]\n\n",potpot);
			printf("더 이상 당신은 멍청한 짓은 하기 싫습니다\n");
			Sleep(1500);
			printf("설마 뭔가 있겠지 하고 하는 사람은 없겠죠?\n\n");
			system("PAUSE");
		}
		else{
			system("cls"); 
			printf("[중앙]-[화분]\n\n");
			printf("'그 행동은 할 수 없겠군..'\n\n");
			system("PAUSE");
		}
	}
 
}

void paper(){ 	//종이 




	char paperpaper[20];
	while(1){
		system("cls"); 
		printf("[중앙]-[종이]\n\n");
		if(paperskip == 0){
			printf("당신은 땅에 떨어져 있는 종이를 주었습니다.\n");
			Sleep(1000);
			printf("음");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf("그뿐입니다\n");

		}
		else if(paperfin == 1){
			printf("음...");
			Sleep(1000);
			printf("책상 그림과 3326이 적힌...");
			Sleep(1000);
			printf("그냥");
			Sleep(1000);
		} 
		else{
			printf("음...");
			Sleep(1000);
			printf("그냥");
			Sleep(1000); 
		}
		if(titaw == 1 && paperskip == 1){
			printf(" 티타늄종이입니다!\n");
		} 
		else if(paperskip == 1){
			printf(" 종이입니다!\n");
		}
		else{
			printf("");
			paperskip = 1;
		}
		printf("  >>");
		scanf("%s",paperpaper);
		//이벤트 타이핑
		 
		if(paperfin == 0 && strcmp(paperpaper,"보기") == 0 || strcmp(paperpaper,"조사") == 0 ||  strcmp(paperpaper,"살펴보기") == 0 ||  strcmp(paperpaper,"본다") == 0 ||  strcmp(paperpaper,"보다") == 0) {
			system("cls"); 
			printf("[중앙]-[종이]-[%s]\n\n",paperpaper);
			printf("당신은 종이를 자세히 살펴보았습니다\n");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n");
			Sleep(1500);
			
			printf("당신은 자세히보니 숫자와 그림이 그려져있습니다!\n");
			Sleep(1000);
			printf("음");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			
			printf("책상 그림이랑 3326이라는 숫자가 옆에 적혀있다.\n");
			printf("더 특별한건 없다.\n");
			paperfin = 1;
			system("PAUSE");
			
		}
		else if(strcmp(paperpaper,"찢는다")==0 || strcmp(paperpaper,"찢다")==0 || strcmp(paperpaper,"찢기")==0 || strcmp(paperpaper,"가르기")==0){
			system("cls"); 
			printf("[중앙]-[종이]-[%s]\n\n",paperpaper);
			printf("당신은 양팔로 종이를 잡고 힘을 주기 시작했습니다\n");
			Sleep(1500);
			printf("이런! 자세히 보니 티타늄 종이였군요!\n\n");
			titaw = 1;
			 
			system("PAUSE"); 
		}
		else if(fay == 0 && strcmp(paperpaper,"접는다") == 0 || fay == 0 && strcmp(paperpaper,"종이접기") == 0 || fay == 0 && strcmp(paperpaper,"접기") == 0){
			system("cls"); 
			printf("[중앙]-[종이]-[%s]\n\n",paperpaper);
			printf("당신은 순진한 생각으로 종이를 접습니다.\n\n"); 
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n\n");
			Sleep(2000);
			
			printf("당신이 힘드게 만든 종이 비행기를 날렸습니다!\n\n");
			Sleep(1000);
			
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n\n");
			Sleep(2000);
			
			printf("이런! 당신의 허접한 비행기는 얼마 못가 땅에 추락했습니다\n");
			Sleep(1000);
			printf("다시 떨어져 있는 종이가 됬습니다.\n\n");
			system("PAUSE");
			
			fay = 1;
			move();
			 
		} 
		else if(fay == 1 && strcmp(paperpaper,"접는다") == 0 || fay == 1 && strcmp(paperpaper,"종이접기") == 0 || fay == 1 && strcmp(paperpaper,"접기") == 0 ){
			system("mode con cols=53 lines=20 | title 종이접기 어렵네");
			system("cls"); 
			printf("[중앙]-[종이]-[%s]\n\n",paperpaper);
		
			printf("당신은 다시 종이를 접기 시작했습니다\n\n");
			
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n\n");
			Sleep(2000);
			
			printf("이번에는 멋진 학으로 변했습니다!\n 당신은 멀리서 학을 구경합니다.\n\n");
		
			printf(".");
			Sleep(2000);
			printf(".");
			Sleep(2000);
			printf("!\n\n");
			Sleep(2000);
			
			printf("이런! 당신의 허접한 학은 무너졌습니다! 다시 종이가 됬습니다.\n\n");
			printf("당신은 살짝 피어올랐던 동심이 무너졌습니다..\n");
			paperch = "인생쓰다"; 
			system("PAUSE");
			jending--;
			fay = 2; 
			move();
		}
		else if(fay == 2 && strcmp(paperpaper,"접는다") == 0 || fay == 2 && strcmp(paperpaper,"종이접기") == 0 || fay == 2 && strcmp(paperpaper,"접기") == 0 ){
			system("cls"); 
			printf("[중앙]-[종이]-[%s]\n\n",paperpaper);
			printf("당신은 더이상 무엇을 접을지 모릅니다.\n\n");
			system("PAUSE"); 
		}
		else if(strcmp(paperpaper,"돌아가기") == 0 || strcmp(paperpaper,"돌아간다") == 0 || strcmp(paperpaper,"중앙") == 0){		//중앙으로 가는 커맨드 
			system("cls"); 
			printf("[중앙]-[종이]\n\n");
			printf("당신은 다시 처음으로 돌아기로 했습니다.\n\n"); 
			system("PAUSE");
			move(); 
		}
		else{
			system("cls"); 
			printf("[중앙]-[종이]\n\n");
			printf("'그 행동은 할 수 없겠군..'\n\n");
			system("PAUSE");
		}
	}
}

 void Photo(){	//액자 
	char PhotoPhoto[20];
	while(1){
		if(Photoskip == 0){
			system("cls"); 
			printf("[중앙]-[액자]\n\n");
			printf("당신은 벽에 걸려있는 액자로 다가갔습니다\n");
			Sleep(1500);
			printf("음");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf(".");
			Sleep(1500);
			printf("예술은 도저히 이해할 수가 없군요!\n");
			Photoskip = 1;
		}
		else{
			system("cls"); 
			printf("[중앙]-[액자]\n\n");
			printf("음...");
			Sleep(1000);
			printf("당신은 예술을 조금 이해했습니다.\n");
			printf("음...");
			Sleep(2500);
			printf("아무래도 아닌 것 같습니다.\n");
		}
		
		printf(" >>");
		scanf("%s",PhotoPhoto);
		
		if(strcmp(PhotoPhoto,"**") == 0 ){
			
		}
		else if(strcmp(PhotoPhoto,"보기") == 0 || strcmp(PhotoPhoto,"조사") == 0 ||  strcmp(PhotoPhoto,"살펴보기") == 0 ||  strcmp(PhotoPhoto,"본다") == 0 ||  strcmp(PhotoPhoto,"보다") == 0 ){
				system("cls"); 
				printf("[중앙]-[액자]-[%s]\n\n",PhotoPhoto);
				if(Photosee == 0){
					printf("당신은 그림을 자세히 보기 시작했습니다.\n");
					Sleep(1000);
					printf("강아지가 공을 들고?");
					Sleep(1500);
					printf("...아니 공이 강아지를 들고?\n");
					Sleep(2000);
					printf("아무튼 이상한 그림인 것은 확실합니다.\n");
					Photosee = 1;
				}
				else if(Photosee == 1){
					printf("음");
					Sleep(1500);
					printf(".");
					Sleep(1500);
					printf(".");
					Sleep(1500);
					printf("당신은 이 그림의 깊은 뜻을 생각합니다.\n");
					Sleep(1500);
					
					Sleep(1500);
					printf(".");
					Sleep(1500);
					printf(".");
					Sleep(1500);
					
					printf("역시 예술은 이해하는 것이 아닙니다\n");
					
					Photosee = 2;
				} 
				else{
					
					printf("당신은 그림의 깊은 뜻을 이해하지 않기로 했습니다.\n");
					Sleep(1000);
					printf("그 또한 예술이라고 생각합니다.\n");
					Sleep(1000);
				}
				
				printf("\n");
				system("PAUSE");
		}
		else if(strcmp(PhotoPhoto,"찢기")==0 ||strcmp(PhotoPhoto,"던지기")==0 ||strcmp(PhotoPhoto,"망가트리기")==0 ||strcmp(PhotoPhoto,"잡기")==0){
			system("mode con cols=53 lines=20 | title 납치범과대화!");
			system("cls"); 
			printf("[중앙]-[액자]-[%s]\n\n",PhotoPhoto);
			if(Photofin == 0){
				
				printf("당신은 이 의미없는 그림을 회손할려고 했습니다.\n");
				Sleep(2500);
				printf("...어디선가 절규가 들리는군요...건들지 않기로 했습니다.\n"); 
				Sleep(2500);
				photoch ="예술의모독";
				Photofin ++;
				jending--;
				system("PAUSE");
			}
			else{
				printf("당신은 그림을 구경만 하였습니다..");
				system("PAUSE");
				
			}
		}
		else if(strcmp(PhotoPhoto,"그림을뺀다")==0){
			system("cls"); 
			printf("[중앙]-[액자]-[%s]\n\n",PhotoPhoto);
			if(photdel == 0){
				printf("당신은 왜인지 모르겟지만 그림을 한번 빼보았습니다.\n");
				printf("안에는 또 그지같은 종이가 들어있습니다!\n"); 
			}
			else{
				printf("당신은 나쁜 기억력을 가지고 있어서 다시 문제를 보기 시작했습니다.\n");
			}
			printf("'원래는 한 묶음에 52장인 카드가 있다.\n그런데 확인해보니 몇장이 없어졌다.\n없어진 채로 9명에게 똑같이 카드를 나눠줬을더니 2장이 남았다.\n이번에는 4명에게 나눠줬는데 3장이 남고, 7명에게 나눠줬더니 5장이 남았다.\n그럼 없어진 카드는 몇장일까?\n'");
			printf("당신은 이문제가 마지막일거라는 느낌이 든다.\n");
			printf("(공백은 0으로 넣어주세요)\n");
			photdel = 1;
			system("PAUSE");
		}
		else if(strcmp(PhotoPhoto,"돌아가기") == 0 || strcmp(PhotoPhoto,"돌아간다") == 0 || strcmp(PhotoPhoto,"중앙") == 0){		//중앙으로 가는 커맨드 
				system("cls"); 
				printf("[중앙]-[액자]\n\n");
				printf("당신은 다시 처음으로 돌아기로 했습니다.\n\n"); 
				system("PAUSE");
				move(); 
			}
		else{
				system("cls"); 	
				printf("[중앙]-[액자]\n\n");
				printf("'그 행동은 할 수 없겠군..'\n\n");
			
				 system("PAUSE");
			} 
	
	}
}

void ending(){
	char a[20];
	system("cls");
	printf("[중앙]-[엔딩]\n\n");		//	system("PAUSE");  Sleep(2000);
	printf("당신은 천천히 걷기 시작했습니다. 혹시 모르는 함정때문일수도 있습니다.\n");
	Sleep(1500);
	printf("당신은 얼마 걷지 않자 바닥에 권총이 있다는 것을 알아차렸습니다.\n\n");
	Sleep(1500);	
	printf("'...혹시 모르니깐 들고가볼까?'\n\n");
	Sleep(1500);	
	printf("당신은 천천히 걸어갔습니다. 많은 생각이 들었습니다.\n");
	Sleep(1500);
	printf("그 순간 앞에 무언가 반짝하고 빛났습니다. 당신은 그곳을 향해 전력질주로 달렸습니다.\n");
	
	system("PAUSE");
	
	system("cls");
	printf("[중앙]-[엔딩]\n\n");
	printf("터벅.\n'...허억..허억..'\n\n");
	Sleep(1500);
	printf("동시에 나는 발자국소리와 나와 같이 숨고르기를 하는 상대방..\n");
	Sleep(1500);
	printf("상대는 주머니에 있던 권총을 꺼내자, 깜짝놀란 나도 대응 사격을 했습니다.\n");
	Sleep(1500);
	printf("당신은 상황을 읽어보니 상대도 납치된 것이 틀림없습니다..하지만...뭘 할수 있을까요?\n"); 
	printf(" >>");
	scanf("%s",a);
	if(strcmp(a,"대화") == 0 || strcmp(a,"조사") == 0 || strcmp(a,"말") == 0 || strcmp(a,"진정") == 0 || strcmp(a,"침착") == 0){
		printf("당신은 자신은 납치범이 아니다라는 것을 말하기 시작했습니다\n");
		Sleep(1500);
		printf("물론 상대측에서 자꾸 경계심을 안풀어서 쫄렸긴했지만,그럴수록 침착하게 행동하였습니다.\n");
		Sleep(1500);
		printf("서로 경계심이 풀리고 총을 내려 서로에게 대화를 하기 시작했습니다.\n"); 
		printf("물론 이야기가 새버려서 딴 이야기도 좀 했긴 했습니다. .\n");
		Sleep(2000);
		printf("당신은 여기서 나갈지 못나갈지 아무도 몰랐지만, 그래도 당신과 비슷한 처지에 있던 사람을 만나 한편으로 후련했습니다\n");
		Sleep(2000);
		printf("뭐 결국 서로 도와 탈출! 서로 친구!...뭐 뻔한 해피엔딩이네요..");
		exit(1); 
	}
	else{
		printf("당신은 머리속에 무엇을 할지 정했습니다.\n");
		Sleep(1500);
		printf("머리속에 복잡하지 않고 정확했더라면요!\n");
		Sleep(1500);
		printf("당신이 하는 행동은 정리되지 않은 상태로 움직이기 시작했습니다...뭐 상대는 전혀 다르게 생각했나봅니다.\n");
		system("PAUSE");
	} 
	system("cls");
	printf("[중앙]-[엔딩]\n\n");
	printf("'타앙!'\n\n");
	printf("당신은 총을 맞더니 쓰러지기 시작했습니다.\n");
	Sleep(1500);
	printf("아니 총에 맞은게 맞을까요?...그닥 아프지는 않았습니다..\n");
	Sleep(1500);
	printf("그저...고통이 점점 없어지고...");
	Sleep(1500);
	printf("...졸린것...뿐입니다! 별거아니군요!");
	Sleep(1500);
	printf("..음 당신은 천천히 눈을 감기 시작했습니다.\n");
	Sleep(1500);
	printf("눈을 천천히 감을 때마다 고통이 점점 생생해집니다.\n");
	Sleep(1500);
	printf("총을 맞은 곳에 뜨거워지기 시작하고..아퍼지기 시작합니다.\n");
	Sleep(1500);
	printf("당신은 뒤늦게 총을 겨누어 쏘아보았지만..뭐 탄창이 없었네요 하하..\n");
	Sleep(1500);
	printf("뭐 당신은 분명 상대와 '침착'하게 '대화'하거나 상대를 '조사'할려고만 했어도 이상황을 모면할수 있었겠죠.\n");
	Sleep(1500);
	printf("어쩌겠습니까?..당신은 이미 총맞고 쓰러져있는데..\n");
	Sleep(1500);
	printf("신중하게 선택 안한 본인을 탓할수 밖에..\n");
	Sleep(1500);
	printf("그리고 잠시 뒤에 들리는..\n"); 
	system("PAUSE");
	printf("'타앙!'\n");
	Sleep(500);
	printf("'타앙!'\n");
	Sleep(500);
	printf("'타앙!'\n\n");
	Sleep(500);
	printf("'탈칵! 탈칵! '\n\n"); 
	Sleep(500);
	printf("뭐...이제는 진짜 죽었네요\n");
	printf("얼굴에 총이 여러개 박힌 모습은 별로 좋지 않네요....\n 배드엔딩입니다!");
	
	exit(1); 
}
