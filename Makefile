TextEditor:App.cpp Frame.cpp IFrame.cpp
	clang++ App.cpp Frame.cpp IFrame.cpp `wx-config --cxxflags --libs` -o TextEditor 