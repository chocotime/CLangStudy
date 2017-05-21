#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
typedef struct Poketmon {
	char name[20];
	char type[5];
	int hp;
	int maxhp;
	int atk;
} Poketmon;

void travel(int poket_count, Poketmon *my_poket[]);

Poketmon *made (int type_select, int mode) { //user 1, com 0
	int i;
	Poketmon *poketmon = (Poketmon *)malloc(sizeof(Poketmon)); //(Poketmon *)
	char *name[6] = {"파이리", "부케인", "브이젤", "꼬부기", "이상해씨", "치코리타"};
	char *type[6] = {"불", "불", "물", "물", "풀", "풀"};
	if (type_select == 0)
		i = rand() % 6;
	else if (type_select == 1)
		i = rand() % 2;
	else if (type_select == 2)
		i = rand() % 2+2;
	else if (type_select == 3)
		i = rand() % 2+4;
	strcpy(poketmon->name, name[i]);
	strcpy(poketmon->type, type[i]);
	if (mode == 1) {
		poketmon->hp = rand() % 501+500;
		poketmon->atk = rand() % 51+100;
		poketmon->maxhp = poketmon->hp;
	}
	else if (mode == 0) {
		poketmon->hp = rand() % 401+300;
		poketmon->atk = rand() % 101+100;
		poketmon->maxhp = poketmon->hp;
	}
	return poketmon;
}
void start(Poketmon *my_poket[], int poket_count) {
	int type_select;
	printf("==========================\n");
	printf("         포켓몬스터       \n");
	printf(" press Enter key to strat \n");
	printf("==========================\n");
	getchar();

	printf("======================================\n");
	printf("   자네와 함께할 포켓몬을 골라주게!   \n");
	printf("  1. 불 타입  2. 물 타입  3. 풀 타입  \n");
	printf("======================================\n");
	printf("\n");
	
	do {
	printf("입력: ");
	scanf("%d", &type_select);
	} while (type_select <=  0 || type_select > 3);
	
	my_poket[0] = (Poketmon *)malloc(sizeof(Poketmon));
	my_poket[0] = made(type_select, 1);
	
	printf("===========================\n");
	printf("     유저의 포켓몬 정보    \n\n");
	printf("이름 : %s \n", my_poket[0]->name);
	printf("유형 : %s \n", my_poket[0]->type);
	printf("HP : %d/%d \n", my_poket[0]->hp, my_poket[0]->maxhp);
	printf("Attack Power : %d \n", my_poket[0]->atk);
	printf("===========================\n");
	
	poket_count++;
}
void menu(int poket_count, Poketmon *my_poket[]) { //여행 선택
	int menu_select, i;
	
	printf("=====================================\n");
	printf("        여행을 떠나시겠습니까?       \n");
	printf("1. 네 2. 아니오 3. 자고가기(체력회복)\n");
	printf("=====================================\n");

	do {
		printf(">>> ");
		scanf("%d", &menu_select);
	} while (menu_select <= 0 || menu_select > 3);

	if(menu_select == 1)
		travel(poket_count, my_poket); //공격 
	else if(menu_select == 2) {
		printf("다음에 또 만나요!\n");
	}
	else if(menu_select == 3) {
		for(i = 0; i < poket_count; i++)
			my_poket[i]->hp = my_poket[i]->maxhp;
		printf("뚠뚜루뚠뚠뚠~ 체력이 회복되었습니다~\n");
	}
}
void attack(Poketmon *my_poket[], Poketmon *com_poket, int poket_count) {
	//상대방 피깎임
	while(1) {
		printf("%d, %d", com_poket->hp, my_poket[0]->atk);
	if(strcmp(my_poket[0]->type, "불") == 0) {
		if(strcmp(com_poket->type, "불") == 0)
			com_poket->hp -= my_poket[0]->atk;
		else if(strcmp(com_poket->type, "물") == 0) {
			if(rand() % 5) //0이면 거짓 
				com_poket->hp -= (my_poket[0]->atk - (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		else if(strcmp(com_poket->type, "풀") == 0) {
			if(rand() % 5) //0이면 거짓 
				com_poket->hp -= (my_poket[0]->atk + (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		}
			
	if(strcmp(my_poket[0]->type, "물") == 0) {
		if(strcmp(com_poket->type, "물") == 0)
			com_poket->hp -= my_poket[0]->atk;
		else if(strcmp(com_poket->type, "불") == 0) {
			if(rand() % 5) //0이면 거짓 
				com_poket->hp -= (my_poket[0]->atk - (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		else if(strcmp(com_poket->type, "풀") == 0) {
			if(rand() % 5) //0이면 거짓 
				com_poket->hp -= (my_poket[0]->atk + (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		}
		
	if(strcmp(my_poket[0]->type, "풀") == 0) {
		if(strcmp(com_poket->type, "풀") == 0)
			com_poket->hp -= my_poket[0]->atk;
		else if(strcmp(com_poket->type, "물") == 0) {
			if(rand() % 5) //0이면 거짓 
				com_poket->hp -= (my_poket[0]->atk - (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		else if(strcmp(com_poket->type, "불") == 0) {
			if(rand() % 5) //0이면 거짓 
				com_poket->hp -= (my_poket[0]->atk + (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		}
	//죽 살
	if(com_poket->hp < 0) {
		printf("야생의 포켓몬이 쓰러졌다! \n");
		menu(poket_count, my_poket);
		break; //
	}
}/////

	//살 = 상대 반격
	//내피 깎임
	//죽 살
	//살 = 반복 
}
void travel(int poket_count, Poketmon *my_poket[]) {
	int travel_select;
	Poketmon *com_poket;
	com_poket = made(0, 0);
	
	printf("===========================\n");
	printf(" 야생의 포켓몬이 나타나따! \n\n");
	printf("이름 : %s\n", com_poket->name);
	printf("유형 : %s\n", com_poket->type);
	printf("HP : %d/%d\n", com_poket->hp, com_poket->maxhp);
	printf("Attack Power : %d\n\n", com_poket->atk);
	printf("1. 공격 2. 도망치기 3. 잡기\n");
	printf("===========================\n");

	do {
		printf(">>> ");
		scanf("%d", &travel_select);
	} while (travel_select <= 0 || travel_select > 3);

	if(travel_select == 1) {
		printf("공격!!!\n");
		attack(my_poket,com_poket, poket_count);
	}
	else if(travel_select == 2)
		printf("도망친다!!!\n");
	else
		printf("잡는다!\n");
}
int main() {
	int poket_count = 0; 
	srand((unsigned)time(NULL));
	Poketmon *my_poket[6];
	start(my_poket, poket_count);
	menu(poket_count, my_poket);
}
