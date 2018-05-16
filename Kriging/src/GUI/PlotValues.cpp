#include "PlotValues.h"

PlotValues::PlotValues()
{
		
}

PlotValues::~PlotValues()
{
}

bool PlotValues::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
	const double width = allocation.get_width();
	const double height = allocation.get_height();
	
	defineBackgroud(cr,width,height);

	defineAxis(cr,width,height);
	
	defineTabulatios(cr,width,height,30,30);
	
	writeScaleAxis(cr,0.1,1);
  return true;
}
void PlotValues::defineAxis(const Cairo::RefPtr<Cairo::Context>& cr,double w,double h){
	const double width = w;
	const double height = h;
	//axis Y
	cr->save();
	cr->set_line_width(5.0);
	// draw red lines out from the center of the window
	cr->set_source_rgb(0.0, 255, 0.0);
	cr->move_to(30, 20);
	cr->line_to(30, height-30);
	cr->stroke();
	
	//axis X
	cr->save();
	cr->set_line_width(5.0);
	// draw red lines out from the center of the window
	cr->set_source_rgb(255, 0.0, 0.0);
	cr->move_to(20,height-40);
	cr->line_to(width-20, height-40);
	cr->stroke();
}
void PlotValues::defineBackgroud(const Cairo::RefPtr<Cairo::Context>& cr,double w,double h)
{
	const double width = w;
	const double height = h;

	cr->save();
	cr->set_source_rgb(255, 255, 200);
	
	cr->rectangle(20, 20, width-30, height-50);
	cr->fill();
	cr->stroke();
}

void PlotValues::defineTabulatios(const Cairo::RefPtr<Cairo::Context>& cr,double w,double h,double scaleX,double scaleY)
{
	const double width = w;
	const double height = h;
	
	this->tabulationX.clear();
	this->tabulationY.clear();
	
	for(double unit = (2); unit <= width; unit++)
	{
	this->tabulationX.push_back((unit*scaleX));
		//axis Y
		cr->save();
		cr->set_line_width(1.0);
		// draw red lines out from the center of the window
		cr->set_source_rgb(0.0, 0.0, 0.0);
		cr->move_to(unit*scaleX,height-40);
		cr->line_to(unit*scaleX, 20);
		cr->stroke();
	}
	for(double unit = (height-40); unit > 20 ; unit-=scaleY)
	{
		this->tabulationY.push_back(unit);
		//axis Y
		cr->save();
		cr->set_line_width(1.0);
		// draw red lines out from the center of the window
		cr->set_source_rgb(0.0, 0.0, 0.0);
		cr->move_to(20,unit);
		cr->line_to(width-20, unit);
		cr->stroke();

	}

}
void PlotValues::writeScaleAxis(const Cairo::RefPtr<Cairo::Context>& cr,double scaleX,double scaleY)
{
	 Gtk::Allocation allocation = get_allocation();
	//const double width = allocation.get_width();
	const double height = allocation.get_height();

	double numberY = 0;
	double numberX = 0;
	
	Pango::FontDescription font;
	
	
	font.set_family("Monospace");
	font.set_weight(Pango::WEIGHT_BOLD);


//WIRTE AXIS Y
	for(int index = 0; index < this->tabulationY.size();index++)
	{
		
		std::ostringstream convert;
		convert << numberY;
		std::string writeY = convert.str();
	
		auto layout = create_pango_layout(writeY);
		layout->set_font_description(font);

		
		// Position the text in the middle
		cr->move_to(10,this->tabulationY.at(index)-10);
		layout->show_in_cairo_context(cr);
		numberY = numberY+scaleY;
	}
//WIRTE AXIS X
	for(int index = 0; index < this->tabulationX.size();index++)
	{
		
		std::ostringstream convert;
		convert << numberX;
		std::string writeX = convert.str();
	
		auto layout = create_pango_layout(writeX);
		layout->set_font_description(font);

		
		// Position the text in the middle
		cr->move_to(this->tabulationX.at(index)-10,height-40);
		layout->show_in_cairo_context(cr);
		numberX = numberX+scaleX;
	}

}
