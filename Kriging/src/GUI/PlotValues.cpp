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
	
	 const double lesser = MIN(width, height);
	
	defineBackgroud(cr,width,height);

	defineAxis(cr,width,height);
	this->scaleAxisX = 30;
	this->scaleAxisY = 30;
	
	defineTabulatios(cr,width,height,this->scaleAxisX,this->scaleAxisY);
	
	writeScaleAxis(cr,this->scaleUnitX,this->scaleUnitY);
	
	ploData(cr);
	
  return true;
}
void PlotValues::defineAxis(const Cairo::RefPtr<Cairo::Context>& cr,double w,double h)
{
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

		cr->save();
		// Position the text in the middle
		cr->move_to(10,this->tabulationY.at(index)-10);
		layout->show_in_cairo_context(cr);
		numberY = numberY+scaleY;
		cr->stroke();
	}
//WIRTE AXIS X
	for(int index = 0; index < this->tabulationX.size();index++)
	{
		
		std::ostringstream convert;
		convert << numberX;
		std::string writeX = convert.str();
	
		auto layout = create_pango_layout(writeX);
		layout->set_font_description(font);
		cr->save();
		
		// Position the text in the middle
		cr->move_to(this->tabulationX.at(index)-40,height-40);
		layout->show_in_cairo_context(cr);
		cr->stroke();
		numberX = numberX+scaleX;
	}

}
void PlotValues::setDataX(std::vector<double> d)
{
	this->dataX = d;
}
void PlotValues::setDataY(std::vector<double> d)
{
	this->dataY = d;
}
void PlotValues::setDataExpo(std::vector<double> d)
{
	this->dataExpo = d;
}
void PlotValues::drawCircle(const Cairo::RefPtr<Cairo::Context>& cr,double x,double y,double lesser,double r,double g,double b)
{
	cr->save();
	//cr->arc(x, y, lesser / 4.0, 0.0, 2.0 * M_PI); // full circle
	cr->arc(x, y, lesser / 4.0, 0.0, 2.0 * M_PI); // full circle
	cr->set_source_rgba(r, g, b, 0.6);    // partially translucent
	cr->fill_preserve();
	cr->restore();  // back to opaque black
	cr->stroke();
}
void PlotValues::ploData(const Cairo::RefPtr<Cairo::Context>& cr)
{
	Gtk::Allocation allocation = get_allocation();
	const double width = allocation.get_width();
	const double height = allocation.get_height();
	double dX = 0;
	double dY = 0;
	double dEXP = 0;
	
	std::cout<<"Plot data."<<std::endl;
std::cout<<" X \t\t Y "<<std::endl;
	for(int index = 0; index < this->dataX.size();index++)
	{
		//std::cout<<"Plot values"<<std::endl;
		dX = this->dataX.at(index);
		dY = this->dataY.at(index);
		dEXP = this->dataExpo.at(index);
		
		dX = ( this->scaleAxisX * dX )/this->scaleUnitX;
		dY = ( this->scaleAxisY * dY )/this->scaleUnitY;
		dEXP = ( this->scaleAxisY * dEXP )/this->scaleUnitY;
		
		
		dX = dX+30;
		dY = dY+40;
		dEXP = dEXP+40;
		
		
		std::cout<<dX<<"\t"<<dY<<std::endl;
		drawCircle(cr,dX,height-dY,20,0,0,0);
		drawCircle(cr,dX,height-dEXP,20,255,0,0);
	}
}

void PlotValues::plotPoints(const Cairo::RefPtr<Cairo::Context>& cr)
{
	Gtk::Allocation allocation = get_allocation();
	const double width = allocation.get_width();
	const double height = allocation.get_height();
	double dX = 0;
	double dY = 0;
	double dZ = 0;
	
	std::cout<<"Plot data."<<std::endl;
	std::cout<<" X \t\t Y "<<std::endl;
	for(int index = 0; index < this->dataX.size();index++)
	{
		//std::cout<<"Plot values"<<std::endl;
		dX = this->dataX.at(index);
		dY = this->dataY.at(index);
		dZ = this->dataExpo.at(index);
		
		dX = ( this->scaleAxisX * dX )/this->scaleUnitX;
		dY = ( this->scaleAxisY * dY )/this->scaleUnitY;
		
		dX = dX+30;
		dY = dY+40;
		
		
		std::cout<<dX<<"\t"<<dY<<std::endl;
		drawCircle(cr,dX,height-dY,20,( (dZ*100) /255),( (dZ*100) /255),( (dZ*100) /255) ) ;

	}
}
void PlotValues::setScaleUnitX(double xUnit)
{
	this->scaleUnitX = xUnit;
}
void PlotValues::setScaleUnitY(double yUnit)
{
	this->scaleUnitY = yUnit;
}


// force the redraw of the image
void PlotValues::force_redraw()
{

}