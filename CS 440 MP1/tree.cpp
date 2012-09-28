// MP1 - CS440 Pathfinding
// Rafael Rego Drumond

#include "master.h"

TreeNode * startTree (int x, int y)
{
    TreeNode * tn;
    tn = (TreeNode *) malloc(sizeof(TreeNode));
    if (tn==NULL) exit(-1);

    tn->posx        = x;
    tn->posy        = y;
    tn->steps       = 0;
    tn->level       = 1;
    tn->father      = NULL;
    tn->fatherdir   = -1;
    tn->childs = (TreeNode *) malloc (sizeof(TreeNode)*4);
    if (childs==NULL) exit(-1);
    tn->isFinal     = FALSE;
    tn->cost        = 0;

    return tn;
}

TreeNode * insertNode(int x, int y, int st, int lv, TreeNode * ft, int ftd, int isf, int cost)
{
    TreeNode * tn;
    tn->posx        = x;
    tn->posy        = y;
    tn->steps       = st;
    tn->level       = lv;
    tn->father      = ft;
    tn->fatherdir   = ftd;
    tn->childs = (TreeNode *) malloc (sizeof(TreeNode)*4);
    if (childs==NULL) exit(-1);
    tn->isFinal     = isf;
    tn->cost        = cost;

    return tn;
}
