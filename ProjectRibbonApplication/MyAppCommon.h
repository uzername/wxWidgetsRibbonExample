//contains definitions of interface classes
#ifndef MYAPPCOMMON_GUARD
#define MYAPPCOMMON_GUARD
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/timer.h>
#include <wx/ribbon/bar.h>
#include <wx/ribbon/buttonbar.h>
#include <wx/artprov.h>
#include "IdCard.xpm"
#include "tech1.xpm"
#include "tech1_disabled.xpm"
#include "globalbeacon.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

////
class MyFrame : public wxFrame
{
public:
	MyFrame();
	virtual ~MyFrame();
	void OnEnable(wxRibbonButtonBarEvent& WXUNUSED(evt));
	void OnEnableUpdateUI(wxUpdateUIEvent& evt);
	
private:

	// ribbon. See more at https://imron02.wordpress.com/2014/12/11/wxwidgets-simple-application-using-wxribbon-and-wxauinotebook/
	wxRibbonBar * ribbonBar;
	wxRibbonPage* securityRibbonPage;
	wxRibbonPage* rolesRibbonPage;
	wxRibbonPage* usersRibbonPage;
	wxRibbonPage* configurationRibbonPage;
	wxRibbonPage* profilesRibbonPage;
	wxRibbonPage* operationsRibbonPage;

	wxRibbonPanel* homeRibbonPanel;
	wxRibbonPanel* itemRibbonPanel;
	wxRibbonButtonBar* homeRibbonButtonBar;
	wxRibbonButtonBar* itemRibbonButtonBar;
	bool m_bEnabled;

};

enum
{
	ID_SECURITYBTN = wxID_HIGHEST + 1,
	ID_CONTROLBTN
};

#endif