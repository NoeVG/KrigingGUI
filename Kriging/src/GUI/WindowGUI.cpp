#include "WindowGUI.h"

WindowGUI::WindowGUI(std::string title,int width,int heigth)
: m_VBox(Gtk::ORIENTATION_HORIZONTAL),
dataVBox(Gtk::ORIENTATION_VERTICAL),
dataComputedVBox(Gtk::ORIENTATION_VERTICAL),
   labelLocationX("Position X",false),
   labelLocationY("Position Y",false),
  labelPropertyZ("Value Z",false),
  labelRandom("Random values",false),
  labelThreadDistance("# Thread calc distance",false),
  labelThreadDiference("# Thread calc diference",false),
  labelThreadSemivariance("# Thread calc Semivarience",false),
  labelThreadAverageDistance("# Thread calc Ave distance",false),
  labelThreadAverageSemivariance("# Thread calc Ave semivariance",false),
  labelBin("Value Bin",false)
{
	set_title(title);
	set_size_request(width,heigth);
	
	/* Sets the border width of the window. */
	set_border_width(5);
			
	mainFrame.set_label(get_title());
	
	//m_VBox.set_border_width(10);
	
	
	dataFrame.set_label("Values");
	dataFrame.set_border_width(5);
	
	labelLocationX.set_size_request(20,10);
	labelLocationY.set_size_request(20,10);
	labelPropertyZ.set_size_request(20,10);
	
	entryLocationX.set_text("0.00");
	entryLocationY.set_text("0.00");
	entryPropertyZ.set_text("0.00");
	buttonSetValue.set_label("Set values");
		
	gridData.add(labelLocationX);
	gridData.add(entryLocationX);
	gridData.attach_next_to(labelLocationY,labelLocationX,Gtk::POS_BOTTOM, 1, 1);
	gridData.attach_next_to(entryLocationY,entryLocationX,Gtk::POS_BOTTOM, 1, 1);	
	gridData.attach_next_to(labelPropertyZ,labelLocationY,Gtk::POS_BOTTOM, 1, 1);
	gridData.attach_next_to(entryPropertyZ,entryLocationY,Gtk::POS_BOTTOM, 1, 1);
	gridData.attach_next_to(buttonSetValue,entryPropertyZ,Gtk::POS_BOTTOM, 1, 1);
	/*gridData.attach_next_to(entryPropertyZ,labelPropertyZ,Gtk::POS_BOTTOM, 1, 1);
	
	gridData.attach_next_to(buttonRamdomValues,entryLocationX,Gtk::POS_BOTTOM, 1, 1);
	gridData.attach_next_to(buttonSetValue,entryPropertyZ,Gtk::POS_BOTTOM, 1, 1);
	*/
	gridData.set_size_request(100,100);
	gridData.set_row_spacing(10);
	dataFrame.add(gridData);
	dataFrame.set_size_request(100,100);
	
	dataVBox.add(dataFrame);
	
	dataRamdomFrame.set_label("Values Random.");
	dataRamdomFrame.set_border_width(10);
	entryRandomSize.set_text("10");
	buttonRamdomValues.set_label("Generate");
	buttonRamdomValues.signal_clicked().connect( sigc::mem_fun(*this,
              &WindowGUI::on_buttonRamdomValues_click) );
	
	gridDataRamdom.add(labelRandom);
	gridDataRamdom.add(entryRandomSize);
	gridDataRamdom.add(buttonRamdomValues);
	
	dataRamdomFrame.add(gridDataRamdom);
	dataVBox.add(dataRamdomFrame);

	//Add the TreeView, inside a ScrolledWindow, with the button underneath:
	m_ScrolledWindow.add(m_TreeView);

	//Only show the scrollbars when they are necessary:
	m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);


	tableFrame.set_label("Data.");
	tableFrame.set_border_width(10);
	tableFrame.add(m_ScrolledWindow);
	tableFrame.set_size_request(100,400);
	dataVBox.add(tableFrame);
	
	buttonLoadValuesTable.set_label("Load Values");
	buttonGenerateMatrixImage.set_label("Generate Matrix");
	gridLoadDataTable.set_border_width(10);
	gridLoadDataTable.add(buttonLoadValuesTable);
	gridLoadDataTable.add(buttonGenerateMatrixImage);
	dataVBox.add(gridLoadDataTable);
	
	//Create the Tree model:
	m_refTreeModel = Gtk::ListStore::create(m_ColumnsData);
	m_TreeView.set_model(m_refTreeModel);
  
  /*
	//Fill the TreeView's model
	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	row[m_ColumnsData.m_col_id] = 1;
	row[m_ColumnsData.m_col_ValeA] = 1;
	row[m_ColumnsData.m_col_ValeB] = 1;
	row[m_ColumnsData.m_col_ValeC] = 10;
 */
	//Add the TreeView's view columns:
	//This number will be shown with the default numeric formatting.
	m_TreeView.append_column("ID", m_ColumnsData.m_col_id);
	m_TreeView.append_column("Position X", m_ColumnsData.m_col_ValeA);
	m_TreeView.append_column("Position Y", m_ColumnsData.m_col_ValeB);
	m_TreeView.append_column("Property Z", m_ColumnsData.m_col_ValeC);
  


	//Make all the columns reorderable:
	//This is not necessary, but it's nice to show the feature.
	//You can use TreeView::set_column_drag_function() to more
	//finely control column drag and drop.

	for(guint i = 0; i < 2; i++)
	{
	auto column = m_TreeView.get_column(i);
	column->set_reorderable();
	}
   
	m_VBox.add(dataVBox);
	
	dataComputedFrame.set_label("Data computed");
	
	setupEmpiricalSemivariogramFrame.set_label("Setup Semivariogram Empirical");
	setupEmpiricalSemivariogramFrame.set_size_request(300,50);
	setupEmpiricalSemivariogramFrame.set_border_width(10);
	
	entryThreadsDistances.set_text("1");
	entryThreadsDiference.set_text("1");
	entryThreadsSemivariance.set_text("1");
	
	buttonThreadDistances.set_label("Set thread");
	buttonThreadDiference.set_label("Set thread");
	buttonThreadSemivariance.set_label("Set thread");
	buttonCalcSemivariogramEmpirical.set_label("Calculate");
	buttonCalcSemivariogramEmpirical.signal_clicked().connect( sigc::mem_fun(*this,
              &WindowGUI::on_buttonCalcSemivariogram_click) );
	
	
	gridSetupEmpiricalSemivariogram.add(labelThreadDistance);
	gridSetupEmpiricalSemivariogram.add(entryThreadsDistances);
	//gridSetupEmpiricalSemivariogram.add(buttonThreadDistances);
	gridSetupEmpiricalSemivariogram.attach_next_to(labelThreadDiference,labelThreadDistance,Gtk::POS_BOTTOM,1,1);
	gridSetupEmpiricalSemivariogram.attach_next_to(entryThreadsDiference,entryThreadsDistances,Gtk::POS_BOTTOM,1,1);
	//gridSetupEmpiricalSemivariogram.attach_next_to(buttonThreadDiference,buttonThreadDistances,Gtk::POS_BOTTOM,1,1);
	gridSetupEmpiricalSemivariogram.attach_next_to(labelThreadSemivariance,labelThreadDiference,Gtk::POS_BOTTOM,1,1);
	gridSetupEmpiricalSemivariogram.attach_next_to(entryThreadsSemivariance,entryThreadsDiference,Gtk::POS_BOTTOM,1,1);
	//gridSetupEmpiricalSemivariogram.attach_next_to(buttonThreadSemivariance,buttonThreadDiference,Gtk::POS_BOTTOM,1,1);
	gridSetupEmpiricalSemivariogram.attach_next_to(buttonCalcSemivariogramEmpirical,labelThreadSemivariance,Gtk::POS_BOTTOM,2,1);
	
	setupEmpiricalSemivariogramFrame.add(gridSetupEmpiricalSemivariogram);
	dataComputedVBox.add(setupEmpiricalSemivariogramFrame);
	
	
	empiricalSemivariogramFrame.set_label("Semivariogram empirical.");
	empiricalSemivariogramFrame.set_size_request(300,150);
	empiricalSemivariogramFrame.set_border_width(10);
		//Add the TreeView, inside a ScrolledWindow, with the button underneath:
	m_ScrolledWindowSemivariogram.add(m_TreeViewSemivariogram);

	//Only show the scrollbars when they are necessary:
	m_ScrolledWindowSemivariogram.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	empiricalSemivariogramFrame.add(m_ScrolledWindowSemivariogram);
	
	//Create the Tree model:
	m_refTreeModelSemivariogram = Gtk::ListStore::create(m_ColumnsSemivariogram);
	m_TreeViewSemivariogram.set_model(m_refTreeModelSemivariogram);
	
	/*
	//Fill the TreeView's model
	Gtk::TreeModel::Row rowSemivariogram = *(m_refTreeModelSemivariogram->append());
	rowSemivariogram[m_ColumnsSemivariogram.m_col_id] = 1;
	rowSemivariogram[m_ColumnsSemivariogram.m_col_ValeA] = 2;
	rowSemivariogram[m_ColumnsSemivariogram.m_col_ValeB] = 2;
	rowSemivariogram[m_ColumnsSemivariogram.m_col_ValeC] = 20;
	*/
	//Add the TreeView's view columns:
	//This number will be shown with the default numeric formatting.
	m_TreeViewSemivariogram.append_column("ID", m_ColumnsSemivariogram.m_col_id);
	m_TreeViewSemivariogram.append_column("Distances", m_ColumnsSemivariogram.m_col_ValeA);
	m_TreeViewSemivariogram.append_column("Diferences", m_ColumnsSemivariogram.m_col_ValeB);
	m_TreeViewSemivariogram.append_column("Semivariance", m_ColumnsSemivariogram.m_col_ValeC);
 
	dataComputedVBox.add(empiricalSemivariogramFrame);
	
	setupBinningSemivariogramFrame.set_label("Setup Binning Semivariogram");
	setupBinningSemivariogramFrame.set_size_request(300,50);
	setupBinningSemivariogramFrame.set_border_width(10);
	entryThreadsAverageDistances.set_text("1");
	entryThreadsAverageSemivariance.set_text("1");
	entryBin.set_text("1");
	buttonCalcBinningSemivariogram.set_label("Calculated");
	buttonCalcBinningSemivariogram.signal_clicked().connect( sigc::mem_fun(*this,
              &WindowGUI::on_buttonCalcAverageSemivariogram_click) );
	
	gridSetupBinningSemivariogram.add(labelThreadAverageDistance);
	gridSetupBinningSemivariogram.add(entryThreadsAverageDistances);
	gridSetupBinningSemivariogram.attach_next_to(labelThreadAverageSemivariance,labelThreadAverageDistance,Gtk::POS_BOTTOM,1,1);
	gridSetupBinningSemivariogram.attach_next_to(entryThreadsAverageSemivariance,entryThreadsAverageDistances,Gtk::POS_BOTTOM,1,1);
	gridSetupBinningSemivariogram.attach_next_to(labelBin,labelThreadAverageSemivariance,Gtk::POS_BOTTOM,1,1);
	gridSetupBinningSemivariogram.attach_next_to(entryBin,entryThreadsAverageSemivariance,Gtk::POS_BOTTOM,1,1);
	gridSetupBinningSemivariogram.attach_next_to(buttonCalcBinningSemivariogram,labelBin,Gtk::POS_BOTTOM,2,1);
	setupBinningSemivariogramFrame.add(gridSetupBinningSemivariogram);
	
	dataComputedVBox.add(setupBinningSemivariogramFrame);
	
	
	binningSemivariogramFrame.set_label("Binning Semivariogram");
	binningSemivariogramFrame.set_size_request(300,200);
	
			//Add the TreeView, inside a ScrolledWindow, with the button underneath:
	m_ScrolledWindowAverageSemivariogram.add(m_TreeViewAverageSemivariogram);

	//Only show the scrollbars when they are necessary:
	m_ScrolledWindowAverageSemivariogram.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	binningSemivariogramFrame.add(m_ScrolledWindowAverageSemivariogram);
	
	//Create the Tree model:
	m_refTreeModelAverageSemivariogram = Gtk::ListStore::create(m_ColumnsAverageSemivariogram);
	m_TreeViewAverageSemivariogram.set_model(m_refTreeModelAverageSemivariogram);
	
	/*
	//Fill the TreeView's model
	Gtk::TreeModel::Row rowSemivariogram = *(m_refTreeModelSemivariogram->append());
	rowSemivariogram[m_ColumnsSemivariogram.m_col_id] = 1;
	rowSemivariogram[m_ColumnsSemivariogram.m_col_ValeA] = 2;
	rowSemivariogram[m_ColumnsSemivariogram.m_col_ValeB] = 2;
	rowSemivariogram[m_ColumnsSemivariogram.m_col_ValeC] = 20;
	*/
	//Add the TreeView's view columns:
	//This number will be shown with the default numeric formatting.
	m_TreeViewAverageSemivariogram.append_column("ID", m_ColumnsAverageSemivariogram.m_col_id);
	m_TreeViewAverageSemivariogram.append_column("Ave distances", m_ColumnsAverageSemivariogram.m_col_ValeA);
	m_TreeViewAverageSemivariogram.append_column("Ave semivariance", m_ColumnsAverageSemivariogram.m_col_ValeB);
	m_TreeViewAverageSemivariogram.append_column("Model Expo", m_ColumnsAverageSemivariogram.m_col_ValeC);

	
	dataComputedVBox.add(binningSemivariogramFrame);
	
	dataComputedFrame.add(dataComputedVBox);
	m_VBox.add(dataComputedFrame);
	
	graphicModelFrame.set_label("Graphic Model");
	ImageMatrix myArea;
	//graphicModelFrame.add(myArea);
	m_VBox.add(graphicModelFrame);
	
	mainFrame.add(m_VBox);
	
	add(mainFrame);
	
	show_all();
}

