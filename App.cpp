#include <wx/wx.h>
#include "Frame.h"
#define wxDEBUG_LEVEL 0
class App : public wxApp
{
public:
	bool OnInit()
	{
		wxInitAllImageHandlers();
		Frame *frame = new Frame();
		frame->SetSize(wxSize(1050, 700));
		frame->Layout();
		frame->Show(true);
		frame->SetPosition(frame->FromDIP(wxPoint(100, 100)));
		return true;
	}
};

wxIMPLEMENT_APP(App);
