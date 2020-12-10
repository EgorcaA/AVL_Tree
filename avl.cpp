//
// Created by egorcaa on 07.12.2020.
//

#include "avl.h"
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;




node::node(int k ){ key = k; left = right = 0; height = 1; }

node::node(){ key = 0; left = right = 0; height = 1; }

node *MakeTree(){
    node *p;
    p=new node;
    return p;
}




int height(node* p)
{
	return p?p->height:0;
}

int bfactor(node* p)
{
	return height(p->right)-height(p->left);
}

void fixheight(node* p)
{
	int hl = height(p->left);
	int hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}


node* rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // балансировка узла p
{
	fixheight(p);
	if( bfactor(p)==2 )
	{
		if( bfactor(p->right) < 0 )
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if( bfactor(p)==-2 )
	{
		if( bfactor(p->left) > 0  )
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}




node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if( !p ) return new node(k);
	if( k<p->key )
		p->left = insert(p->left,k);
	else
		p->right = insert(p->right,k);
	return balance(p);
}


node* findmin(node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left?findmin(p->left):p;
}

node* removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if( p->left==0 )
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}


node* remove(node* p, int k) // удаление ключа k из дерева p
{
	if( !p ) return 0;
	if( k < p->key )
		p->left = remove(p->left,k);
	else if( k > p->key )
		p->right = remove(p->right,k);	
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if( !r ) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

node* find(node* p, int k) // поиск ключа k в дереве p
{
    if( !p ) return 0; // в пустом дереве можно не искать
    if( k == p->key )
        return p; 
    if( k < p->key )
        return find(p->left,k); 
    else
        return find(p->right,k); 
}

void bfs(node *p){
        std::queue< node* > que;
        que.push(p);
        while (!que.empty()) {
            node *cur = que.front();
            std::cout << cur->key <<' ';
            que.pop();
            if(cur->left !=0 ){
                que.push(cur->left);
            }
            if(cur->right !=0 ){
                que.push(cur->right);
            }
            }
    }



