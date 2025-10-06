///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "IFrame.h"

///////////////////////////////////////////////////////////////////////////

IFrame::IFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer *MainSizer;
	MainSizer = new wxBoxSizer(wxVERTICAL);

	MainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer *PanelSizer;
	PanelSizer = new wxBoxSizer(wxVERTICAL);

	ToolBar = new wxPanel(MainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer *ToolbarSizer;
	ToolbarSizer = new wxBoxSizer(wxHORIZONTAL);

	NewFileBtn = new wxButton(ToolBar, wxID_ANY, _("New File"), wxDefaultPosition, wxDefaultSize, 0);

	NewFileBtn->SetBitmap(wxBitmap(wxT("icons/NewFile40.png"), wxBITMAP_TYPE_ANY));
	NewFileBtn->SetBitmapPosition(wxTOP);
	ToolbarSizer->Add(NewFileBtn, 0, wxALL, 0);

	OpenFileBtn = new wxButton(ToolBar, wxID_ANY, _("Open"), wxDefaultPosition, wxDefaultSize, 0);

	OpenFileBtn->SetBitmap(wxBitmap(wxT("icons/OpenNew40.png"), wxBITMAP_TYPE_ANY));
	OpenFileBtn->SetBitmapPosition(wxTOP);
	ToolbarSizer->Add(OpenFileBtn, 0, wxALL, 0);

	SaveFileBtn = new wxButton(ToolBar, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0);

	SaveFileBtn->SetBitmap(wxBitmap(wxT("icons/SaveFile40.png"), wxBITMAP_TYPE_ANY));
	SaveFileBtn->SetBitmapPosition(wxTOP);
	ToolbarSizer->Add(SaveFileBtn, 0, wxALL, 0);

	SaveAsFileBtn1 = new wxButton(ToolBar, wxID_ANY, _("Save As"), wxDefaultPosition, wxDefaultSize, 0);

	SaveAsFileBtn1->SetBitmap(wxBitmap(wxT("icons/SaveAs40.png"), wxBITMAP_TYPE_ANY));
	SaveAsFileBtn1->SetBitmapPosition(wxTOP);
	ToolbarSizer->Add(SaveAsFileBtn1, 0, wxALL, 0);

	MoveFileBtn = new wxButton(ToolBar, wxID_ANY, _("Move"), wxDefaultPosition, wxDefaultSize, 0);

	MoveFileBtn->SetBitmap(wxBitmap(wxT("icons/MoveFile40.png"), wxBITMAP_TYPE_ANY));
	MoveFileBtn->SetBitmapPosition(wxTOP);
	ToolbarSizer->Add(MoveFileBtn, 0, wxALL, 0);

	ToolbarSizer->Add(10, 0, 0, wxEXPAND, 5);

	FindReplacePanel = new wxPanel(ToolBar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer *FindReplaceSizer;
	FindReplaceSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer *FindSizer;
	FindSizer = new wxBoxSizer(wxHORIZONTAL);

	FindL = new wxStaticText(FindReplacePanel, wxID_ANY, _("Find :"), wxDefaultPosition, wxSize(40, -1), 0);
	FindL->Wrap(-1);
	FindSizer->Add(FindL, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	FindInput = new wxTextCtrl(FindReplacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), wxTE_PROCESS_ENTER);
	FindSizer->Add(FindInput, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxBoxSizer *PrevNextBtnSizer;
	PrevNextBtnSizer = new wxBoxSizer(wxHORIZONTAL);

	FindPrevBtn = new wxButton(FindReplacePanel, wxID_ANY, _("<"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
	PrevNextBtnSizer->Add(FindPrevBtn, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	FindNextBtn = new wxButton(FindReplacePanel, wxID_ANY, _(">"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
	PrevNextBtnSizer->Add(FindNextBtn, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	DoneFindBtn = new wxButton(FindReplacePanel, wxID_ANY, _("Done"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
	PrevNextBtnSizer->Add(DoneFindBtn, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	FindSizer->Add(PrevNextBtnSizer, 1, wxEXPAND, 5);

	FindReplaceSizer->Add(FindSizer, 1, wxEXPAND, 0);

	wxBoxSizer *ReplaceSizer;
	ReplaceSizer = new wxBoxSizer(wxHORIZONTAL);

	ReplaceL = new wxStaticText(FindReplacePanel, wxID_ANY, _("Replace :"), wxDefaultPosition, wxSize(40, -1), 0);
	ReplaceL->Wrap(-1);
	ReplaceSizer->Add(ReplaceL, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	ReplaceI = new wxTextCtrl(FindReplacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0);
	ReplaceSizer->Add(ReplaceI, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	ReplaceBtn = new wxButton(FindReplacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(30, -1), 0);

	ReplaceBtn->SetBitmap(wxBitmap(wxT("icons/Replace16.png"), wxBITMAP_TYPE_ANY));
	ReplaceSizer->Add(ReplaceBtn, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	FindReplaceSizer->Add(ReplaceSizer, 1, wxEXPAND, 0);

	FindReplacePanel->SetSizer(FindReplaceSizer);
	FindReplacePanel->Layout();
	FindReplaceSizer->Fit(FindReplacePanel);
	ToolbarSizer->Add(FindReplacePanel, 0, wxEXPAND | wxALL, 0);

	ToolbarSizer->Add(10, 0, 0, wxEXPAND, 5);

	CloseBtn = new wxButton(ToolBar, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0);

	CloseBtn->SetBitmap(wxBitmap(wxT("icons/CloseFile40.png"), wxBITMAP_TYPE_ANY));
	CloseBtn->SetBitmapPosition(wxTOP);
	ToolbarSizer->Add(CloseBtn, 0, wxALL, 0);

	DeleteBtn = new wxButton(ToolBar, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0);

	DeleteBtn->SetBitmap(wxBitmap(wxT("icons/DeleteFile40.png"), wxBITMAP_TYPE_ANY));
	DeleteBtn->SetBitmapPosition(wxTOP);
	ToolbarSizer->Add(DeleteBtn, 0, wxALL, 0);

	ToolBar->SetSizer(ToolbarSizer);
	ToolBar->Layout();
	ToolbarSizer->Fit(ToolBar);
	PanelSizer->Add(ToolBar, 0, wxEXPAND | wxALL, 0);

	TextEditor = new wxTextCtrl(MainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_PROCESS_ENTER | wxTE_PROCESS_TAB | wxTE_RICH | wxTE_RICH2);
	TextEditor->SetFont(wxFont(18, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Courier")));

	PanelSizer->Add(TextEditor, 1, wxALL | wxEXPAND, 0);

	MainPanel->SetSizer(PanelSizer);
	MainPanel->Layout();
	PanelSizer->Fit(MainPanel);
	MainSizer->Add(MainPanel, 1, wxEXPAND | wxALL, 0);

	this->SetSizer(MainSizer);
	this->Layout();
	StatusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);
	MenuBar = new wxMenuBar(0);
	File = new wxMenu();
	wxMenuItem *NewFile;
	NewFile = new wxMenuItem(File, wxID_ANY, wxString(_("New File")) + wxT('\t') + wxT("CTRL+N"), wxEmptyString, wxITEM_NORMAL);
	File->Append(NewFile);

	wxMenuItem *OpenFile;
	OpenFile = new wxMenuItem(File, wxID_ANY, wxString(_("Open File")) + wxT('\t') + wxT("CTRL+O"), wxEmptyString, wxITEM_NORMAL);
	File->Append(OpenFile);

	wxMenuItem *OpenFileNew;
	OpenFileNew = new wxMenuItem(File, wxID_ANY, wxString(_("Open File in New Window")), wxEmptyString, wxITEM_NORMAL);
	File->Append(OpenFileNew);

	File->AppendSeparator();

	wxMenuItem *SaveFile;
	SaveFile = new wxMenuItem(File, wxID_ANY, wxString(_("Save")) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL);
	File->Append(SaveFile);

	wxMenuItem *SaveAsFile;
	SaveAsFile = new wxMenuItem(File, wxID_ANY, wxString(_("Save As")) + wxT('\t') + wxT("CTRL+SHIFT+S"), wxEmptyString, wxITEM_NORMAL);
	File->Append(SaveAsFile);

	File->AppendSeparator();

	wxMenuItem *MoveFile;
	MoveFile = new wxMenuItem(File, wxID_ANY, wxString(_("Move to")), wxEmptyString, wxITEM_NORMAL);
	File->Append(MoveFile);

	wxMenuItem *CloseFile;
	CloseFile = new wxMenuItem(File, wxID_ANY, wxString(_("Close")), wxEmptyString, wxITEM_NORMAL);
	File->Append(CloseFile);

	wxMenuItem *DeleteFile;
	DeleteFile = new wxMenuItem(File, wxID_ANY, wxString(_("Delete")), wxEmptyString, wxITEM_NORMAL);
	File->Append(DeleteFile);

	MenuBar->Append(File, _("File"));

	Edit = new wxMenu();
	wxMenuItem *Undo;
	Undo = new wxMenuItem(Edit, wxID_ANY, wxString(_("Undo")) + wxT('\t') + wxT("CTRL+Z"), wxEmptyString, wxITEM_NORMAL);
	Edit->Append(Undo);

	wxMenuItem *Redo;
	Redo = new wxMenuItem(Edit, wxID_ANY, wxString(_("Redo")) + wxT('\t') + wxT("CTRL+SHIFT+Z"), wxEmptyString, wxITEM_NORMAL);
	Edit->Append(Redo);

	Edit->AppendSeparator();

	wxMenuItem *Cut;
	Cut = new wxMenuItem(Edit, wxID_ANY, wxString(_("Cut")) + wxT('\t') + wxT("CTRL+X"), wxEmptyString, wxITEM_NORMAL);
	Edit->Append(Cut);

	wxMenuItem *Copy;
	Copy = new wxMenuItem(Edit, wxID_ANY, wxString(_("Copy")) + wxT('\t') + wxT("CTRL+C"), wxEmptyString, wxITEM_NORMAL);
	Edit->Append(Copy);

	wxMenuItem *Paste;
	Paste = new wxMenuItem(Edit, wxID_ANY, wxString(_("Paste")) + wxT('\t') + wxT("CTRL+V"), wxEmptyString, wxITEM_NORMAL);
	Edit->Append(Paste);

	Edit->AppendSeparator();

	wxMenuItem *SelectAll;
	SelectAll = new wxMenuItem(Edit, wxID_ANY, wxString(_("Select All")) + wxT('\t') + wxT("CTRL+A"), wxEmptyString, wxITEM_NORMAL);
	Edit->Append(SelectAll);

	MenuBar->Append(Edit, _("Edit"));

	Text = new wxMenu();
	wxMenuItem *FontSize;
	FontSize = new wxMenuItem(Text, wxID_ANY, wxString(_("Set Font Size")), wxEmptyString, wxITEM_NORMAL);
	Text->Append(FontSize);

	MenuBar->Append(Text, _("Text"));

	Window = new wxMenu();
	wxMenuItem *FullScreen;
	FullScreen = new wxMenuItem(Window, wxID_ANY, wxString(_("Full Screen")), wxEmptyString, wxITEM_NORMAL);
	Window->Append(FullScreen);

	wxMenuItem *NewWindow;
	NewWindow = new wxMenuItem(Window, wxID_ANY, wxString(_("New Window")) + wxT('\t') + wxT("CTRL+SHIFT+N"), wxEmptyString, wxITEM_NORMAL);
	Window->Append(NewWindow);

	MenuBar->Append(Window, _("Window"));

	this->SetMenuBar(MenuBar);

	this->Centre(wxBOTH);

	// Connect Events
	NewFileBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::CreateNewFile), NULL, this);
	OpenFileBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::OpenFileNew), NULL, this);
	SaveFileBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::SaveFile), NULL, this);
	SaveAsFileBtn1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::SaveFileAs), NULL, this);
	MoveFileBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::MoveFileF), NULL, this);
	FindInput->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(IFrame::FindText), NULL, this);
	FindPrevBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::FindPrev), NULL, this);
	FindNextBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::FindNext), NULL, this);
	DoneFindBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::FindDone), NULL, this);
	ReplaceBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::Replace), NULL, this);
	CloseBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::CloseFile), NULL, this);
	DeleteBtn->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(IFrame::DeleteFileF), NULL, this);
	TextEditor->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(IFrame::TextEditorType), NULL, this);
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::CreateNewFile), this, NewFile->GetId());
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::OpenFile), this, OpenFile->GetId());
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::OpenFileNew), this, OpenFileNew->GetId());
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::SaveFile), this, SaveFile->GetId());
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::SaveFileAs), this, SaveAsFile->GetId());
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::MoveFileF), this, MoveFile->GetId());
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::CloseFile), this, CloseFile->GetId());
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::DeleteFileF), this, DeleteFile->GetId());
	Edit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::Undo), this, Undo->GetId());
	Edit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::Redo), this, Redo->GetId());
	Edit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::Cut), this, Cut->GetId());
	Edit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::Copy), this, Copy->GetId());
	Edit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::Paste), this, Paste->GetId());
	Edit->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::SelectAll), this, SelectAll->GetId());
	Text->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::SetFontSize), this, FontSize->GetId());
	Window->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::FullScreen), this, FullScreen->GetId());
	Window->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(IFrame::NewWindow), this, NewWindow->GetId());
}

IFrame::~IFrame()
{
}
