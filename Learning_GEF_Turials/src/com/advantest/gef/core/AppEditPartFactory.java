package com.advantest.gef.core;

import org.eclipse.gef.EditPart;
import org.eclipse.gef.EditPartFactory;
import org.eclipse.gef.editparts.AbstractGraphicalEditPart;

import com.advantest.gef.editpart.EmployeEditPart;
import com.advantest.gef.editpart.EntrepriseEditPart;
import com.advantest.gef.editpart.ServiceEditPart;
import com.advantest.gef.model.Employe;
import com.advantest.gef.model.Entreprise;
import com.advantest.gef.model.Service;

public class AppEditPartFactory implements EditPartFactory {

	@Override
	public EditPart createEditPart(EditPart context, Object model) {
		// TODO Auto-generated method stub
		AbstractGraphicalEditPart editPart = null;
		
		if (model instanceof Entreprise) {
			editPart = new EntrepriseEditPart();
		}else if (model instanceof Service) {
			editPart = new ServiceEditPart();
		}else if (model instanceof Employe) {
			editPart = new EmployeEditPart();
		}
		
		
		
		editPart.setModel(model);
		return editPart;
	}

}
