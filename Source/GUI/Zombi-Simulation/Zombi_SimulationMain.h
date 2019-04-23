/***************************************************************
 * Name:      Zombi_SimulationMain.h
 * Purpose:   Defines Application Frame
 * Author:    Alex ()
 * Created:   2019-04-19
 * Copyright: Alex ()
 * License:
 **************************************************************/

#ifndef ZOMBI_SIMULATIONMAIN_H
#define ZOMBI_SIMULATIONMAIN_H

//(*Headers(Zombi_SimulationFrame)
#include <wx/gauge.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
//*)
#include "Continent.h"
#include <wx/dcbuffer.h>
#include <wx/gdicmn.h>

struct ContinentSpec
{
    int ContinentSize;
    Continents_e name;
    int x;
    int y;
};

class Zombi_SimulationFrame: public wxFrame
{
    public:

        Zombi_SimulationFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Zombi_SimulationFrame();

    private:
        Continent **continent;
        RandomGenerator *RandomGeneratorObject;
        const static int width = 700;
        const static int length = 300;
        const static int squareSize = 16;

        ContinentSpec continentSpec[6];
        static const int NorthAmericaSize = 10;
        static const int SouthAmericaSize = 7;
        static const int EuropeSize = 6;
        static const int AustraliaSize = 4;
        static const int AsiaSize = 13;
        static const int AfricaSize = 11;

        int humans;
        int zombies;
        int traps;
        int resources;
        int totalContinents;
        int speed;

        bool initializeOK;

        static const int NorthAmericaX = 0;
        static const int NorthAmericaY = 0;
        static const int SouthAmericaX = 0;
        static const int SouthAmericaY = 176;
        static const int EuropeX = 272;
        static const int EuropeY = 0;
        static const int AustraliaX = 624;
        static const int AustraliaY = 224;
        static const int AsiaX = 496;
        static const int AsiaY = 0;
        static const int AfricaX = 240;
        static const int AfricaY = 112;

        //(*Handlers(Zombi_SimulationFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBackgroundPanelPaint(wxPaintEvent& event);
        void OnStartButtonClick(wxCommandEvent& event);
        void render();
        void renderContinentCells(wxDC *dc, Continent *cont, int positionX, int positionY);
        void OnZombieSpinCtrlChange(wxSpinEvent& event);
        void OnHumanSpinCtrlChange(wxSpinEvent& event);
        void OnTrapSpinCtrlChange(wxSpinEvent& event);
        void OnResourceSpinCtrlChange(wxSpinEvent& event);
        void SetCellPercentageVariables();
        void InitiliazeContinets();
        void OnContinentSpinCtrlChange(wxSpinEvent& event);
        void OnSpeedCtrlChange(wxSpinEvent& event);
        //*)

        //(*Identifiers(Zombi_SimulationFrame)
        static const long ID_STAR_BUTTON;
        static const long ID_ZOMBIE_SPINCTRL;
        static const long ID_STATICTEXT1;
        static const long ID_TRAP_SPINCTRL;
        static const long ID_RESOURCE_SPINCTRL;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_HUMAN_SPINCTRL;
        static const long ID_CONTINENT_SPINCTRL;
        static const long ID_STATICTEXT5;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT6;
        static const long ID_GAUGE;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_CONFIG_PANEL;
        static const long ID_STATICBITMAP1;
        static const long ID_DISPALY_PANEL;
        static const long ID_BACKGROUND_PANEL;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Zombi_SimulationFrame)
        wxStaticBitmap* WelcomeScreen;
        wxPanel* DisplayPanel;
        wxSpinCtrl* HumanSpinCtrl;
        wxStatusBar* StatusBar1;
        wxSpinCtrl* SpeedCtrl;
        wxPanel* ConfigPanel;
        wxStaticText* StaticText1;
        wxButton* StartButton;
        wxStaticText* StaticText3;
        wxSpinCtrl* TrapSpinCtrl;
        wxStaticText* StaticText8;
        wxSpinCtrl* ZombieSpinCtrl;
        wxStaticText* StaticText7;
        wxSpinCtrl* ContinentSpinCtrl;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxStaticText* StaticText6;
        wxGauge* ProgressGauge;
        wxSpinCtrl* ResourceSpinCtrl;
        wxStaticText* StaticText9;
        wxPanel* BackgroundPanel;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZOMBI_SIMULATIONMAIN_H
