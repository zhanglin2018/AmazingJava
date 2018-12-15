package com.advantest.gef.commands;

import org.eclipse.draw2d.geometry.Rectangle;

import com.advantest.gef.model.Service;

public class ServiceChangeLayoutCommand extends AbstractLayoutCommand {
	private Service model;
	private Rectangle layout;
	private Rectangle oldLayout;

	@Override
	public void execute() {
		// TODO Auto-generated method stub
		model.setLayout(layout);
	}

	@Override
	public void setConstraint(Rectangle rect) {
		// TODO Auto-generated method stub
		this.layout = rect;
	}
	
	@Override
	public void undo() {
		// TODO Auto-generated method stub
		super.undo();
		this.model.setLayout(this.oldLayout);
	}

	@Override
	public void setModel(Object model) {
		// TODO Auto-generated method stub
		this.model = (Service) model;
		this.oldLayout = ((Service)model).getLayout();
	}

}
