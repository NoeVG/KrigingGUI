#include "ImageMatrix.h"

ImageMatrix::ImageMatrix()
{
	
}

ImageMatrix::~ImageMatrix()
{
}
bool ImageMatrix::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{

	// Draw a black rectangle
  cr->set_source_rgb(255, 255, 255);
				// rectangle_width, rectangle_height
  draw_rectangle(cr, 100, 100);
}
void ImageMatrix::draw_rectangle(const Cairo::RefPtr<Cairo::Context>& cr,
                            int width, int height)
{
  cr->rectangle(0, 0, width, height);
  cr->fill();
}