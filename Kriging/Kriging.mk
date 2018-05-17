##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Kriging
ConfigurationName      :=Release
WorkspacePath          :=/media/eon/Archivos/proyectosGit/GEOSTATISTICAL_ANALYSIS_GUI/KrigingGUI
ProjectPath            :=/media/eon/Archivos/proyectosGit/GEOSTATISTICAL_ANALYSIS_GUI/KrigingGUI/Kriging
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=eon
Date                   :=17/05/18
CodeLitePath           :=/home/eon/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Kriging.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0) 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)src/GUI $(IncludeSwitch)/usr/local/include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  $(shell pkg-config --cflags gtkmm-3.0)  $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_GUI_WindowGUI.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GUI_PlotValues.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GUI_ModelColumns.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_GUI_Kriging.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_GUI_WindowGUI.cpp$(ObjectSuffix): src/GUI/WindowGUI.cpp $(IntermediateDirectory)/src_GUI_WindowGUI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/eon/Archivos/proyectosGit/GEOSTATISTICAL_ANALYSIS_GUI/KrigingGUI/Kriging/src/GUI/WindowGUI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GUI_WindowGUI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GUI_WindowGUI.cpp$(DependSuffix): src/GUI/WindowGUI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GUI_WindowGUI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GUI_WindowGUI.cpp$(DependSuffix) -MM src/GUI/WindowGUI.cpp

$(IntermediateDirectory)/src_GUI_WindowGUI.cpp$(PreprocessSuffix): src/GUI/WindowGUI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GUI_WindowGUI.cpp$(PreprocessSuffix) src/GUI/WindowGUI.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/eon/Archivos/proyectosGit/GEOSTATISTICAL_ANALYSIS_GUI/KrigingGUI/Kriging/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/src_GUI_PlotValues.cpp$(ObjectSuffix): src/GUI/PlotValues.cpp $(IntermediateDirectory)/src_GUI_PlotValues.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/eon/Archivos/proyectosGit/GEOSTATISTICAL_ANALYSIS_GUI/KrigingGUI/Kriging/src/GUI/PlotValues.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GUI_PlotValues.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GUI_PlotValues.cpp$(DependSuffix): src/GUI/PlotValues.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GUI_PlotValues.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GUI_PlotValues.cpp$(DependSuffix) -MM src/GUI/PlotValues.cpp

$(IntermediateDirectory)/src_GUI_PlotValues.cpp$(PreprocessSuffix): src/GUI/PlotValues.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GUI_PlotValues.cpp$(PreprocessSuffix) src/GUI/PlotValues.cpp

$(IntermediateDirectory)/src_GUI_ModelColumns.cpp$(ObjectSuffix): src/GUI/ModelColumns.cpp $(IntermediateDirectory)/src_GUI_ModelColumns.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/eon/Archivos/proyectosGit/GEOSTATISTICAL_ANALYSIS_GUI/KrigingGUI/Kriging/src/GUI/ModelColumns.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GUI_ModelColumns.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GUI_ModelColumns.cpp$(DependSuffix): src/GUI/ModelColumns.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GUI_ModelColumns.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GUI_ModelColumns.cpp$(DependSuffix) -MM src/GUI/ModelColumns.cpp

$(IntermediateDirectory)/src_GUI_ModelColumns.cpp$(PreprocessSuffix): src/GUI/ModelColumns.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GUI_ModelColumns.cpp$(PreprocessSuffix) src/GUI/ModelColumns.cpp

$(IntermediateDirectory)/src_GUI_Kriging.cpp$(ObjectSuffix): src/GUI/Kriging.cpp $(IntermediateDirectory)/src_GUI_Kriging.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/eon/Archivos/proyectosGit/GEOSTATISTICAL_ANALYSIS_GUI/KrigingGUI/Kriging/src/GUI/Kriging.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GUI_Kriging.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GUI_Kriging.cpp$(DependSuffix): src/GUI/Kriging.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GUI_Kriging.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GUI_Kriging.cpp$(DependSuffix) -MM src/GUI/Kriging.cpp

$(IntermediateDirectory)/src_GUI_Kriging.cpp$(PreprocessSuffix): src/GUI/Kriging.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GUI_Kriging.cpp$(PreprocessSuffix) src/GUI/Kriging.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


