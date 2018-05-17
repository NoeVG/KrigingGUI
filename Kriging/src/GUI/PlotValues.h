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
	
	void setDataX(std::vector<double>);
	void setDataY(std::vector<double>);
	void setDataExpo(std::vector<double>);
	void force_redraw();
	void setScaleUnitX(double);
	void setScaleUnitY(double);
	
	void setOptionPlot(int);
private:
	void defineAxis(const Cairo::RefPtr<Cairo::Context>& cr,double,double);
	void defineBackgroud(const Cairo::RefPtr<Cairo::Context>& cr,double,double);
	void defineTabulatios(const Cairo::RefPtr<Cairo::Context>& cr,double,double,double,double);
	void writeScaleAxis(const Cairo::RefPtr<Cairo::Context>& cr,double,double);
	void ploData(const Cairo::RefPtr<Cairo::Context>& cr);
	void drawCircle(const Cairo::RefPtr<Cairo::Context>& cr,double,double,double,double,double,double);
	void plotPoints(const Cairo::RefPtr<Cairo::Context>& cr);
	
protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
private:
	int scaleAxisX;
	int scaleAxisY;
	
	double scaleUnitX;
	double scaleUnitY;
	
	int optionPlot;
	
	std::vector<double> tabulationX;
	std::vector<double> tabulationY;
	
	std::vector<double> dataX;
	std::vector<double> dataY;
	std::vector<double> dataExpo;
	
	
};

#endif // PLOTVALUES_H
