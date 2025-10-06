///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class IFrame
///////////////////////////////////////////////////////////////////////////////
class IFrame : public wxFrame
{
	private:

	protected:
		wxPanel* MainPanel;
		wxPanel* ToolBar;
		wxButton* NewFileBtn;
		wxButton* OpenFileBtn;
		wxButton* SaveFileBtn;
		wxButton* SaveAsFileBtn1;
		wxButton* MoveFileBtn;
		wxPanel* FindReplacePanel;
		wxStaticText* FindL;
		wxTextCtrl* FindInput;
		wxButton* FindPrevBtn;
		wxButton* FindNextBtn;
		wxButton* DoneFindBtn;
		wxStaticText* ReplaceL;
		wxTextCtrl* ReplaceI;
		wxButton* ReplaceBtn;
		wxButton* CloseBtn;
		wxButton* DeleteBtn;
		wxTextCtrl* TextEditor;
		wxStatusBar* StatusBar;
		wxMenuBar* MenuBar;
		wxMenu* File;
		wxMenu* Edit;
		wxMenu* Text;
		wxMenu* Window;

		// Virtual event handlers, override them in your derived class
		virtual void CreateNewFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OpenFileNew( wxCommandEvent& event ) { event.Skip(); }
		virtual void SaveFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void SaveFileAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void MoveFileF( wxCommandEvent& event ) { event.Skip(); }
		virtual void FindText( wxCommandEvent& event ) { event.Skip(); }
		virtual void FindPrev( wxCommandEvent& event ) { event.Skip(); }
		virtual void FindNext( wxCommandEvent& event ) { event.Skip(); }
		virtual void FindDone( wxCommandEvent& event ) { event.Skip(); }
		virtual void Replace( wxCommandEvent& event ) { event.Skip(); }
		virtual void CloseFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void DeleteFileF( wxCommandEvent& event ) { event.Skip(); }
		virtual void TextEditorType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OpenFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void Undo( wxCommandEvent& event ) { event.Skip(); }
		virtual void Redo( wxCommandEvent& event ) { event.Skip(); }
		virtual void Cut( wxCommandEvent& event ) { event.Skip(); }
		virtual void Copy( wxCommandEvent& event ) { event.Skip(); }
		virtual void Paste( wxCommandEvent& event ) { event.Skip(); }
		virtual void SelectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void SetFontSize( wxCommandEvent& event ) { event.Skip(); }
		virtual void FullScreen( wxCommandEvent& event ) { event.Skip(); }
		virtual void NewWindow( wxCommandEvent& event ) { event.Skip(); }


	public:

		IFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("TextEditor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~IFrame();

};

