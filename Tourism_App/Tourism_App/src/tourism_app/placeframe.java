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
public class placeframe extends javax.swing.JFrame {

    getConnection gc = new getConnection();
    /**
     * Creates new form placeframe
     */
    public placeframe() {
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

        jTextField1 = new javax.swing.JTextField();
        jTextField2 = new javax.swing.JTextField();
        jTextField3 = new javax.swing.JTextField();
        jTextField4 = new javax.swing.JTextField();
        jTextField5 = new javax.swing.JTextField();
        jTextField6 = new javax.swing.JTextField();
        jComboBox1 = new javax.swing.JComboBox<String>();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        jLabel9 = new javax.swing.JLabel();
        jButton2 = new javax.swing.JButton();
        jLabel8 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(null);
        getContentPane().add(jTextField1);
        jTextField1.setBounds(638, 192, 200, 20);
        getContentPane().add(jTextField2);
        jTextField2.setBounds(638, 282, 200, 20);

        jTextField3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField3ActionPerformed(evt);
            }
        });
        getContentPane().add(jTextField3);
        jTextField3.setBounds(638, 327, 200, 20);
        getContentPane().add(jTextField4);
        jTextField4.setBounds(638, 372, 200, 20);

        jTextField5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField5ActionPerformed(evt);
            }
        });
        getContentPane().add(jTextField5);
        jTextField5.setBounds(638, 417, 200, 20);
        getContentPane().add(jTextField6);
        jTextField6.setBounds(638, 462, 200, 20);

        jComboBox1.setModel(new javax.swing.DefaultComboBoxModel<>(Tourism_App.sqlstringData));
        getContentPane().add(jComboBox1);
        jComboBox1.setBounds(638, 237, 200, 20);

        jLabel1.setText("Place Name:");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(430, 197, 190, 14);

        jLabel2.setText("Location/ Weather Region:");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(430, 242, 190, 14);

        jLabel3.setText("Address:");
        getContentPane().add(jLabel3);
        jLabel3.setBounds(430, 287, 190, 14);

        jLabel4.setText("Latitude:");
        getContentPane().add(jLabel4);
        jLabel4.setBounds(430, 332, 190, 14);

        jLabel5.setText("Longitude:");
        getContentPane().add(jLabel5);
        jLabel5.setBounds(430, 377, 190, 14);

        jLabel6.setText("Category:");
        getContentPane().add(jLabel6);
        jLabel6.setBounds(430, 422, 190, 14);

        jLabel7.setText("Description:");
        getContentPane().add(jLabel7);
        jLabel7.setBounds(430, 467, 190, 14);

        jButton1.setText("Create Place");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1);
        jButton1.setBounds(597, 610, 185, 23);

        jLabel9.setFont(new java.awt.Font("Noto Sans", 1, 18)); // NOI18N
        jLabel9.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel9.setText("TOURIST PLACE FORM");
        getContentPane().add(jLabel9);
        jLabel9.setBounds(516, 94, 270, 24);

        jButton2.setForeground(new java.awt.Color(234, 17, 17));
        jButton2.setLabel("BACK");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton2);
        jButton2.setBounds(110, 640, 130, 23);

        jLabel8.setIcon(new javax.swing.ImageIcon(getClass().getResource("/tourism_app/placeback.png"))); // NOI18N
        getContentPane().add(jLabel8);
        jLabel8.setBounds(0, 0, 1366, 760);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jTextField3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField3ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextField3ActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        String name = jTextField1.getText();
        String location = (String)jComboBox1.getSelectedItem();
        String address = jTextField2.getText();
        String latitude = jTextField3.getText();
        String longitude = jTextField4.getText();
        String category = jTextField5.getText();
        String description = jTextField6.getText();
        JOptionPane.showMessageDialog(null,"New Data Inserted!");
        gc.insertData("insert into place (place_name, location, Address, latitude, longitude, category, description)"
                + " values ('"+name+"','"+location+"','"+address+"',"+latitude+","+longitude+",'"+category+"','"+description+"')");
        
        dispose();
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jTextField5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField5ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextField5ActionPerformed

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
            java.util.logging.Logger.getLogger(placeframe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(placeframe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(placeframe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(placeframe.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new placeframe().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JComboBox<String> jComboBox1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JTextField jTextField2;
    private javax.swing.JTextField jTextField3;
    private javax.swing.JTextField jTextField4;
    private javax.swing.JTextField jTextField5;
    private javax.swing.JTextField jTextField6;
    // End of variables declaration//GEN-END:variables
}
