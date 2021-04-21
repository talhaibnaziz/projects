/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tourism_app;
import java.sql.*;
/**
 *
 * @author talha
 */
public class Tourism_App {

    public static Object [][]sql2DData;
    public static Object []sql1DData;
    public static String []sqlstringData;
    public static byte[][] image;
    public static int imagecount;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        HomePage home = new HomePage();
        home.setVisible(true);
        //adminpage ap = new adminpage();
        //ap.setSize(1366, 760);
        //ap.setVisible(true);
        //UserForm uf = new UserForm();
        //uf.setSize(1366, 760);
        //uf.setVisible(true);
        //BookingFrame bf = new BookingFrame();
        //bf.setSize(1366, 760);
        //bf.setVisible(true);
        /*getConnection gc = new getConnection();
        gc.set1DData("SELECT location from accomodation group by location");
        gc.set2DData("SELECT * from accomodation");
        for(int i=0; i<2; i++)   System.out.printf("%s\t", sql1DData[i]);
        System.out.println();
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<sql2DData[0].length; j++)
            {
                System.out.printf("%s\t", sql2DData[i][j]);
            }
            System.out.println();
        }*/
    }
    
}
