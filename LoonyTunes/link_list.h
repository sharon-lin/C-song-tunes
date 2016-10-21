#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;
 
// ==========================================
// Headers

void print_list(song_node *node);
void print_node(song_node *node);
int list_len(song_node *node);
void clear_list(song_node *node);
song_node* insert_front(song_node *node, char *newArtist, char *newName);
song_node* insert_ordered(song_node *node, char *newArtist, char *newName);
song_node* insert(song_node *node, char *newArtist, char *newName);
song_node* free_list(song_node *node);
song_node* find_song(song_node *node, char *name);
song_node* find_artist_song(song_node *node, char *artist);
song_node* random_pointer(song_node *node);
song_node* remove_node(song_node *node);
song_node* remove_node2(song_node *node, int index);

#endif
