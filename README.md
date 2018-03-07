# Resize_GtkDrawingArea

Resize_GtkDrawingArea is a demo show us how to resize A GtkDrawingArea by width and height GtkSpinButtons.

cd GtkDrawingArea

cc main.c -Wl,--export-dynamic  `pkg-config --cflags --libs gtk+-3.0`
