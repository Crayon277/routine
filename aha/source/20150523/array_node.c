#include<stdio.h>
#include<stdlib.h>
#define vectex 4
#define edge 5

int main(){

  int i,k;
  int vec_out[edge],
    vec_in[edge],
    weight[edge];
  int first[vectex],
    next[edge];
  
  //scanf("%d%d",&vectex,&edge);
	FILE* fp = fopen("./test2.txt","r"); 
  for(i = 0 ; i< edge ; i++){
    //fgets(buf,sizeof(buf),stdin);
    //fflush(stdin);
	
    fscanf(fp,"%d%d%d",&vec_out[i],&vec_in[i],&weight[i]);
	printf("%d %d %d\n",vec_out[i],vec_in[i],weight[i]);
  }

  for(i = 0 ;i<vectex;i++){
    first[i] = -1;
  }
  //test first
	for(i = 0 ; i < vectex ;i++){
		printf("%d\n",first[i]);
	}
//test end
  for(i = 0; i< edge ;i ++){
    next[i] = first[vec_out[i]];
    first[vec_out[i]] = i;
	printf("%d %d %d\n",first[vec_out[i]],next[i],vec_out[i]);
  }

  printf("=======first=======\n");
  for(i = 0 ;i < vectex;i++){
    printf("%d\n",first[i]);
  }
  printf("=======first end ===\n");


  printf("======edge ========\n");
  for(i = 0 ;i<edge ;i++){
    printf("%d\n",next[i]);
  }
  printf("======edge end======\n");
  
  for(i=0;i< vectex;i++){
    k = first[i];
    while(k!=-1){
      printf("%d %d %d\n",vec_out[k],vec_in[k],weight[k]);
      k = next[k];
    }
  }

  return 0;
  
}
