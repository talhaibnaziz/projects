/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pacman;

    
/**
 *
 * @author talha
 */
public class PACMAN {

    static boolean state[][] = new boolean[100][100], load=false, custom=false;
    static int score=0, x=0, y=0;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        //mazeset ms = new mazeset();
        //ms.setVisible(true);
        //ms.setSize(1366, 760);
        Menu menu = new Menu();
        menu.setVisible(true);
        //gamescreen gc = new gamescreen();
        //gc.setVisible(true);
        //gc.setSize(1366, 760);
    }
    
}