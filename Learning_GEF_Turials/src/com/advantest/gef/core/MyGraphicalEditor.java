package com.advantest.gef.core;

import java.util.ArrayList;

import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.draw2d.LightweightSystem;
import org.eclipse.draw2d.Viewport;
import org.eclipse.draw2d.geometry.Rectangle;
import org.eclipse.draw2d.parts.ScrollableThumbnail;
import org.eclipse.gef.ContextMenuProvider;
import org.eclipse.gef.DefaultEditDomain;
import org.eclipse.gef.GraphicalViewer;
import org.eclipse.gef.KeyHandler;
import org.eclipse.gef.KeyStroke;
import org.eclipse.gef.LayerConstants;
import org.eclipse.gef.MouseWheelHandler;
import org.eclipse.gef.MouseWheelZoomHandler;
import org.eclipse.gef.editparts.ScalableRootEditPart;
import org.eclipse.gef.editparts.ZoomManager;
import org.eclipse.gef.ui.actions.GEFActionConstants;
import org.eclipse.gef.ui.actions.ZoomInAction;
import org.eclipse.gef.ui.actions.ZoomOutAction;
import org.eclipse.gef.ui.parts.ContentOutlinePage;
import org.eclipse.gef.ui.parts.GraphicalEditor;
import org.eclipse.gef.ui.parts.TreeViewer;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.SashForm;
import org.eclipse.swt.events.DisposeEvent;
import org.eclipse.swt.events.DisposeListener;
import org.eclipse.swt.widgets.Canvas;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.ui.IActionBars;
import org.eclipse.ui.actions.ActionFactory;
import org.eclipse.ui.part.IPageSite;
import org.eclipse.ui.views.contentoutline.IContentOutlinePage;

import com.advantest.gef.editpart.tree.AppTreeEditPartFactory;
import com.advantest.gef.model.Employe;
import com.advantest.gef.model.Entreprise;
import com.advantest.gef.model.Service;

public class MyGraphicalEditor extends GraphicalEditor {
	public static final String ID = "com.advantest.gef.core.mygraphicaleditor";

	private Entreprise model;
	private KeyHandler keyHandler;

	protected class OutlinePage extends ContentOutlinePage {
		private SashForm sash;
		private ScrollableThumbnail thumbnail;
		private DisposeListener disposeListener;
		
		public OutlinePage() {
			super(new TreeViewer());
			// TODO Auto-generated constructor stub
		}

		@Override
		public void createControl(Composite parent) {
			// TODO Auto-generated method stub
			sash = new SashForm(parent, SWT.VERTICAL);
			getViewer().createControl(sash);

			getViewer().setEditDomain(getEditDomain());
			getViewer().setEditPartFactory(new AppTreeEditPartFactory());
			getViewer().setContents(model);

			getSelectionSynchronizer().addViewer(getViewer());
			
			
			/*
			 * Part seven : Miniature View
			 * 
			 */
			
			Canvas canvas = new Canvas(sash, SWT.BORDER);
			LightweightSystem lightweightSystem = new LightweightSystem(canvas);
			thumbnail = new ScrollableThumbnail((Viewport)((ScalableRootEditPart)(getGraphicalViewer()
					.getRootEditPart())).getFigure());
			thumbnail.setSource(((ScalableRootEditPart)(getGraphicalViewer()
					.getRootEditPart())).getLayer(LayerConstants.PRINTABLE_LAYERS));
			
			lightweightSystem.setContents(thumbnail);
			
			disposeListener = new DisposeListener() {
				
				@Override
				public void widgetDisposed(DisposeEvent e) {
					// TODO Auto-generated method stub
					if (thumbnail != null) {
						thumbnail.deactivate();
						thumbnail = null;
					}
					
				}
			};
			
			getGraphicalViewer().getControl().addDisposeListener(disposeListener);
					
		}

