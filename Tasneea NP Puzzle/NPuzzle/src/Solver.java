
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author TASNEEA
 */
public class Solver {
    public State start, target;
    public Solver(int array[][])
    {
        start = new State(array);
        int [][] tarray = new int[4][4];
        tarray[0][0] = 1; tarray[0][1] = 2; tarray[0][2] = 3; tarray[0][3] = 4;
        tarray[1][0] = 5; tarray[1][1] = 6; tarray[1][2] = 7; tarray[1][3] = 8;
        tarray[2][0] = 9; tarray[2][1] = 10; tarray[2][2] = 11; tarray[2][3] = 12;
        tarray[3][0] = 13; tarray[3][1] = 14; tarray[3][2] = 15; tarray[3][3] = 0;
        target = new State(tarray);
    }
    public void solve()
    {
        Queue <State> q = new LinkedList<>();
        q.add(start);
        int cnt = 0;
        while(!q.isEmpty() && cnt<100)
        {
            cnt++; System.out.println("this is queue: "+cnt);
            State currentState = q.poll();
            ArrayList <State> nextStates = currentState.generateNextState();
            System.out.println(nextStates.size());
            for(int i=0; i<nextStates.size(); i++)
            {
                State s = nextStates.get(i);
                if(s.check(target))   return;
                q.add(s);
            }
        }
    }
}
