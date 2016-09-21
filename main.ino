#include "LinkedList.h"

void setup(){
  Serial.begin(9600);
  Node<int>* root = create_node(0);
  
  for(int i=0; i<50; i++){
    Node<int>* nx = create_node(i);
    insert_node_first(root, nx);
  }
  
  remove_node_last(root);  
  display_list_serial(root);

  

}

void loop(){
  Serial.println(get_list_size(root));
  delay(2000);
}
