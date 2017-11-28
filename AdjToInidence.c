//Maximum size of the Adjacency matrix is 10x10
//No. of components is retricted to 1


#include<stdio.h>

int n=0;          //no. of vertices
int X[10][10];    //Adjacency matrix
int A[10][10];    //Incidence matrix
int edge=0;       //no. of edges

void readMatrix(); //reads Adjacency matrix
void AdjToInc();  //Creates the Incidence matrix from Adjacency matrix
void display();   //displays Incidence matrix


void main(){

  printf("How many vertices in the graph?\n");
  scanf("%d",&n);
  printf("Enter the adjacency matrix:\n");
  readMatrix();
  AdjToInc();
  printf("\nThe corresponding Incidence matrix is:\n");
  display();
  printf("\nNo. of edges = %d\n",edge );

}

void readMatrix(){

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&X[i][j]);
    }
  }
}

void AdjToInc(){
  //Read half of the Adjacency matrix
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(X[i][j] && i!=j){
        A[i][edge]=1;
        A[j][edge]=1;
        edge++;
      }
    }
  }
  //Set all non-1 elements to 0
  for(int i=0;i<n;i++)
    for(int j=0;j<edge;j++)
      if(A[i][j]!=1)
        A[i][j]=0;
}

void display(){
  for(int i=0;i<n;i++){
    printf("\n");
    for(int j=0;j<edge;j++){
      printf("%d ",A[i][j]);
    }
  }
}
