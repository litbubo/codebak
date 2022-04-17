// test20210106.1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int m = 0;
int judge = 1;

template <class T>
struct BiNode   //�������Ľ��ṹ
{
	T data;
	BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree
{ //��������
public:
	BiTree();											//���캯��������������չ��������ǰ�����й��������
	BiNode<T>* Getroot();								//���ָ�������ָ��
	void PreOrder(BiNode<T> *root);					    //ǰ������������ݹ�
	void InOrder(BiNode<T> *root);						//��������������ݹ�
	void PostOrder(BiNode<T> *root);				    //��������������ݹ�
	void InsetTree(BiNode<T> *root,BiNode<T> *tree);
private:
	BiNode<T> *root;									//ָ�������ͷָ��
	BiNode<T> *Creat();								    //�޲ι��캯������
};


template<class T>
BiTree<T>::BiTree()
{
	root = Creat();
}

template <class T>
BiNode<T>* BiTree <T>::Creat()
{
	BiNode<T>* root;
	T ch; 
	cout << "������ֵ�Ͷ�������";
	cout << "Input a number: ";
	cin >> ch;
	if (ch == 99)     root = NULL;
	else {
		root = new BiNode<T>;
		root->data = ch;
		root->lchild = Creat();
		root->rchild = Creat();
	}
	return root;
}

BiNode<char>* BiTree <char>::Creat()
{
	BiNode<char>* root;
	char ch;
	cout << "�����ַ��Ͷ�������";
	cout << "Input a char: ";
	cin >> ch;
	if (ch == '#')     root = NULL;
	else {
		root = new BiNode<char>;
		root->data = ch;
		root->lchild = Creat();
		root->rchild = Creat();
	}
	return root;
}


template<class T>
BiNode<T>* BiTree<T>::Getroot()
{
	return root;
}

template<class T>
void BiTree<T>::PreOrder(BiNode<T> *root)
{
	if (root == NULL)  return;
	else {
		cout << root->data << " ";
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

template <class T>
void BiTree<T>::InOrder(BiNode<T> *root)
{
	if (root == NULL)  return;						 //�ݹ���õĽ�������
	else {
		InOrder(root->lchild);						 //����ݹ����root��������
		cout << root->data << " ";					 //���ʸ�����������
		InOrder(root->rchild);						 //����ݹ����root��������
	}
}

template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{
	if (root == NULL)   return;						 //�ݹ���õĽ�������
	else {
		PostOrder(root->lchild);					 //����ݹ����root��������
		PostOrder(root->rchild);					 //����ݹ����root��������
		cout << root->data << " ";					 //���ʸ�����������
	}
}

template <class T>
void Count(BiNode<T> *root, int &n)					 //nΪȫ�������ѳ�ʼ��Ϊ0
{//�������������
	if (root)
	{
		Count(root->lchild, n);
		n++;
		Count(root->rchild, n);
	}
}

template <class T>
int CountNodes(BiNode<T> *root)
{//�������������
	int n = 0;
	Count(root, n);
	return n;
}

template <class T>
void Count1(BiNode<T>* root, int& m)				//nΪȫ�������ѳ�ʼ��Ϊ0
{//�������Ҷ�ӽ�����
	if (root)
	{
		if (!root->lchild && !root->rchild)
			m++;
		Count1(root->lchild, m);
		Count1(root->rchild, m);
	}
}

template <class T>
int Count1Nodes(BiNode<T>* root)
{//�������Ҷ�ӽ�����
	int m = 0;
	Count1(root, m);
	return m;
}

template <class T>
int  Depth(BiNode<T> *root)
{//��������ĸ߶�
	if (root == NULL) return 0;
	else
	{
		int hl = Depth(root->lchild);
		int hr = Depth(root->rchild);
		return hl>hr ? hl + 1 : hr + 1;
	}
}

template <class T>
void BiTree<T>::InsetTree(BiNode<T> *root, BiNode<T> *tree)
{
	if (root == NULL)
		return;
	else
	{
		if (judge)
			if (root != NULL)
			{
				if (root->lchild == NULL)
				{
					root->lchild = tree;
					judge = 0;
				}
				if (judge)
					if (root->rchild == NULL)
					{
						root->rchild = tree;
						judge = 0;
					}
			}
		InsetTree(root->lchild, tree);
		InsetTree(root->rchild, tree);
	}
}


int main()
{
	BiNode<char> * root;
	BiTree<char> bt; //����һ�ö�����
	root = bt.Getroot();  //��ȡָ�������ָ��
	cout << "------ǰ�����------ " << endl;
	bt.PreOrder(root);
	cout << endl;
	cout << "------�������------ " << endl;
	bt.InOrder(root);
	cout << endl;
	cout << "------�������------ " << endl;
	bt.PostOrder(root);
	cout << endl;
	cout << "Number of nodes=" << CountNodes(root) << endl;
	cout << "Leaf-nodes are " << Count1Nodes(root) << endl;
	cout << "Depth=" << Depth(root) << endl;
	BiNode<char>* root2;
	BiTree<char> bt2; //����һ�ö�����
	root2 = bt2.Getroot();  //��ȡָ�������ָ��
	cout << "------ǰ�����------ " << endl;
	bt2.PreOrder(root2);
	cout << endl;
	cout << "------�������------ " << endl;
	bt2.InOrder(root2);
	cout << endl;
	cout << "------�������------ " << endl;
	bt2.PostOrder(root2);
	cout << endl;
	cout << "Number of nodes=" << CountNodes(root2) << endl;
	cout << "Leaf-nodes are " << Count1Nodes(root2) << endl;
	cout << "Depth=" << Depth(root2) << endl;
	bt.InsetTree(root,root2);
	cout << "------ǰ�����------ " << endl;
	bt.PreOrder(root);
	cout << endl;
	cout << "------�������------ " << endl;
	bt.InOrder(root);
	cout << endl;
	cout << "------�������------ " << endl;
	bt.PostOrder(root);
	cout << endl;
	cout << "Number of nodes=" << CountNodes(root) << endl;
	cout << "Leaf-nodes are " << Count1Nodes(root) << endl;
	cout << "Depth=" << Depth(root) << endl;
	system("pause");
	return 0;
}
