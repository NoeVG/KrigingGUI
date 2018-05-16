#ifndef PLOTVALUES_H
#define PLOTVALUES_H

#include <gtkmm/drawingarea.h>
#include <iostream>
#include <vector>

class PlotValues: public Gtk::DrawingArea
{
public:
	PlotValues();
	~PlotValues();

private:
	void defineAxis(const Cairo::RefPtr<Cairo::Context>& cr,double,double);
	void defineBackgroud(const Cairo::RefPtr<Cairo::Context>& cr,double,double);
	void defineTabulatios(const Cairo::RefPtr<Cairo::Context>& cr,double,double,double,double);
	void writeScaleAxis(const Cairo::RefPtr<Cairo::Context>& cr,double,double);
	
protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
private:
	std::vector<double> tabulationX;
	std::vector<double> tabulationY;
	
};

#endif // PLOTVALUES_H
