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
  const int width = allocation.get_width();
  const int height = allocation.get_height();

	cr->save();
	cr->set_line_width(10.0);
	// draw red lines out from the center of the window
	cr->set_source_rgb(0.8, 0.0, 0.0);
	cr->move_to(30, 20);
	cr->line_to(30, height-30);
	cr->stroke();
	
	cr->save();
	cr->set_line_width(10.0);
	// draw red lines out from the center of the window
	cr->set_source_rgb(0.0, 0.0, 255);
	cr->move_to(20,height-40);
	cr->line_to(width-20, height-40);
	cr->stroke();

  return true;
}
