/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tourism_app;

import javax.swing.JOptionPane;

/**
 *
 * @author talha
 */
public class weatherframe extends javax.swing.JFrame {

    getConnection gc = new getConnection();
    /**
     * Creates new form weatherframe
     */
    public weatherframe() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jTextField5 = new javax.swing.JTextField();
        jTextField4 = new javax.swing.JTextField();
        jTextField3 = new javax.swing.JTextField();
        jTextField2 = new javax.swing.JTextField();
        jTextField1 = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jLabel7 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(null);
        getContentPane().add(jTextField5);
        jTextField5.setBounds(665, 394, 200, 20);
        getContentPane().add(jTextField4);
        jTextField4.setBounds(665, 349, 200, 20);
        getContentPane().add(jTextField3);
        jTextField3.setBounds(665, 304, 200, 20);

        jTextField2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField2ActionPerformed(evt);
            }
        });
        getContentPane().add(jTextField2);
        jTextField2.setBounds(665, 259, 200, 20);
        getContentPane().add(jTextField1);
        jTextField1.setBounds(665, 214, 200, 20);

        jLabel1.setForeground(new java.awt.Color(37, 173, 156));
        jLabel1.setText("Minimum Temperature:");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(460, 219, 170, 14);

        jLabel2.setForeground(new java.awt.Color(37, 173, 156));
        jLabel2.setText("Maximum Temperature:");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(460, 264, 170, 14);

        jLabel3.setForeground(new java.awt.Color(37, 173, 156));
        jLabel3.setText("Minimum Rainfall:");
        getContentPane().add(jLabel3);
        jLabel3.setBounds(460, 309, 170, 14);

        jLabel4.setForeground(new java.awt.Color(37, 173, 156));
        jLabel4.setText("Maximum Rainfall:");
        getContentPane().add(jLabel4);
        jLabel4.setBounds(460, 354, 170, 14);

        jLabel5.setForeground(new java.awt.Color(37, 173, 156));
        jLabel5.setText("Weather Region:");
        getContentPane().add(jLabel5);
        jLabel5.setBounds(460, 399, 170, 14);

        jLabel6.setFont(new java.awt.Font("Noto Sans", 1, 18)); // NOI18N
        jLabel6.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel6.setText("WEATHER FORM");
        getContentPane().add(jLabel6);
        jLabel6.setBounds(547, 147, 240, 24);

        jButton1.setText("Create Weather");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1);
        jButton1.setBounds(597, 502, 153, 23);

        jButton2.setForeground(new java.awt.Color(234, 17, 17));
        jButton2.setLabel("BACK");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton2);
        jButton2.setBounds(110, 640, 130, 23);

        jLabel7.setIcon(new javax.swing.ImageIcon(getClass().getResource("/tourism_app/weatherback.png"))); // NOI18N
        getContentPane().add(jLabel7);
        jLabel7.setBounds(0, 0, 1366, 760);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jTextField2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField2ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextField2ActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        String mintemp = jTextField1.getText();
        String maxtemp = jTextField2.getText();
        String minrain = jTextField3.getText();
        String maxrain = jTextField4.getText();
        String region = jTextField5.getText();
        gc.setstringData("select * from weather where weather_region = '"+region+"'");
        if(Tourism_App.sqlstringData.length==0)
        {
            JOptionPane.showMessageDialog(null,"New Data Inserted!");
            gc.insertData("insert into weather (weather_region, min_temp, max_temp, min_rainfall, max_rainfall)"
                    + " values ('"+region+"',"+mintemp+","+maxtemp+","+minrain+","+maxrain+")");
            dispose();
        }
        else    JOptionPane.showMessageDialog(null, "Weather already created\nfor this region.");
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
            java.util.logging.Logger.getLogger(weatherframe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(weatherframe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(weatherframe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(weatherframe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new weatherframe().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JTextField jTextField2;
    private javax.swing.JTextField jTextField3;
    private javax.swing.JTextField jTextField4;
    private javax.swing.JTextField jTextField5;
    // End of variables declaration//GEN-END:variables
}
