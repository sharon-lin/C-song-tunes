#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "link_list.h"

void print_list(song_node *node) {

  if (node){
    song_node *tmp = node;
  
    while(tmp != NULL) {
      printf("\n'%s' by %s", tmp->name, tmp->artist);
      tmp = tmp->next;
    }
    printf("\n");
  }
}

void print_node(song_node *node){
  if (node) printf("'%s' by %s\n", node->name, node->artist);
  else printf("**Song does not exist**\n");
}

int list_len(song_node* node){
  int len = 0;
  while (node){
    len++;
    node = node->next;
  }
  return len;
}

void clear_list(song_node *node) {
  if (node->next) {
    node->next = 0;
    clear_list(node->next);
  }
}

song_node* insert_front(song_node *node, char *newArtist, char *newName){
  //initializes song node to be added
  song_node *parent = (song_node *)malloc(sizeof(song_node));
  //assigns values to artist and song name
  strncpy(parent->artist, newArtist, 256);
  strncpy(parent->name, newName, 256);
  parent->next = node;
  return parent;
}

song_node* insert_after(song_node *node, char *newArtist, char *newName){
  song_node *parent = (song_node *)malloc(sizeof(song_node));
  strncpy(parent->artist, newArtist, 256);
  strncpy(parent->name, newName, 256);
  parent->next = 0;
  node->next = parent;
  return parent;
}

int song_cmp(song_node *node, char *artist, char *name){
  //compares songs by artist
  int by_artist = strcmp(node->artist, artist);
  if (by_artist == 0){
    //compares songs by name
    return strcmp(node->name, name);
  }
  return by_artist;
}

song_node* insert_ordered(song_node *node, char *newArtist, char *newName){
  if (!node)
    return insert_front(node, newArtist, newName);
  if (strcmp(newArtist, node->artist) < 0)
    return insert_front(node, newArtist, newName);
  if (strcmp(newArtist, node->artist) == 0 && strcmp(newName, node->name) < 0)
    return insert_front(node, newArtist, newName);
  else
    node->next = insert_ordered(node->next, newArtist, newName);
  
  return node;
}

song_node* insert(song_node *node, char *newArtist, char *newName){
  song_node *temp = node;
  return insert_ordered(temp, newArtist, newName);
}

song_node* free_list(song_node *node){
  song_node *tmp = node;

  if (node){
    while (node) {
      node = node->next;
      printf("Freeing node: '%s' by %s\n", tmp->name, tmp->artist);
      free(tmp);
      tmp = node;
    }
  }
  return node;
}

song_node* find_song(song_node *node, char *name){
  while (node){
    //if keyword matches song name
    if (strstr(node->name, name)) break;
    node = node->next;
  }
  return node;
}

song_node* find_artist_song(song_node *node, char *artist){
  while (node){
    //if keyword matches artist name
    if (strstr(node->artist, artist)) break;
    node = node->next;
  }
  return node;
}

song_node* random_pointer(song_node *node){
  if (node){
    int len = list_len(node);
    int seed = rand() % len;
    for (len = 0; len<seed; len++)
      node = node->next;
  }
  return node;
}

song_node* remove_node(song_node *node){
  song_node* curNode = node;
  song_node* prevNode = NULL;
  while (curNode){
    //if the song nodes are the same
    if(song_cmp(curNode, node->artist, node->name) == 0){
      if(prevNode==NULL){
	//remove first nod
	curNode = curNode->next;
	free(node);
	return curNode;
      }
      else{
	//skips over curNode and then assigns the next to the prevNode
	prevNode->next = curNode->next;
	free(curNode);
	curNode = prevNode->next;
	break;
      }
    }
    else{
      //continues search
      prevNode = curNode;
      curNode = curNode->next;
    }
  }
  return node;
}

song_node* remove_node2(song_node *node, int index){
  int len = list_len(node);
  song_node* curNode = node;
  //if index is out of range
  if (index < 0 || index > len-1) return node;
  //removal
  if (!index) {
    curNode = node->next;
    free(node);
  } else {
    //continue
    while (index - 1) {
      node = node->next;
      index--;
    }
    //removes in middle
    song_node* newChild = node->next->next;
    free(node->next);
    node->next = newChild;
  }
  return curNode;
}
