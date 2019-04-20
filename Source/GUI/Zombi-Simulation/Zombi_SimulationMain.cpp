/***************************************************************
 * Name:      Zombi_SimulationMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Alex ()
 * Created:   2019-04-19
 * Copyright: Alex ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Zombi_SimulationMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Zombi_SimulationFrame)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Zombi_SimulationFrame)
const long Zombi_SimulationFrame::ID_BUTTON1 = wxNewId();
const long Zombi_SimulationFrame::ID_PANEL2 = wxNewId();
const long Zombi_SimulationFrame::ID_PANEL3 = wxNewId();
const long Zombi_SimulationFrame::ID_PANEL1 = wxNewId();
const long Zombi_SimulationFrame::ID_MENUITEM1 = wxNewId();
const long Zombi_SimulationFrame::idMenuAbout = wxNewId();
const long Zombi_SimulationFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Zombi_SimulationFrame,wxFrame)
    //(*EventTable(Zombi_SimulationFrame)
    //*)
END_EVENT_TABLE()

Zombi_SimulationFrame::Zombi_SimulationFrame(wxWindow* parent,wxWindowID id)
{
    RandomGeneratorObject = new RandomGenerator();

    continent = new Continent(NorthAmericaSize, NorthAmerica, humans, zombies, traps, resources, RandomGeneratorObject, 1);
    //(*Initialize(Zombi_SimulationFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BackgroundPanel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(700,421), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BackgroundPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
    ConfigPanel = new wxPanel(BackgroundPanel, ID_PANEL2, wxPoint(0,320), wxSize(700,88), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StartButton = new wxButton(ConfigPanel, ID_BUTTON1, _("Start"), wxPoint(24,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    DisplayPanel = new wxPanel(BackgroundPanel, ID_PANEL3, wxPoint(0,0), wxSize(700,300), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer1->Add(BackgroundPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnStartButtonClick);
    BackgroundPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Zombi_SimulationFrame::OnBackgroundPanelPaint,0,this);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnAbout);
    //*)
}

Zombi_SimulationFrame::~Zombi_SimulationFrame()
{
    //(*Destroy(Zombi_SimulationFrame)
    //*)
}

void Zombi_SimulationFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Zombi_SimulationFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Zombi_SimulationFrame::OnBackgroundPanelPaint(wxPaintEvent& event)
{
}

void Zombi_SimulationFrame::render(wxDC& dc)
{
    //dc.SetPen(wxPen());wxClientDC dc(DisplayPanel);
    for(int i = 0; i <= width ; i+=squareSize)
    {

        dc.DrawLine(i, 0, i,length);
    }

    for(int i = 0; i <= length ; i+=squareSize)
    {

        dc.DrawLine(0, i, width, i);
    }


}

void Zombi_SimulationFrame::OnStartButtonClick(wxCommandEvent& event)
{
    wxClientDC dc(DisplayPanel);
    render(dc);
}
