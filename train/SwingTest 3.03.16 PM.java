import java.util.*;
import javax.swing.*;
import java.awt.*;

class SwingConsole {
	public static void run(final JFrame f, final int width, final int height) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				f.setTitle(f.getClass().getSimpleName());
				f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				f.setSize(width, height);
				f.setVisible(true);
			}
		});
	}
}

public class SwingTest extends JFrame {
	private JButton b1 = new JButton("Button 1"), b2 = new JButton("Button 2");
	public SwingTest() {
		setLayout(new FlowLayout());
		add(b1);
		add(b2);
	}
	public static void main(String[] args) {
		SwingConsole.run(new SwingTest(), 200, 100);
		System.out.print(Arrays.deepToString(SwingTest.class.getMethods()));
	}
}