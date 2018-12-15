package com.advantest.gef.editpart;

import java.beans.PropertyChangeEvent;
import java.util.List;

import org.eclipse.draw2d.IFigure;
import org.eclipse.gef.EditPolicy;
import org.eclipse.gef.editparts.AbstractGraphicalEditPart;
import org.w3c.dom.events.EventException;

import com.advantest.gef.editPolicies.AppDeletePolicy;
import com.advantest.gef.editPolicies.AppEditLayoutPolicy;
import com.advantest.gef.figure.ServiceFigure;
import com.advantest.gef.model.Node;
import com.advantest.gef.model.Service;

public class ServiceEditPart extends AppAbstractEditPart {

	@Override
	protected IFigure createFigure() {
		// TODO Auto-generated method stub
		ServiceFigure figure = new ServiceFigure();
		return figure;
	}

	@Override
	protected void createEditPolicies() {
		// TODO Auto-generated method stub
		installEditPolicy(EditPolicy.LAYOUT_ROLE, new AppEditLayoutPolicy());
		installEditPolicy(EditPolicy.COMPONENT_ROLE, new AppDeletePolicy());

	}
	
	@Override
	protected void refreshVisuals() {
		// TODO Auto-generated method stub
		ServiceFigure figure = (ServiceFigure)getFigure();
		Service model = (Service)getModel();
		
		figure.setName(model.getName());
		figure.setEtate(model.getEtage());
		figure.setLayout(model.getLayout());
		
	}
	
	@Override
	protected List getModelChildren() {
		// TODO Auto-generated method stub
		
		return ((Service)getModel()).getChildrenArray();
	}

	@Override
	public void propertyChange(PropertyChangeEvent event) {
		// TODO Auto-generated method stub
		if (event.getPropertyName().equals(Node.PROPERTY_LAYOUT)) {
			refreshVisuals();
		}
		
		if (event.getPropertyName().equals(Node.PROPERTY_ADD)) {
			refreshChildren();
		}
		
		if (event.getPropertyName().equals(Node.PROPERTY_REMOVE)) {
			refreshChildren();
		}
	}

}
