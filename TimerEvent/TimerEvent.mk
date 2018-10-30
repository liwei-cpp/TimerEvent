##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=TimerEvent
ConfigurationName      :=Release
WorkspacePath          :=/home/liwei/TimerEvent
ProjectPath            :=/home/liwei/TimerEvent/TimerEvent
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=liwei
Date                   :=30/10/18
CodeLitePath           :=/home/liwei/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="TimerEvent.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=   $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_event.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_shared_timer_impl.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_shared_timer.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/liwei/TimerEvent/.build-release"
	@echo rebuilt > "/home/liwei/TimerEvent/.build-release/TimerEvent"

MakeIntermediateDirs:
	@test -d ./Release || $(MakeDirCommand) ./Release


./Release:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_event.cpp$(ObjectSuffix): src/event.cpp $(IntermediateDirectory)/src_event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/liwei/TimerEvent/TimerEvent/src/event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_event.cpp$(DependSuffix): src/event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_event.cpp$(DependSuffix) -MM src/event.cpp

$(IntermediateDirectory)/src_event.cpp$(PreprocessSuffix): src/event.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_event.cpp$(PreprocessSuffix) src/event.cpp

$(IntermediateDirectory)/src_shared_timer_impl.cpp$(ObjectSuffix): src/shared_timer_impl.cpp $(IntermediateDirectory)/src_shared_timer_impl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/liwei/TimerEvent/TimerEvent/src/shared_timer_impl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_shared_timer_impl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_shared_timer_impl.cpp$(DependSuffix): src/shared_timer_impl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_shared_timer_impl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_shared_timer_impl.cpp$(DependSuffix) -MM src/shared_timer_impl.cpp

$(IntermediateDirectory)/src_shared_timer_impl.cpp$(PreprocessSuffix): src/shared_timer_impl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_shared_timer_impl.cpp$(PreprocessSuffix) src/shared_timer_impl.cpp

$(IntermediateDirectory)/src_shared_timer.cpp$(ObjectSuffix): src/shared_timer.cpp $(IntermediateDirectory)/src_shared_timer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/liwei/TimerEvent/TimerEvent/src/shared_timer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_shared_timer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_shared_timer.cpp$(DependSuffix): src/shared_timer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_shared_timer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_shared_timer.cpp$(DependSuffix) -MM src/shared_timer.cpp

$(IntermediateDirectory)/src_shared_timer.cpp$(PreprocessSuffix): src/shared_timer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_shared_timer.cpp$(PreprocessSuffix) src/shared_timer.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


