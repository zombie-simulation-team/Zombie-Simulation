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
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)
#include <wx/imagpng.h>
#include <wx/statbmp.h>

wxBitmap zombieBMP("./icons/zombie_16px.png", wxBITMAP_TYPE_PNG);
wxBitmap humanBMP("./icons/human_16px.png", wxBITMAP_TYPE_PNG);
wxBitmap trapBMP("./icons/trap_16px.png", wxBITMAP_TYPE_PNG);
wxBitmap resourceBMP("./icons/resource_16px.png", wxBITMAP_TYPE_PNG);


//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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
const long Zombi_SimulationFrame::ID_STAR_BUTTON = wxNewId();
const long Zombi_SimulationFrame::ID_ZOMBIE_SPINCTRL = wxNewId();
const long Zombi_SimulationFrame::ID_STATICTEXT1 = wxNewId();
const long Zombi_SimulationFrame::ID_TRAP_SPINCTRL = wxNewId();
const long Zombi_SimulationFrame::ID_RESOURCE_SPINCTRL = wxNewId();
const long Zombi_SimulationFrame::ID_STATICTEXT2 = wxNewId();
const long Zombi_SimulationFrame::ID_STATICTEXT3 = wxNewId();
const long Zombi_SimulationFrame::ID_STATICTEXT4 = wxNewId();
const long Zombi_SimulationFrame::ID_HUMAN_SPINCTRL = wxNewId();
const long Zombi_SimulationFrame::ID_CONTINENT_SPINCTRL = wxNewId();
const long Zombi_SimulationFrame::ID_STATICTEXT5 = wxNewId();
const long Zombi_SimulationFrame::ID_SPINCTRL1 = wxNewId();
const long Zombi_SimulationFrame::ID_STATICTEXT6 = wxNewId();
const long Zombi_SimulationFrame::ID_BUTTON1 = wxNewId();
const long Zombi_SimulationFrame::ID_BUTTON2 = wxNewId();
const long Zombi_SimulationFrame::ID_CONFIG_PANEL = wxNewId();
const long Zombi_SimulationFrame::ID_DISPALY_PANEL = wxNewId();
const long Zombi_SimulationFrame::ID_BACKGROUND_PANEL = wxNewId();
const long Zombi_SimulationFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Zombi_SimulationFrame,wxFrame)
    //(*EventTable(Zombi_SimulationFrame)
    //*)
END_EVENT_TABLE()

