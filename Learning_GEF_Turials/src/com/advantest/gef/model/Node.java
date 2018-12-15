package com.advantest.gef.model;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.util.ArrayList;
import java.util.List;
import org.eclipse.draw2d.geometry.Rectangle;

public class Node {
	private String name;
	private Rectangle layout;
	private List<Node> children;
	private Node parent;
	
	private PropertyChangeSupport listeners;  
	public static final String PROPERTY_LAYOUT = "NodeLayout";
	public static final String PROPERTY_ADD = "NodeAddChild";
	public static final String PROPERTY_REMOVE = "NodeRemoveChild";
	
	public Node() {
		this.name = "Unknown";
		this.layout = new Rectangle(10, 10, 100, 100);
		this.children = new ArrayList<Node>();
		this.parent = null;
		this.listeners = new PropertyChangeSupport(this);
	}
	
	public void addPropertyChangedListener(PropertyChangeListener listener) {
		listeners.addPropertyChangeListener(listener);
	}
	
	public void removePropertyChangedListener(PropertyChangeListener listener) {
		listeners.removePropertyChangeListener(listener);
	}
	
	public PropertyChangeSupport getListeners() {
		return this.listeners;
	}
	

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Rectangle getLayout() {
		return layout;
	}

	public void setLayout(Rectangle newLayout) {
		Rectangle oldLayout = this.layout;
		this.layout = newLayout;
		getListeners().firePropertyChange(PROPERTY_LAYOUT, oldLayout, newLayout);
	}

	public List<Node> getChildrenArray() {
		return children;
	}

	public Node getParent() {
		return parent;
	}

	public void setParent(Node parent) {
		this.parent = parent;
	}
	
	public boolean addChild(Node child) {
		boolean b = this.children.add(child);
		if (b) {
			child.setParent(this);
			getListeners().firePropertyChange(PROPERTY_ADD, null, child);
		}
			
		return b;
	}
	
	public boolean removeChild(Node child) {
		boolean b = this.children.remove(child);
		if (b) {
			child.setParent(null);
			getListeners().firePropertyChange(PROPERTY_REMOVE, child, null);
		}
		return b;
	}
	

}
