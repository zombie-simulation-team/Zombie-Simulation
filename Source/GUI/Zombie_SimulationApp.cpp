/***************************************************************
 * Name:      Zombie_Simulation App
 * Author:    Alex, Javier, Gavin
 * Created:   2019-04-23
 * Copyright: Florida International University
 **************************************************************/
#include "wx_pch.h"
#include "Zombie_SimulationApp.h"

//(*AppHeaders
#include "Zombie_SimulationMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Zombie_SimulationApp);

bool Zombie_SimulationApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Zombie_SimulationFrame* Frame = new Zombie_SimulationFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
