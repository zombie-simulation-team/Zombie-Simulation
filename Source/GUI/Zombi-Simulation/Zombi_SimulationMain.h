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
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
//*)

class Zombi_SimulationFrame: public wxFrame
{
    public:

        Zombi_SimulationFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Zombi_SimulationFrame();

    private:

        //(*Handlers(Zombi_SimulationFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(Zombi_SimulationFrame)
        static const long ID_STATICBITMAP1;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Zombi_SimulationFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxStaticBitmap* StaticBitmap1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ZOMBI_SIMULATIONMAIN_H
