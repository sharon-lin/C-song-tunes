#include <stdio.h>
#include <stdlib.h>

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node *table[26];




