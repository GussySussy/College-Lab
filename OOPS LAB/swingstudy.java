import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class sample extends JFrame implements ActionListener{
    
    JFrame f;
    JTextField tf;
    JButton b;
    JLabel l;

    sample() {
        f = new JFrame("A sample Frame");
        tf = new JTextField();
        tf.setBounds(130,50,100,30);
        l = new JLabel("Sample Text Field");
        l.setText("Hello");
        l.setVisible(true);
        l.setBounds(130,150,40,50);
        b = new JButton("click!");
        b.setBorder(BorderFactory.createLineBorder(Color.orange,3));
        b.setBackground(Color.white);
        b.setBounds(130, 100, 100, 40);
        f.add(b);
        f.add(tf);
        f.add(l);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(400, 500);
        f.setLayout(null);
        f.setVisible(true);
        f.setBackground(Color.darkGray);
        f.setForeground(Color.darkGray);
        f.setResizable(false);
        b.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e){
        if(e.getSource()==b){ 
            tf.setText("Welcome to Java");
        }
        else{
            tf.setText("");
        }
    }
}

public class swingstudy{
    
    public static void main(String[] args) {
        new sample();
    }
}