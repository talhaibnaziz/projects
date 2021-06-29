/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author TASNEEA
 */

public class BFS {
	Queue<State> Q;
	HashSet<String> visited;
	
	LinkedList<ArrayList<String>> paths;
	ArrayList<String> shortest_path;
	
	public BFS()
	{
		Q = new LinkedList<>();
		visited = new HashSet<>();
		paths = new LinkedList<>();
	}
	
	public void printPath()
	{
		for (String s : shortest_path)
		{
			System.out.println(s);
		}
	}
	
	public void start(State start)
	{
		Q.add(start);
		
		ArrayList<String> r = new ArrayList<>();/// arraylist holo dynamic, ekhane string er arraylist nicche
		r.add(start.toString()); /// start holo ekta state type er object,jetake string e convert kore r e dhukano hocche
		paths.add(r); ///LinkedList<ArrayList<String>> paths;
		
		visited.add(start.toString()); ///HashSet<String> visited; add kore jacche jeta visit kortese
		while (Q.size() != 0)
		{
			State u = Q.poll();
               ///      System.out.println("Q theke poll kore ja ber hocche"+u.obj[0]+u.obj[1]+u.obj[2]+u.obj[3]+u.obj[4]+u.obj[5]+u.obj[6]);
			shortest_path = paths.poll();
			if (u.toString().equals("1111111"))
				return;
				//System.out.println("Found end");
			////////State v_list[] = u.generateNextState();
                        ArrayList<State> v_list =u.generateNextState();
                ///        System.out.println("v list"+v_list.toString());
			for (State v : v_list)
			{
                          //  System.out.println("v state"+v.toString());
                        ///////////    if(v!=null) ///null pointer exception ashtese bole
                           // {	
                            if (visited.contains(v.toString()))
					continue;
				if (v.isIllegalState())
					continue;
                            
				visited.add(v.toString());
				Q.add(v);
				
				ArrayList<String> r1 = new ArrayList<>(shortest_path);
				r1.add(v.toString());
				paths.add(r1);
                        //    }
                            //else System.out.println(v); //null print kore dekhtesi
                        
			}
		}
	}
}
