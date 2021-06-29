
import java.util.ArrayList;

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

    public int[] obj;

    public State() {
        obj = new int[7];
        obj[0] = obj[1] = obj[2] = obj[3] = obj[4] = obj[5] = obj[6] = 0;
    }

    public State(int mis1, int mis2, int mis3, int can1, int can2, int can3, int boat) {
        obj = new int[7];
        obj[0] = mis1;
        obj[1] = mis2;
        obj[2] = mis3;
        obj[3] = can1;
        obj[4] = can2;
        obj[5] = can3;
        obj[6] = boat;
    }

    public ArrayList<State> generateNextState() {
        //////////////  State ret[] = new State[36]; ///ekhane bhul hocche maybe? nullpointerException 
        ArrayList<State> ret = new ArrayList<>();
        State s1 = new State(obj[0], obj[1], obj[2], obj[3], obj[4], obj[5], obj[6]);
        if (obj[6] == 0) {
            State s = new State(obj[0], obj[1], obj[2], obj[3], obj[4], obj[5], obj[6]);
            s.obj[6] = 1;
            System.out.println("ja add kortesi" + s.obj[0] + s.obj[1] + s.obj[2] + s.obj[3] + s.obj[4] + s.obj[5]);
            ret.add(s); //boat ta k onno prante pathalam i. e 0 to 1
            for (int i = 0; i < 6; i++) {
                ///   s= new State(obj[0],obj[1],obj[2],obj[3],obj[4],obj[5],obj[6]);
                s = new State(obj[0], obj[1], obj[2], obj[3], obj[4], obj[5], obj[6]);
                s.obj[6] = 1;
                s.obj[i] = (s.obj[i] == 0 ? 1 : 1);
                System.out.println("ja add kortesi outer" + s.obj[0] + s.obj[1] + s.obj[2] + s.obj[3] + s.obj[4] + s.obj[5]);
                ret.add(s);
                // State s2=new State();
                State s2 = s;
                System.out.println("outer loop er s2 er obostha" + s2.obj[0] + s2.obj[1] + s2.obj[2] + s2.obj[3] + s2.obj[4] + s2.obj[5]);
                ////    s1=s;

                // }S
                //  ret.add(s);
                for (int j = i + 1; j < 6; j++) {
                    // if(s.obj[j]!=1){
                     s2 = s;
                    // s2.obj[j]=1;
                    //  System.out.println("inner loop er s2 er obostha"+s2.obj[0]+s2.obj[1]+s2.obj[2]+s2.obj[3]+s2.obj[4]+s2.obj[5]);
                       int a = s2.obj[j];
                    s2.obj[j] = (s2.obj[j] == s2.obj[i] ? s2.obj[j] : s2.obj[i]);

                    System.out.println("ja add kortesi inner" + s2.obj[0] + s2.obj[1] + s2.obj[2] + s2.obj[3] + s2.obj[4] + s2.obj[5]);
                    ret.add(s2);
                    //s2=s;
                    if(a==1){}
                    else s2.obj[j]=0;
                }
            }
        }
        //    }
        //  }

        return ret;
        // }
    }

    public boolean isIllegalState() {
        if (obj[0] + obj[1] + obj[2] < obj[3] + obj[4] + obj[5]) { ///# missionary has to be greater than #cannibals
            return true;
        } else {
            return false;
        }
    }

    @Override
    public String toString() {
        return "" + obj[0] + obj[1] + obj[2] + obj[3] + obj[4] + obj[5] + obj[6];
    }

}
