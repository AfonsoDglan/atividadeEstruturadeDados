#include "stack.h"
#include <stdio.h>

int main(){
  int y,temp;
  char x;
  Stack* parkingOne = Stack_create();
  Stack* parkingTwo = Stack_create();
  while(1){
    scanf("%s ",&x);
    scanf("%d",&y);
    if(x == '0' && y == 0){
      break;
    }else if(x == 'i'){
      if(!Stack_push(parkingOne, y)){
        puts("Overflow");
      }
    }else if(x == 'r'){
      while(1){
        if(Stack_pop(parkingOne,&temp)){
          printf("%d, ", temp);
          if(temp != y){
            Stack_push(parkingTwo,temp);
          }else{
            printf("\n");
            break;
          }
        }else{
          puts("Underflow");
          break;
        }
      }
      while(Stack_pop(parkingTwo,&temp)){
        Stack_push(parkingOne,temp);
      }
    }else{
      puts("Entrada inválida.");
    }
  }
  return 0;
}