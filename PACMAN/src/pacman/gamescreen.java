/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pacman;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.ImageIcon;
import javax.swing.JCheckBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

/**
 *
 * @author talha
 */
public class gamescreen extends javax.swing.JFrame implements KeyListener{

    JLabel label[][] = new JLabel[60][60];
    int playerx = 0 , playery = 0, score =0;
    ImageIcon brick = new ImageIcon(getClass().getResource("brick.png"));
    ImageIcon grass = new ImageIcon(getClass().getResource("grass.png"));
    ImageIcon player = new ImageIcon(getClass().getResource("boy.png"));
    /**
     * Creates new form gamescreen
     */
    public gamescreen() {
        initComponents();
        for(int i=0; i<50; i++)
        {
            for(int j=0; j<36; j++)
            {
                label[i][j] = new JLabel();
                label[i][j].setText("");
                label[i][j].setOpaque(true);
                if(PACMAN.state[i][j])  label[i][j].setIcon(brick);
                else  label[i][j].setIcon(grass);
                getContentPane().add(label[i][j]);
                label[i][j].setBounds(i*20+183, j*20, 40, 17);
                label[i][j].setSize(20, 20);
            }
        }
        if(PACMAN.load)
        {
            label[PACMAN.x][PACMAN.y].setIcon(player);
            jLabel1.setText("SCORE: "+PACMAN.score);
            score = PACMAN.score;
            playerx=PACMAN.x;
            playery=PACMAN.y;
            PACMAN.load=false;
        }
        else label[0][0].setIcon(player);
        
        addKeyListener(this);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton2 = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setSize(new java.awt.Dimension(400, 400));
        getContentPane().setLayout(null);

        jButton2.setFont(new java.awt.Font("Norasi", 1, 18)); // NOI18N
        jButton2.setForeground(new java.awt.Color(235, 16, 16));
        jButton2.setText("EXIT");
        jButton2.setFocusable(false);
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton2);
        jButton2.setBounds(25, 240, 110, 300);

        jButton1.setFont(new java.awt.Font("Norasi", 1, 18)); // NOI18N
        jButton1.setForeground(new java.awt.Color(44, 136, 41));
        jButton1.setText("SAVE");
        jButton1.setFocusable(false);
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1);
        jButton1.setBounds(1225, 240, 110, 300);

        jLabel1.setText("SCORE: "+score);
        getContentPane().add(jLabel1);
        jLabel1.setBounds(1230, 30, 100, 60);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        // TODO add your handling code here:
        dispose();
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:

        try{
            FileWriter fw = new FileWriter("save.txt");
            for(int i=0; i<50; i++)
            {
                for(int j=0; j<36; j++)
                {
                    if(PACMAN.state[i][j]) fw.write("1");
                    else    fw.write("0");
                }
                fw.write("\n");
            }
            fw.write(playerx+" "+playery+" "+score);
            fw.close();
        }
        catch(IOException e)
        {
            JOptionPane.showMessageDialog(null, e);
        }

        dispose();
    }//GEN-LAST:event_jButton1ActionPerformed

    
    @Override
    public void keyTyped(KeyEvent e)
    {
        System.out.println("YES");
    }

    @Override
    public void keyPressed(KeyEvent e)
    {
        for(int i=0; i<50; i++)
        {
            for(int j=0; j<36; j++)
            {
                if(PACMAN.state[i][j])  label[i][j].setIcon(brick);
                else  label[i][j].setIcon(grass);
            }
        }
        int c = e.getKeyCode();
        score++;
        jLabel1.setText("SCORE: "+score);
        System.out.println(c);
        int x, y;
        switch (c) {
            case KeyEvent.VK_UP:
                {
                    x=playerx;
                    y=playery-1;
                    if(x>=0 && x<50 && y>=0 && y<36 && !PACMAN.state[x][y])
                    {
                        playerx=x;
                        playery=y;
                    }
                    label[playerx][playery].setIcon(player);
                    break;
                }
            case KeyEvent.VK_DOWN:
                {
                    x=playerx;
                    y=playery+1;
                    if(x>=0 && x<50 && y>=0 && y<36 && !PACMAN.state[x][y])
                    {
                        playerx=x;
                        playery=y;
                    }
                    label[playerx][playery].setIcon(player);
                    break;
                }
            case KeyEvent.VK_LEFT:
                {
                    x=playerx-1;
                    y=playery;
                    if(x>=0 && x<50 && y>=0 && y<36 && !PACMAN.state[x][y])
                    {
                        playerx=x;
                        playery=y;
                    }
                    label[playerx][playery].setIcon(player);
                    break;
                }
            case KeyEvent.VK_RIGHT:
                {
                    x=playerx+1;
                    y=playery;
                    if(x>=0 && x<50 && y>=0 && y<36 && !PACMAN.state[x][y])
                    {
                        playerx=x;
                        playery=y;
                    }
                    label[playerx][playery].setIcon(player);
                    break;
                }
            default:
                break;
        }
        if(playerx == 49 && playery == 35)
        {
            JOptionPane.showMessageDialog(null, "You Have Won!\nYour score is "+score+".");
            dispose();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(gamescreen.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(gamescreen.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(gamescreen.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(gamescreen.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new gamescreen().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    // End of variables declaration//GEN-END:variables
}