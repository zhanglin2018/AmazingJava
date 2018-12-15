package com.advantest.gef.editPolicies;

import org.eclipse.draw2d.geometry.Rectangle;
import org.eclipse.gef.EditPart;
import org.eclipse.gef.commands.Command;
import org.eclipse.gef.editpolicies.XYLayoutEditPolicy;
import org.eclipse.gef.requests.ChangeBoundsRequest;
import org.eclipse.gef.requests.CreateRequest;

import com.advantest.gef.commands.AbstractLayoutCommand;
import com.advantest.gef.commands.EmployeChangeLayoutCommand;
import com.advantest.gef.commands.ServiceChangeLayoutCommand;
import com.advantest.gef.editpart.EmployeEditPart;
import com.advantest.gef.editpart.ServiceEditPart;
import com.advantest.gef.model.Employe;

public class AppEditLayoutPolicy extends XYLayoutEditPolicy {

	@Override
	protected Command createChangeConstraintCommand(EditPart child, Object constraint) {
		// TODO Auto-generated method stub
		AbstractLayoutCommand command = null;
		
		if (child instanceof EmployeEditPart) {
			command = new EmployeChangeLayoutCommand();
		} else if (child instanceof ServiceEditPart) {
			command = new ServiceChangeLayoutCommand();
		}
		
		command.setModel(child.getModel());
		command.setConstraint((Rectangle)constraint);		
		return command;
	}

	@Override
	protected Command getCreateCommand(CreateRequest arg0) {
		// TODO Auto-generated method stub
		return null;
	}

}
