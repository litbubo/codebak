// test20210106.1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int m = 0;
int judge = 1;

template <class T>
struct BiNode   //二叉树的结点结构
{
	T data;
	BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree
{ //二叉树类
public:
	BiTree();											//构造函数，键盘输入扩展二叉树的前序序列构造二叉树
	BiNode<T>* Getroot();								//获得指向根结点的指针
	void PreOrder(BiNode<T> *root);					    //前序遍历二叉树递归
	void InOrder(BiNode<T> *root);						//中序遍历二叉树递归
	void PostOrder(BiNode<T> *root);				    //后序遍历二叉树递归
	void InsetTree(BiNode<T> *root,BiNode<T> *tree);
private:
	BiNode<T> *root;									//指向根结点的头指针
	BiNode<T> *Creat();								    //无参构造函数调用
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
	cout << "创建数值型二叉树：";
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
	cout << "创建字符型二叉树：";
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
	if (root == NULL)  return;						 //递归调用的结束条件
	else {
		InOrder(root->lchild);						 //中序递归遍历root的左子树
		cout << root->data << " ";					 //访问根结点的数据域
		InOrder(root->rchild);						 //中序递归遍历root的右子树
	}
}

template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{
	if (root == NULL)   return;						 //递归调用的结束条件
	else {
		PostOrder(root->lchild);					 //后序递归遍历root的左子树
		PostOrder(root->rchild);					 //后序递归遍历root的右子树
		cout << root->data << " ";					 //访问根结点的数据域
	}
}

template <class T>
void Count(BiNode<T> *root, int &n)					 //n为全局量并已初始化为0
{//求二叉树结点个数
	if (root)
	{
		Count(root->lchild, n);
		n++;
		Count(root->rchild, n);
	}
}

template <class T>
int CountNodes(BiNode<T> *root)
{//求二叉树结点个数
	int n = 0;
	Count(root, n);
	return n;
}

template <class T>
void Count1(BiNode<T>* root, int& m)				//n为全局量并已初始化为0
{//求二叉树叶子结点个数
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
{//求二叉树叶子结点个数
	int m = 0;
	Count1(root, m);
	return m;
}

template <class T>
int  Depth(BiNode<T> *root)
{//求二叉树的高度
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
	BiTree<char> bt; //创建一棵二叉树
	root = bt.Getroot();  //获取指向根结点的指针
	cout << "------前序遍历------ " << endl;
	bt.PreOrder(root);
	cout << endl;
	cout << "------中序遍历------ " << endl;
	bt.InOrder(root);
	cout << endl;
	cout << "------后序遍历------ " << endl;
	bt.PostOrder(root);
	cout << endl;
	cout << "Number of nodes=" << CountNodes(root) << endl;
	cout << "Leaf-nodes are " << Count1Nodes(root) << endl;
	cout << "Depth=" << Depth(root) << endl;
	BiNode<char>* root2;
	BiTree<char> bt2; //创建一棵二叉树
	root2 = bt2.Getroot();  //获取指向根结点的指针
	cout << "------前序遍历------ " << endl;
	bt2.PreOrder(root2);
	cout << endl;
	cout << "------中序遍历------ " << endl;
	bt2.InOrder(root2);
	cout << endl;
	cout << "------后序遍历------ " << endl;
	bt2.PostOrder(root2);
	cout << endl;
	cout << "Number of nodes=" << CountNodes(root2) << endl;
	cout << "Leaf-nodes are " << Count1Nodes(root2) << endl;
	cout << "Depth=" << Depth(root2) << endl;
	bt.InsetTree(root,root2);
	cout << "------前序遍历------ " << endl;
	bt.PreOrder(root);
	cout << endl;
	cout << "------中序遍历------ " << endl;
	bt.InOrder(root);
	cout << endl;
	cout << "------后序遍历------ " << endl;
	bt.PostOrder(root);
	cout << endl;
	cout << "Number of nodes=" << CountNodes(root) << endl;
	cout << "Leaf-nodes are " << Count1Nodes(root) << endl;
	cout << "Depth=" << Depth(root) << endl;
	system("pause");
	return 0;
}
