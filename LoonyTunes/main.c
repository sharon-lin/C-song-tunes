#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "link_list.h"
#include "music_library.h"

int main(){
  //seed
  srand(time(NULL));

  //MAIN TESTS

  printf("*****Music:\n");
  add_song("Mos Def", "Quiet Dog");
  add_song("Neil Diamond", "If You Go Away");
  add_song("Bora York", "Open Tales");
  add_song("Len", "Steal My Sunshine");
  add_song("Sonic Youth", "Kool Thing");
  add_song("Neil Diamond", "Song Sung Blue");
  add_song("M83", "Gone");
  add_song("Nancy Sinatra", "Some Velvet Morning");
  add_song("Animotion", "Obsession");
  add_song("Animotion", "Room to Move");
  add_song("Bora York", "Let Loose");
  add_song("Rick Astley", "Never Gonna Give You Up");
  print_library();
  printf("\n");
  
  printf("\n*****Finding Songs:\n");
  printf("\nSong Query: 'Kool'\n");
  find_song2("Kool");
  printf("\nSong Query: 'Mov'\n");
  find_song2("Mov");
  printf("\nSong Query: 'Rami'\n");
  find_song2("Rami");

  printf("\n*****Finding Artist Songs\n");
  printf("\nArtist Query: 'Bora'\n");
  find_artist_song2("Bora");
  printf("\nArtist Query: 'Anim'\n");
  find_artist_song2("Anim");
  printf("\nArtist Query: 'Christian'\n");
  find_artist_song2("Christian");
    
  printf("\n*****Printing Letters:\n");
  print_letter('e');
  print_letter('v');
  print_letter('a');
  print_letter('n');
  print_letter('c');
  
  printf("\n******Printing by Artists:\n");
  print_artist("Bora York");
  print_artist("Neil Diamond");
  print_artist("Rick Astley");

  printf("\n******Everyday I'm Shuffling:\n");
  shuffle();
  shuffle();

  printf("\n******Deleting:\n");
  print_library();
  remove_song("Len", "Steal My Sunshine");
  remove_song("Sonic Youth", "Kool Thing");
  remove_song("The Invisible Hand", "BloopityBlob");
  printf("\n");

  printf("\n******Clearing all the things\n");
  print_library();
  printf("\n\n");
  clear_library();
  print_library();
  printf("\n");
  

  //TESTS FOR LINKED LIST
  /*
  
  //creating list
  song_node *node = insert_front(NULL, "Neil Diamond", "If You Go Away");
  node = insert_ordered(node, "Bora York", "Open Tales");  
  node = insert_ordered(node, "Len", "Steal My Sunshine");
  node = insert_ordered(node, "Sonic Youth", "Kool Thing");
  node = insert_ordered(node, "Neil Diamond", "Song Sung Blue");
  node = insert_ordered(node, "Pixies", "Where Is My Mind");
  
  //printing list
  printf("Music:\n");
  print_list(node);
  
  //finding song
  printf("\nSong Query: Kool\n");
  print_node(find_song(node, "Kool"));
  printf("\nSong Query: Song\n");
  print_node(find_song(node, "Song"));
  printf("\nSong Query: Doggy\n");
  print_node(find_song(node, "Doggy"));

  //finding artist
  printf("\nArtist Query: Diamond\n");
  print_node(find_artist_song(node, "Diamond"));
  printf("\nArtist Query: Pix\n");
  print_node(find_artist_song(node, "Pix"));
  printf("\nArtist Query: Cats\n");
  print_node(find_artist_song(node, "Cats"));

  //random song
  int i = 0;
  for (; i < 3; i++) {
    printf("\nRandom song:\n");
    print_node(random_pointer(node));
  }

  //remove songs
  printf("\nRemoving song 0...\n");
  print_list(node = remove_node2(node,0));
  printf("\nRemoving song 3...\n");
  print_list(node = remove_node2(node,3));
  printf("\nAttempting to remove song 100\n");
  print_list(node = remove_node2(node,100));

  // Freeing the List - Verified with valgrind
  free_list(node);
  */
  return 0;
}