		@Override
		public void init(IPageSite pageSite) {
			// TODO Auto-generated method stub
			super.init(pageSite);

			IActionBars bars = getSite().getActionBars();
			bars.setGlobalActionHandler(ActionFactory.UNDO.getId(),
					getActionRegistry().getAction(ActionFactory.UNDO.getId()));

			bars.setGlobalActionHandler(ActionFactory.REDO.getId(),
					getActionRegistry().getAction(ActionFactory.REDO.getId()));

			bars.setGlobalActionHandler(ActionFactory.DELETE.getId(),
					getActionRegistry().getAction(ActionFactory.DELETE.getId()));

			bars.updateActionBars();

			getViewer().setKeyHandler(keyHandler);
			
			/*
			 * add menu context
			 * 
			 */
			
			ContextMenuProvider provider = new AppContextMenuProvider(getViewer(), getActionRegistry());
			getViewer().setContextMenu(provider);
		}

		@Override
		public Control getControl() {
			// TODO Auto-generated method stub
			return sash;
		}

		@Override
		public void dispose() {
			// TODO Auto-generated method stub
			getSelectionSynchronizer().removeViewer(getViewer());
			if (getGraphicalViewer().getControl() != null
					&& !getGraphicalViewer().getControl().isDisposed()) {
				getGraphicalViewer().getControl().removeDisposeListener(disposeListener);
			}
					
			
			super.dispose();
		}

		protected void initializeGraphicalViewer() {
			GraphicalViewer viewer = getGraphicalViewer();
			model = createEntreprise();
			viewer.setContents(model);
		}

		protected void configureGraphicalViewer() {
			keyHandler = new KeyHandler();

			keyHandler.put(KeyStroke.getPressed(SWT.DEL, 127, 0),
					getActionRegistry().getAction(ActionFactory.DELETE.getId()));

			keyHandler.put(KeyStroke.getPressed('+', SWT.KEYPAD_ADD, 0),
					getActionRegistry().getAction(GEFActionConstants.ZOOM_IN));

			keyHandler.put(KeyStroke.getPressed('-', SWT.KEYPAD_SUBTRACT, 0),
					getActionRegistry().getAction(GEFActionConstants.ZOOM_OUT));

			getViewer().setProperty(MouseWheelHandler.KeyGenerator.getKey(SWT.NONE), MouseWheelZoomHandler.SINGLETON);

			getViewer().setKeyHandler(keyHandler);
			
		}

	}

	public MyGraphicalEditor() {
		setEditDomain(new DefaultEditDomain(this));
	}

	public Entreprise createEntreprise() {
		Entreprise entreprise = new Entreprise();

//		entreprise.setName("ADVANTEST Entreprise");
//		entreprise.setAddress("zhangjiang");
//		entreprise.setCapital(100000);
//
//		Service itService = new Service();
//		itService.setName("IT department");
//		itService.setEtage(2);
//		itService.setLayout(new Rectangle(30, 50, 250, 150));
//
//		Employe employeZhang = new Employe();
//		employeZhang.setName("zhanglin");
//		employeZhang.setPrenom("zhang");
//		employeZhang.setLayout(new Rectangle(25, 40, 60, 40));
//		itService.addChild(employeZhang);
//
//		Employe employeHan = new Employe();
//		employeHan.setName("hanjiaojiao");
//		employeHan.setPrenom("han");
//		employeHan.setLayout(new Rectangle(100, 60, 60, 40));
//		itService.addChild(employeHan);
//
//		Employe employeWei = new Employe();
//		employeWei.setName("zhangwei");
//		employeWei.setPrenom("zhang");
//		employeWei.setLayout(new Rectangle(180, 90, 60, 40));
//		itService.addChild(employeWei);
//
//		entreprise.addChild(itService);
//
//		Service rhService = new Service();
//		rhService.setName("Resources Humaine");
//		rhService.setEtage(1);
//		rhService.setLayout(new Rectangle(220, 230, 250, 150));
//
//		Employe employeXihua = new Employe();
//		employeXihua.setName("fuxihua");
//		employeXihua.setPrenom("fu");
//		employeXihua.setLayout(new Rectangle(40, 70, 60, 40));
//		rhService.addChild(employeXihua);
//
//		Employe employeJinzhou = new Employe();
//		employeJinzhou.setName("zhangjinzhou");
//		employeJinzhou.setPrenom("zhang");
//		employeJinzhou.setLayout(new Rectangle(170, 100, 60, 40));
//		rhService.addChild(employeJinzhou);
//
//		entreprise.addChild(rhService);

		return entreprise;
	}

