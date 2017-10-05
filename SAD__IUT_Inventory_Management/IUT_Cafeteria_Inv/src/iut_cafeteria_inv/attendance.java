/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package iut_cafeteria_inv;
import javax.swing.JPanel;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;
import org.jfree.ui.ApplicationFrame;
/**
 *
 * @author talha
 */
public class attendance extends ApplicationFrame 
{
   private javax.swing.JButton but = new javax.swing.JButton();
   public attendance( String title ) 
   {
      super( title ); 
      setContentPane(createDemoPanel( ));
      but.setText("OK");
      but.addActionListener(new java.awt.event.ActionListener() {
          public void actionPerformed(java.awt.event.ActionEvent evt) {
              setVisible(false);
          }
      });
      add(but);
      setLayout(null);
      but.setBounds(600, 570, 170, 30);
   }
   private PieDataset createDataset( ) 
   {
      DefaultPieDataset dataset = new DefaultPieDataset( );
      dataset.setValue( "Will be absent" , new Double( 10 ) );
      dataset.setValue( "Will Take next meal" , new Double( 90 ) );
      return dataset;         
   }
   private JFreeChart createChart( PieDataset dataset )
   {
      JFreeChart chart = ChartFactory.createPieChart(      
         "Meal Attendance",  // chart title 
         dataset,        // data    
         true,           // include legend   
         true, 
         false);

      return chart;
   }
   public JPanel createDemoPanel( )
   {
      JFreeChart chart = createChart(createDataset( ) );  
      return new ChartPanel( chart ); 
   }
}
