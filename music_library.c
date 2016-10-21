#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "music_library.h"

void add_song(char *artist, char *name){
  //subtracting value of 'a' from value of first letter
  char letter = tolower(artist[0]) - 'a'+1;
  printf("Adding '%s' by %s...\n", name, artist);
  table[letter] = insert(table[letter], artist, name);
}

song_node* find_song2(char *name){
  int i=0;
  song_node *temp = 0;
  //searches each row of table
  while(!temp && i++ < 26)
    //searches through entries in row
    temp = find_song(table[i], name);
  if (temp == NULL){
    printf("\n<Song not found>\n");
    return temp;
  }
  print_list(temp);
  return temp;
}

song_node* find_artist_song2(char *artist){
  song_node *temp = table[tolower(artist[0]) - 'a'+1];
  temp = find_artist_song(temp, artist);
  if (!temp){
    printf("\n<Song not found>\n");
    return temp;
    }
    print_node(temp);
  return temp;
}

void print_letter(char letter){
  printf("%c list:", toupper(letter));
  print_list(table[tolower(letter)-'a'+1]);
  printf("\n\n");
}

void print_library(){
  printf("\nLibrary:");
  int i=0;
  while(i++ < 26)
    print_list(table[i]);
}

void print_artist(char *artist){
  printf("%s list:\n", artist);
  song_node *l = find_artist_song(table[tolower(artist[0])-'a'+1], artist);
  while(l && strncmp(artist, l->artist, 1) == 0) {
    if(strcmp(l->artist, artist) == 0)
      printf("*' %s' by  %s\n", l->name, l->artist);
    l = l->next;
  }
  printf("\n");
}

void remove_song(char *artist, char *name){
  printf("\n\nDeleting '%s' by %s", name, artist);
  table[tolower(artist[0])-'a'+1] = remove_node(find_song(table[tolower(artist[0])-'a'+1], name));
  print_library();
}

void clear_library(){
  int i=0;
  while(i++ < 26)
    if (table[i] != NULL)
      table[i] = free_list(table[i]);
}

void shuffle(){
  printf("Shuffled:\n");
  song_node *temp = 0;
  int i=0;
  while(i++ < 26) {
    song_node *a = table[i];
    while(a) {
      temp = insert_front(temp, a->artist, a->name);
      a = a->next;
    }
  }
  while(temp) {
    song_node *rand = random_pointer(temp);
    printf("'%s'- by %s\n", rand->name, rand->artist);
    temp = remove_node(find_song(temp, rand->name));
  }
  printf("\n");
}
