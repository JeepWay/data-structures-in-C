#define INIT_PARENT -1

typedef struct set {
    int* parent;
    int* count;
    int* height;
    int size;
} Set;

Set* createSet(int size);

int findSet(Set* set, int x);

int findSetAndCompress(Set* set, int x);

void unionSetNormal(Set* set, int x, int y);

void unionSetByWeight(Set* set, int x, int y);

void unionSetByHeight(Set* set, int x, int y);

int countSetNodes(Set* set, int x);

int countSetNumbers(Set* set);

void freeSet(Set* set);
