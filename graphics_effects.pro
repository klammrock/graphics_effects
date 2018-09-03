TEMPLATE = subdirs

SUBDIRS += \
    graphics_w_ui \
    graphics_core

graphics_w_ui.depends = graphics_core
