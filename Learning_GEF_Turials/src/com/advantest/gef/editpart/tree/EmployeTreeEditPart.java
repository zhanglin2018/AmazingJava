package com.advantest.gef.editpart.tree;

import java.beans.PropertyChangeEvent;
import java.util.List;

import org.eclipse.gef.EditPolicy;
import org.eclipse.ui.ISharedImages;
import org.eclipse.ui.PlatformUI;

import com.advantest.gef.editPolicies.AppDeletePolicy;
import com.advantest.gef.model.Employe;
import com.advantest.gef.model.Node;

public class EmployeTreeEditPart extends AppAbstractTreeEditPart {
	@Override
	protected List<Node> getModelChildren() {
		// TODO Auto-generated method stub
		return ((Employe)getModel()).getChildrenArray();
	}
	
	@Override
	protected void createEditPolicies() {
		// TODO Auto-generated method stub
		installEditPolicy(EditPolicy.COMPONENT_ROLE, new AppDeletePolicy());
	}

	@Override
	protected void refreshVisuals() {
		// TODO Auto-generated method stub
		Employe model = (Employe)getModel();
		setWidgetText(model.getName() + " " + model.getPrenom());
		setWidgetImage(PlatformUI.getWorkbench()
				.getSharedImages().getImage(ISharedImages.IMG_DEF_VIEW));
	}
	
	@Override
	public void propertyChange(PropertyChangeEvent event) {
		// TODO Auto-generated method stub
		if (event.getPropertyName().equals(Node.PROPERTY_ADD)) {
			refreshChildren();
		}
		
		if (event.getPropertyName().equals(Node.PROPERTY_REMOVE)) {
			refreshChildren();
		}

	}

}
