#ifndef WINDOWGUI_H
#define WINDOWGUI_H

#include <gtkmm.h>
#include "PlotValues.h"
#include "ModelColumns.h"
#include "Kriging.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>


class WindowGUI: public Gtk::Window
{
public:
	WindowGUI(std::string,int,int);
	~WindowGUI();
	

private:
	Gtk::Frame mainFrame,dataFrame,dataRamdomFrame,tableFrame,dataComputedFrame,graphicModelFrame;
	Gtk::Frame setupEmpiricalSemivariogramFrame,empiricalSemivariogramFrame,setupBinningSemivariogramFrame,binningSemivariogramFrame;
	Gtk::Frame frameMatrix;
	Gtk::Frame frameKrigingAproximation;
	Gtk::Grid gridData,gridDataRamdom,gridDataTable,gridLoadDataTable;
	Gtk::Grid gridSetupEmpiricalSemivariogram;
	Gtk::Grid gridBinningSemivariogram,gridSetupBinningSemivariogram;
	Gtk::Grid gridKrigingAproximation;
	Gtk::Entry entryLocationX,entryLocationY,entryPropertyZ,entryRandomSize;
	Gtk::Entry entryThreadsDistances,entryThreadsDiference,entryThreadsSemivariance;
	Gtk::Entry entryThreadsAverageDistances,entryThreadsAverageSemivariance,entryBin;
	Gtk::Button buttonRamdomValues,buttonSetValue,buttonLoadValuesTable,buttonGenerateMatrixImage;
	Gtk::Button buttonThreadDistances,buttonThreadDiference,buttonThreadSemivariance,buttonCalcSemivariogramEmpirical;
	Gtk::Button buttonCalcBinningSemivariogram;
	Gtk::Button buttonCalcKrigin;
	PlotValues plot,plotMatrixData;
	Kriging krigin;
	Gtk::Window windowMatrix;

protected:
	Gtk::Box m_VBox;
	Gtk::Box dataVBox,dataComputedVBox;
	
	Gtk::Label labelLocationX,labelLocationY,labelPropertyZ,labelRandom;
	Gtk::Label labelThreadDistance,labelThreadDiference,labelThreadSemivariance;
	Gtk::Label labelThreadAverageDistance,labelThreadAverageSemivariance,labelBin;
	
	
	ModelColumns m_ColumnsData;
	ModelColumns m_ColumnsSemivariogram;
	ModelColumns m_ColumnsAverageSemivariogram;
	
	//Gtk::ScrolledWindow plotScrolledWindow;
	Gtk::ScrolledWindow m_ScrolledWindow;
	Gtk::ScrolledWindow m_ScrolledWindowSemivariogram;
	Gtk::ScrolledWindow m_ScrolledWindowAverageSemivariogram;
	//Gtk::ScrolledWindow scrollWindowDataCompued;
	
	Gtk::TreeView m_TreeView;
	Gtk::TreeView m_TreeViewSemivariogram;
	Gtk::TreeView m_TreeViewAverageSemivariogram;
	
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModelSemivariogram;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModelAverageSemivariogram;
	
	void on_buttonRamdomValues_click();
	void on_buttonGenerateMatrix_click();
	void on_buttonCalcSemivariogram_click();
	void on_buttonCalcAverageSemivariogram_click();
	
	
	
};

#endif // WINDOWGUI_H
