#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 200

typedef struct {
	int key;
}element;

//���� ����ü 
typedef struct Heap {
	element array[MAX_HEAP_SIZE];//heap �迭
	int size;
}Heap;

//���� ���� �Լ�
Heap* create() {
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->size = 0;
	return heap;
}

//�� ����� ��ġ�� �ٲٴ� �Լ�
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int insert(Heap* heap, element value) {
	int i = ++(heap->size);
	heap->array[i] = value;

	int count = 0; //�湮�� ��� ����
	//ó�� ��忡 ���� ������ �迭 ���
	for (int j = 1; j <= heap->size; j++) {
		printf("%d ", heap->array[j]);
	}
	printf("\n");

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϸ� ��ġ ����
	while ((i != 1) && (value.key > heap->array[i / 2].key)) {
		heap->array[i] = heap->array[i / 2];
		i /= 2;
		heap->array[i] = value;
		for (int k = 1; k <= heap->size; k++)
		{
			printf("%d ", heap->array[k].key);
		}
		printf("\n");

		count++;
	}

	return count;
}

//Ư�� ��带 �����ϴ� �Լ�
int delete(Heap* heap, int value) {
	int count = 0; //ã�� ����� �ε���

	int delete_index, child_index; //������ �ε����� �ڽ� �ε��� ����
	int	temp = heap->array[(heap->size)--].key;

	//ã�� ����� ���� �ε����� ���ϱ�
	for (int i = 1; i <= heap->size; i++) {
		if (heap->array[i].key == value) {
			delete_index = i;
			child_index = 2 * i;
		}
	}

	// ã�� ��带 �������� �ʰ� ���� �籸��
	while (child_index <= heap->size) {
		// ���� ����� �ڽ� ��� �� �� ū �ڽ� ��带 ã�´�.
		if ((child_index < heap->size) && (heap->array[child_index].key < heap->array[child_index + 1].key)) {
			child_index++;
		}
		while (temp >= heap->array[child_index].key) {
			break;
		}

		heap->array[delete_index] = heap->array[child_index];
		delete_index = child_index;
		child_index *= 2;

		for (int k = 1; k <= heap->size; k++)
		{
			printf("%d ", heap->array[k].key);
		}
		printf("\n");

		count++; // �湮�� ����� Ƚ�� ����
	}
	heap->array[delete_index].key = temp;

	return count; // �湮�� ����� �� Ƚ���� ��ȯ
}

void insert_menu(Heap* heap) {
	element data;
	int value, count = 0;
	printf("�߰��� �� �Է� : ");
	scanf("%d", &value);
	data.key = value;
	count = insert(heap, data);
	printf("�湮�� ����� Ƚ�� : %d\n", count);
}

void delete_menu(Heap* heap) {
	int value, count = 0;
	printf("������ �� �Է� : ");
	scanf("%d", &value);
	count = delete(heap, value);
	printf("�湮�� ����� Ƚ�� : %d\n", count);
}

// �������� ����ϴ� �Լ�
void levelOrder(Heap* heap) {
	int currentLevel = 1; // ���� ����
	int levelStartIndex = 1; // ���� ������ ù ��° ��� �ε���

	for (int i = 1; i <= heap->size; i++) {
		if (i == levelStartIndex) {
			printf("[%d] ", currentLevel);
			currentLevel++;
			levelStartIndex = i * 2;
		}
		printf("%d ", heap->array[i].key);
		if (i == levelStartIndex - 1) {
			printf("\n");
		}
	}
	printf("\n");
}

void menu() {
	printf("----------------------\n");
	printf("| i   : ��� �߰�    |\n");
	printf("| d   : ��� ����    |\n");
	printf("| p   : ������ ���  |\n");
	printf("| c   : ����         |\n");
	printf("----------------------\n");
}

int main() {
	//������ ���� �� ����
	element e1 = { 90 }, e2 = { 89 }, e3 = { 70 }, e4 = { 36 }, e5 = { 75 }, e6 = { 63 }, e7 = { 65 }, e8 = { 21 }, e9 = { 18 }, e10 = { 15 };

	//���� ����
	Heap* heap = create();
	insert(heap, e1);
	insert(heap, e2);
	insert(heap, e3);
	insert(heap, e4);
	insert(heap, e5);
	insert(heap, e6);
	insert(heap, e7);
	insert(heap, e8);
	insert(heap, e9);
	insert(heap, e10);

	menu(); // �޴� �����ֱ�
	char choice; // �޴� �Է� ����

	while (1)
	{
		printf("�޴� �Է� : ");
		scanf(" %c", &choice);

		switch (choice)
		{
			//��� �߰�
		case 'i':
			insert_menu(heap);
			printf("\n");
			break;
			//��� ����
		case 'd':
			delete_menu(heap);
			printf("\n");
			break;
			//������ ���
		case 'p':
			levelOrder(heap);
			printf("\n");
			break;
		}
		if (choice == 'c')
		{
			printf("����\n");
			break;
		}
	}

	free(heap);
	return 0;
}