package com.advantest.gef.editPolicies;

import org.eclipse.gef.commands.Command;
import org.eclipse.gef.editpolicies.ComponentEditPolicy;
import org.eclipse.gef.requests.GroupRequest;

import com.advantest.gef.commands.DeleteCommand;
import com.advantest.gef.model.Node;

public class AppDeletePolicy extends ComponentEditPolicy {
	@Override
	protected Command createDeleteCommand(GroupRequest deleteRequest) {
		// TODO Auto-generated method stub
		DeleteCommand command = new DeleteCommand();
		Node model = (Node)(getHost().getModel());
		command.setModel(model);
		command.setParentModel(model.getParent());
		return command;
	}
}
