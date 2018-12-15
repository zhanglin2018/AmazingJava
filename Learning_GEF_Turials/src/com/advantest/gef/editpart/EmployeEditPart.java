package com.advantest.gef.editpart;

import java.beans.PropertyChangeEvent;
import java.util.ArrayList;
import java.util.List;

import org.eclipse.draw2d.IFigure;
import org.eclipse.gef.EditPolicy;
import org.eclipse.gef.editparts.AbstractGraphicalEditPart;

import com.advantest.gef.editPolicies.AppDeletePolicy;
import com.advantest.gef.figure.EmployeFigure;
import com.advantest.gef.model.Employe;
import com.advantest.gef.model.Node;

public class EmployeEditPart extends AppAbstractEditPart {

	@Override
	protected IFigure createFigure() {
		// TODO Auto-generated method stub
		IFigure figure = new EmployeFigure();
		return figure;
	}

	@Override
	protected void createEditPolicies() {
		// TODO Auto-generated method stu
		System.out.println("delete fun EmployEditPart");
		installEditPolicy(EditPolicy.COMPONENT_ROLE, new AppDeletePolicy());
	}
	
	@Override
	protected void refreshVisuals() {
		// TODO Auto-generated method stub
		EmployeFigure figure = (EmployeFigure)getFigure();
		Employe model = (Employe)getModel();
		
		figure.setName(model.getName());
		figure.setFirstName(model.getPrenom());
		figure.setLayout(model.getLayout());
	}
	
	@Override
	protected List getModelChildren() {
		// TODO Auto-generated method stub
		return new ArrayList<Node>();
	}

	@Override
	public void propertyChange(PropertyChangeEvent event) {
		// TODO Auto-generated method stub
		if (event.getPropertyName().equals(Node.PROPERTY_LAYOUT)) {
			this.refreshVisuals();
		}
	}

}
