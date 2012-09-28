// MP1 - CS440 Pathfinding
// Rafael Rego Drumond

typedef struct _TreeNode_{

    //Position of the node in maze
    int posx;
    int posy;

    //steps taken to get to this node
    int steps;

    //tree level of the node
    int level;

    //pointer to the node father
    struct _TreeNode_ * father;

    //where father came from
    int fatherdir;

    //possible childs of the node (UP, DOWN, LEFT, RIGHT)
    struct _TreeNode_ * childs;

    //if this node is final
    int isFinal;

    //cost to get here
    int cost;

}TreeNode;

TreeNode * startTree (int, int);
TreeNode * insertNode(int, int, int, int, TreeNode *, int, int, int);
