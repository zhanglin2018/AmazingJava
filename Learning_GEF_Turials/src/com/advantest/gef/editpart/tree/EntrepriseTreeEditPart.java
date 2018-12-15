package com.advantest.gef.editpart.tree;

import java.beans.PropertyChangeEvent;
import java.util.List;

import com.advantest.gef.model.Entreprise;
import com.advantest.gef.model.Node;

public class EntrepriseTreeEditPart extends AppAbstractTreeEditPart {

	@Override
	protected List<Node> getModelChildren() {
		// TODO Auto-generated method stub
		return ((Entreprise)getModel()).getChildrenArray();
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
