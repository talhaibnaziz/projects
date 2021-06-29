/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author TASNEEA
 */
public class Driver {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        	BFS bfs = new BFS();
		bfs.start(new State());
		bfs.printPath();
		System.out.println("Done!");
    }
    
}
