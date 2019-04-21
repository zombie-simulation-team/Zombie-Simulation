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
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
//*)
#include "Continent.h"
#include <wx/dcbuffer.h>
#include <wx/gdicmn.h>

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

        int NorthAmericaSize;
        int SouthAmericaSize;
        int EuropeSize;
        int AustraliaSize;
        int AsiaSize;
        int AfricaSize;
        int humans;
        int zombies;
        int traps;
        int resources;

        static const int NorthAmericaX = 0;
        static const int NorthAmericaY = 0;
        static const int SouthAmericaX = 0;
        static const int SouthAmericaY = 176;
        static const int EuropeX = 272;
        static const int EuropeY = 0;
        static const int AustraliaX = 624;
        static const int AustraliaY = 224;
        static const int AsiaSizeX = 496;
        static const int AsiaSizeY = 0;
        static const int AfricaX = 240;
        static const int AfricaY = 112;

        //(*Handlers(Zombi_SimulationFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBackgroundPanelPaint(wxPaintEvent& event);
        void OnStartButtonClick(wxCommandEvent& event);
        void render(wxDC& dc);
        void renderContinentCells(wxDC& dc, Continent *cont, int positionX, int positionY);
        //*)

        //(*Identifiers(Zombi_SimulationFrame)
        static const long ID_STAR_BUTTON;
        static const long ID_CONFIG_PANEL;
        static const long ID_DISPALY_PANEL;
        static const long ID_BACKGROUND_PANEL;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Zombi_SimulationFrame)
        wxPanel* DisplayPanel;
        wxStatusBar* StatusBar1;
        wxPanel* ConfigPanel;
        wxButton* StartButton;
        wxPanel* BackgroundPanel;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZOMBI_SIMULATIONMAIN_H
