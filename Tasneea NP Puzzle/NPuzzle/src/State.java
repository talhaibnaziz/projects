
import java.util.ArrayList;
import java.util.Iterator;

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
    
    public int [][] array;
    int x, y;
   
    int g_score =1 ; // protitar g_score from the adjacent is 1 shei hishabe dhore
    int parent;
    
    State(int input[][]){
            array = new int [4][4];
            parent =0;
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    array[i][j] = input[i][j];
                    if(array[i][j]==0)
                    {
                        x = i;
                        y = j;
                    }
                }
            }
    }
    public ArrayList<State> generateNextState(){
        ArrayList<State> ret = new ArrayList<>();
        int [] dirx = new int [4];
        int [] diry = new int [4];
        dirx[0]=0; dirx[1]=0; dirx[2]=1; dirx[3]=-1;
        diry[0]=1; diry[1]=-1; diry[2]=0; diry[3]=0;
        for(int i=0; i<4; i++)
        {
            int newx, newy;
            newx = x + dirx[i];
            newy = y + diry[i];
            if(newx >=0 && newy>=0 && newx<4 && newy<4)
            {
                State newState = new State(this.array);
                newState.swap(x, y, newx, newy);
                ret.add(newState);
                newState.toString(newState);
            }
        }
        
        return ret;
    }
    public void swap(int x1, int y1, int x2, int y2)
    {
        int a = this.array[x1][y1];
        int b = this.array[x2][y2];
        this.array[x1][y1] = b;
        this.array[x2][y2] = a;
        if(a==0)
        {
            x = x2;
            y = y2;
        }
        else
        {
            x = x1;
            y = y1;
        }
    }
    public void toString(State s){
        System.out.println("printing board states: ");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <4; j++) {
                System.out.print(s.array[i][j]+" ");
            }
            System.out.println();
        }
    }
    public boolean check(State s)
    {
        boolean same = true;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j <4; j++)
                if(s.array[i][j]!=this.array[i][j]) same = false;
        return same;
    }
}