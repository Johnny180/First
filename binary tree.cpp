#include <iostream> 
#include<fstream>
struct nod
{
	int info;
	nod* stanga;
	nod* dreapta;
};
struct Arbore
{
	nod* root;
	Arbore()
	{
		root = NULL;
	}
	int search(int *v, int start, int end, int value)
	{
		for (int i = start; i <= end; i++)
		{
			if (v[i] == value)
				return i;
		}
	}
	nod* newNod(int data)
	{
		nod* Node = new nod();
		Node->info = data;
		Node->stanga = NULL;
		Node->dreapta = NULL;
		return (Node);
	}
	nod* construire(int *in, int *pre, int inStart, int inEnd)
	{
		static int preIndex = 0;
		if (inStart > inEnd)
			return NULL;
		nod* tNode = newNod(pre[preIndex++]);
		if (inStart == inEnd)
			return tNode;
		int inIndex = search(in, inStart, inEnd, tNode->info);
		tNode->stanga = construire(in, pre, inStart, inIndex - 1);
		tNode->dreapta = construire(in, pre, inIndex + 1, inEnd);
		return tNode;
	}
	void printInorder(nod* node)
	{
		if (node == NULL)
			return;
		printInorder(node->stanga);
		std::cout << node->info << " ";
		printInorder(node->dreapta);
	}
};
void fcin(int *&in, int *&pre, int &size)
{
	int i;
	std::ifstream f("Tema3 ex6.in");
	f >> size;
	in = new int[size];
	pre = new int[size];
	for (i = 0; i < size; i++)
		f >> in[i];
	for (i = 0; i < size; i++)
		f >> pre[i];
}
int main()
{
	Arbore T;
	int *inz, *prez, size = 0;
	fcin(inz, prez, size);
	T.root = T.construire(inz, prez, 0, size - 1);
	T.printInorder(T.root);
	system("pause");
}