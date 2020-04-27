

import java.util.*;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author TASNEEA
 */
public class State {
    
    int [][] array;
   
    int g_score =1 ; // protitar g_score from the adjacent is 1 shei hishabe dhore
    int parent;
    int f_score;
    int SwapperX,SwapperY;
    State(){
            array = new int [4][4];
            parent =0;
            
    
    }
    State(int [][]array1){
        array = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
               array[i][j]=array1[i][j];
                
            }
        }
    
    }
    public ArrayList<State> generateNextState(State s){
            ArrayList<State> ret = new ArrayList<>();
            
      int coordX=0,coordY=0;
            for (int i = 0; i <4; i++) {
                for (int j = 0; j < 4; j++) {
                   if(s.array[i][j]==0){
                       //coord save korlam jekhane space ase
                   coordX=i;
                   coordY=j;
                   }
                    
                }
            
        }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j <4; j++) {
                    
                    if(i==coordX && j==coordY){
                            if(i==0){ //jodi space 0 row te thake
                                if(j==0){swap(s,0,0,0,1); //0,0 position e space thakle
                                ret.add(s);
                            //    System.out.println("ary bhitor"+s.array[0][0]);
                               swap(s,0,0,0,1);
                               
                               swap(s,1,0,0,0);
                               ret.add(s);
                                swap(s,1,0,0,0);
                              // System.out.println("ary bhitor abr"+s.array[0][0]);
                                }
                                else if(j==3){
                                swap(s,0,3,0,2);
                                ret.add(s);
                                 swap(s,0,3,0,2);
                                  swap(s,1,3,0,3);
                                  ret.add(s);
                                  swap(s,1,3,0,3);
                                }
                                else{ //3ta wala 
                                swap(s,i,j,i,j-1);
                                ret.add(s);
                                swap(s,i,j,i,j-1);//ager jaigai anlam
                                swap(s,i,j,i,j+1);
                                ret.add(s);
                                swap(s,i,j,i,j+1);
                                swap(s,i,j,i+1,j);
                                ret.add(s);
                                swap(s,i,j,i+1,j);
                                
                                }
                            }
                            else if(i==3){
                            if(j==0){
                            swap(s,3,0,2,0);
                            ret.add(s);
                            swap(s,3,0,2,0);
                            swap(s,3,0,3,1);
                            ret.add(s);
                            swap(s,3,0,3,1);
                            }
                            else if(j==3){
                            swap(s,3,3,2,3);
                            ret.add(s);
                             swap(s,3,3,2,3);//swap back
                              swap(s,3,3,3,2);
                              ret.add(s);
                              swap(s,3,3,3,2);
                            }
                            
                            else{   //3ta wala
                                swap(s,i,j,i,j-1);
                                ret.add(s);
                                 swap(s,i,j,i,j-1);
                                  swap(s,i,j,i,j+1);
                                  ret.add(s);
                                  swap(s,i,j,i,j+1);
                                  swap(s,i,j,i-1,j);
                                  ret.add(s);
                                  swap(s,i,j,i-1,j);
                                  
                            
                            }
                            
                            }
                            else if(i==1 || i==3){
                            if(j==0){
                            swap(s,i,j,i-1,j);
                            ret.add(s);
                            swap(s,i,j,i-1,j);
                            swap(s,i,j,i+1,j);
                            ret.add(s);
                             swap(s,i,j,i+1,j);
                              swap(s,i,j,i,j+1);
                              ret.add(s);
                               swap(s,i,j,i,j+1);
                            }
                            else if(j==3){
                            swap(s,i,j,i-1,j);
                            ret.add(s);
                             swap(s,i,j,i-1,j);
                             
                             swap(s,i,j,i+1,j);
                             ret.add(s);
                             swap(s,i,j,i+1,j);
                             
                             swap(s,i,j,i,j-1);
                             ret.add(s);
                             swap(s,i,j,i,j-1);
                                   
                            }
                            else
                            {
                                swap(s,i,j,i-1,j);
                                ret.add(s);
                                swap(s,i,j,i-1,j);
                                
                                swap(s,i,j,i+1,j);
                                ret.add(s);
                                swap(s,i,j,i+1,j);
                                
                                swap(s,i,j,i,j-1);
                                ret.add(s);
                                swap(s,i,j,i,j-1);
                             
                                   swap(s,i,j,i,j+1);
                                   ret.add(s);
                                    swap(s,i,j,i,j+1);
                                
                            }
                            }
                    
                    }
                }
            
        }
            
            
       // swap(s,0,0,0,1);
         // System.out.println("ary "+s.array[0][0]);
       
//   System.out.println("coord"+coordX+ " "+coordY);
            
        
    return ret;
        
    }
  public State swap(State s,int pos1,int pos2,int pos3,int pos4){
   int temp=s.array[pos1][pos2];
   array[pos1][pos2]=array[pos3][pos4];
   array[pos3][pos4]=temp;
      return s;
  
  }
    /*
    public void toString(State s){
    
        System.out.println("printing next states: ");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <4; j++) {
                System.out.print(s.array[i][j]);
            }
            System.out.println();
        }
    
}*/
    
  
   }
          

