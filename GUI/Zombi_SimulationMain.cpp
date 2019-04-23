/***************************************************************
 * Name:      Zombie_Simulation App
 * Author:    Alex, Javier, Gavin
 * Created:   2019-04-23
 * Copyright: Florida International University
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
#include <wx/msgdlg.h>
#include <wx/file.h>

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
const long Zombi_SimulationFrame::ID_GAUGE = wxNewId();
const long Zombi_SimulationFrame::ID_STATICTEXT7 = wxNewId();
const long Zombi_SimulationFrame::ID_BUTTON1 = wxNewId();
const long Zombi_SimulationFrame::ID_BUTTON2 = wxNewId();
const long Zombi_SimulationFrame::ID_STATICTEXT8 = wxNewId();
const long Zombi_SimulationFrame::ID_TEXTCTRL1 = wxNewId();
const long Zombi_SimulationFrame::ID_CONFIG_PANEL = wxNewId();
const long Zombi_SimulationFrame::ID_STATICBITMAP1 = wxNewId();
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

    humanWins = 0;
    zombieWins = 0;
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
    SetClientSize(wxSize(710,460));
    Move(wxPoint(-1,-1));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("./icons/biohazard.png"))));
    	SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BackgroundPanel = new wxPanel(this, ID_BACKGROUND_PANEL, wxDefaultPosition, wxSize(700,-1), wxTAB_TRAVERSAL, _T("ID_BACKGROUND_PANEL"));
    ConfigPanel = new wxPanel(BackgroundPanel, ID_CONFIG_PANEL, wxPoint(0,300), wxSize(700,104), wxSIMPLE_BORDER, _T("ID_CONFIG_PANEL"));
    ConfigPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    StartButton = new wxButton(ConfigPanel, ID_STAR_BUTTON, _("Start"), wxPoint(504,32), wxSize(150,50), 0, wxDefaultValidator, _T("ID_STAR_BUTTON"));
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
    ContinentSpinCtrl = new wxSpinCtrl(ConfigPanel, ID_CONTINENT_SPINCTRL, _T("4"), wxPoint(380,20), wxSize(63,27), 0, 1, 6, 4, _T("ID_CONTINENT_SPINCTRL"));
    ContinentSpinCtrl->SetValue(_T("4"));
    StaticText5 = new wxStaticText(ConfigPanel, ID_STATICTEXT5, _("Continents"), wxPoint(380,2), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    SpeedCtrl = new wxSpinCtrl(ConfigPanel, ID_SPINCTRL1, _T("1"), wxPoint(380,68), wxSize(64,27), 0, 1, 10, 1, _T("ID_SPINCTRL1"));
    SpeedCtrl->SetValue(_T("1"));
    StaticText6 = new wxStaticText(ConfigPanel, ID_STATICTEXT6, _("Speed"), wxPoint(380,50), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    ProgressGauge = new wxGauge(ConfigPanel, ID_GAUGE, 100, wxPoint(552,41), wxSize(141,28), 0, wxDefaultValidator, _T("ID_GAUGE"));
    StaticText7 = new wxStaticText(ConfigPanel, ID_STATICTEXT7, _("Progress"), wxPoint(480,48), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    LoadButton = new wxButton(ConfigPanel, ID_BUTTON1, _("Load"), wxPoint(32,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    SaveButton = new wxButton(ConfigPanel, ID_BUTTON2, _("Save"), wxPoint(32,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText8 = new wxStaticText(ConfigPanel, ID_STATICTEXT8, _("Humans vs Zombies:"), wxPoint(475,8), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    ScoreTextCtrl = new wxTextCtrl(ConfigPanel, ID_TEXTCTRL1, _("0 - 0"), wxPoint(615,5), wxSize(50,20), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    ScoreTextCtrl->SetMaxLength(10);
    DisplayPanel = new wxPanel(BackgroundPanel, ID_DISPALY_PANEL, wxPoint(0,0), wxSize(700,300), wxTAB_TRAVERSAL, _T("ID_DISPALY_PANEL"));
    DisplayPanel->SetBackgroundColour(wxColour(5,183,247));
    WelcomeScreen = new wxStaticBitmap(DisplayPanel, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/ubuntu/Documents/Zombie-Simulation/GUI/icons/StartScreen.PNG")).Rescale(wxSize(700,300).GetWidth(),wxSize(700,300).GetHeight())), wxPoint(0,0), wxSize(700,300), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    BoxSizer1->Add(BackgroundPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_STAR_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnStartButtonClick);
    Connect(ID_ZOMBIE_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnZombieSpinCtrlChange);
    Connect(ID_TRAP_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnTrapSpinCtrlChange);
    Connect(ID_RESOURCE_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnResourceSpinCtrlChange);
    Connect(ID_HUMAN_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnHumanSpinCtrlChange);
    Connect(ID_CONTINENT_SPINCTRL,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnContinentSpinCtrlChange);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnSpeedCtrlChange);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnLoadButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zombi_SimulationFrame::OnSaveButtonClick);
    //*)

    SetCellPercentageVariables();
    ProgressGauge->Hide();
    StaticText7->Hide();

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

void Zombi_SimulationFrame::render()
{
    StartButton->Hide();
    ProgressGauge->Show();
    StaticText7->Show();

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

    for(int i = 0; i <= width ; i+=squareSize)
    {

        clientDC.DrawLine(i, 0, i,length);
        for(int j = 0; j <= length ; j+=squareSize)
        {
            clientDC.DrawLine(0, j, width, j);
        }
    }

    int progress = 0;
    int gaugeValue = 100/totalContinents;
    ProgressGauge->SetValue(progress);
    int zombieCount = 0;
    int humanCount = 0;
    int loopCount = 0;
    int count = 1;
    while(count < totalContinents)
    {
        humanCount = 0;
        zombieCount = 0;
        wxBufferedDC *dc = new wxBufferedDC(&clientDC, wxSize(width,length));
        dc->Clear();
        dc->SetBrush(*wxGREY_BRUSH);
        dc->DrawRectangle(NorthAmericaX,NorthAmericaY, NorthAmericaSize*squareSize, NorthAmericaSize*squareSize);
        dc->SetBrush(*wxBLUE_BRUSH);
        dc->DrawRectangle(SouthAmericaX,SouthAmericaY, SouthAmericaSize*squareSize, SouthAmericaSize*squareSize);
        dc->SetBrush(*wxRED_BRUSH);
        dc->DrawRectangle(EuropeX,EuropeY, EuropeSize*squareSize, EuropeSize*squareSize);
        dc->SetBrush( wxBrush( wxColour(223,107,19)));
        dc->DrawRectangle(AustraliaX,AustraliaY, AustraliaSize*squareSize, AustraliaSize*squareSize);
        dc->SetBrush(*wxGREEN_BRUSH);
        dc->DrawRectangle(AsiaX,AsiaY, AsiaSize*squareSize, AsiaSize*squareSize);
        dc->SetBrush(wxBrush( wxColour(173,9,148)));
        dc->DrawRectangle(AfricaX,AfricaY, AfricaSize*squareSize, AfricaSize*squareSize);


        for(int i = 0; i < totalContinents ; i++)
            renderContinentCells(dc,continent[i], continentSpec[i].x, continentSpec[i].y);

        delete dc;

        wxMilliSleep(speed * 10);
        for(int j = 0; j < totalContinents ; j++)
        {
            zombieCount += continent[j]->GetZombieCount();
            humanCount += continent[j]->GetHumanCount();
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

        if(progress < count)
        {
            progress = count;
            ProgressGauge->SetValue(ProgressGauge->GetValue()+gaugeValue);
        }

        SetStatusText(wxString::Format(wxT("Day:%i    Humans Left:%i    Zombies Left:%i"), loopCount, humanCount, zombieCount));
        loopCount++;

    }
    ProgressGauge->SetValue(100);
    SetStatusText(wxString::Format(wxT("Day: %i    Humans:%i     Zombies:%i.   "), loopCount,humanCount, zombieCount) + wxT(" End of Simulation."));

    int zombiePercent = ((double)zombieCount/(zombieCount+humanCount))*100;
    int humanPercent = ((double)humanCount/(zombieCount+humanCount))*100;
    wxString results;
    wxString winner;
    if( zombieCount > humanCount)
    {
        results.Append(wxString::Format(wxT("Zombies conquered %i percent of the World"),zombiePercent));
        winner.Append("ZOMBIES WON");
        zombieWins++;
    }
    else if( zombieCount < humanCount )
    {
        results.Append(wxString::Format(wxT("Humans saved %i percent of the World"),humanPercent));
        winner.Append("HUMANS WON");
        humanWins++;
    }
    else
    {
        results.Append(wxT("Humans and Zombies got each half of the World"));
        winner.Append("TIE");
    }
    wxMessageBox(results, winner);

    ProgressGauge->Hide();
    StaticText7->Hide();
    StartButton->Show();
    ScoreTextCtrl->ChangeValue(wxString::Format(wxT("%i - %i"), humanWins, zombieWins));

    for(int j = 0 ; j< totalContinents ; j++)
        delete continent[j];
    delete []continent;


}

void Zombi_SimulationFrame::renderContinentCells(wxDC *dc, Continent *cont, int positionX, int positionY)
{


    for(int y  = 0 ; y < cont->GetSize(); y++ )
    {
        for(int x = 0; x < cont->GetSize(); x++)
        {
            Cell *current = cont->GetShape()[y][x];
            int xx = (x*squareSize) + positionX;
            int yy = (y*squareSize) + positionY;

            if(current->IsEmpty())
            {
                continue; //don't display anything
            }
            else if(current->IsHuman())
            {
                dc->DrawBitmap(humanBMP, xx,yy);
            }
            else if(current->IsZombie())
            {
                dc->DrawBitmap(zombieBMP, xx,yy);
            }
            else if(current->IsResource())
            {
                dc->DrawBitmap(resourceBMP, xx,yy);
            }
            else if(current->IsTrap())
            {
                dc->DrawBitmap(trapBMP, xx,yy);
            }
        }
    }

}
void Zombi_SimulationFrame::OnStartButtonClick(wxCommandEvent& event)
{
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

void Zombi_SimulationFrame::OnSpeedCtrlChange(wxSpinEvent& event)
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

    if(totalPercentage > 75)
    {
        wxMessageBox(wxString("Cannot fill the world over 75%. Need to leave some empty places to move"),wxString("Wrong Percentage"));
        initializeOK = false;

    }
    else if(humans == 75 || zombies == 75)
    {
        wxMessageBox(wxString("Cannot select all percentage of one type"),wxString("Wrong Percentage"));
        initializeOK = false;
    }
    else if((humans + zombies)>75)
    {
        wxMessageBox(wxString("Cannot fill the world with 75% of zombies and humans only"),wxString("Wrong Percentage"));
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

        continent[i] = new Continent(tmpContinentSize, tmpName, tmpHumans, tmpZombies, tmpTraps, tmpResources, RandomGeneratorObject);
    }
}

void Zombi_SimulationFrame::OnContinentSpinCtrlChange(wxSpinEvent& event)
{
    totalContinents = ContinentSpinCtrl->GetValue() + 1;
}

void Zombi_SimulationFrame::OnDisplayPanelEraseBackground(wxEraseEvent& event)
{
}

void Zombi_SimulationFrame::OnLoadButtonClick(wxCommandEvent& event)
{
    wxFileDialog loadFileDialog(this, wxT("Load a simulation saved configuration"), "", "",  "BIN files (*.bin)|*.bin", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if(loadFileDialog.ShowModal() == wxID_CANCEL)
    {
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
    configFile.Read(&humanWins, sizeof(int));
    configFile.Read(&zombieWins, sizeof(int));

    HumanSpinCtrl->SetValue(humans);
    ZombieSpinCtrl->SetValue(zombies);
    TrapSpinCtrl->SetValue(traps);
    ResourceSpinCtrl->SetValue(resources);
    ContinentSpinCtrl->SetValue(totalContinents);
    SpeedCtrl->SetValue(11 - speed);
    ScoreTextCtrl->ChangeValue(wxString::Format(wxT("%i - %i"), humanWins, zombieWins));

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
    configFile.Write(&humanWins, sizeof(int));
    configFile.Write(&zombieWins, sizeof(int));


    configFile.Close();

}
