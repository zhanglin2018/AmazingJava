package com.advantest.gef.editpart;

import java.beans.PropertyChangeListener;

import org.eclipse.gef.editparts.AbstractGraphicalEditPart;

import com.advantest.gef.model.Node;

public abstract class AppAbstractEditPart extends AbstractGraphicalEditPart implements PropertyChangeListener {

	@Override
	public void activate() {
		// TODO Auto-generated method stub
		
		super.activate();
		((Node)getModel()).addPropertyChangedListener(this);
	}
	
	@Override
	public void deactivate() {
		// TODO Auto-generated method stub
		super.deactivate();
		((Node)getModel()).removePropertyChangedListener(this);
	}
}
