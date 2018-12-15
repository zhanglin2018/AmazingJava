package com.advantest.gef.figure;

import org.eclipse.draw2d.Button;
import org.eclipse.draw2d.ChangeEvent;
import org.eclipse.draw2d.ChangeListener;
import org.eclipse.draw2d.ColorConstants;
import org.eclipse.draw2d.Figure;
import org.eclipse.draw2d.Label;
import org.eclipse.draw2d.LineBorder;
import org.eclipse.draw2d.ToolbarLayout;
import org.eclipse.draw2d.XYLayout;
import org.eclipse.draw2d.geometry.Rectangle;
import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.widgets.MessageBox;

public class ServiceFigure extends Figure {
	private Label labelName = new Label();
	private Label labelEtage = new Label();
	private Button button = new Button("OK");
	private XYLayout layout;
	
	public ServiceFigure() {
		layout = new XYLayout();
		this.setLayoutManager(layout);
		
		labelName.setForegroundColor(ColorConstants.darkGray);
		add(labelName, ToolbarLayout.ALIGN_CENTER);
		this.setConstraint(labelName, new Rectangle(5, 17, -1, -1));
		
		labelEtage.setForegroundColor(ColorConstants.black);
		add(labelEtage, ToolbarLayout.ALIGN_CENTER);
		this.setConstraint(labelEtage, new Rectangle(5, 5, -1, -1));
		
		button.setBackgroundColor(ColorConstants.red);
		add(button, ToolbarLayout.ALIGN_CENTER);
		setConstraint(button, new Rectangle(5, 40, -1, -1));
		button.addChangeListener(new ChangeListener() {

			@Override
			public void handleStateChanged(ChangeEvent event) {
				// TODO Auto-generated method stub
				System.out.println("hello zhang lin");
			}
			
			
		});
		
		/**
		 * Just for fun
		 */
		
		setForegroundColor(new Color(null,
				(new Double(Math.random() * 128)).intValue() + 128,
			    (new Double(Math.random() * 128)).intValue() + 128,
			    (new Double(Math.random() * 128)).intValue() + 128));
		
		setBackgroundColor(new Color(null,
				(new Double(Math.random() * 128)).intValue() + 128,
			    (new Double(Math.random() * 128)).intValue() + 128,
			    (new Double(Math.random() * 128)).intValue() + 128));
		
		setBorder(new LineBorder(1));
		setOpaque(true);
			
	}
	
	public void setName(String text) {
		labelName.setText(text);
	}
	
	public void setEtate(int etage) {
		labelEtage.setText("Etage: " + etage);
	}
	
	public void setLayout(Rectangle rect) {
		getParent().setConstraint(this, rect);
	}
		
}
