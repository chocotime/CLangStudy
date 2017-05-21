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
	char *name[6] = {"���̸�", "������", "������", "���α�", "�̻��ؾ�", "ġ�ڸ�Ÿ"};
	char *type[6] = {"��", "��", "��", "��", "Ǯ", "Ǯ"};
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
	printf("         ���ϸ���       \n");
	printf(" press Enter key to strat \n");
	printf("==========================\n");
	getchar();

	printf("======================================\n");
	printf("   �ڳ׿� �Բ��� ���ϸ��� ����ְ�!   \n");
	printf("  1. �� Ÿ��  2. �� Ÿ��  3. Ǯ Ÿ��  \n");
	printf("======================================\n");
	printf("\n");
	
	do {
	printf("�Է�: ");
	scanf("%d", &type_select);
	} while (type_select <=  0 || type_select > 3);
	
	my_poket[0] = (Poketmon *)malloc(sizeof(Poketmon));
	my_poket[0] = made(type_select, 1);
	
	printf("===========================\n");
	printf("     ������ ���ϸ� ����    \n\n");
	printf("�̸� : %s \n", my_poket[0]->name);
	printf("���� : %s \n", my_poket[0]->type);
	printf("HP : %d/%d \n", my_poket[0]->hp, my_poket[0]->maxhp);
	printf("Attack Power : %d \n", my_poket[0]->atk);
	printf("===========================\n");
	
	poket_count++;
}
void menu(int poket_count, Poketmon *my_poket[]) { //���� ����
	int menu_select, i;
	
	printf("=====================================\n");
	printf("        ������ �����ðڽ��ϱ�?       \n");
	printf("1. �� 2. �ƴϿ� 3. �ڰ���(ü��ȸ��)\n");
	printf("=====================================\n");

	do {
		printf(">>> ");
		scanf("%d", &menu_select);
	} while (menu_select <= 0 || menu_select > 3);

	if(menu_select == 1)
		travel(poket_count, my_poket); //���� 
	else if(menu_select == 2) {
		printf("������ �� ������!\n");
	}
	else if(menu_select == 3) {
		for(i = 0; i < poket_count; i++)
			my_poket[i]->hp = my_poket[i]->maxhp;
		printf("�Ӷѷ�ӶӶ�~ ü���� ȸ���Ǿ����ϴ�~\n");
	}
}
void attack(Poketmon *my_poket[], Poketmon *com_poket, int poket_count) {
	//���� �Ǳ���
	while(1) {
		printf("%d, %d", com_poket->hp, my_poket[0]->atk);
	if(strcmp(my_poket[0]->type, "��") == 0) {
		if(strcmp(com_poket->type, "��") == 0)
			com_poket->hp -= my_poket[0]->atk;
		else if(strcmp(com_poket->type, "��") == 0) {
			if(rand() % 5) //0�̸� ���� 
				com_poket->hp -= (my_poket[0]->atk - (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		else if(strcmp(com_poket->type, "Ǯ") == 0) {
			if(rand() % 5) //0�̸� ���� 
				com_poket->hp -= (my_poket[0]->atk + (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		}
			
	if(strcmp(my_poket[0]->type, "��") == 0) {
		if(strcmp(com_poket->type, "��") == 0)
			com_poket->hp -= my_poket[0]->atk;
		else if(strcmp(com_poket->type, "��") == 0) {
			if(rand() % 5) //0�̸� ���� 
				com_poket->hp -= (my_poket[0]->atk - (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		else if(strcmp(com_poket->type, "Ǯ") == 0) {
			if(rand() % 5) //0�̸� ���� 
				com_poket->hp -= (my_poket[0]->atk + (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		}
		
	if(strcmp(my_poket[0]->type, "Ǯ") == 0) {
		if(strcmp(com_poket->type, "Ǯ") == 0)
			com_poket->hp -= my_poket[0]->atk;
		else if(strcmp(com_poket->type, "��") == 0) {
			if(rand() % 5) //0�̸� ���� 
				com_poket->hp -= (my_poket[0]->atk - (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		else if(strcmp(com_poket->type, "��") == 0) {
			if(rand() % 5) //0�̸� ���� 
				com_poket->hp -= (my_poket[0]->atk + (my_poket[0]->atk)/10);
			else
				com_poket->hp -= my_poket[0]->atk;
			}
		}
	//�� ��
	if(com_poket->hp < 0) {
		printf("�߻��� ���ϸ��� ��������! \n");
		menu(poket_count, my_poket);
		break; //
	}
}/////

	//�� = ��� �ݰ�
	//���� ����
	//�� ��
	//�� = �ݺ� 
}
void travel(int poket_count, Poketmon *my_poket[]) {
	int travel_select;
	Poketmon *com_poket;
	com_poket = made(0, 0);
	
	printf("===========================\n");
	printf(" �߻��� ���ϸ��� ��Ÿ����! \n\n");
	printf("�̸� : %s\n", com_poket->name);
	printf("���� : %s\n", com_poket->type);
	printf("HP : %d/%d\n", com_poket->hp, com_poket->maxhp);
	printf("Attack Power : %d\n\n", com_poket->atk);
	printf("1. ���� 2. ����ġ�� 3. ���\n");
	printf("===========================\n");

	do {
		printf(">>> ");
		scanf("%d", &travel_select);
	} while (travel_select <= 0 || travel_select > 3);

	if(travel_select == 1) {
		printf("����!!!\n");
		attack(my_poket,com_poket, poket_count);
	}
	else if(travel_select == 2)
		printf("����ģ��!!!\n");
	else
		printf("��´�!\n");
}
int main() {
	int poket_count = 0; 
	srand((unsigned)time(NULL));
	Poketmon *my_poket[6];
	start(my_poket, poket_count);
	menu(poket_count, my_poket);
}