Zombi_SimulationFrame::Zombi_SimulationFrame(wxWindow* parent,wxWindowID id)
{
    RandomGeneratorObject = new RandomGenerator();

    continentSpec[0].ContinentSize = NorthAmericaSize;
    continentSpec[0].name = NorthAmerica;
    continentSpec[0].x = NorthAmericaX;
    continentSpec[0].y = NorthAmericaY;

    continentSpec[1].ContinentSize = SouthAmerica;
    continentSpec[1].name = SouthAmerica;
    continentSpec[1].x = SouthAmericaX;
    continentSpec[1].y = SouthAmericaY;

    continentSpec[2].ContinentSize = EuropeSize;
    continentSpec[2].name = Europe;
    continentSpec[2].x = EuropeX;
    continentSpec[2].y = EuropeY;

    continentSpec[3].ContinentSize = AfricaSize;
    continentSpec[3].name = Africa;
    continentSpec[3].x = AfricaX;
    continentSpec[3].y = AfricaY;

    continentSpec[4].ContinentSize = AsiaSize;
    continentSpec[4].name = Asia;
    continentSpec[4].x = AsiaX;
    continentSpec[4].y = AsiaY;

    continentSpec[5].ContinentSize = AustraliaSize;
    continentSpec[5].name = Australia;
    continentSpec[5].x = AustraliaX;
    continentSpec[5].y = AustraliaY;

//    SetBackgroundStyle(wxBG_STYLE_PAINT); /// NEEDED FOR DOUBLE BUFFERING
    //(*Initialize(Zombi_SimulationFrame)
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Zombie Simulation"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("./icons/biohazard.png"))));
    	SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BackgroundPanel = new wxPanel(this, ID_BACKGROUND_PANEL, wxDefaultPosition, wxSize(700,-1), wxTAB_TRAVERSAL, _T("ID_BACKGROUND_PANEL"));
    BackgroundPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
    ConfigPanel = new wxPanel(BackgroundPanel, ID_CONFIG_PANEL, wxPoint(0,300), wxSize(700,104), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_CONFIG_PANEL"));
    ConfigPanel->SetBackgroundColour(wxColour(225,216,216));
    StartButton = new wxButton(ConfigPanel, ID_STAR_BUTTON, _("Start"), wxPoint(500,30), wxSize(150,50), 0, wxDefaultValidator, _T("ID_STAR_BUTTON"));
    StartButton->SetBackgroundColour(wxColour(161,209,75));
    ZombieSpinCtrl = new wxSpinCtrl(ConfigPanel, ID_ZOMBIE_SPINCTRL, _T("10"), wxPoint(152,20), wxSize(56,27), 0, 2, 100, 10, _T("ID_ZOMBIE_SPINCTRL"));
    ZombieSpinCtrl->SetValue(_T("10"));
    StaticText1 = new wxStaticText(ConfigPanel, ID_STATICTEXT1, _("Zombies %"), wxPoint(152,2), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TrapSpinCtrl = new wxSpinCtrl(ConfigPanel, ID_TRAP_SPINCTRL, _T("5"), wxPoint(264,20), wxSize(56,27), 0, 0, 10, 5, _T("ID_TRAP_SPINCTRL"));
    TrapSpinCtrl->SetValue(_T("5"));
    ResourceSpinCtrl = new wxSpinCtrl(ConfigPanel, ID_RESOURCE_SPINCTRL, _T("10"), wxPoint(264,68), wxSize(56,27), 0, 0, 20, 10, _T("ID_RESOURCE_SPINCTRL"));
    ResourceSpinCtrl->SetValue(_T("10"));
    StaticText2 = new wxStaticText(ConfigPanel, ID_STATICTEXT2, _("Humans %"), wxPoint(152,50), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(ConfigPanel, ID_STATICTEXT3, _("Traps %"), wxPoint(264,2), wxSize(64,17), 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(ConfigPanel, ID_STATICTEXT4, _("Resources %"), wxPoint(264,50), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    HumanSpinCtrl = new wxSpinCtrl(ConfigPanel, ID_HUMAN_SPINCTRL, _T("30"), wxPoint(152,68), wxSize(56,27), 0, 5, 100, 30, _T("ID_HUMAN_SPINCTRL"));
    HumanSpinCtrl->SetValue(_T("30"));
    ContinentSpinCtrl = new wxSpinCtrl(ConfigPanel, ID_CONTINENT_SPINCTRL, _T("4"), wxPoint(380,20), wxSize(56,27), 0, 1, 6, 4, _T("ID_CONTINENT_SPINCTRL"));
    ContinentSpinCtrl->SetValue(_T("4"));
    StaticText5 = new wxStaticText(ConfigPanel, ID_STATICTEXT5, _("Continents"), wxPoint(380,2), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    SpeedCtrl = new wxSpinCtrl(ConfigPanel, ID_SPINCTRL1, _T("1"), wxPoint(380,68), wxSize(56,27), 0, 1, 10, 1, _T("ID_SPINCTRL1"));
    SpeedCtrl->SetValue(_T("1"));
    StaticText6 = new wxStaticText(ConfigPanel, ID_STATICTEXT6, _("Speed"), wxPoint(380,50), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    LoadButton = new wxButton(ConfigPanel, ID_BUTTON1, _("Load"), wxPoint(30,14), wxSize(-1,27), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    SaveButton = new wxButton(ConfigPanel, ID_BUTTON2, _("Save"), wxPoint(30,62), wxSize(-1,27), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    DisplayPanel = new wxPanel(BackgroundPanel, ID_DISPALY_PANEL, wxPoint(0,0), wxSize(700,300), wxTAB_TRAVERSAL, _T("ID_DISPALY_PANEL"));
    BoxSizer1->Add(BackgroundPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_STAR_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnStartButtonClick);
    Connect(ID_ZOMBIE_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnZombieSpinCtrlChange);
    Connect(ID_TRAP_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnTrapSpinCtrlChange);
    Connect(ID_RESOURCE_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnResourceSpinCtrlChange);
    Connect(ID_HUMAN_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnHumanSpinCtrlChange);
    Connect(ID_CONTINENT_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnContinentSpinCtrlChange);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnSpeedCtrlChange);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnLoadButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnSaveButtonClick);
    DisplayPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Zombi_SimulationFrame::OnDisplayPanelPaint,0,this);
    DisplayPanel->Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&Zombi_SimulationFrame::OnDisplayPanelEraseBackground,0,this);
    //*)

    SetCellPercentageVariables();


}

Zombi_SimulationFrame::~Zombi_SimulationFrame()
{
    //(*Destroy(Zombi_SimulationFrame)
    delete RandomGeneratorObject;
    //*)
}

void Zombi_SimulationFrame::OnQuit(wxCommandEvent& event)
{
    Destroy();
}

void Zombi_SimulationFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Zombi_SimulationFrame::OnDisplayPanelPaint(wxPaintEvent& event)
{
//    wxBufferedPaintDC dc(DisplayPanel);
//    dc.Clear();
}

void Zombi_SimulationFrame::render()
{

    wxClientDC clientDC(DisplayPanel);


    if(initializeOK)
    {
        totalContinents = ContinentSpinCtrl->GetValue();
        continent = new Continent*[totalContinents];
        InitiliazeContinets();
    }
    else
    {
        wxMessageBox(wxString("You have a wrong setup. Pick the right values and try again"),wxString("Setup Error"));
        return;
    }


    //dc.SetPen(wxPen());wxClientDC dc(DisplayPanel);
    for(int i = 0; i <= width ; i+=squareSize)
    {

        clientDC.DrawLine(i, 0, i,length);
        for(int j = 0; j <= length ; j+=squareSize)
        {
            clientDC.DrawLine(0, j, width, j);
        }
    }

//    dc.Clear();
//    dc.SetBrush(*wxGREY_BRUSH);
//    dc.DrawRectangle(NorthAmericaX,NorthAmericaY, NorthAmericaSize*squareSize, NorthAmericaSize*squareSize);
//    dc.DrawRectangle(SouthAmericaX,SouthAmericaY, SouthAmericaSize*squareSize, SouthAmericaSize*squareSize);
//    dc.DrawRectangle(EuropeX,EuropeY, EuropeSize*squareSize, EuropeSize*squareSize);
//    dc.DrawRectangle(AustraliaX,AustraliaY, AustraliaSize*squareSize, AustraliaSize*squareSize);
//    dc.DrawRectangle(AsiaX,AsiaY, AsiaSize*squareSize, AsiaSize*squareSize);
//    dc.DrawRectangle(AfricaX,AfricaY, AfricaSize*squareSize, AfricaSize*squareSize);

    int loopCount = 0;
    int count = 1;
    while(count < totalContinents)
    {
//        dc.Clear();
        wxBufferedDC *dc = new wxBufferedDC(&clientDC, wxSize(width,length));
        dc->Clear();
        dc->SetBrush(*wxGREY_BRUSH);
        dc->DrawRectangle(NorthAmericaX,NorthAmericaY, NorthAmericaSize*squareSize, NorthAmericaSize*squareSize);
        dc->DrawRectangle(SouthAmericaX,SouthAmericaY, SouthAmericaSize*squareSize, SouthAmericaSize*squareSize);
        dc->DrawRectangle(EuropeX,EuropeY, EuropeSize*squareSize, EuropeSize*squareSize);
        dc->DrawRectangle(AustraliaX,AustraliaY, AustraliaSize*squareSize, AustraliaSize*squareSize);
        dc->DrawRectangle(AsiaX,AsiaY, AsiaSize*squareSize, AsiaSize*squareSize);
        dc->DrawRectangle(AfricaX,AfricaY, AfricaSize*squareSize, AfricaSize*squareSize);


        for(int i = 0; i < totalContinents ; i++)
            renderContinentCells(dc,continent[i], continentSpec[i].x, continentSpec[i].y);

        delete dc;

        wxMilliSleep(speed * 10);
        for(int j = 0; j < totalContinents ; j++)
        {
            if(!continent[j]->Finished())
            {
                count = 1;
                continent[j]->Tick();
            }
            else
            {
                count++;
            }
        }
         wxMilliSleep(speed * 10);

        SetStatusText(wxString::Format(wxT("Day:%i"), loopCount));
        loopCount++;

    }

//    for(int i = 0; i < totalContinents ; i++)
//        renderContinentCells(dc,continent[i], continentSpec[i].x, continentSpec[i].y);
    SetStatusText(wxString::Format(wxT("Done ticking. Finished on Day: %i"), loopCount));
    for(int j = 0 ; j< totalContinents ; j++)
        delete continent[j];
    delete []continent;
}

void Zombi_SimulationFrame::renderContinentCells(wxDC *dc, Continent *cont, int positionX, int positionY)
{

//    wxBufferedDC bufferedDC (&dc, wxSize(width,length));

    for(int y  = 0 ; y < cont->GetSize(); y++ )
    {
        for(int x = 0; x < cont->GetSize(); x++)
        {
            Cell *current = cont->GetShape()[y][x];
            int xx = (x*squareSize) + positionX;
            int yy = (y*squareSize) + positionY;

            if(current->IsEmpty())
            {
//                dc.SetBrush(*EMPTY_COLOR);
//                dc.DrawBitmap(zombieBMP, xx,yy);
            }
            else if(current->IsHuman())
            {
                dc->DrawBitmap(humanBMP, xx,yy);
//                bufferedDC.DrawBitmap(humanBMP, xx,yy);
            }
            else if(current->IsZombie())
            {
                dc->DrawBitmap(zombieBMP, xx,yy);
//                bufferedDC.DrawBitmap(zombieBMP, xx,yy);
            }
            else if(current->IsResource())
            {
                dc->DrawBitmap(resourceBMP, xx,yy);
//                bufferedDC.DrawBitmap(resourceBMP, xx,yy);
            }
            else if(current->IsTrap())
            {
                dc->DrawBitmap(trapBMP, xx,yy);
//                bufferedDC.DrawBitmap(trapBMP, xx,yy);
            }
//            bufferedDC.DrawRectangle(positionX+(x*squareSize), positionY+(y*squareSize), squareSize,squareSize);
//            dc.DrawRectangle(positionX+(x*squareSize), positionY+(y*squareSize), squareSize,squareSize);
        }
    }
//    delete bufferedDC;
}
void Zombi_SimulationFrame::OnStartButtonClick(wxCommandEvent& event)
{
//    wxPaintDC dc(DisplayPanel);
    render();
}



void Zombi_SimulationFrame::OnZombieSpinCtrlChange(wxSpinEvent& event)
{
    SetCellPercentageVariables();
}

void Zombi_SimulationFrame::OnHumanSpinCtrlChange(wxSpinEvent& event)
{
    SetCellPercentageVariables();
}

void Zombi_SimulationFrame::OnTrapSpinCtrlChange(wxSpinEvent& event)
{
    SetCellPercentageVariables();
}

void Zombi_SimulationFrame::OnResourceSpinCtrlChange(wxSpinEvent& event)
{
    SetCellPercentageVariables();
}

void Zombi_SimulationFrame::SetCellPercentageVariables()
{
    speed = 11 - SpeedCtrl->GetValue();
    humans = HumanSpinCtrl->GetValue();
    zombies = ZombieSpinCtrl->GetValue();
    traps = TrapSpinCtrl->GetValue();
    resources = ResourceSpinCtrl->GetValue();
    initializeOK = true;
    int totalPercentage = humans+zombies+traps+resources;

    if(totalPercentage > 100)
    {
        wxMessageBox(wxString("Total percent goes over 100"),wxString("Wrong Percentage"));
        initializeOK = false;

    }
    else if(humans == 100 || zombies == 100)
    {
        wxMessageBox(wxString("Cannot select 100% of one type"),wxString("Wrong Percentage"));
        initializeOK = false;
    }

}

void Zombi_SimulationFrame::InitiliazeContinets()
{
    for(int i = 0; i < totalContinents ; i++)
    {
        int tmpContinentSize = continentSpec[i].ContinentSize;
        Continents_e tmpName = continentSpec[i].name;
        int tmpZombies       = (tmpContinentSize*tmpContinentSize)*zombies/100;
        int tmpHumans        = (tmpContinentSize*tmpContinentSize)*humans/100;
        int tmpTraps         = (tmpContinentSize*tmpContinentSize)*traps/100;
        int tmpResources     = (tmpContinentSize*tmpContinentSize)*resources/100;

        continent[i] = new Continent(tmpContinentSize,tmpName, tmpHumans, tmpZombies, tmpTraps, tmpResources, RandomGeneratorObject);
    }
}

void Zombi_SimulationFrame::OnContinentSpinCtrlChange(wxSpinEvent& event)
{
    totalContinents = ContinentSpinCtrl->GetValue() + 1;
}

void Zombi_SimulationFrame::OnSpeedCtrlChange(wxSpinEvent& event)
{
  SetCellPercentageVariables();
}


void Zombi_SimulationFrame::OnDisplayPanelEraseBackground(wxEraseEvent& event)
{
}

void Zombi_SimulationFrame::OnLoadButtonClick(wxCommandEvent& event)
{
    wxFileDialog loadFileDialog(this, wxT("Load a simulation saved configuration"), "", "",  "BIN files (*.bin)|*.bin", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if(loadFileDialog.ShowModal() == wxID_CANCEL){
            return;
    }
    wxString fileName(loadFileDialog.GetPath());

    wxFile configFile;
    configFile.Open(fileName, wxFile::read);

    configFile.Seek(0, wxFromStart);
    configFile.Read(&humans, sizeof(int));
    configFile.Read(&zombies, sizeof(int));
    configFile.Read(&traps, sizeof(int));
    configFile.Read(&resources, sizeof(int));
    configFile.Read(&totalContinents, sizeof(int));
    configFile.Read(&speed, sizeof(int));

    HumanSpinCtrl->SetValue(humans);
    ZombieSpinCtrl->SetValue(zombies);
    TrapSpinCtrl->SetValue(traps);
    ResourceSpinCtrl->SetValue(resources);
    ContinentSpinCtrl->SetValue(totalContinents);
    SpeedCtrl->SetValue(11 - speed);

    configFile.Close();
}

void Zombi_SimulationFrame::OnSaveButtonClick(wxCommandEvent& event)
{
    wxString defaultDir = wxGetCwd();
    wxString defaultFilename = wxEmptyString;
    wxFileDialog saveFileDialog(this, _("Save this simulation"), defaultDir, defaultFilename,  "BIN files (*.bin)|*.bin", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }
    wxString fileName = saveFileDialog.GetPath();

    wxFile configFile;
    configFile.Open(fileName, wxFile::write);

    configFile.Seek(0, wxFromStart);

    humans = HumanSpinCtrl->GetValue();
    zombies = ZombieSpinCtrl->GetValue();
    traps = TrapSpinCtrl->GetValue();
    resources = ResourceSpinCtrl->GetValue();
    totalContinents = ContinentSpinCtrl->GetValue();
    speed = 11 - SpeedCtrl->GetValue();

    configFile.Write(&humans, sizeof(int));
    configFile.Write(&zombies, sizeof(int));
    configFile.Write(&traps, sizeof(int));
    configFile.Write(&resources, sizeof(int));
    configFile.Write(&totalContinents, sizeof(int));
    configFile.Write(&speed, sizeof(int));


    configFile.Close();

}