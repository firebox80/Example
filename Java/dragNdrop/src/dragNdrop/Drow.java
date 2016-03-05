package dragNdrop;

import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;


public class Drow {
	
	DrowP myJpnl;
	
	public Drow() {
		JFrame jfrm = new JFrame("Drag-n-Drop");
		jfrm.getContentPane().setLayout(new FlowLayout());
		jfrm.setSize(400, 400);
		jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//		jfrm.setResizable(false);
		
		myJpnl = new DrowP();
		
		jfrm.setContentPane(myJpnl);
//		jfrm.add(myJpnl);
//		myJpnl.setFocusable(true);
//		jfrm.repaint();
//		jfrm.pack();
		jfrm.setVisible(true);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {  
		      public void run() {  
		        new Drow();  
		      }  
	    }); 
	}
}
