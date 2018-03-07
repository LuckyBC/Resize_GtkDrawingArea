#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

gboolean
callback_drawing (GtkWidget *widget, cairo_t *cr, gpointer data)
{
  guint width, height;
  GdkRGBA color;
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (widget);

  width = gtk_widget_get_allocated_width (widget);
  height = gtk_widget_get_allocated_height (widget);

  gtk_render_background (context, cr, 0, 0, width, height);

	/* Filled background */
	cairo_set_source_rgb(cr, 1, 0, 0);
	cairo_paint(cr);

	/* Drew a circle on the background */	
  cairo_arc (cr, width / 2.0, height / 2.0, MIN (width, height) / 2.0, 0, 2 * G_PI);
	cairo_set_source_rgb(cr, 1, 0, 1);

  cairo_fill (cr);

 return FALSE;
}

void
callback_change_drawing_height (GtkSpinButton *spin_button,
															  GtkBuilder *builder)
{
	unsigned int width;
	unsigned int height;
	GtkWidget *drawing_area;

	height = (unsigned int) gtk_spin_button_get_value (spin_button);

	printf ("Drawing Height:%u\n", height);

	drawing_area = (GtkWidget*) gtk_builder_get_object (builder, "drawing_area");

	gtk_widget_get_size_request (drawing_area, &width, NULL);
	gtk_widget_set_size_request (drawing_area, width, height);
	gtk_widget_queue_resize (drawing_area);
}

void
callback_change_drawing_width (GtkSpinButton *spin_button,
															 GtkBuilder *builder)
{
	unsigned int width;
	unsigned int height;
	GtkWidget *drawing_area;

	width = (unsigned int) gtk_spin_button_get_value (spin_button);

	printf ("Drawing Width:%u\n", width);

	drawing_area = (GtkWidget*) gtk_builder_get_object (builder, "drawing_area");

	gtk_widget_get_size_request (drawing_area, NULL, &height);
	gtk_widget_set_size_request (drawing_area, width, height);
	gtk_widget_queue_resize (drawing_area);
}

int main (int argc, char **argv)
{
	GtkWidget *window;
	GtkBuilder *builder;

	gtk_init (&argc, &argv);

	builder = gtk_builder_new_from_file ("gui.ui");
	gtk_builder_connect_signals (builder, builder);	
	window = (GtkWidget *) gtk_builder_get_object (builder, "window");

	gtk_widget_show (window);
	gtk_main ();

	return 0;
}
