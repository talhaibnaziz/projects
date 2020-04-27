
import java.awt.Font;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author TASNEEA
 */
public class GUI {
    public static void main(String[] args) {
         JPanel p = new JPanel(new GridBagLayout());
   JLabel label = new JLabel("sdfdgfdg");
   label.setFont(new Font("Tahoma",Font.BOLD,20));
              JFrame J =  new JFrame("NPuzzle");
           
try{
    J.setContentPane(new JLabel(new ImageIcon(ImageIO.read(new File("src/Grid.jpg")))));
//J.setContentPane(new JLabel(new ImageIcon(ImageIO.read(new File("C:/Users/TASNEEA/Desktop/download.png"))));
}catch(IOException e1)
{
    System.out.println("doesn't exist");
}

J.setResizable(true);
J.pack();
J.setVisible(true);

label.setText("kaj kore na keno?");

label.setVerticalTextPosition(JLabel.BOTTOM);
    }
}

 /*  J.addMouseListener(new MouseAdapter(){
   public void mouseClicked(MouseEvent e){
  // label.setText("X "+e.getX()+ " Y "+ e.getY()); ///
 /*      System.out.println(e.getX() + " " + e.getY());
   }
   });*/
     /*   }
        }*/
               

