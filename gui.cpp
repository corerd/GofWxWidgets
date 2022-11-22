///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );

	mBoard = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	MainSizer->Add( mBoard, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( MainSizer );
	this->Layout();
	mTimer.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	mBoard->Connect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( MainFrameBase::OnEraseBackgroundEvent ), NULL, this );
	mBoard->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrameBase::OnPaintEvent ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MainFrameBase::OnTimerTick ) );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	mBoard->Disconnect( wxEVT_ERASE_BACKGROUND, wxEraseEventHandler( MainFrameBase::OnEraseBackgroundEvent ), NULL, this );
	mBoard->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrameBase::OnPaintEvent ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MainFrameBase::OnTimerTick ) );

}
