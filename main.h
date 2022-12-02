/*********************************************************************
 * Name:      	main.h
 * Purpose:   	Declares simple wxWidgets application with GUI
 * 				created using wxFormBuilder.
 * Author:    
 * Created:   
 * Copyright: 
 * License:   	wxWidgets license (www.wxwidgets.org)
 * 
 * Notes:		Note that all GUI creation code is declared in
 * 				gui.h source file which is generated by wxFormBuilder.
 *********************************************************************/

#ifndef __main__
#define __main__

// main wxWidgets header file
#include <wx/wx.h>
// gui classes generated by wxFormBuilder
#include "gui.h"

#include "GofEngine.h"

#define CELL_SZ     8

////////////////////////////////////////////////////////////////////////////////
// application class declaration 
////////////////////////////////////////////////////////////////////////////////

class MainApp : public wxApp
{
	public:
		virtual bool OnInit();
};

// declare global static function wxGetApp()
DECLARE_APP(MainApp)

////////////////////////////////////////////////////////////////////////////////
// main application frame declaration 
////////////////////////////////////////////////////////////////////////////////

class MainFrame : public MainFrameBase
{
	public:
		MainFrame( wxWindow *parent, GofEngine *engine );
		virtual ~MainFrame();
		
	protected:
        GofEngine *mEngine{};
		void draw(wxDC&  dc);

		// protected event handlers
		virtual void OnCloseFrame( wxCloseEvent& event );
		virtual void OnTimerTick( wxTimerEvent& event );
		virtual void OnPaintEvent( wxPaintEvent& event );
		virtual void OnEraseBackgroundEvent( wxEraseEvent& event );
};

#endif //__main__
