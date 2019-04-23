/***************************************************************
 * Name:      Zombi_SimulationApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Alex ()
 * Created:   2019-04-19
 * Copyright: Alex ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Zombi_SimulationApp.h"

//(*AppHeaders
#include "Zombi_SimulationMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Zombi_SimulationApp);

bool Zombi_SimulationApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Zombi_SimulationFrame* Frame = new Zombi_SimulationFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
