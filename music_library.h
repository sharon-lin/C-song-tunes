#include "link_list.h"

void add_song(char *artist, char *name);
song_node* find_song2(char *name);
song_node* find_artist_song2(char *artist);
void print_letter(char letter);
void print_library();
void print_artist(char *artist);
void remove_song(char *artist, char *name);
void clear_library();
void shuffle();

song_node *table[26];
