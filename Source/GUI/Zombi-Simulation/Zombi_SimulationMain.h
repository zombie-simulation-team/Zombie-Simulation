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
#include "Continent/Continent.h"


class Zombi_SimulationFrame: public wxFrame
{
    public:

        Zombi_SimulationFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Zombi_SimulationFrame();





    private:
        Continent *continent;
        RandomGenerator *RandomGeneratorObject;
        const static int width = 700;
        const static int length = 300;
        const static int squareSize = 10;

        int NorthAmericaSize = 18;
        int humans = 10;
        int zombies = 10;
        int traps = 10;
        int resources = 10;



        //(*Handlers(Zombi_SimulationFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBackgroundPanelPaint(wxPaintEvent& event);
        void OnStartButtonClick(wxCommandEvent& event);
        void render(wxDC& dc);
        //*)

        //(*Identifiers(Zombi_SimulationFrame)
        static const long ID_BUTTON1;
        static const long ID_PANEL2;
        static const long ID_PANEL3;
        static const long ID_PANEL1;
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
