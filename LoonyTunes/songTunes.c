#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

void print_list(song_node *n){
  while (n){
    printf("[%s, %s]\n", n->artist, n->name);
    n = n->next;
  }
}

// insert_front: adds before the current node

song_node* insert_front(song_node *curNode, char *newArtist, char *newName){
  song_node *newNode = (song_node *)malloc(sizeof(song_node));
  
  strncpy(newNode->artist, newArtist, 256);
  strncpy(newNode->name, newName, 256);

  newNode->next = curNode;

  return newNode;

  /*  if (pList->firstNode == NULL){
    pList->firstNode = newNode;
    newNode->next = NULL;
  }

  else{
    song_node *pos = pList->firstNode;
    for(; pos->next; pos=pos->next);
    pos->next = newNode;
    newNode->next = NULL;
  }*/
}

int song_cmp(song_node* curNode, char *artist, char *name){
  int artist_cmp = strcmp(curNode->artist, artist);
  if (artist_cmp == 0) return strcmp(curNode->name, name);
  return artist_cmp;
}

song_node* insert_ordered(song_node *curNode, char *newArtist, char *newName){
  if (song_cmp(curNode, newArtist, newName) > 0) return insert_front(curNode, newArtist, newName);
  else{
    song_node *before = curNode;
    song_node *after = curNode->next;
    while(1){
      if (after == 0){
	song_node *last = (song_node *)malloc(sizeof(song_node));
	strncpy(last->artist, newArtist, 256);
	strncpy(last->name, newName, 256);

	last->next = 0;
	before->next = last;
	break;
      }
      if (song_cmp(after, newArtist, newName) > 0){
	after->next = insert_front(after, newArtist, newName);
	break;
      }
      before = after;
      after = after->next;
    }
    return curNode;
  }
}

song_node* find_by_name(song_node* curNode, char* name){
  while (curNode){
    if (strcmp(curNode->name, name) == 0) return curNode;
    curNode = curNode->next;
  }
  return 0;
}

song_node* find_by_artist(song_node* curNode, char* artist){
  while (curNode){
    if (strcmp(curNode->artist, artist) == 0) return curNode;
    curNode = curNode->next;
  }
  return 0;
}

song_node* delete_node(song_node* curNode, song_node* remove){
  if (song_cmp(curNode, remove->artist, remove->name) == 0) return remove->next;
  while (curNode){
    if (song_cmp(
  }
}

int main(){
  printf("TESTING PRINTING\n");
  
  song_node *songs = insert_front(0, "rihanna", "baby");;
  //  song_node *song1 = insert_front(songs, "justin", "woop");
  song_node *song2 = insert_ordered(songs, "rihanna", "abrac");
  song_node *song3 = insert_ordered(song2, "justin", "woop");
  print_list(song3);

  //  song_node *table[26];

  /*
  song_node *Foo = (song_node *)malloc(sizeof(song_node));

  char *newArtist = "rihanna";
  char *newName = "baby baby";
  
  Foo->artist = malloc(strlen(newArtist)+1);
  strcpy(Foo->artist, newArtist);

  Foo->name = malloc(strlen(newName)+1);
  strcpy(Foo->name, newName);

  list *firstList = (list *)malloc(sizeof(list));
  
  //  append_list(firstList, newArtist, newName);
  
  printf("[%s, %s]\n",Foo->artist,Foo->name);

  song_node *Foo = (song_node *)malloc(sizeof(song_node));
  Foo->next = 0; Foo->name = "song"; Foo->artist = "artist";
  printf("Foo: ");
  print_list(Foo);

  printf("***TESTING FIND****\n");

  printf("***TESTING FIND_ARTIST2***\n");

  printf("***TESTING PRINT_LETTER***\n");

  printf("***TESTING REMOVE_SONG***\n");

  printf("***TESTING PRINT_ARTIST***\n");

  printf("***TESTING SHUFFLE***\n");
  */
}
