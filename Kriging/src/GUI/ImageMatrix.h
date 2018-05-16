#ifndef IMAGEMATRIX_H
#define IMAGEMATRIX_H

#include <gtkmm/drawingarea.h>

class ImageMatrix : public Gtk::DrawingArea
{
public:
	ImageMatrix();
	~ImageMatrix();

protected:
  //Override default signal handler:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
private:
void draw_rectangle(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);

};

#endif // IMAGEMATRIX_H
