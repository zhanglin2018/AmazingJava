package com.advantest.gef.core;



import org.eclipse.jface.wizard.Wizard;
import org.eclipse.jface.wizard.WizardPage;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;

public class RenameWizard extends Wizard {
	
	private class RenamePage extends WizardPage{
		public Text nameText;
		
		public RenamePage(String pageName) {
			super(pageName);
			setTitle("Rename");
			setDescription("Rename a component");
		}

		@Override
		public void createControl(Composite parent) {
			// TODO Auto-generated method stub
			Composite composite = new Composite(parent, SWT.NONE);
			
			Label label = new Label(composite, SWT.None);
			label.setText("Rename to: ");
			
			nameText = new Text(composite, SWT.NONE);
//			nameText.setText(string);
			
			
			
		}
		
		
	}

	@Override
	public boolean performFinish() {
		// TODO Auto-generated method stub
		return false;
	}

}