WindowGUI::~WindowGUI()
{
	
}
void WindowGUI::on_buttonRamdomValues_click(){
	std::string::size_type sz;
	std::cout<<"Event generate random values"<<std::endl;
	krigin.generateRandomValues(std::stoi(this->entryRandomSize.get_text(),&sz));
	
	//Fill the TreeView's model
	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	
	for(int index = 0; index < krigin.getValuesX().size(); index++)
	{
		row[m_ColumnsData.m_col_id] = index;
		row[m_ColumnsData.m_col_ValeA] = krigin.getValuesX().at(index);
		row[m_ColumnsData.m_col_ValeB] = krigin.getValuesY().at(index);;
		row[m_ColumnsData.m_col_ValeC] = krigin.getValuesZ().at(index);;
		row = *(m_refTreeModel->append());
	}
}
void WindowGUI::on_buttonCalcSemivariogram_click()
{
	std::string::size_type sz;
	
	int threadDistance = std::stoi(this->entryThreadsDistances.get_text(),&sz);
	int threadDiference = std::stoi(this->entryThreadsDiference.get_text(),&sz);;
	int threadSemivariance = std::stoi(this->entryThreadsSemivariance.get_text(),&sz);;
	
	krigin.calcSemivariogramEmpirical(threadDistance,threadDiference,threadSemivariance);
	
	
	
	//Fill the TreeView's model
	Gtk::TreeModel::Row rowSemivariogram = *(m_refTreeModelSemivariogram->append());
	for(int index = 0; index < krigin.getDistances().size();index++)
	{
		rowSemivariogram[m_ColumnsSemivariogram.m_col_id] = index;
		rowSemivariogram[m_ColumnsSemivariogram.m_col_ValeA] = krigin.getDistances().at(index);
		rowSemivariogram[m_ColumnsSemivariogram.m_col_ValeB] = krigin.getDiferencesSquard().at(index);
		rowSemivariogram[m_ColumnsSemivariogram.m_col_ValeC] = krigin.getSemivariance().at(index);
		rowSemivariogram = *(m_refTreeModelSemivariogram->append());
	}
	
}
void WindowGUI::on_buttonCalcAverageSemivariogram_click()
{
	std::string::size_type sz;
	
	int threadAverageDistance = std::stoi(this->entryThreadsAverageDistances.get_text(),&sz);
	int threadAverageSemivariance = std::stoi(this->entryThreadsAverageSemivariance.get_text(),&sz);;
	int dataBin = std::stoi(this->entryBin.get_text(),&sz);
	
	krigin.calcAverageSemivariogramEmpirical(threadAverageDistance,threadAverageSemivariance,dataBin);

	//Fill the TreeView's model
	Gtk::TreeModel::Row rowAverageSemivariogram = *(m_refTreeModelAverageSemivariogram->append());
	for(int index = 0; index < krigin.getAverageDistance().size();index++)
	{
		rowAverageSemivariogram[m_ColumnsAverageSemivariogram.m_col_id] = index;
		rowAverageSemivariogram[m_ColumnsAverageSemivariogram.m_col_ValeA] = krigin.getAverageDistance().at(index);
		rowAverageSemivariogram[m_ColumnsAverageSemivariogram.m_col_ValeB] = krigin.getSemivariance().at(index);
		rowAverageSemivariogram[m_ColumnsAverageSemivariogram.m_col_ValeC] = krigin.getDatosExponentialModelFunction().at(index);
		rowAverageSemivariogram = *(m_refTreeModelAverageSemivariogram->append());
	}
}
