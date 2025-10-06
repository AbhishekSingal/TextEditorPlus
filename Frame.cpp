#include "Frame.h"
#include <fstream>
#include <filesystem>
#include <vector>

Frame::Frame() : IFrame(nullptr)
{
	TextEditor->SetFont(wxFont(14, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
	SetSize(wxSize(650, 500));
}

void Frame::save_file()
{
	std::ofstream file(filepath);
	file.clear();
	file << TextEditor->GetValue();
	file.close();
}

void Frame::CreateNewFile(wxCommandEvent &event)
{
	wxTextEntryDialog *file_name = new wxTextEntryDialog(this, "File Name : ", "Create New File");
	file_name->SetSize(wxSize(600, 120));
	if (file_name->ShowModal() == wxID_OK)
	{
		filename = file_name->GetValue().ToStdString();
	}
	else
	{
		return;
	}

	file_name->Close();

	wxDirDialog *dir_dlg = new wxDirDialog(this, "Select Location");
	if (dir_dlg->ShowModal() == wxID_OK)
	{
		dir = dir_dlg->GetPath().ToStdString();
		if (wxFileExists(dir + wxFILE_SEP_PATH + filename))
		{
			wxMessageBox("File Already Exist , Please Choose Another Name");
			return;
		}
		wxFile file;
		file.Create(dir + wxFILE_SEP_PATH + filename);
		filepath = dir + wxFILE_SEP_PATH + filename;
		SetStatusText(dir + wxFILE_SEP_PATH + filename + " Created Successfully");
		SetTitle("TextEditor - " + dir + wxFILE_SEP_PATH + filename);
	}

	dir_dlg->Close();
}

void Frame::OpenFile(wxCommandEvent &event)
{
	wxFileDialog *file_dlg = new wxFileDialog(this);
	if (file_dlg->ShowModal() == wxID_OK)
	{
		this->filename = file_dlg->GetFilename();
		this->dir = file_dlg->GetDirectory();

		std::ifstream file(file_dlg->GetPath().ToStdString());
		std::string contents = "";
		std::string line = "";
		while (std::getline(file, line))
		{
			contents += line;
			contents += "\n";
		}

		TextEditor->SetValue(contents);

		filepath = dir + wxFILE_SEP_PATH + filename;
		SetStatusText(dir + wxFILE_SEP_PATH + filename + " Opened Successfully");
		SetTitle("TextEditor - " + dir + wxFILE_SEP_PATH + filename);
	}
}

void Frame::OpenFileNew(wxCommandEvent &event)
{
	if (filepath == "")
	{
		wxCommandEvent event_;
		OpenFile(event_);
		return;
	}
	wxFileDialog *file_dlg = new wxFileDialog(this);
	if (file_dlg->ShowModal() == wxID_OK)
	{
		Frame *frame = new Frame();
		frame->SetSize(wxSize(1050, 700));
		frame->Layout();
		frame->Show(true);

		frame->filename = file_dlg->GetFilename();
		frame->dir = file_dlg->GetDirectory();

		std::ifstream file(file_dlg->GetPath().ToStdString());
		std::string contents = "";
		std::string line = "";
		while (std::getline(file, line))
		{
			contents += line;
			contents += "\n";
		}

		frame->TextEditor->SetValue(contents);

		frame->filepath = frame->dir + wxFILE_SEP_PATH + frame->filename;
		frame->SetStatusText(frame->dir + wxFILE_SEP_PATH + frame->filename + " Opened Successfully");
		frame->SetTitle("TextEditor - " + frame->dir + wxFILE_SEP_PATH + frame->filename);
	}
}

void Frame::SaveFile(wxCommandEvent &event)
{
	if (filepath == "")
	{
		wxCommandEvent event_;
		SaveFileAs(event_);
		return;
	};
	std::ofstream file(filepath);
	file.clear();
	file << TextEditor->GetValue();
	file.close();
	SetStatusText(filepath + " Saved Successfully");
	SetTitle("TextEditor - " + filepath + " (Saved)");
	saved = true;
}

void Frame::SaveFileAs(wxCommandEvent &event)
{
	std::string original_path = filepath;

	wxTextEntryDialog *file_name = new wxTextEntryDialog(this, "File Name : ", "Save File As");
	file_name->SetSize(wxSize(600, 120));
	if (file_name->ShowModal() == wxID_OK)
	{
		filename = file_name->GetValue().ToStdString();
	}
	else
	{
		return;
	}

	file_name->Close();

	wxDirDialog *dir_dlg = new wxDirDialog(this, "Select Location");
	if (dir_dlg->ShowModal() == wxID_OK)
	{
		dir = dir_dlg->GetPath().ToStdString();
		filepath = dir + wxFILE_SEP_PATH + filename;

		if (wxFileExists(dir + wxFILE_SEP_PATH + filename))
		{
			wxMessageBox("File Already Exist , Please Choose Another Name");
			return;
		}

		if (original_path == "")
		{
			wxCommandEvent event_;
			SaveFile(event_);
		}
		else
		{
			wxRenameFile(original_path, dir + wxFILE_SEP_PATH + filename);
		}

		SetTitle("TextEditor - " + dir + wxFILE_SEP_PATH + filename + " (Saved)");
		SetStatusText("File Saved As " + dir + wxFILE_SEP_PATH + filename);

		save_file();
		saved = true;
	}

	dir_dlg->Close();
}

void Frame::MoveFileF(wxCommandEvent &event)
{
	if (filepath == "")
	{
		event.Skip();
		return;
	};
	std::string orignal_path = filepath;
	wxDirDialog *dir_dlg = new wxDirDialog(this, "Select Move Location");
	if (dir_dlg->ShowModal() == wxID_OK)
	{
		dir = dir_dlg->GetPath();
		filepath = dir + wxFILE_SEP_PATH + filename;
		if (wxFileExists(dir + wxFILE_SEP_PATH + filename))
		{
			wxMessageBox("File Already Exist , Please Choose Another Name");
			return;
		}
		wxRenameFile(orignal_path, filepath);
		SetTitle("TextEditor - " + dir + wxFILE_SEP_PATH + filename);
		SetStatusText("File Moved To " + dir);
		save_file();
	}

	dir_dlg->Close();
}

void Frame::CloseFile(wxCommandEvent &event)
{
	if (filepath == "")
	{
		event.Skip();
		return;
	};
	save_file();
	TextEditor->SetValue("");
	SetTitle("TextEditor");
	SetStatusText(filepath + " Closed and Saved Successfully");
}

void Frame::DeleteFileF(wxCommandEvent &event)
{
	if (filepath == "")
	{
		event.Skip();
		return;
	};
	wxMessageDialog *msldg = new wxMessageDialog(this, "Confirm Delete File ?\nThis action cannot be undone", "TextEditor", wxYES_NO | wxICON_QUESTION);
	if (msldg->ShowModal() == wxID_YES)
	{
		wxRemoveFile(filepath);
		TextEditor->SetValue("");
		SetTitle("TextEditor");
		SetStatusText(filepath + " Deleted");
	}
}

void Frame::Undo(wxCommandEvent &event)
{
	TextEditor->Undo();
}

void Frame::Redo(wxCommandEvent &event)
{
	TextEditor->Redo();
}

void Frame::Cut(wxCommandEvent &event)
{
	TextEditor->Cut();
}

void Frame::Copy(wxCommandEvent &event)
{
	TextEditor->Copy();
}

void Frame::Paste(wxCommandEvent &event)
{
	TextEditor->Paste();
}

void Frame::SelectAll(wxCommandEvent &event)
{
	TextEditor->SelectAll();
}

void Frame::FindText(wxCommandEvent &event)
{
	find_pos.clear();

	wxTextAttr default_(
		wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT),
		wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	TextEditor->SetStyle(0, TextEditor->GetLastPosition(), default_);

	std::string content = TextEditor->GetValue().ToStdString();
	std::string to_find = FindInput->GetValue().ToStdString();
	if (to_find == "")
	{
		return;
	};
	size_t pos = content.find(to_find);

	wxTextAttr attr;
	attr.SetBackgroundColour(*wxYELLOW);
	attr.SetTextColour(*wxBLACK);

	int i = 0;

	while (pos != std::string::npos)
	{
		find_pos.push_back(pos);
		if (i == 0)
		{
			TextEditor->SetStyle(pos, pos + to_find.length(), wxTextAttr(*wxWHITE, *wxBLUE));
		}
		else
		{
			TextEditor->SetStyle(pos, pos + to_find.length(), attr);
		}

		pos = content.find(to_find, pos + to_find.length());
		i++;
	}

	total_occ = find_pos.size();
	wxMessageBox("Occurances of \"" + to_find + "\" Found : " + std::to_string(find_pos.size()));
	SetStatusText("Occurances of \"" + to_find + "\" Found : " + std::to_string(find_pos.size()));
}

void Frame::FindNext(wxCommandEvent &event)
{
	std::string to_find = FindInput->GetValue().ToStdString();
	if (find_pos.size() == 0)
	{
		return;
	};

	int next_occ = (current_find_occ != find_pos.size() - 1 ? current_find_occ + 1 : 0);

	wxTextAttr yllw;
	yllw.SetBackgroundColour(*wxYELLOW);
	yllw.SetTextColour(*wxBLACK);
	TextEditor->SetStyle(find_pos[current_find_occ], find_pos[current_find_occ] + to_find.length(), yllw);

	wxTextAttr next_attr;
	next_attr.SetBackgroundColour(*wxBLUE);
	next_attr.SetTextColour(*wxWHITE);
	TextEditor->SetStyle(find_pos[next_occ], find_pos[next_occ] + to_find.length(), next_attr);
	TextEditor->ShowPosition(find_pos[next_occ]);
	SetStatusText("Occurance " + std::to_string(next_occ + 1) + " Out of " + std::to_string(total_occ));

	current_find_occ = next_occ;
}

void Frame::FindPrev(wxCommandEvent &event)
{
	std::string to_find = FindInput->GetValue().ToStdString();
	if (find_pos.size() == 0)
	{
		return;
	};

	int prev_occ = (current_find_occ != 0 ? current_find_occ - 1 : find_pos.size() - 1);

	wxTextAttr yllw;
	yllw.SetBackgroundColour(*wxYELLOW);
	yllw.SetTextColour(*wxBLACK);
	TextEditor->SetStyle(find_pos[current_find_occ], find_pos[current_find_occ] + to_find.length(), yllw);

	wxTextAttr next_attr;
	next_attr.SetBackgroundColour(*wxBLUE);
	next_attr.SetTextColour(*wxWHITE);
	TextEditor->SetStyle(find_pos[prev_occ], find_pos[prev_occ] + to_find.length(), next_attr);
	TextEditor->ShowPosition(find_pos[prev_occ]);
	SetStatusText("Occurance " + std::to_string(prev_occ + 1) + " Out of " + std::to_string(total_occ));

	current_find_occ = prev_occ;
}

void Frame::FindDone(wxCommandEvent &event)
{
	total_occ = 0;
	current_find_occ = 0;
	find_pos.clear();

	wxTextAttr default_(
		wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT),
		wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	TextEditor->SetStyle(0, TextEditor->GetLastPosition(), default_);
}

void Frame::Replace(wxCommandEvent &event)
{
	std::string contents = TextEditor->GetValue().ToStdString();
	std::string to_repl = FindInput->GetValue().ToStdString();
	std::string repl_with = ReplaceI->GetValue().ToStdString();
	if (to_repl != "" && repl_with != "")
	{
		int i = 0;

		std::string to = repl_with;
		std::string from = to_repl;
		std::string str = contents;

		size_t pos = 0;
		size_t fromLength = from.length();
		size_t toLength = to.length();

		while ((pos = str.find(from, pos)) != std::string::npos)
		{
			str.replace(pos, fromLength, to);
			pos += toLength; // Move past the last replaced substring
			i++;
		}

		contents = str;

		TextEditor->SetValue(contents);
		if (i != 0)
		{
			wxMessageBox("Replaced " + std::to_string(i) + " Occurances of \"" + to_repl + "\" with " + repl_with);
		}
		else
		{
			wxMessageBox("No Occurances of " + to_repl + " found to Replace");
		}
	}
	else
	{
		wxMessageBox("Please fill in Find and Replace Values");
	}
}

void Frame::SetFontSize(wxCommandEvent &event)
{
	if (filepath == "")
	{
		event.Skip();
		return;
	};
	wxTextEntryDialog *fontsize_dlg = new wxTextEntryDialog(this, "Point Size : ", "Set Font Size", std::to_string(TextEditor->GetFont().GetPointSize()));
	if (fontsize_dlg->ShowModal() == wxID_OK)
	{
		int font_size = std::stoi(fontsize_dlg->GetValue().ToStdString());
		TextEditor->SetFont(wxFont(font_size, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
		Layout();
	}
}

void Frame::FullScreen(wxCommandEvent &event)
{
	this->Maximize();
}

void Frame::NewWindow(wxCommandEvent &event)
{
	Frame *frame = new Frame();
	frame->SetSize(wxSize(1050, 700));
	frame->Layout();
	frame->Show(true);
}

void Frame::TextEditorType(wxCommandEvent &event)
{
	saved = false;
	SetStatusText("Editing " + filepath);
	SetTitle("TextEditor - " + filepath + " (Not Saved)");

	// wxCommandEvent event_;
	// FindDone(event_);
}
