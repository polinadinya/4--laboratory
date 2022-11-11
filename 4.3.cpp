#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <locale.h>
#include <windows.h>
#pragma warning (disable:6054)

struct tree {
	int data;
	struct tree* right;
	struct tree* left;
};

struct tree* root = NULL;

//  функция создания дерева
struct tree* CreateTree(struct tree* root, struct tree* r, int data)
{
	if (r == NULL)
	{
		r = (struct tree*)malloc(sizeof(struct tree));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(1);
		}
		r->right = NULL;
		r->left = NULL;
		r->data = data;
		if (root == NULL)
			return r;
		if (data > root->data)
			root->right = r;
		else root->left = r;
		return r;
	}
	if (data > r->data)
		CreateTree(r, r->right, data);
	else if (data < r->data) CreateTree(r, r->left, data);
	else return root;
	return root;
}

//  функция вывода дерева на экран
void print_tree(struct tree* r, int l)
{
	if (r == NULL)
	{
		return;
	}
	print_tree(r->left, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}
	printf("%d\n", r->data);
	print_tree(r->right, l + 1);
}

int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;
	printf("-1 - окончание построения дерева\n");
	while (start)
	{
		printf("Введите число: ");
		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);
	}
	print_tree(root, 0);
	return 0;
}
