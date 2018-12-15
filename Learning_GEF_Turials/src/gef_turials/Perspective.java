package gef_turials;

import org.eclipse.ui.IPageLayout;
import org.eclipse.ui.IPerspectiveFactory;

public class Perspective implements IPerspectiveFactory {

	@Override	
	public void createInitialLayout(IPageLayout layout) {
		 String editorArea = layout.getEditorArea();
         layout.setEditorAreaVisible(true);
         layout.addStandaloneView(IPageLayout.ID_OUTLINE, true, IPageLayout.LEFT, 0.3f, editorArea);
//         layout.addStandaloneView(IPageLayout.ID_PROP_SHEET, true, IPageLayout.LEFT, 0.6f, editorArea);

	}
}
