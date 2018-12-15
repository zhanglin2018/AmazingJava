package com.advantest.gef.editpart;

import java.beans.PropertyChangeEvent;
import java.util.ArrayList;
import java.util.List;

import org.eclipse.draw2d.IFigure;
import org.eclipse.draw2d.graph.NodeList;
import org.eclipse.gef.EditPolicy;
import org.eclipse.gef.editparts.AbstractGraphicalEditPart;

import com.advantest.gef.editPolicies.AppEditLayoutPolicy;
import com.advantest.gef.figure.EntrepriseFigure;
import com.advantest.gef.model.Entreprise;
import com.advantest.gef.model.Node;

public class EntrepriseEditPart extends AppAbstractEditPart {

	@Override
	protected IFigure createFigure() {
		// TODO Auto-generated method stub
		IFigure figure = new EntrepriseFigure();
		return figure;
	}

	@Override
	protected void createEditPolicies() {
		// TODO Auto-generated method stub
		installEditPolicy(EditPolicy.LAYOUT_ROLE, new AppEditLayoutPolicy());

	}
	
	@Override
	protected void refreshVisuals() {
		EntrepriseFigure figure = (EntrepriseFigure)getFigure();
		Entreprise model = (Entreprise)getModel();
		
		figure.setAddress(model.getAddress());
		figure.setCapital(model.getCapital());
		figure.setName(model.getName());
		
	}
	
	public List<Node> getModelChildren(){
		return ((Entreprise)getModel()).getChildrenArray();
	}

	@Override
	public void propertyChange(PropertyChangeEvent event) {
		// TODO Auto-generated method stub
		if (event.getPropertyName().equals(Node.PROPERTY_LAYOUT)) {
			this.refreshVisuals();
		}
		if (event.getPropertyName().equals(Node.PROPERTY_ADD)) {
			refreshChildren();
		}
		
		if (event.getPropertyName().equals(Node.PROPERTY_REMOVE)){
			refreshChildren();
		}
	}

}
