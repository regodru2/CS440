// MP1 - CS440 Pathfinding
// Rafael Rego Drumond

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dungeon.h"
#include "tree.h"
#include "search1.h"

#define UP     0
#define DOWN   1
#define LEFT   2
#define RIGHT  3

#define WALL   37
#define FLOOR  2
#define START  3
#define GOAL   4
#define WALKED 5

#define TRUE   1
#define FALSE  0
