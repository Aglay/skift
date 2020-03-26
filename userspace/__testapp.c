/* Copyright © 2018-2020 N. Van Bossuyt.                                      */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

#include <libsystem/io/Stream.h>

#include <libwidget/Widgets.h>
#include <libwidget/core/Application.h>

int main(int argc, char **argv)
{
    __unused(argc);
    __unused(argv);

    application_initialize(argc, argv);

    Widget *panel0 = panel_create(NULL, RECTANGLE(100, 100, 150, 150));

    panel_create(panel0, RECTANGLE(0, 0, 50, 100));
    panel_create(panel0, RECTANGLE(50, 0, 50, 100));
    panel_create(panel0, RECTANGLE(0, 100, 100, 50));

    Window *main_window = window_create(RECTANGLE_SIZE(500, 400));
    window_set_main_widget(main_window, panel0);

    application_dump();

    return application_run();
}
