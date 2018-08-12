#include "MyAppCommon.h"

void MyFrame::OnEnable(wxRibbonButtonBarEvent& WXUNUSED(evt))
{
	m_bEnabled = !m_bEnabled;
}

void MyFrame::OnEnableUpdateUI(wxUpdateUIEvent& evt)
{
	evt.Enable(m_bEnabled);
}
/*
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_RIBBONBUTTONBAR_CLICKED(ID_CONTROLBTN, MyFrame::OnEnable)
EVT_UPDATE_UI(ID_SECURITYBTN, MyFrame::OnEnableUpdateUI)
wxEND_EVENT_TABLE()
*/


bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame();
	//frame->Show(true);
	return true;
}
//// MyFrame implementation
MyFrame::MyFrame()
	: wxFrame(NULL, wxID_ANY, "Here be things", wxDefaultPosition, wxSize(1000, 600)
	)
{
	m_bEnabled = true;
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	// Ribbon
	ribbonBar = new wxRibbonBar(this, -1, wxDefaultPosition, wxDefaultSize, wxRIBBON_BAR_FLOW_HORIZONTAL
		| wxRIBBON_BAR_SHOW_PAGE_LABELS
		| wxRIBBON_BAR_SHOW_PANEL_EXT_BUTTONS
		| wxRIBBON_BAR_SHOW_TOGGLE_BUTTON
	);

	securityRibbonPage = new wxRibbonPage(ribbonBar, wxID_ANY, wxT("Security"), wxNullBitmap);
	rolesRibbonPage = new wxRibbonPage(ribbonBar, wxID_ANY, wxT("Roles"), wxNullBitmap);
	usersRibbonPage = new wxRibbonPage(ribbonBar, wxID_ANY, wxT("Users"), wxNullBitmap);
	configurationRibbonPage = new wxRibbonPage(ribbonBar, wxID_ANY, wxT("Configuration"), wxNullBitmap);
	profilesRibbonPage = new wxRibbonPage(ribbonBar, wxID_ANY, wxT("Profiles"), wxNullBitmap);
	operationsRibbonPage = new wxRibbonPage(ribbonBar, wxID_ANY, wxT("Operations"), wxNullBitmap);

	homeRibbonPanel = new wxRibbonPanel(securityRibbonPage, wxID_ANY, wxT("Home"), wxNullBitmap,
		wxDefaultPosition, wxDefaultSize,
		wxRIBBON_PANEL_NO_AUTO_MINIMISE);
	itemRibbonPanel = new wxRibbonPanel(usersRibbonPage, wxID_ANY, wxT("Data Item"),
		wxNullBitmap, wxDefaultPosition, wxDefaultSize,
		wxRIBBON_PANEL_NO_AUTO_MINIMISE);

	homeRibbonButtonBar = new wxRibbonButtonBar(homeRibbonPanel);
	itemRibbonButtonBar = new wxRibbonButtonBar(itemRibbonPanel);

	homeRibbonButtonBar->AddButton(wxID_ANY, wxT("Home Menu"),
		wxArtProvider::GetBitmap(wxART_QUESTION, wxART_TOOLBAR, wxSize(32, 32)));

	homeRibbonButtonBar->AddButton(ID_SECURITYBTN, wxT("Security?"), wxBitmap(tech1_xpm), wxBitmap(tech1_xpm),
		wxNullBitmap, wxNullBitmap, wxRIBBON_BUTTON_NORMAL,
		"Is Security really required?");

	homeRibbonButtonBar->AddButton(ID_CONTROLBTN, wxT("Disable Security"), wxArtProvider::GetBitmap(wxART_PLUS, wxART_OTHER, wxSize(32, 32)));

	itemRibbonButtonBar->AddButton(wxID_ANY, wxT("Daftar Guru"),
		IdCard_xpm);
	itemRibbonButtonBar->AddButton(wxID_ANY, wxT("Tambah Guru"),
		IdCard_xpm);
	itemRibbonButtonBar->AddButton(wxID_ANY, wxT("Daftar Siswa"),
		IdCard_xpm);
	itemRibbonButtonBar->AddButton(wxID_ANY, wxT("Tambah Siswa"),
		IdCard_xpm);

	ribbonBar->AddPageHighlight(/*ribbonBar->GetPageCount() - 1*/0);
	ribbonBar->Realize();

	// set style msw provider
	ribbonBar->DismissExpandedPanel();
	ribbonBar->SetArtProvider(new wxRibbonMSWArtProvider);
	//panel
	// set layout
	wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(ribbonBar, 0, wxEXPAND);

	SetSizer(sizer);

	Center();

	Bind(wxEVT_RIBBONBUTTONBAR_CLICKED, &MyFrame::OnEnable, this, ID_CONTROLBTN);
	Bind(wxEVT_UPDATE_UI, &MyFrame::OnEnableUpdateUI, this, ID_SECURITYBTN);

	Show(true);


}


MyFrame::~MyFrame()
{

}