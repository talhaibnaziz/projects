/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tourism_app;
import java.sql.*;
import javax.swing.JOptionPane;
/**
 *
 * @author talha
 */
public class getConnection {
    private static final String CONNECTION =
                          "jdbc:mysql://localhost/talha?autoReconnect=true&useSSL=false";
    Connection c;
    Statement st;
    ResultSet rs;
    PreparedStatement ps;
    
    public void set2DData(String q)
    {
        
        try{
            c = DriverManager.getConnection(CONNECTION, "root", "shahriar");
            st = c.createStatement();
            rs = st.executeQuery(q);
            ResultSetMetaData metaData = rs.getMetaData();
            int col = metaData.getColumnCount();
            int row;
            int i=0;
            while(rs.next())    i++;
            row=i;
            Tourism_App.sql2DData = new Object[row][col];
            //System.out.println(row+" "+col);
            rs = st.executeQuery(q);
            i=0;
            while(rs.next())
            {
                i++;
                for(int j=1; j<=col; j++)
                {
                    Tourism_App.sql2DData[i-1][j-1] = rs.getObject(j);
                    //System.out.printf("%s\t", Tourism_App.sqlData[i-1][j-1]);
                }
                //System.out.println();
            }
        }
        catch(SQLException se){
          //Handle errors for JDBC
          JOptionPane.showMessageDialog(null, se);
        }
        finally
        {
            try
            {
                rs.close();
                st.close();
                c.close();
            }
            catch(SQLException se)
            {
                JOptionPane.showMessageDialog(null, se);
            }
        }
    }
    public void set1DData(String q)
    {
        
        try{
            c = DriverManager.getConnection(CONNECTION, "root", "shahriar");
            st = c.createStatement();
            rs = st.executeQuery(q);
            int row;
            int i=0;
            while(rs.next())    i++;
            row=i;
            Tourism_App.sql1DData = new Object[row];
            //System.out.println(row+" "+col);
            rs = st.executeQuery(q);
            i=0;
            while(rs.next())
            {
                i++;
                Tourism_App.sql1DData[i-1] = rs.getObject(1);
                //System.out.printf("%s\t", Tourism_App.sql1DData[i-1]);
            }
            //System.out.println();
        }
        catch(SQLException se){
          //Handle errors for JDBC
          se.printStackTrace();
        }
        finally
        {
            try
            {
                rs.close();
                st.close();
                c.close();
            }
            catch(SQLException se)
            {
                se.printStackTrace();
            }
        }
    }
    public void setstringData(String q)
    {
        
        try{
            c = DriverManager.getConnection(CONNECTION, "root", "shahriar");
            st = c.createStatement();
            rs = st.executeQuery(q);
            int row;
            int i=0;
            while(rs.next())    i++;
            row=i;
            Tourism_App.sqlstringData = new String[row];
            //System.out.println(row+" "+col);
            rs = st.executeQuery(q);
            i=0;
            while(rs.next())
            {
                i++;
                Tourism_App.sqlstringData[i-1] = rs.getString(1);
                //System.out.printf("%s\t", Tourism_App.sql1DData[i-1]);
            }
            //System.out.println();
        }
        catch(SQLException se){
          //Handle errors for JDBC
          se.printStackTrace();
        }
        finally
        {
            try
            {
                rs.close();
                st.close();
                c.close();
            }
            catch(SQLException se)
            {
                se.printStackTrace();
            }
        }
    }
    public void setImageData(String q)
    {
        
        try{
            c = DriverManager.getConnection(CONNECTION, "root", "shahriar");
            st = c.createStatement();
            rs = st.executeQuery(q);
            int i=0;
            Tourism_App.image = new byte[20][];
            while(rs.next())
            {
                Tourism_App.image[i] = rs.getBytes("image");
                //System.out.println(Tourism_App.image.length);
                //System.out.printf("%s\t", Tourism_App.sql1DData[i-1]);
                i++;
            }
            Tourism_App.imagecount = i;
            //System.out.println();
        }
        catch(SQLException se){
          //Handle errors for JDBC
          se.printStackTrace();
        }
        finally
        {
            try
            {
                rs.close();
                st.close();
                c.close();
            }
            catch(SQLException se)
            {
                se.printStackTrace();
            }
        }
    }
    public void insertData(String q)
    {
        
        try{
            c = DriverManager.getConnection(CONNECTION, "root", "shahriar");
            ps = c.prepareStatement(q);
            
            ps.execute();
            //System.out.println();
        }
        catch(SQLException se){
          //Handle errors for JDBC
          JOptionPane.showMessageDialog(null, se);
        }
        finally
        {
            try
            {
                ps.close();
                c.close();
            }
            catch(SQLException se)
            {
                JOptionPane.showMessageDialog(null, se);
            }
        }
    }
}//end of class
