#include "IFrame.h"
#include <wx/msgdlg.h>
#include <wx/textdlg.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>


class Frame :public IFrame
{

protected:

	std::string filename;
	std::string dir;
	std::string filepath = "";
	bool saved = true;

	void save_file();




	//File Menu
	void CreateNewFile(wxCommandEvent& event);
	void OpenFile(wxCommandEvent& event);
	void OpenFileNew(wxCommandEvent& event);
	void SaveFile(wxCommandEvent& event);
	void SaveFileAs(wxCommandEvent& event);
	void MoveFileF(wxCommandEvent& event);
	void CloseFile(wxCommandEvent& event);
	void DeleteFileF(wxCommandEvent& event);

	//Edit Menu
	void Undo(wxCommandEvent& event);
	void Redo(wxCommandEvent& event);
	void Cut(wxCommandEvent& event);
	void Copy(wxCommandEvent& event);
	void Paste(wxCommandEvent& event);
	void SelectAll(wxCommandEvent& event);

	//Text Menu
	int total_occ = 0;
	int current_find_occ = 0;
	std::vector<size_t> find_pos;
	void FindText(wxCommandEvent& event);
	void FindNext(wxCommandEvent& event);
	void FindPrev(wxCommandEvent& event);
	void FindDone(wxCommandEvent& event);
	void Replace(wxCommandEvent& event);
	void SetFontSize(wxCommandEvent& event);

	//Window Menu
	void FullScreen(wxCommandEvent& event);
	void NewWindow(wxCommandEvent& event);


	void TextEditorType(wxCommandEvent& event);




public:
	Frame();

};
