/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tourism_app;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JPanel;

/**
 *
 * @author talha
 */
public class ScrollingText extends JPanel{
    int x=1300, y=30;
    
    public void paint(Graphics g)
    {
        super.paint(g);
        Graphics2D g2 = (Graphics2D)g;
        g2.setFont(new java.awt.Font("Rachana", 1, 30));;
        g2.setColor(new Color(167, 59, 59));
        g2.drawString("WELCOME TOURISTS! To beautiful Bangladesh!!", x, y);
        setBackground(Color.BLACK);
        try{Thread.sleep(80);}catch(Exception ex) {}
        x-=10;
        if(x<=-700)
        {
            x=1300;
        }
        repaint();
    }
}
