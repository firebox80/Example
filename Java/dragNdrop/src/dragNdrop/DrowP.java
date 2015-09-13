package dragNdrop;

import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JPanel;

class DrowP extends JPanel implements MouseListener, MouseMotionListener {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int x;
	int y;
	int startX;
	int startY;
	Cursor myCursor;
	
	DrowP() {
		x = 10;
		y = 10;
		setBackground(Color.GREEN);
		setPreferredSize(new Dimension(400, 400));
		setOpaque(true);
		setFocusable(true);
		myCursor = new Cursor(0);
		
		addMouseListener(this);
//		addMouseMotionListener(this);
	}
	
	@Override
	protected void paintComponent(Graphics g){
		super.paintComponent(g);
		
		g.setColor(Color.BLUE);
		g.fillRect(x, y, 100, 100);
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		myCursor = Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR);
		setCursor(myCursor);
		System.out.println("mouseClicked");
	}

	@Override
	public void mousePressed(MouseEvent e) {
		myCursor = Cursor.getPredefinedCursor(Cursor.HAND_CURSOR);
		setCursor(myCursor);
		
		boolean condition = (e.getX() >= x && e.getY() >= y && e.getX() <= (x + 100) && e.getY() <= (y+ 100));
		if(!condition) return;

	    System.out.println("mousePressed");
		System.out.println(e.getX());
		System.out.println(e.getY());
		setBackground(Color.RED);
		startX = e.getX();
		startY = e.getY();
		addMouseMotionListener(this);		
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		System.out.println("mouseReleased");
		myCursor = Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR);
		setCursor(myCursor);
		setBackground(Color.GREEN);
		removeMouseMotionListener(this);			
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub		
		System.out.println("mouseEntered");
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub	
		System.out.println("mouseExited");
	}

	@Override
	public void mouseDragged(MouseEvent e) {
		myCursor = Cursor.getPredefinedCursor(Cursor.MOVE_CURSOR);
		setCursor(myCursor);
		
		System.out.println("mouseDragged");
		System.out.println(e.getX());
		System.out.println(e.getY());
		x = x + (e.getX() - startX);
	    y = y + (e.getY() - startY); 
	    startX = e.getX();
	    startY = e.getY();
		        
	    repaint();
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		System.out.println("mouseMoved");
	}

}
