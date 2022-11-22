/*********************************************************************
 * Name:      	main.cpp
 * Purpose:   	Implements wxWidgets Game Of Life application
 * 
 * The original idea:
 * See: https://github.com/knotman90/SinervisCourses/tree/master/ST_CPP_Nov22/Lezione3/Gof
 * 
 * Sample code for c++ WxWidgets to plot an image to the canvas
 * See: https://stackoverflow.com/a/61806276
 * 
 * Code snippet to do drawing using software rendering on a wxPanel with a DC
 * See: https://wiki.wxwidgets.org/Drawing_on_a_panel_with_a_DC
 *      https://forum.wxwidgets.org/viewtopic.php?p=204018
 * 
 * Flicker-free drawing on Windows
 * https://wiki.wxwidgets.org/Flicker-Free_Drawing
 *********************************************************************/

#include "main.h"
#include <wx/dcbuffer.h>  // Flicker-free drawing

// initialize the application
IMPLEMENT_APP(MainApp);

////////////////////////////////////////////////////////////////////////////////
// application class implementation 
////////////////////////////////////////////////////////////////////////////////

bool MainApp::OnInit()
{
    GofEngine *engine = new GofEngine(100);
    MainFrame* frame = new MainFrame(NULL, engine);

	SetTopWindow( frame );
	GetTopWindow()->Show();
	
	// true = enter the main loop
	return true;
}

////////////////////////////////////////////////////////////////////////////////
// main application frame implementation 
////////////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow *parent, GofEngine *engine) :
    MainFrameBase( parent ),
    mEngine(engine)
{
    SetIcon(wxICON(sample));
    auto esize = mEngine->getSize();
    // sheet_dots = Matrix(esize, std::vector<bool>(esize, false));
    mTimer.Start(100);
}

MainFrame::~MainFrame()
{
    delete mEngine;
}

void MainFrame::OnCloseFrame(wxCloseEvent& event)
{
	Destroy();
}

void MainFrame::OnTimerTick( wxTimerEvent& event )
{
    mEngine->step();
    Refresh();
}

/**
 * Disable erase background event (Flicker-free drawing)
 */
void MainFrame::OnEraseBackgroundEvent( wxEraseEvent& event )
{
}

/**
 * Paint Event
 * 
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh().
 */
void MainFrame::OnPaintEvent( wxPaintEvent& event )
{
    //wxPaintDC dc(mBoard);
    wxBufferedPaintDC dc(mBoard); // Flicker-free drawing
    draw(dc);
}

/*
 * Paint on the panel at any time
 =
 * Using this generally does not free you from catching paint events,
 * since it is possible that e.g. the window manager throws away your drawing
 * when the window comes to the background, and expects you will redraw it
 * when the window comes back (by sending a paint event).
 *
 * In most cases, this will not be needed at all; simply handling
 * paint events and calling Refresh() when a refresh is needed
 * will do the job.
 */
void MainFrame::paintNow()
{
    wxClientDC dc(mBoard);
    draw(dc);
}

void MainFrame::draw(wxDC&  dc)
{
    //dc.Clear();

    // Draw the sheet
    auto sheet_sz = mEngine->getSize();
    for ( auto i = 0 ; i < sheet_sz ; ++i )
    {
        for ( auto j = 0 ; j < sheet_sz ; ++j )
        {
            auto cell_status = mEngine->getCell(i, j);
        /*
            if (sheet_dots[i][j] == cell_status)
                continue;
            sheet_dots[i][j] = cell_status;
        */
            if (cell_status)
            {
                // fill cell
                dc.SetPen(wxColour(0,0,0));
                dc.SetBrush(wxColour(0,0,0));
            }
            else
            {
                // empty cell
                dc.SetPen(wxColour(255,255,255));
                dc.SetBrush(wxColour(255,255,255));
            }
            dc.DrawRectangle(i*CELL_SZ, j*CELL_SZ, CELL_SZ, CELL_SZ);
        }
    }
}