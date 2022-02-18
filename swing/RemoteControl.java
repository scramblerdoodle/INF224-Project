import javax.swing.*; 
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.Container;

public class RemoteControl extends JPanel implements ActionListener
{
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;

	private JButton b1, b2, b3;
	private JLabel requestLabel;	
	private JTextArea responseField;
	private JTextField requestField;
	
	private Client client;
	
	public RemoteControl( Client client )
	{
		this.client = client;
		JFrame f = new JFrame();
	    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    
		Container container = f.getContentPane();

		// Buttons
	    JPanel buttons = new JPanel();
		b1 = new JButton("Show available medias");
		b2 = new JButton("Show details");
		b3 = new JButton("Play");
	    b1.addActionListener(this); b2.addActionListener(this); b3.addActionListener(this);
		buttons.add(b1); buttons.add(b2); buttons.add(b3);
		container.add(buttons,BorderLayout.NORTH);		

		// Request field
		JPanel mainPanel = new JPanel();
		requestLabel = new JLabel("choose a media file or a group:");
		requestLabel.setHorizontalAlignment(JLabel.LEFT);
		requestField = new JTextField(50);
		requestLabel.setHorizontalAlignment(JTextField.LEFT);
		mainPanel.add(requestLabel); mainPanel.add(requestField);
		container.add(mainPanel, BorderLayout.CENTER);

		// Response field
	    responseField = new JTextArea(50,60);
		responseField.setLineWrap(true);
	    container.add(responseField, BorderLayout.SOUTH);


		f.pack();
	    f.setVisible(true);
	    
	}

	public void actionPerformed(ActionEvent e)
	{
		try{
			if (e.getSource() == b1)
			{
				String response = client.send("list");
				responseField.setText(response.replace(";", "\n"));
			}
			else if (e.getSource() == b2)
			{
				String response = client.send("print " + requestField.getText());
				responseField.setText(response.replace(";", "\n"));
			}
			else if (e.getSource() == b3)
			{
				String response = client.send("play " + requestField.getText());
				responseField.setText(response.replace(";", "\n"));
			}
		}catch(Exception ex){System.out.println(ex);}
	}

	public static void main(String argv[])
	{
		try {
			new RemoteControl(new Client(DEFAULT_HOST, DEFAULT_PORT));
			System.out.println("Starting Server on port " + DEFAULT_PORT);  
		}
		catch(Exception e) {
			e.printStackTrace();
			System.out.println("Could not start Server on port  " + DEFAULT_PORT); 
		}
	}
}