	@Override
	protected void configureGraphicalViewer() {
		// TODO Auto-generated method stub
		super.configureGraphicalViewer();
		GraphicalViewer viewer = getGraphicalViewer();
		viewer.setEditPartFactory(new AppEditPartFactory());

		/*
		 * Part5: Zoom and keyboard shortcuts add zooming features
		 */

		double[] zoomLevels;
		ArrayList<String> zoomContributions;
		ScalableRootEditPart rootEditPart = new ScalableRootEditPart();
		viewer.setRootEditPart(rootEditPart);

		ZoomManager manager = rootEditPart.getZoomManager();
		getActionRegistry().registerAction(new ZoomInAction(manager));
		getActionRegistry().registerAction(new ZoomOutAction(manager));

		zoomLevels = new double[] { 0.25, 0.5, 0.75, 1.0, 1.5, 2.0, 2.5, 3.0, 4.0, 5.0, 10.0, 20.0 };
		manager.setZoomLevels(zoomLevels);

		zoomContributions = new ArrayList<String>();
		zoomContributions.add(ZoomManager.FIT_ALL);
		zoomContributions.add(ZoomManager.FIT_HEIGHT);
		zoomContributions.add(ZoomManager.FIT_WIDTH);

		manager.setZoomLevelContributions(zoomContributions);

		/*
		 * add keyboard feature
		 */

		KeyHandler keyHandler = new KeyHandler();

		keyHandler.put(KeyStroke.getPressed(SWT.DEL, 127, 0),
				getActionRegistry().getAction(ActionFactory.DELETE.getId()));

		keyHandler.put(KeyStroke.getPressed('+', SWT.KEYPAD_ADD, 0),
				getActionRegistry().getAction(GEFActionConstants.ZOOM_IN));

		keyHandler.put(KeyStroke.getPressed('-', SWT.KEYPAD_SUBTRACT, 0),
				getActionRegistry().getAction(GEFActionConstants.ZOOM_OUT));

		viewer.setProperty(MouseWheelHandler.KeyGenerator.getKey(SWT.NONE),
				MouseWheelZoomHandler.SINGLETON);

		viewer.setKeyHandler(keyHandler);
		
		/*
		 * add menu context 
		 */
		
		ContextMenuProvider provider = new AppContextMenuProvider(viewer, getActionRegistry());
		viewer.setContextMenu(provider);

	}

	@Override
	public Object getAdapter(Class type) {
		// TODO Auto-generated method stub
		if (type == ZoomManager.class) {
			System.out.println("zoomManager.class");
			return ((ScalableRootEditPart) (getGraphicalViewer().getRootEditPart())).getZoomManager();
		}

		if (type == IContentOutlinePage.class) {
			System.out.println("IContentOutlinePage.class");

			return new OutlinePage();
		}

		return super.getAdapter(type);
	}

	@Override
	protected void initializeGraphicalViewer() {
		// TODO Auto-generated method stub
		GraphicalViewer viewer = getGraphicalViewer();
		this.model = createEntreprise();
		viewer.setContents(model);  //this.model must be same model. important

	}

	@Override
	public void doSave(IProgressMonitor monitor) {
		// TODO Auto-generated method stub

	}

}
