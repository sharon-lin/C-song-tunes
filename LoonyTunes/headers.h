// HEADER FILE  
// ===========================================
// Struct definition

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;
 
typedef struct list{
  song_node *firstNode;
} list;

// ==========================================
// Headers

void print_list(song_node *n);
//void append_list(List *list, char *artist, char *name);
void clear_list(song_node *n);
song_node* insert_front(song_node *curNode, char *newArtist, char *newName);
song_node* insert_ordered(song_node *curNode, char *newArtist, char *newName);
song_node* free_list(song_node *n);

/*
int add_song();

int find_artist2();

void print_letter();

void print_artist();

void print_library();

int shuffle();

int delete_song();

*/
