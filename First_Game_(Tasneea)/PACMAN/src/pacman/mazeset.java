/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pacman;

import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JCheckBox;
import javax.swing.JOptionPane;

/**
 *
 * @author talha
 */
public class mazeset extends javax.swing.JFrame {

    JCheckBox grid[][] = new JCheckBox[100][100];
    /**
     * Creates new form mazeset
     */
    public mazeset() {
        initComponents();
        for(int i=0; i<50; i++)
        {
            for(int j=0; j<36; j++)
            {
                grid[i][j]=new JCheckBox();
                getContentPane().add(grid[i][j]);
                grid[i][j].setBounds(i*20+183, j*20, 21, 22);
            }
        }
        if(PACMAN.custom)   jTextField1.setVisible(false);
        setVisible(true);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jTextField1 = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(null);

        jButton1.setFont(new java.awt.Font("Norasi", 1, 18)); // NOI18N
        jButton1.setForeground(new java.awt.Color(44, 136, 41));
        jButton1.setText("DONE");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1);
        jButton1.setBounds(1225, 280, 110, 260);

        jButton2.setFont(new java.awt.Font("Norasi", 1, 18)); // NOI18N
        jButton2.setForeground(new java.awt.Color(235, 16, 16));
        jButton2.setText("CANCEL");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton2);
        jButton2.setBounds(25, 240, 110, 300);

        jTextField1.setText("lvl1/lvl2/lvl3");
        getContentPane().add(jTextField1);
        jTextField1.setBounds(1230, 240, 100, 27);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        if(PACMAN.custom)
        {
            for(int i=0; i<50; i++)
            {
                for(int j=0; j<36; j++)
                {
                    if(grid[i][j].isSelected()) PACMAN.state[i][j]=true;
                    else    PACMAN.state[i][j]=false;
                }
            }
            gamescreen gc = new gamescreen();
            gc.setVisible(true);
            gc.setSize(1366, 760);
            PACMAN.custom=false;
        }
        else
        {
            String name = jTextField1.getText();
            try{
                FileWriter fw = new FileWriter(name+".txt");
                for(int i=0; i<50; i++)
                {
                    for(int j=0; j<36; j++)
                    {
                        if(grid[i][j].isSelected()) fw.write("1");
                        else    fw.write("0");
                    }
                    fw.write("\n");
                }
                fw.close();
            }
            catch(IOException e)
            {
                JOptionPane.showMessageDialog(null, e);
            }
        }
        dispose();
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        // TODO add your handling code here:
        dispose();
    }//GEN-LAST:event_jButton2ActionPerformed

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
            java.util.logging.Logger.getLogger(mazeset.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(mazeset.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(mazeset.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(mazeset.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new mazeset().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JTextField jTextField1;
    // End of variables declaration//GEN-END:variables
}
