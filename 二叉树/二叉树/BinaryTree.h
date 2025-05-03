#pragma once
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cassert>
typedef char DataType;

typedef struct BTNode
{
	struct BTNode* right;
	struct BTNode* left;
	DataType x;
}BTNode;

void Init(BTNode* root);

void Destroy(BTNode* root);

BTNode* CreatNewnode(DataType x);

void PrevOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

int TreeSize(BTNode* root);

int TreeLeafSize(BTNode* root);