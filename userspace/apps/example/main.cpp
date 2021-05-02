#include <libwidget/Application.h>
#include <libwidget/Components.h>
#include <libwidget/Layouts.h>
#include <libwidget/Window.h>

using namespace Widget;

struct CounterComponent : public Statefull<int>
{
    RefPtr<Element> build(int state) override
    {
        return hflow({
            fill(label(IO::format("You clicked {} times", state))),
            basic_button("Click Me!", [this, state] { update(state + 1); }),
        });
    }
};

WIDGET_BUILDER(CounterComponent, counter);

struct MainWindow : public Window
{
    RefPtr<Element> build() override
    {
        return vflow({
            titlebar(Graphic::Icon::get("duck"), "Example"),
            spacing(16, counter()),
        });
    }
};

struct ExampleApplication : public Application
{
    OwnPtr<Window> build() override
    {
        return own<MainWindow>();
    }
};

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    ExampleApplication app;
    return app.run();
}