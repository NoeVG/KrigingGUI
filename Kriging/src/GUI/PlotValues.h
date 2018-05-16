#ifndef PLOTVALUES_H
#define PLOTVALUES_H

#include <gtkmm/drawingarea.h>

class PlotValues: public Gtk::DrawingArea
{
public:
	PlotValues();
	~PlotValues();

protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

};

#endif // PLOTVALUES_H
