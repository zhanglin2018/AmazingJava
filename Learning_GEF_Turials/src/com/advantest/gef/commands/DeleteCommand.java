package com.advantest.gef.commands;

import org.eclipse.gef.commands.Command;

import com.advantest.gef.model.Node;

public class DeleteCommand extends Command {
	private Node model;
	private Node parentModel;
	
	@Override
	public void execute() {
		// TODO Auto-generated method stub
		this.parentModel.removeChild(this.model);
	}
	
	public void setModel(Object model) {
		this.model = (Node)model;
	}
	
	public void setParentModel(Object model) {
		this.parentModel = (Node)model;
	}
	
	@Override
	public void undo() {
		// TODO Auto-generated method stub
		parentModel.addChild(model);
	}
}
