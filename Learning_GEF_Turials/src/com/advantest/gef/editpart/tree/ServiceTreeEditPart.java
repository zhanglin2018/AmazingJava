package com.advantest.gef.editpart.tree;

import java.beans.PropertyChangeEvent;
import java.util.List;

import org.eclipse.gef.EditPolicy;
import org.eclipse.ui.ISharedImages;
import org.eclipse.ui.PlatformUI;

import com.advantest.gef.editPolicies.AppDeletePolicy;
import com.advantest.gef.model.Node;
import com.advantest.gef.model.Service;

public class ServiceTreeEditPart extends AppAbstractTreeEditPart {

	@Override
	protected List<Node> getModelChildren() {
		// TODO Auto-generated method stub
		return ((Service)getModel()).getChildrenArray();
	}
	
	@Override
	protected void createEditPolicies() {
		// TODO Auto-generated method stub
		installEditPolicy(EditPolicy.COMPONENT_ROLE, new AppDeletePolicy());
	}
	
	@Override
	protected void refreshVisuals() {
		// TODO Auto-generated method stub
		Service model = (Service)getModel();
		setWidgetText(model.getName());
		setWidgetImage(PlatformUI.getWorkbench()
				.getSharedImages().getImage(ISharedImages.IMG_OBJ_ELEMENT));
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
