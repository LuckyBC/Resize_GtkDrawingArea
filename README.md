# Resize_GtkDrawingArea

cd GtkDrawingArea

cc main.c -Wl,--export-dynamic  `pkg-config --cflags --libs gtk+-3.0`
