package com.advantest.gef.editpart.tree;

import java.beans.PropertyChangeListener;

import org.eclipse.gef.editparts.AbstractTreeEditPart;

import com.advantest.gef.model.Node;

public abstract class AppAbstractTreeEditPart extends AbstractTreeEditPart 
					implements PropertyChangeListener {

	@Override
	public void activate() {
		// TODO Auto-generated method stub
		super.activate();
		Node model = (Node)getModel();
		model.addPropertyChangedListener(this);
	}
	
	@Override
	public void deactivate() {
		// TODO Auto-generated method stub
		Node model = (Node)getModel();
		model.removePropertyChangedListener(this);	
		super.deactivate();

	}

}
