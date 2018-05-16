#ifndef MODELCOLUMNS_H
#define MODELCOLUMNS_H

#include <gtkmm.h>

class ModelColumns : public Gtk::TreeModel::ColumnRecord
{
public:
	ModelColumns();
	
	~ModelColumns();
	
	Gtk::TreeModelColumn<int> m_col_id;
    Gtk::TreeModelColumn<double> m_col_ValeA;
    Gtk::TreeModelColumn<double> m_col_ValeB;
    Gtk::TreeModelColumn<double> m_col_ValeC;
	

};

#endif // MODELCOLUMNS_H
