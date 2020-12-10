//
// Created by egorcaa on 07.12.2020.
//

#ifndef MYT_AVL_H
#define MYT_AVL_H

struct node // структура для представления узлов дерева
{
        int key;
        int height;
        node* left;
        node* right;
        node(int k);
        node();
};

node *MakeTree();

int height(node* p);

int bfactor(node* p);

void fixheight(node* p);

node* rotateright(node* p);

node* rotateleft(node* q);

node* balance(node* p);

node* insert(node* p, int k);

node* findmin(node* p);

node* removemin(node* p);

node* remove(node* p, int k);

node* find(node* p, int k);

void bfs(node *p);



#endif //MYT_AVL_H


