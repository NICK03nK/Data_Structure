#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Queue.h"

BTNode* CreateTree();

void DestroyTree(BTNode** root);

int BTSize(BTNode* root);

int BTLeavesSize(BTNode* root);

int BTLevelKSize(BTNode* root, BTDataType k);

int BTHight(BTNode* root);

BTNode* BTFind(BTNode* root, BTDataType x);

void BTPrevOrder(BTNode* root);

void BTInOrder(BTNode* root);

void BTPostOrder(BTNode* root);

void BTLevelOrder(BTNode* root);

bool IsBinaryTree(BTNode* root);