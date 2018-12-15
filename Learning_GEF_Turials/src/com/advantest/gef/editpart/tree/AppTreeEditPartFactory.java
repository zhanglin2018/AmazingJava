package com.advantest.gef.editpart.tree;

import org.eclipse.gef.EditPart;
import org.eclipse.gef.EditPartFactory;
import org.eclipse.gef.editparts.AbstractGraphicalEditPart;

import com.advantest.gef.editpart.EmployeEditPart;
import com.advantest.gef.editpart.EntrepriseEditPart;
import com.advantest.gef.editpart.ServiceEditPart;
import com.advantest.gef.model.Employe;
import com.advantest.gef.model.Entreprise;
import com.advantest.gef.model.Service;

public class AppTreeEditPartFactory implements EditPartFactory {

	@Override
	public EditPart createEditPart(EditPart context, Object model) {
		// TODO Auto-generated method stub
		EditPart editPart = null;
		
		if (model instanceof Entreprise) {
			editPart = new EntrepriseTreeEditPart();
		}else if (model instanceof Service) {
			editPart = new ServiceTreeEditPart();
		}else if (model instanceof Employe) {
			editPart = new EmployeTreeEditPart();
		}
		
		
		if (editPart != null) {
			editPart.setModel(model);
		}
		return editPart;
	}

}
