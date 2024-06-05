// ===========================================================================
// Main.cpp  // Namespaces
// ===========================================================================

// want to prevent some annoying warnings: "warning C4101 : 'tb1' : unreferenced local variable"
#pragma warning(push)
#pragma warning(disable : 4101)

// this is the top level namespace
const double Pi = 3.14159265358979323846;

namespace MyFirstProject
{
    namespace Widgets
    {
        class Textbox
        {
        };
    }
}

namespace AnotherProject
{
    class Textbox
    {
    };
}

static void namespace_01()
{
    using namespace MyFirstProject::Widgets;
    // or
    // using namespace AnotherProject;

    Textbox tb1;                             // namespace MyFirstProject::Widgets
                                             
    MyFirstProject::Widgets::Textbox tb2;    // namespace MyFirstProject::Widgets

    AnotherProject::Textbox tb3;             // namespace AnotherProject
}

static void namespace_02()
{
    // accessing classes with full namespace specification
    using namespace MyFirstProject::Widgets;
    Textbox tb1;

    using namespace AnotherProject;
    // Textbox tb2;                          // doesn't compile: why
}

static void namespace_03()
{
    // better way
    MyFirstProject::Widgets::Textbox tb;

    // or - possible - but 'smells'
    using namespace MyFirstProject::Widgets;

    Textbox tb2;
}

void main_Namespaces()
{
    namespace_01();
    namespace_02();
    namespace_03();
}

#pragma warning(pop)

// ===========================================================================
// End-of-File
// ===========================================================================
